#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>
#include <crtdbg.h>   
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream>
using namespace std; 
struct LinkList //制作一个链表，以储存分配的内存 
{
    void * pLL;  
    int Size; //泄漏的大小 
    char File[256]; //内存泄漏的文件 
    int Line; //所在文件行数 
    LinkList * pNext; //指向下一个节点 
};

class LLManager //管理类 
{
private:
    LinkList *LinkListHead; 
public:
    LLManager(); //构造函数 
    ~LLManager(); //析构函数 
    static bool Ready; 
public:
    static LLManager* GetInstance(); //取实例 
    void Add(LinkList *pLinkList); //插入节点 
    void Remove(void *ptr); //删除节点 
    void Dump(); //输出内存泄漏信息并释放 
};

bool LLManager::Ready = false;  

LLManager::LLManager()//构造函数 
{
    LinkListHead=NULL; //初始化 
    Ready = true;  
}

LLManager::~LLManager()//析构函数 
{
	Ready = false;  
	Dump(); //析构时自动执行Dump()
}

void LLManager::Add(LinkList *p)//插入节点操作 
{
    p->pNext=LinkListHead; 
    LinkListHead = p; 
}

void LLManager::Remove(void *ptr)//删除节点操作 
{
    LinkList * p1 = LinkListHead;
    LinkList * p2 = NULL;
    while(p1)//寻找ptr，并释放其指向的内存 
    {
        if(p1->pLL ==ptr)  
        {
           if(p2)
            {
               p2->pNext =p1->pNext;
            }
           else
            {
               LinkListHead = p1->pNext;  
            }
           free(p1);
           break;
        }
        p2 = p1;
        p1 = p1->pNext;
    }
 
}

void LLManager::Dump()//输出内存泄漏信息并释放 
{
    LinkList * pp = LinkListHead;
    printf("由new分配的动态内存且未被delete所释放：\n");
    while(pp)//遍历链表 
    {
        printf( "File is %s\n", pp->File );//输出所处文件名 
        printf( "Size is %d\n", pp->Size );//输出泄露大小 
        printf( "Line is %d\n", pp->Line );//输出发生内存泄漏的行数 
        printf("已释放\n");
        pp = pp->pNext;
    }
}
 
void PutEntry(void *ptr,int size,const char*FFile, int LLine)//将ptr插入链表中 
{
    LinkList * p = (LinkList *)(malloc(sizeof(LinkList)));
    if(p)
    {
        strcpy(p->File,FFile);
        p->Line = LLine;
        p->pLL = ptr;
        p->Size = size;
        LLManager::GetInstance()->Add(p);
    }
}

void RemoveEntry(void *ptr)//将ptr从链表中删除 
{
    LLManager::GetInstance()->Remove(ptr);
}


void *operator new(size_t size,const char*FFile, int LLine)//重载new 
{
    void * ptr = malloc(size);
    if (LLManager::Ready)  			PutEntry(ptr,size,FFile,LLine);
    return ptr;
}

void operator delete(void *ptr)//重载delete
{
    if (LLManager::Ready)  RemoveEntry(ptr);
    free(ptr);
}

void*operator new[] (size_t size,const char* FFile,int LLine)//重载new []
{
    void * ptr = malloc(size);
    if (LLManager::Ready)  PutEntry(ptr,size,FFile,LLine);
    return ptr;
}
 
void operator delete[](void *ptr)//重载delete[] 
{
    if (LLManager::Ready)  RemoveEntry(ptr);
    free(ptr);
}
 
#define new new(__FILE__,__LINE__)
LLManager Tracer;
 
LLManager* LLManager::GetInstance()
{
    return &Tracer;
}

class Text
{//测试类 
	public:
		void Array1(){
			int * a = new int(100);
			
		}
		void Array2() {
	        int* b = new int[105];
	      
	    }
	    void Array3(){
	    	int * c = new int[90];
	    	delete []c;
		}
};

int main()
{
	Text T1;
	T1.Array1();
	T1.Array2();
	T1.Array3();
	//_CrtDumpMemoryLeaks();
    return 0;
}
