>1、find 
```
// -type 指定文件类型
   find ./ -type 'l'(文件要使用f来访问)
// -name 指定文件名称
   find ./ -name '*.mp3'
// -maxdepth 指定文件路径深度(应该作为第一个参数出现)
   find -maxdepth 2 -name '*.jpg'
// -size 指定文件大小,单位：k、M、G
   find ./ -size +20M -size -50M
//-atime、-ctime、-mtime 天 -amin、-cmin、-mmin分钟
//将find操作的结果执行某一特定命令
   find /usr/ -name "*tmp" -exec ls -l  {} \;
//以交互式的信息显示
   find /usr/ -name "*tmp" -ok ls -l  {} \;
//-xargs：将find搜索的结果执行某一特定命令，当搜索结果过大时候分片映射(默认以空格作为分割方式)
   find /usr/ -name "*tmp" | xargs ls -l 
   find /usr/ -name "*tmp" -print0 | xargs -print0 ls -l //修改默认分割方式
```
>2、ps 显示正在与用户交互的进程

>3、软件安装
+   1、联网
+   2、更新软件资源列表到本地
```
 sudo apt-get update
```
+   3、安装
```
//  在线安装
    sudo apt-get install  软件名称
//  离线安装
    sudo dpkg -i 软件名称
```
+   4、源码安装
    + 1、解压缩源代码包
    + 2、cd dir
    + 3、./configure 检测文件是否缺失，创建makefile,检测编译环境
    + make 编译源码，生成库和可执行程序
    + sudo make install 将库和可执行程序，安装到系统路径下
    + sudo make distclean 删除和卸载软件
+   5、卸载
```
    sudo apt-get remove 软件名称
//  软件包卸载
    sudo dpkg -r xxx.deb
//  连同配置文件一起卸载
    sudo dpkg -r --purge xxx.deb
```
+   6.解压
```
//压缩
    tar -zcvf test.tar.gz file 使用gzip方法压缩
    tar -jcvf test.tar.gz file 使用bzip2方式压缩
//解压
    tar -zxvf test.tar.gz 使用gzip方式解压
    tar -jxvf test.tar.gz 使用bzip2方式解压
```

