//���ļ�
//�ļ�����s4_11\smain4_11.cpp

#include <iostream>  					//����ͷ�ļ�,ʹ��iostream��
#include "sclass4_11_Node.h"			//����������ͷ�ļ�

int CNode::sNodeNum = 0;
/*****************************************************************************/

//������: ���������˼·��Ҫ��Ϊ�˱���ѧϰ�͹۲����C++����!!
//�������������г�����ϸ�۲졢���ɼ������ظ������⡣
void main( )
{
	CNodeArray oCArray;
	CNode node1("1st"),node2("2nd"),node3("3th"),node4("4th");
	
	oCArray.Insert(node1);
	oCArray.Insert(node2);
	oCArray.Insert(node3);
	for(int i=0;i<=oCArray.m_aIndex;i++)
	{
		cout<<oCArray[i]<<endl;
	}
	oCArray.Delete(0);
	oCArray.Insert(node4);

	for(i=0;i<=oCArray.m_aIndex;i++)
	{
		cout<<oCArray[i]<<endl;
	}

}

