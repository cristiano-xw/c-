#include<bits/stdc++.h>
using namespace std;
int main()
{  
    long long n,k;int a[511111];
    scanf("%d%d",&n,&k);
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
     
    nth_element(a,a+k,a+n);//nth_element(������,������+��kСԪ��,������+Ԫ�ظ���) 
    printf("%d",a[k]);//���õ�kС����
}
