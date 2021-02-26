#include<bits/stdc++.h>
using namespace std;

long long sumBitDiff(int arr[], int n) 
{ 
    int zero=0;
    int one=0;
    long long ans=0;
    for(int i=0;i<=31;i++)
    {
         int zero=0;
         int one=0;
         for(int j=0;j<n;j++)
         {
             int bit=arr[j]&1;
             arr[j]=arr[j]>>1;
             if(bit==0)
             {
                 zero++;
             }
             else
             {
                 one++;
             }
         }
         ans+=(zero*one);
    }
    return 2*ans;
} 
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<sumBitDiff(a,n);
}