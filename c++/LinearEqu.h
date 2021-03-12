#ifndef _LINEAR_EQU_H
#define _LINEAR_EQU_H
#include"Matrix.h"

class LinearEqu:public Matrix
{
	public:
		LinearEqu(int size=2);
		~LinearEqu();
		void setLinearEqu(const double*a,const double*b); //���̸�ֵ 
		bool solve();  //ѡȡ��˹��ȥ����ⷽ�� 
		void printLinearEqu() const; //��ʾ���� 
		void printSolution() const; //��ʾ���̵Ľ� 
	
	private:
		double *sums;
		double* solution;
};     
#endif
