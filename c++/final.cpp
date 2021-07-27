#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>
#include <crtdbg.h>   
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream>
using namespace std; 
struct LinkList //����һ�������Դ��������ڴ� 
{
    void * pLL;  
    int Size; //й©�Ĵ�С 
    char File[256]; //�ڴ�й©���ļ� 
    int Line; //�����ļ����� 
    LinkList * pNext; //ָ����һ���ڵ� 
};

class LLManager //������ 
{
private:
    LinkList *LinkListHead; 
public:
    LLManager(); //���캯�� 
    ~LLManager(); //�������� 
    static bool Ready; 
public:
    static LLManager* GetInstance(); //ȡʵ�� 
    void Add(LinkList *pLinkList); //����ڵ� 
    void Remove(void *ptr); //ɾ���ڵ� 
    void Dump(); //����ڴ�й©��Ϣ���ͷ� 
};

bool LLManager::Ready = false;  

LLManager::LLManager()//���캯�� 
{
    LinkListHead=NULL; //��ʼ�� 
    Ready = true;  
}

LLManager::~LLManager()//�������� 
{
	Ready = false;  
	Dump(); //����ʱ�Զ�ִ��Dump()
}

void LLManager::Add(LinkList *p)//����ڵ���� 
{
    p->pNext=LinkListHead; 
    LinkListHead = p; 
}

void LLManager::Remove(void *ptr)//ɾ���ڵ���� 
{
    LinkList * p1 = LinkListHead;
    LinkList * p2 = NULL;
    while(p1)//Ѱ��ptr�����ͷ���ָ����ڴ� 
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

void LLManager::Dump()//����ڴ�й©��Ϣ���ͷ� 
{
    LinkList * pp = LinkListHead;
    printf("��new����Ķ�̬�ڴ���δ��delete���ͷţ�\n");
    while(pp)//�������� 
    {
        printf( "File is %s\n", pp->File );//��������ļ��� 
        printf( "Size is %d\n", pp->Size );//���й¶��С 
        printf( "Line is %d\n", pp->Line );//��������ڴ�й©������ 
        printf("���ͷ�\n");
        pp = pp->pNext;
    }
}
 
void PutEntry(void *ptr,int size,const char*FFile, int LLine)//��ptr���������� 
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

void RemoveEntry(void *ptr)//��ptr��������ɾ�� 
{
    LLManager::GetInstance()->Remove(ptr);
}


void *operator new(size_t size,const char*FFile, int LLine)//����new 
{
    void * ptr = malloc(size);
    if (LLManager::Ready)  			PutEntry(ptr,size,FFile,LLine);
    return ptr;
}

void operator delete(void *ptr)//����delete
{
    if (LLManager::Ready)  RemoveEntry(ptr);
    free(ptr);
}

void*operator new[] (size_t size,const char* FFile,int LLine)//����new []
{
    void * ptr = malloc(size);
    if (LLManager::Ready)  PutEntry(ptr,size,FFile,LLine);
    return ptr;
}
 
void operator delete[](void *ptr)//����delete[] 
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
{//������ 
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
