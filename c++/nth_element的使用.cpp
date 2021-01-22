#include<bits/stdc++.h>
using namespace std;
int main()
{  
    long long n,k;int a[511111];
    scanf("%d%d",&n,&k);
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
     
    nth_element(a,a+k,a+n);//nth_element(数组名,数组名+第k小元素,数组名+元素个数) 
    printf("%d",a[k]);//调用第k小整数
}
