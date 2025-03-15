# 定义目标文件名
TARGET = run

# 定义源文件和生成文件
LEX_SRC = $(wildcard *.l)
BISON_SRC = $(wildcard *.y)
C_SRCS = syn_tree.c
BISON_C = bison.tab.c
LEX_C = lex.yy.c
BISON_H = bison.tab.h

# 定义编译器和编译选项
CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -ll

# 默认目标
all: $(TARGET)

# 目标文件的规则
$(TARGET): $(LEX_C) $(BISON_C) $(C_SRCS)
	$(CC) $(LEX_C) $(BISON_C) $(C_SRCS) $(CFLAGS) -o $(TARGET)

# 使用 Flex 生成 C 文件
$(LEX_C): $(LEX_SRC) $(BISON_H)
	$(FLEX) $(LEX_SRC)

# 使用 Bison 生成 C 和头文件
$(BISON_C) $(BISON_H): $(BISON_SRC)
	$(BISON) -d $(BISON_SRC)

# 清理生成的文件
clean:
	rm -f $(TARGET) $(LEX_C) $(BISON_C) $(BISON_H)
