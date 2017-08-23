#include "stdio.h"
#include <tr1/memory>
#include <string>
#include <vector>

using namespace std;

class Base
{
public:
    Base(int value = 0):_value(value)
    {
        printf("Base, value=%d\n", _value);
    }

    virtual void print()
    {
        printf("Base print, value=%d\n", _value);
    }

    ~Base()
    {
        printf("~Base, value=%d\n", _value);
    }

    int _value;
};

class Child: public Base
{
public:
    Child(int value = 0):Base(value)
    {
        printf("Child, value=%d\n", _value);
    }

    ~Child()
    {
        printf("~Child, value=%d\n", _value);
    }

    void print()
    {
        printf("Child print, value=%d\n", _value);
    }
};

tr1::shared_ptr<Base> genBase()
{
    tr1::shared_ptr<Base> sp(new Base());
    return sp;
}

tr1::shared_ptr<Base> genChild()
{
    tr1::shared_ptr<Base> sp(new Child());
    return sp;
}

// 可以往智能指针中存放值为null的指针
void test_null()
{
    printf("--------------- %s -------------\n", __FUNCTION__);
    int *p = NULL;
    tr1::shared_ptr<int> sp(p);
    if(sp) {
        printf("sp not empty\n");
    }
    else {
        printf("sp is empty\n");\
    }
    
    //tr1::shared_ptr<int> sp2(NULL); // 这样会导致编译出错
}

// 简单数据类型
void test_simpletype()
{
    printf("--------------- %s -------------\n", __FUNCTION__);
    tr1::shared_ptr<int> sp(new int);
    *sp = 10;
    printf("*sp=%d\n", *sp);
}

void test_getstoredptr() 
{
    printf("--------------- %s -------------\n", __FUNCTION__);

    tr1::shared_ptr<int> sp(new int);
    *sp = 10;
    printf("*sp=%d\n", *sp);
    int *p = sp.get();   
    printf("*sp=%d\n", *p);
}

void test_object()
{
    printf("--------------- %s -------------\n", __FUNCTION__);
    tr1::shared_ptr<Base> sp(new Base(1));
    sp->print();

    sp.reset(new Base(2)); // will delete old base object 
    sp->print();
}

void test_stl()
{
    printf("--------------- %s -------------\n", __FUNCTION__);
    std::vector<tr1::shared_ptr<Base> > v;
    tr1::shared_ptr<Base> sp1(new Base(1));
    v.push_back(sp1);

    tr1::shared_ptr<Base> sp2(new Child(2));
    v.push_back(sp2);
    for(size_t i = 0; i < v.size(); i++)
    {
        v[i]->print();
    }
}

void test_reset()
{
    printf("--------------- %s -------------\n", __FUNCTION__);
    tr1::shared_ptr<Base> sp(new Base(1));
    if(sp)
        sp->print();
    else
        printf("sp is empty\n");

    sp.reset();
    if(sp)
        sp->print();
    else
        printf("sp is empty\n");

    sp.reset(new Base(2));
    if(sp)
        sp->print();
    else
        printf("sp is empty\n");
}

// 不要构造一个临时的shared_ptr作为函数的参数,这样可能会造成内存泄漏
void fun_arg_is_shared_ptr(tr1::shared_ptr<Base> sp)
{
    sp->print();
}
void test_tmp_shared_ptr()
{
    printf("--------------- %s -------------\n", __FUNCTION__);
    tr1::shared_ptr<Base> sp1(new Base(1));
    tr1::shared_ptr<Base> sp2 = tr1::shared_ptr<Base>(new Base(2));
    fun_arg_is_shared_ptr(tr1::shared_ptr<Base>(new Base(3)));
}

// 多次引用同一数据会导致 重复释放
void test_multi_shared_ptr_ref_to_one_object()
{
   printf("--------------- %s -------------\n", __FUNCTION__);
   Base* p = new Base(1);
   tr1::shared_ptr<Base> sp1(p);
   //tr1::shared_ptr<Base> sp2(p);  // will double free
}

void test_cycles_ref()
{
   printf("--------------- %s -------------\n", __FUNCTION__);
   
}

void test_multi_thread()
{
  printf("--------------- %s -------------\n", __FUNCTION__);
}

int main()
{
    test_null();
    test_getstoredptr();
    test_simpletype();
    test_object();
    test_stl();
    test_reset();
    test_tmp_shared_ptr();
    test_multi_shared_ptr_ref_to_one_object();
    test_cycles_ref();
    test_multi_thread();
    return 0;
}
