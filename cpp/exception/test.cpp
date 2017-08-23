#include <iostream>  

using namespace std;  

class demo {  
};  

double div1(int a, int b) {  
    if(b == 0)  throw demo();         
    return    a/b;  
}  

double div2(int a, int b) throw() {  
    if(b == 0)  throw demo();         
    return    a/b;  
}  

double div3(int a, int b) throw(int) { //异常说明，表示函数divd会抛出类型为int的异常  
    if(b == 0)  throw demo();         //抛出类型为demo的异常  

    return    a/b;  
}  

int main() {  
    try  
    {  
        div1(1,0);  
    }  
    catch(demo)                       //捕获异常类型demo  
    {  
        cout << "div1 divided by zero " << endl;  
    }  
    catch(int)                        //捕获异常类型int  
    {  
        cout<<"zero"<<endl;  
    }  

    try  
    {  
        div2(1,0);  
    } 
    catch(demo)                       //捕获异常类型demo  
    {  
        cout << "div2 divided by zero " << endl;  
    }  
    catch(int)                        //捕获异常类型int  
    {  
        cout<<"zero"<<endl;  
    }  

    return 0;  
}  
