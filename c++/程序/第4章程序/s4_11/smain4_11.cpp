//主文件
//文件名：s4_11\smain4_11.cpp

#include <iostream>  					//包含头文件,使用iostream库
#include "sclass4_11_Node.h"			//包含类声明头文件

int CNode::sNodeNum = 0;
/*****************************************************************************/

//主函数: 本例的设计思路主要是为了便于学习和观察相关C++机制!!
//调整作用域运行程序，仔细观察、体会可加深对相关概念的理解。
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

