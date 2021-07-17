Usage:
	hunt.bat image outdir

	image:	镜像文件全路径
	outdir:	输出目录全路径	

步骤：
（0）将sleuthkit工具包解压到特定目录
（1）在hunt.bat中将sleuthkit环境变量配置为步骤（0）中的路径下的bin子目录
（2）在hunt.conf文件中配置需要查找的文件或者目录
（3）运行脚本后将查找到的配置文件存放到out目录下

说明：
（0）out目录下的文件名采用id命名，如：81481-128-1
（1）tmp目录用于存放抽取过程中的临时文件，方便定位问题
（2）如果需要查看id对应的具体文件名，可以在tmp目录中的fls.tmp中找到