目录：
	1、GDB 断点调试
	2、Segmentation fault (core dumped) 错误时，采用gdb定位问题的点	
	3、常用的gdb 命令
	4、多线程调试
	
正文：
1、GDB 断点调试
   1）、开启 gdb 调试 common_demo 程序
	gdb ./common_demo

   2）、设置args 的传入参数（demo 传入参数）
	set args              #可指定运行时参数。(gdb) set args xxx
	show args             #查看运行时参数。

   3）、设置断点、并显示断点
	b <lines>             #b: Breakpoint的简写，设置断点。(gdb) b 10
	b <func>              #b: Breakpoint的简写，设置断点。(gdb) b main
	b filename:[line/function]  #b:在文件filename的某行或某个函数处设置断点。例如：b xxx.cpp:lines_num  
	b xxx if xxx	 # 设置条件断点、当程序满足条件时才会触发断点
	i breakpoints         #i: info 的简写。(gdb)i breakpoints
	disable + 断点的数值标识符，disable 1：禁用第1个断点；

	tbreak xxx		# 设置临时断点，断点触发后自动删除
	clear 		# 删除当前行所有断点
	clear func 	# 删除func 处的断点
	clear file:func 	# 删除file文件中func出的断点
	clear line 	# 删除行号断点
	clear file:line 	# 删除file 文件中行号为line 的断点
	delete 		# 删除所有断点
