# コンパイラ
CC  = gcc

# 実行ファイル名
TARGET  = ./bin/atelier

# コンパイルオプション
CFLAGS    = -g -Wall

# インクルードファイル
INCLUDE  = -I./

# ライブラリファイルのディレクトリ
LIBDIR  =

# ライブラリファイル
LIBS    = -lsqlite3

# ソースファイルのディレクトリ
SRCDIR    = ./src

# コンパイル対象
SRCS    = $(wildcard $(SRCDIR)/*.c)

# オブジェクトファイルの出力先
OBJDIR = ./obj

# オブジェクトファイル名
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

# 実行ファイル作成
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

# オブジェクトファイル
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
