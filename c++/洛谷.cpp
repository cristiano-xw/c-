#include<bits/stdc++.h>  
using   namespace   std;
const int Max = 30;		//学号和字符串的大小
//函数的声明
class Student;
/*void setData(Student &s);
void count(Student &s);
void sort(Student S[], int N);
double getAverage(Student S[], int N);
void print(Student &s);
int search(Student S[], int N, char *n);*/

class Student
{
public:	
	char number[Max];	//学号
	char name[Max];		//姓名
	double chinese;		//语文
	double math;		//数学
	double english;		//英语
	double total;		//总分
	double average;		//平均分
	int rank;			//排名
};

//主函数部分
int main()
{
	const int M = 3;	//定义常量，假设为3位同学
	Student S[M];		//创建对象数组
	for (int i = 0; i < M; i++)
	{
		cout << "输入下面第" << i + 1 << "位同学的数据：" << endl;
		setData(S[i]);		//调用数据输入函数
		count(S[i]);
		cout << endl;
	}
	sort(S, M);
	int order = 1;
	
	while (order != 4)
	{
		cout << "****************************命令菜单****************************" << endl;
		cout << "1.查询所有排名" << endl;
		cout << "2.查询成绩在全班平均分以上的学生名单和信息" << endl;
		cout << "3,任意输入一个学号，查找该学生的排名和考试成绩" << endl;
		cout << "4.退出系统" << endl;
		cout << "****************************************************************" << endl;
		cout << "请输入命令：";
		cin >> order;
		switch (order)
		{
		case 1:
		{
			for (int j = 0; j < M; j++)
				print(S[j]);	//输出对象数组
		}
		break;
		case 2:
		{
			double compare = getAverage(S, M);		//获取平均分，之后将大于平均分的同学输出
			for (int k = 0; k < M; k++)
				if (S[k].average > compare)
					print(S[k]);
		}
		break;
		case 3:
		{
			char code[Max];
			cout << "输入您要查找的学号：";
			cin >> code;
			int result = search(S, M, code);
			if (result == -1)
				cout << "您输入的学号不存在！" << endl;
			else
				print(S[result]);
		}
		break;
		case 4:
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
		}
	}
}

//功能函数部分
void setData(Student &s)
{
	cout << "输入学号，姓名，语文，数学，英语成绩：";
	cin >> s.number >> s.name >> s.chinese >> s.math >> s.english;		//分别将输入的数据赋给类的成员
	//成员的初始化
	s.total = 0;
	s.average = 0;
	s.rank = 0;
}

void count(Student &s)
{
	s.total = s.chinese + s.math + s.english;		//求总分
	s.average = s.total / 3;		//求平均分
}

void sort(Student S[], int N)		//插入法排序
{
	int index;
	Student inserter;
	for (int i = 1; i < N; i++)		//依次比较所有学生
	{
		inserter = S[i];		//取出元素i
		index = i - 1;
		while (index >= 0 && inserter.average > S[index].average)
		{		//该元素大于第i-1个元素
			S[index + 1] = S[index];
			index--;
		}
		S[index + 1] = inserter;		//插入
	}
	for (int j = 0; j < N; j++)
		S[j].rank = j + 1;		//设置排名
}

double getAverage(Student S[], int N)
{
	double Average = 0;
	for (int i = 0; i < N; i++)
		Average += (S[i].chinese + S[i].math + S[i].english);
	Average /= (N * 3);
	return Average;
}

void print(Student &s)
{
	cout << "排名" << "\t" << "学号" << "\t" << "姓名" << "\t" << "语文" << "\t" << "数学" << "\t" << "英语"
		<< "\t" << "总分" << "\t" << "平均分" << endl;
	cout <<s.rank<< "\t" << s.number << "\t" << s.name << "\t" << s.chinese << "\t" <<s.math << "\t" << s.english
		<< "\t" << s.total << "\t" << s.average << endl;
}

int search(Student S[], int N, char *n)
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(S[i].number, n) == 0)		//比较字符，如果n(用户输入的学号)与系统中学号相等，strcmp(S[i].number, n)值为0
			return i;		//返回下标
	}
	return -1;
}

