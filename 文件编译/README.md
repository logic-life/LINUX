# makefile
## makefile中的函数
```
    //查找所有符合PATTERN模式的文件
    //$(wildcard PATTERN)
    //返回当前目录中拓展名为.c的文件列表
    $(wildcard *.c)

    //将text中的pattern转换为replacement
    //$(patsubst pattern,replacement,text)
    //将add.c字符串转换为add.o
    $(patsubst %.c,%.o,add.c)
    //将当前文件夹中的所有.c文件转化为.o文件输出
    $(patsubst %.c,%.o,$(wildcard *.c))

    //遍历LIST,传进VAR，最后执行TEXT
    //$(foreach VAR,LIST,TEXT)
    //将LIST中的字符串依次传到VAR中，然后执行TEXT表达式，返回TEXT执行的结果
    //遍历文件夹中的.c文件
    DIRS= sub add ./
    FILES=$(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))

    //配合使用
    DIRS= sub add ./
    FILES=$(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
    OBJS=$(patsubst %.c,%.o,$(FILES))


```

[父文件调用](./makefile/makefile)

[递归调用(父文件)](./recursive_makefile/makefile)
[递归调用(子文件)](./recursive_makefile/add/makefile)
[递归调用(子文件)](./recursive_makefile/sub/makefile)