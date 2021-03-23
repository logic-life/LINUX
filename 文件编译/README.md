# makefile
**make命令读取makefile文件，确定重建目标文件所需的最少命令，并以正确的顺序执行它们**
## 宏
**makefile允许使用宏,使用宏命令可以实现不同系统下的更改**
```
DIRS = add sub 
//引用宏的方式是$(DIRS)或者${DIRS}
```
## 自动变量
**$?**: 当前目标中最新的文件
**$@**: 当前文件的名称
**$<**: 依赖项文件中第一个文件
**$***: 目标文件的名称，不包含目标文件的拓展名
**@**:  执行命令时，不显示在标准输出
**-**:  忽视任何错误
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
## 伪目标
**-PHONY: clean main #伪目标，防止文件夹中的同名文件干扰指令执行**

## shell可执行程序命令搜索路径
```
//查看所有路径
echo $PATH
//只对当前shell窗口有效
export PATH=$PATH:/new path
//对所有窗口有效
//修改当前窗口的.bash_profile文件，在PATH=$PATH...后添加
:/new path
//保存退出后，需要在当前窗口执行
..bash_profile //更新配置
```


## 静态库
**创建指令**
```
gcc -g -c -fpic string.c -o string.o
ar -rcs libstr.a string.o
gcc -g -W -fpic test.c -o test -L./ -lstr 
```
**makefile:** [静态库](./staticlib/makefile)

## 动态库
```
gcc -g -c -fpic string.c -o string.o
gcc -g -shared string.o -o libstr.so 

//使用动态库前需要添加搜索路径
按照优先级搜索顺序：

1、在编译目标代码时指定该程序的动态库搜索路径（还可以在编译目标代码时指定程序的动态库搜索路径。 这是通过gcc 的参数"-Wl,-rpath,"指定,当指定多个动态库搜索路径时，路径之间用冒号"："分隔）(已验证)
#gcc test.c -o main -L./ -ltest -Wl,-rpath=/root/lib 

2、通过环境变量LD_LIBRARY_PATH指定动态库搜索路径（当通过该环境变量指定多个动态库搜索路径时，路径之间用冒号"："分隔）(已验证)
#export LD_LIBRARY_PATH=/example/ex02: /...

3、在配置文件/etc/ld.so.conf中指定动态库搜索路径（需要添加其它库文件的路径，在文件的最后添加具体的路径即可 [ 如：/usr/local/lib ]，添加后保存退出，然后在命令行ldconfig

4、默认的动态库搜索路径/lib

5、默认的动态库搜索路径/usr/lib

```
**makefile:**   [动态库](./dynamiclib/makefile)

[父文件调用](./makefile/makefile)
[递归调用(父文件)](./recursive_makefile/makefile)
[递归调用(子文件)](./recursive_makefile/add/makefile)
[递归调用(子文件)](./recursive_makefile/sub/makefile)
[makefile模板](./test/makefile)
