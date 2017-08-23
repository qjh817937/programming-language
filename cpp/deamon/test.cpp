#include<iostream>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

void sig_child(int signo)
{
    pid_t pid;
    while((pid=waitpid(-1,NULL,WNOHANG)>0))
    {
        cout<<"child " << pid << "exit" << endl;
        sleep(1);
    }
}

int main()
{
    pid_t pid;

    signal(SIGCHLD,sig_child);
    
    for(int i=0;i<3;i++)
    {
        pid=fork();
        if(pid==0)
        {
            cout<<"in child process "<< getpid() << endl;
            sleep(2);
            return 0;
        }
        else if(pid>0)
        {
            cout<<"in parent process , fork pid is " << pid << endl;
            continue;
        }
        else
        {
            cout<<"fork failed"<< endl;
        }
    }


    while(1)
    {
        cout<<"parenet process sleep"<<endl;
        sleep(1);

    }
    
    return 0;
}
