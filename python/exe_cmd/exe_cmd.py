#!/usr/bin/python
#coding=utf-8
import os;
import commands;
import subprocess;

# os.system 在一个子shell执行命令,能得到返回值，但得不到命令的输出结果
#   返回值:On Unix, the return value is the exit status of the process encoded in the format specified for wait()
#        wait(): return is a 16-bit number, whose low byte is the signal number that killed the process, and whose high byte is the exit status (if the signal number is zero); the high bit of the low byte is set if a core file was produced.
def os_system_test():
    ret = os.system("ls")
    print "ret=", ret
    
    ret = os.system("ls /root")
    print "ret=", ret

    ret = os.system("exit 3")
    print "ret=", ret

# os.popen() 返回的是 file read 的对象，对其进行读取 read() 的操作可以看到执行的输出
def os_popen_test():
    fileobj = os.popen("ls")
    print 

# commands.getstatusoutput 执行命令，并获取返回值(返回值函意和os.system一样)和输出
def commands_getstatusoutput_test():
    print "----commands_getstatusoutput_test----"
    ret = commands.getstatusoutput("ls");
    print "ret=", ret

    ret = commands.getstatusoutput("ls /root");
    print "ret=", ret
    
    ret = commands.getstatusoutput("exit 3");
    print "ret=", ret

# subprocess
# 从python2.4版本开始，你就可以用可以用subprocess这个模块来产生子进程，并连接到子进程的标准输入 /输出/错误中去，还可以得到子进程的返回值。subprocess意在替代其他几个老的模块或者函数，比如：
# os.system
# os.spawn*
# os.popen*
# popen2.*
# commands.*
def subprocess_popen_test():
    print "----subprocess_popen_test----"
    cmd = "ls"
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,close_fds=True)
    stdout=ret.stdout.readlines()
    stdout=''.join(stdout)
    print "ret=", stdout
    
    cmd = "ls /*"
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,close_fds=True)
    print "ret=", ret
    
    cmd = "exit 3"
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,close_fds=True)
    print "ret=", ret

## Popen.wait()
## Wait for child process to terminate. Set and return returncode attribute.
##      Warning This will deadlock when using stdout=PIPE and/or stderr=PIPE and the child process generates enough output to a pipe such that it blocks waiting for the OS pipe buffer to accept more data. Use communicate() to avoid that.

def subprocess_popen_output_test():
    print "----subprocess_popen_output_test----"
    cmd = "ls /root"
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,close_fds=True)
    ret.wait()
    stdout=ret.stdout.readlines()
    stderr=ret.stderr.readlines()
    print "retcode=",ret.returncode, "stdout=", ''.join(stdout),"stderr=", stderr 
    
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,close_fds=True)
    stdout=ret.stdout.readlines()
    #stderr=ret.stderr.readlines()  ## 出错
    print "stdout=", stdout
    
    ret = subprocess.Popen(cmd,shell=True,stderr=subprocess.PIPE,close_fds=True)
    #stdout=ret.stdout.readlines()  ## 出错
    stderr=ret.stderr.readlines()
    print "stderr=", stderr 

def subprocess_popen_output_bufsize_test():
    print "----subprocess_popen_output_bufsize_test----"
    cmd = "cat smalldata"
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,close_fds=True)
    ret.wait()
    stdout=ret.stdout.readlines()
    stderr=ret.stderr.readlines()
    print "retcode=",ret.returncode, "stdout=", ''.join(stdout),"stderr=", stderr 
    print ""

    cmd = "cat bigdata"
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,close_fds=True)
    (stdout, stderr) = ret.communicate()
    ret.wait()
    print "retcode=",ret.returncode, "stdout=", ''.join(stdout),"stderr=", stderr 
    
    cmd = "cat noexistdata"
    ret = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,close_fds=True)
    (stdout, stderr) = ret.communicate()
    ret.wait()
    print "retcode=",ret.returncode, "stdout=", ''.join(stdout),"stderr=", stderr 

if __name__ == '__main__':
    #os_system_test()
    #commands_getstatusoutput_test()
    #subprocess_popen_test()
    #subprocess_popen_output_test()
    subprocess_popen_output_bufsize_test()
