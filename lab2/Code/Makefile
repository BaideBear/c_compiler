# TARGET = parser

# LEX_SRC = $(wildcard *.l)
# BISON_SRC = $(wildcard *.y)
# C_SRCS = syn_tree.c
# BISON_C = bison.tab.c
# LEX_C = lex.yy.c
# BISON_H = bison.tab.h

# CC = gcc
# FLEX = flex
# BISON = bison
# CFLAGS = -ll

# all: $(TARGET)

# $(TARGET): $(LEX_C) $(BISON_C) $(C_SRCS)
# 	$(CC) $(LEX_C) $(BISON_C) $(C_SRCS) $(CFLAGS) -o $(TARGET)

# $(LEX_C): $(LEX_SRC) $(BISON_H)
# 	$(FLEX) $(LEX_SRC)

# $(BISON_C) $(BISON_H): $(BISON_SRC)
# 	$(BISON) -d $(BISON_SRC)

# clean:
# 	rm -f $(TARGET) $(LEX_C) $(BISON_C) $(BISON_H)


#以下为课程要求的Makefile，因为oj测试要替换Makefile而妥协
#-----------------------------------------------------------------------

CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -std=c99

# 编译目标：src目录下的所有.c文件
CFILES = $(shell find ./ -name "*.c")
OBJS = $(CFILES:.c=.o)
LFILE = $(shell find ./ -name "*.l")
YFILE = $(shell find ./ -name "*.y")
LFC = $(shell find ./ -name "*.l" | sed s/[^/]*\\.l/lex.yy.c/)
YFC = $(shell find ./ -name "*.y" | sed s/[^/]*\\.y/syntax.tab.c/)
LFO = $(LFC:.c=.o)
YFO = $(YFC:.c=.o)

parser: syntax $(filter-out $(LFO),$(OBJS))
	$(CC) -o parser $(filter-out $(LFO),$(OBJS)) -lfl -ly

syntax: lexical syntax-c
	$(CC) -c $(YFC) -o $(YFO)

lexical: $(LFILE)
	$(FLEX) -o $(LFC) $(LFILE)

syntax-c: $(YFILE)
	$(BISON) -o $(YFC) -d -v $(YFILE)

-include $(patsubst %.o, %.d, $(OBJS))

.PHONY: clean test
test:
	./parser ../Test/ex4.cmm
clean:
	rm -f parser lex.yy.c syntax.tab.c syntax.tab.h syntax.output
	rm -f $(OBJS) $(OBJS:.o=.d)
	rm -f $(LFC) $(YFC) $(YFC:.c=.h)
	rm -f *~

