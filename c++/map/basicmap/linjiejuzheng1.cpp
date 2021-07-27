#include<iostream>
#include<vector> //vector版本的邻接矩阵
using namespace std;

typedef int T;
struct node
{
    T value;
    int numbers; //顶点的值和编号
};

struct Edge
{
    int num1; 
    int num2;
    int weight; //起始顶点，终止顶点，以及边所对应的权值
};

class Graph
{
    private:
        int  vertex_nums;
        int  edge_nums;
        vector<node> vertex;
        vector<Edge> edge; //顶点表和边表
        vector<vector<int>>edge_maze;
    public:
        Graph(int n1=10,int n2=10) //先默认输入的边数
        {
            vertex_nums=n1;
            edge_nums=n2;
            for(int i=0;i<vertex_nums;i++)
            {
                node a;
                a.numbers=i;
                a.value=0;
                vertex.push_back(a); //初始化边表
            }

            for(int i=0;i<vertex_nums;i++)
            {
                vector<int>temp(vertex_nums,0); // 定义了nums个元素，而且每个元素的值都为0
                edge_maze.push_back(temp); //利用vector初始化了一个矩阵 也可以理解是二维矩阵
            }

 cout<<"please input the edges about the graph: vertex_number1 vertex_number2 weight"<<endl;
        int x,y,z;
        for(int i=0;i<edge_nums;i++)
        {
            cin>>x>>y>>z; //起始点，终点，边权值
            Edge temp_edge; //建立一条边
            temp_edge.num1=x;
            temp_edge.num2=y;
            temp_edge.weight=z;
            edge.push_back(temp_edge);
            edge_maze[x][y]=1;
            edge_maze[y][x]=1;
        }
}

void print_edge_maze()
{
    cout<<endl;
    cout<<"输出邻接矩阵"<<endl;
    cout<<" ";
    for(int i=0;i<vertex_nums;i++)
    {
        cout<<"v"<<i<<" ";
    }
    cout<<endl;

    for(int i=0;i<vertex_nums;i++)
    {
        cout<<"v"<<i<<" ";
        for(int j=0;j<vertex_nums;j++)
        {
            cout<<edge_maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_edge_vec()
    {
        cout<<endl;
        cout<<"输出边表："<<endl;
        cout<<"起始顶点-->结束顶点  边权值"<<endl;
        for(int i=0;i<edge_nums;i++)
        {
            cout<<"   v"<<edge[i].num1<<"   -->"<<"   v"<<edge[i].num2<<"        "<<edge[i].weight<<endl;
        }
    }

};

int main()
{
    Graph graph(8,10);
    graph.print_edge_vec();
    graph.print_edge_maze();
    return 0;
}


