CC = gcc
# CFLAGS: 编译选项，-Wall 开启所有常见警告，-Wextra 开启额外警告，-std=c11 指定 C11 标准
CFLAGS = -Wall -Wextra -std=c11

all: ls

ls: ls.c ../error.c
	$(CC) $(CFLAGS) -o $@ $^
# $@: 规则的目标文件名，这里是 ls
# $^: 规则的所有依赖文件列表，这里是 ls.c ../error.c

run: ls
	./ls /dev

clean:
	# -f: 强制删除，不报错即使文件不存在
	rm -f ls
