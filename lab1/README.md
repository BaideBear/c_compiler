# 词法分析与语法分析的实现

**contributer**: BaideBear, auroralbeauty

## 运行方式

编译过程：

```bash
cd Code
make
```

生成的程序是出现在Code目录下的parser，以下是parser的使用方法：

```bash
./parser ./path_to_Test/test.cmm #test.cmm是等待被处理的C--代码
```

## 设计思路

### 符号管理

我们使用树状结构来管理所有的终结符和非终结符节点，树上每个节点的结构如下（在注释中有详细的解释）：

```c++
#define TERMINAL 0x88
#define UNTERMINAL 0x99
typedef struct Node{
    char *name;   //节点的名字 
    int type;     //节点种类（TERMINAL, UNTERMINAL）
    char *text;   //节点对应的文本内容，非终结符为空（'\0'）
    int pos;      //代码行号
    struct Node* up;     //父节点
    struct Node* down;   //第一个子节点
    struct Node* next;   //右侧节点
}Node;
```

以下是创建节点和加入文法（S->ABC...）的接口:

```c++
void set_root(Node* node); //创建根节点的接口，只在创建Program时调用
Node* create_node(char *name, int type, char *text, int pos); //创建节点，从左到右分别是node类型的各个属性值
Node* build_cfg(Node* S, int cnt, ...);  //构建文法S->ABC..., cnt是右侧产生式的符号数目，后面的参数是各个产生式对应的节点指针，用va_list处理
```

通过print_tree()接口来打印整个语法树，打印代码使用深度优先遍历（dfs）实现；

### flex实现细节

- 每个接口调用create_node接口即可，然后把创建的node返回给bison；

- A类型错误处理（未匹配的符号），打印A类报错并且标记报错行数即可（标记行数是为了防止在bison中同一个错误被重复播报）；

```c++
. { 
    printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext);
    flex_has_error = 1;
    is_flex_error[yylineno] = 1;
}
```

- 注释处理：对于“//”,直接跳过所在行即可；对于“$/**/$”,我们在识别到 “$/*$”模式之后，一直进行读取，跨行后一直继续读取，直到能够匹配到第一个“$*/$”,我们进行退出。要注意的是，注释错误作为B型错误，我们在flex中进行了单独处理，对于有“$/*$”但是没有“$*/$”出现或者“$*/$”多出现的情况，我们在flex中都进行了捕捉；

- 加入了DEBUG模式，通过“#define DEBUG_MODE”来对FLEX的匹配过程进行打印；

### bison实现细节

- 对于每个产生式语句，先调用create_node创建左节点，再调用build_cfg来将文法的结构传递到树结构中；

- 重载yyerror函数，捕获到的错误，不在A型中播报过的，进行B类型的错误播报；

- 错误处理

错误处理的格式如下，对错误所在的左节点设置为NULL,并设置bison_has_error为true（用来决定是否打印文法树）：

```c++
S: A error C {$$ = NULL; bison_has_error = 1;} // S->ABC中的B匹配失败，那我们跳过B，继续处理
```

错误处理初始考虑是枚举产生式每个位置可能的错误并把他们都报出来，经过测试我们发现，这样会发生大量的[规约-规约]错误导致出现多个错报或误报；

之后的思路是沿着发现的问题去做减法，对冗余的错误匹配进行移除。方法如下：考虑其他非终结符尽量不考虑错误处理，只处理各个非终结符特有的错误（**e.g.**:有的非终结符产生式会产生逗号，处理该处逗号缺失或被替换的错误*:**），不处理括号匹配等在多个非终结符产生式会发生，可能出现[规约-规约]冲突的错误，这些错误集中到Stmt的产生式和Exp的产生式进行处理。

以下是一个false positive的例子：

```c++
while (j < (n) {
    n = n - 2;
    j = j + 1;
}
```

实际上只应该报出while行的错误，但是代码同时报出了n=n-2行的错误，上交的代码并未成功处理掉这个多报的错误。
