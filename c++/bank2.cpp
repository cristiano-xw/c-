#include<bits/stdc++.h>
#include"bank2.h"
using namespace std;

int main() {
Account *accounts[3];
accounts[0] = new SavingsAccount(100, 3); //���100Ԫ����Ϣ3%
accounts[1] = new CheckingAccount(100, 5); //���100Ԫ�����׷�5Ԫ
accounts[2] = new CheckingAccount(50, 5); //���50Ԫ�����׷�5Ԫ
for (int i = 0; i < 3; i++) {
cout << "��" << i + 1 << "��ѭ���Ľ����" << endl;
accounts[i]->debit(200); //���200Ԫ
accounts[i]->debit(40);
accounts[i]->credit(50); //���50Ԫ
accounts[i]->debit(49);
accounts[i]->debit(43);
accounts[i]->credit(1);
//��Accountָ��ǿ��ת��ΪSavingAccountָ��
SavingsAccount *derivedPtr =
dynamic_cast<SavingsAccount *>(accounts[i]);
if(derivedPtr != NULL) //������ͼ��ݣ�ת���ɹ�
derivedPtr->credit(derivedPtr->calculateInterest());
cout << fixed << setprecision(2); //ʹ�ö�������ʽ��2λС������
cout << "�˻������Ϊ��" << accounts[i]->getBalance() << endl;
} 
return 0;
} 

