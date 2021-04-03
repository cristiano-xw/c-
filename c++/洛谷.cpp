#include<bits/stdc++.h>  
using   namespace   std;
const int Max = 30;		//ѧ�ź��ַ����Ĵ�С
//����������
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
	char number[Max];	//ѧ��
	char name[Max];		//����
	double chinese;		//����
	double math;		//��ѧ
	double english;		//Ӣ��
	double total;		//�ܷ�
	double average;		//ƽ����
	int rank;			//����
};

//����������
int main()
{
	const int M = 3;	//���峣��������Ϊ3λͬѧ
	Student S[M];		//������������
	for (int i = 0; i < M; i++)
	{
		cout << "���������" << i + 1 << "λͬѧ�����ݣ�" << endl;
		setData(S[i]);		//�����������뺯��
		count(S[i]);
		cout << endl;
	}
	sort(S, M);
	int order = 1;
	
	while (order != 4)
	{
		cout << "****************************����˵�****************************" << endl;
		cout << "1.��ѯ��������" << endl;
		cout << "2.��ѯ�ɼ���ȫ��ƽ�������ϵ�ѧ����������Ϣ" << endl;
		cout << "3,��������һ��ѧ�ţ����Ҹ�ѧ���������Ϳ��Գɼ�" << endl;
		cout << "4.�˳�ϵͳ" << endl;
		cout << "****************************************************************" << endl;
		cout << "���������";
		cin >> order;
		switch (order)
		{
		case 1:
		{
			for (int j = 0; j < M; j++)
				print(S[j]);	//�����������
		}
		break;
		case 2:
		{
			double compare = getAverage(S, M);		//��ȡƽ���֣�֮�󽫴���ƽ���ֵ�ͬѧ���
			for (int k = 0; k < M; k++)
				if (S[k].average > compare)
					print(S[k]);
		}
		break;
		case 3:
		{
			char code[Max];
			cout << "������Ҫ���ҵ�ѧ�ţ�";
			cin >> code;
			int result = search(S, M, code);
			if (result == -1)
				cout << "�������ѧ�Ų����ڣ�" << endl;
			else
				print(S[result]);
		}
		break;
		case 4:
			break;
		default:
			cout << "�����������������" << endl;
		}
	}
}

//���ܺ�������
void setData(Student &s)
{
	cout << "����ѧ�ţ����������ģ���ѧ��Ӣ��ɼ���";
	cin >> s.number >> s.name >> s.chinese >> s.math >> s.english;		//�ֱ���������ݸ�����ĳ�Ա
	//��Ա�ĳ�ʼ��
	s.total = 0;
	s.average = 0;
	s.rank = 0;
}

void count(Student &s)
{
	s.total = s.chinese + s.math + s.english;		//���ܷ�
	s.average = s.total / 3;		//��ƽ����
}

void sort(Student S[], int N)		//���뷨����
{
	int index;
	Student inserter;
	for (int i = 1; i < N; i++)		//���αȽ�����ѧ��
	{
		inserter = S[i];		//ȡ��Ԫ��i
		index = i - 1;
		while (index >= 0 && inserter.average > S[index].average)
		{		//��Ԫ�ش��ڵ�i-1��Ԫ��
			S[index + 1] = S[index];
			index--;
		}
		S[index + 1] = inserter;		//����
	}
	for (int j = 0; j < N; j++)
		S[j].rank = j + 1;		//��������
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
	cout << "����" << "\t" << "ѧ��" << "\t" << "����" << "\t" << "����" << "\t" << "��ѧ" << "\t" << "Ӣ��"
		<< "\t" << "�ܷ�" << "\t" << "ƽ����" << endl;
	cout <<s.rank<< "\t" << s.number << "\t" << s.name << "\t" << s.chinese << "\t" <<s.math << "\t" << s.english
		<< "\t" << s.total << "\t" << s.average << endl;
}

int search(Student S[], int N, char *n)
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(S[i].number, n) == 0)		//�Ƚ��ַ������n(�û������ѧ��)��ϵͳ��ѧ����ȣ�strcmp(S[i].number, n)ֵΪ0
			return i;		//�����±�
	}
	return -1;
}

