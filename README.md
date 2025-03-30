# CSAPP

阅读CSAPP的笔记。

### CONTENT
- [0. 读前准备](#0-读前准备)
- [1. 计算机系统漫游](#1-计算机系统漫游)
- [3. stack栈](#3-stack栈)
- [4. linked_list链表](#4-linked_list链表)
- [5. dp](#5-dp)
- [6. binary_search二分查找](#6-binary_search二分查找)
- [7. 离线算法](#7-离线算法)
- [8. heap堆](#8-heap堆)
- [9. backtracking回溯](#9-backtracking回溯)
- [10. trivial](#10-trivial)

### 0. 读前准备

其实在此之前（读前之前）已经接触到了Linux相关的命令行操作了（如使用GitBash来从本地将更新的代码`push`到远端；或者用picgo把本地图片上传到远端，再用`pull`指令拉到本地文件夹）。
之后看到网上说vim是编辑器之神（这里网上包括知乎、csdn、南大的ICS课程的课前准备），便去详细了解了一下vim的使用，并对其进行了外观的配置，变得更加好看了。
说一下我对vim的感受：无gui的按钮操作，全部都是键盘按键完成（当然这是在关闭鼠标操作设置的前提下，不过我发现即使开启了鼠标的操作功能，在root下开启vim会使用最最最原始的配置），
而且这个编辑器既然是存在于Linux系统中的，于是可以编写各种代码如python、cpp，并随时保存和在命令行中（编译和）运行，实际上与windows系统中的pycharm或者vscode功能是差不多的。

总结来看，我对vim目前的用途也就仅仅限于：找到根目录，`cd`到`/mnt`中，去`/d`盘编辑我的本地代码（实际上和用pycharm的效果是一样的）。最大的好处是：可以同时编辑py文件和cpp文件（虽然和vscode是一样的）。
但是配置完成后真的很酷啊！效果图如下：
![my_vim_after_setting.png](imgs%2Fmy_vim_after_setting.png)
![my_vim_after_setting2.png](imgs%2Fmy_vim_after_setting2.png)

这里附上我配置vim参考的链接教程：`https://blog.csdn.net/qq_42417071/article/details/139027077` 。

对vim的配置主要是对vimrc的内容进行修改，第一步是先对其复制得到一个拷贝，粘贴到~下，重命名为.vimrc，每次访问的命令就是：`ink@gale:~$ vim .vimrc`。我把配置文件内容都放在了这个repo的vimrc文件夹[我的 Vim 配置](vimrc/myconfig.vim)中，可以用来参考。
（尽量实现了类似于vscode编辑代码时的自动功能，但仍有一些不完善的地方，..也懒得改了主要是我自己不太会写shell脚本，需要靠互联网和gpt和deepseek三者辅助修改，比较麻烦吧）

此外，在vim中下载了tmux的包，这样可以在一个窗口中建立多个pane，如在左侧写py代码，在右侧随时执行这个文件，实现和pycharm类似的功能（我的配置中设置了`\1`作为热键在完成操作：
保存当前代码文件`:w`->向右侧pane中发送指令`python3 %`->将光标移到右侧pane中（这样方便输入测试数据））

### 1. 计算机系统漫游
