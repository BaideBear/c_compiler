TARGET = run

LEX_SRC = $(wildcard *.l)
BISON_SRC = $(wildcard *.y)
C_SRCS = syn_tree.c
BISON_C = bison.tab.c
LEX_C = lex.yy.c
BISON_H = bison.tab.h

CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -ll

all: $(TARGET)

$(TARGET): $(LEX_C) $(BISON_C) $(C_SRCS)
	$(CC) $(LEX_C) $(BISON_C) $(C_SRCS) $(CFLAGS) -o $(TARGET)

$(LEX_C): $(LEX_SRC) $(BISON_H)
	$(FLEX) $(LEX_SRC)

$(BISON_C) $(BISON_H): $(BISON_SRC)
	$(BISON) -d $(BISON_SRC)

clean:
	rm -f $(TARGET) $(LEX_C) $(BISON_C) $(BISON_H)
