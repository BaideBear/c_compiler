# 目标代码生成

**id**: BaideBear

## 运行方式

编译过程：

```bash
cd Code
make
```

生成的程序是出现在Code目录下的parser，以下是parser的使用方法：

```bash
./parser ./path_to_Test/test.cmm ./out.s #test.cmm是等待被处理的C--代码,out.s是生成的mips目标代码的位置
```

## 实现思路

### mips语句的储存结构

我使用链表的方式储存生成的mips语句，并提供了生成初始代码的接口、添加新mips语句的接口、以及以printf格式添加mips语句的接口：

```c
typedef struct MipsCode MipsCode;
struct MipsCode{
    char *code;
    MipsCode* next;
    MipsCode* pre;
};
typedef struct MipsCodeList{
    MipsCode* head;
    MipsCode* tail;
}MipsCodeList;
void output_mipscode(FILE* file, MipsCodeList* mcl); //将mips代码输出到对应的文件中
void output_mipscode_std(MipsCodeList* mcl); //将mips代码输出到stdout
MipsCode* new_mipscode(const char *formatted_code); //创建新的mips语句
MipsCodeList* new_mipscodelist(); //创建新的mips语句列表，包含可执行mips文件的初始代码
void add_mipscode(MipsCodeList* mcl, char *pattern, ...); //在列表中添加新的mips代码
```

### 寄存器管理

使用了朴素分配方法，不过多描述；

### 栈管理

这是我的栈布局：

```bash
高地址
+-------------------+
| 保存的$s8         | <-- 新$s8指向这里 (旧帧指针)
+-------------------+
| 返回地址          | 
+-------------------+
| 参数5+            | (如果有的话)
| ...               |
+-------------------+
| 局部变量1         |
| 局部变量2         |
| ...               |
| 数组/大对象       |
+-------------------+ <-- 当前$sp
低地址

```

首先，我用一个哈希表管理当前所有的变量的偏移量，用sp_offset表示当前栈的偏移计数器：

```c
int sp_offset = 0;  // 当前栈偏移计数器(以字为单位)
HashTable_Offset* table_offset;  // 变量到栈偏移的映射表
```

1. create_sp: 为函数调用准备栈空间

遍历函数的中间代码，收集所有需要栈空间的变量:对于DEC指令(数组/结构体)，调用dec_offset;对于其他变量，调用add_offset;

保存旧的帧指针($s8),设置新的帧指针,调整栈指针($sp)为所有局部变量分配空间

2. add_offset: 为普通变量分配栈空间(4字节)

3. dec_offset: 为数组/结构体等大对象分配栈空间

4. get_offset: 获取变量在栈帧中的偏移量

