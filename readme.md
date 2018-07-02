# AirCraft

### 介绍

这是我早年刚入门 C 时候写的一个小游戏。记得我是看翁恺老师的C语言课入的门，感谢翁恺老师，让我觉得编程特别有意思。而且翁恺老师在课程中介绍了浙大了一个windows开发框架ACLLIB，让我这种一开始对界面程序特别好奇的人能够写一些简单的windows图形界面程序，而不用去学习那些复杂的windows API，MFC等等。

### 游戏截图

![1530526077843](C:\Users\pzq\Desktop\cpp\aircraft-new\data\screen1.png)

![1530526102780](C:\Users\pzq\Desktop\cpp\aircraft-new\data\screen2.png)

### 说明

资源文件在`data`目录下，如果想直接体验游戏内容，可以直接运行`aircraft.exe`。

如果想查看源码，建议下载DEVCPP，可以直接打开`AirCraft.dev`项目文件。

整个游戏用C语言编程，`main.c`是主函数，`aircraft.h`是库函数，总共300行左右。

其中用到acllib框架，框架就在主目录下，包括两个文件：`acllib.h`，`acllib.c`，框架由浙江大学开发。

### 框架使用方法

需要在链接选项中加入如下路径，注意把路径修改为DEVCPP的安装路径。

/*
For Dev C++, these lib files need to be added into linker options.
Be sure to change the leading folders as your installation.
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libwinmm.a"
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libmsimg32.a"
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libkernel32.a"
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libuser32.a"
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libgdi32.a"
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libole32.a"
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/liboleaut32.a"
"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libuuid.a"
*/

# AirCraft
