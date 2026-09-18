CC = gcc
# CFLAGS: 编译选项，-Wall 开启所有常见警告，-Wextra 开启额外警告，-std=c11 指定 C11 标准
CFLAGS = -Wall -Wextra -std=c11
TARGET1 = copy
TARGET2 = read_time
TARGETS = $(TARGET1) $(TARGET2)

all: $(TARGETS)

$(TARGETS): %: %.c ../error.c
	$(CC) $(CFLAGS) -o $@ $^
# $@: 规则的目标文件名，这里是 xxx
# $^: 规则的所有依赖文件列表，这里是 xxx.c ../error.c

run: $(TARGETS)
	./$(TARGET1)
	./$(TARGET2)

run1: $(TARGET1)
	./$(TARGET1)

run2: $(TARGET2)
	./$(TARGET2)

clean:
	# -f: 强制删除，不报错即使文件不存在
	rm -f $(TARGETS)
