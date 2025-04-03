# 语义分析的实现

**id**: BaideBear

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

## 实现思路

### 符号表的实现

整体使用了两张表，table_syn储存所有的类型结构，table_func储存所有的函数结构；数据表使用哈希表进行管理，实现方式是PJW哈希函数+线性探查开散列；

对于符号结构体，对推荐的数据结构进行了如下修改，在kind类型中添加了FAULT项，用于在出现语义错误时，对错误的符号类型使用FAULT类型的Type进行填充，而不是直接返回NULL，解决了空指针访问导致RE的问题。

```c
struct Type{
    enum { BASIC, ARRAY, STRUCTURE, FAULT} kind;
    union {
        int basic; //BASIC, 0->int, 1->float
        struct { Type* elem; int size; }; //ARRAY
        FieldList* structure; //STRUCTURE
    };
};
```

函数使用如下结构储存，其中的Args结构体是一个单向链表的表头，用来储存每一个参数的类型：

```c
struct Func{
    char* name;
    Type* return_type;
    Arg* args;
};
```

实现了包括节点创建、节点比较、插入、查询等基本的api，以提高代码的复用性，整个符号表的接口可以通过syn_hash_list.h调用

### 语义分析的实现细节

#### 结构体，函数的特殊处理

在处理结构，函数相关的语义分析时，经常会碰到对上层的结构体、函数，进行访问的过程，所以要对一些非终结符对应的函数进行重载，例如：

```c
void VarDec_struct(Node *now, Type *struct_, Type *ty);
Type* VarDec_func(Node* now, Type *ty);
```

#### 现场恢复

在发现了一个错误时，我们不能将一个这个分支直接扔下不管，这样的话会导致后续的错误多报甚至段错误（访问空指针），所以，我们在遇到需要返回指针的函数中遇到错误时，会返回一个default类型的type/func, 或者让后续分析能够正常运行的type/func。

这里举两个个例子：
在Exp的逻辑符号判断中，在发现操作数不是int类型时，我们在报错之后，必须返回一个int类型的type，也就是说我们就假设这一句正确，返回可能的正确类型：

```c
else if(AND_ != NULL || OR_ != NULL){
    Type *t1 = Exp(now->down);
    Type *t2 = Exp(now->down->next->next);
    if(!type_compare(int_example, t1) || !type_compare(int_example, t2))
        printf("Error type 7 at line %d: Logic operands only accepts int\n", now->pos);
    return int_example;
}
```

在不确定应该返回什么类型时，我们返回default_type/default_func来防止指针空访问：

```c
Type *t1 = Exp(now->down);
Type *t2 = Exp(now->down->next->next);
if((!type_compare(t1, t2)) || (type_compare(t1, t2) && !type_compare(t1, int_example) && !type_compare(t1, float_example))){
    printf("Error type 7 at line %d: Unmatched type or illeagal type for calculating\n", now->pos);
    return fault_type;
}
else return t1;
```





