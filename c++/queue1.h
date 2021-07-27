#include<iostream>
#include<cstdlib>
using namespace std;

class customer
{
    private:
        long arrive;
        int processtime;
    public:
        customer() {arrive=processtime=0;}
        void set(long a);//只读入进入时间即可
        long when()
        {
            return arrive;
        }                                                    
        int ptime(){return processtime;}    //
};

typedef customer Item;

class queue
{
    private:
        struct Node{Item item;struct Node * next;};//在内里面创建结构体  结构体的作用范围就是该类
        enum{Q_SIZE=10};

        Node * front;  //两个结构体指针
        Node * rear;  //中间指针
        int items;//计数
        const int qsize; //队列的最大值不变
        queue(const queue & q):qsize(0){};
        queue & operator=(const queue & q){return * this;}

    public:
        queue(int qs=Q_SIZE);
        ~queue();
        bool isempty() const ; 
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item & item);//入队指令
        bool dequeue(Item & item);//出队指令
};

queue::queue(int qs):qsize(qs)
{
    front=rear=NULL;
    items=0;
}

queue::~queue()
{
    Node*temp; //创建成员
    while(front!=NULL)
    {
        temp=front;
        front=front->next;//指向下一个成员
        delete temp; //删除一个对象
    }
}

bool queue::isempty() const
{
   return items==0; //检查是否为空
}

bool queue::isfull() const
{
    return items==qsize; //检查是否满了
}

int queue::queuecount() const
{
    return items;
}

bool queue::enqueue(const Item & item) //增加变量
{
    if(isfull())
    return false;  //如果说已经满了

    Node *add=new Node;//
    add->item=item;     
    add->next=NULL; 
    items++;  
    if(front==NULL)
        front=add;
    else
        rear->next=add;
    rear=add;//更新rear的位置
    return true; 
}

//队列的结构是先进先出
bool queue::dequeue(Item & item)
{
    if(front==NULL) 
        return false;
    item=front->item; 
    items--;
    Node * temp=front; //将队列的第一个元素清除
    front=front->next;
    delete temp;   //释放内存
    if(items==0)
        rear=NULL;
    return true;
}

void customer::set(long when)
{
    processtime=rand()%3+1;
    arrive=when;
}