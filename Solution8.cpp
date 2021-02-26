#include<bits/stdc++.h>
using namespace std;

int maxCandy(int height[], int n) 
{
    int i=0;
    int j=n-1;
    int res=0;
    int ans=0;
    while(i<j)
    {
        res=((j-i)-1)*min(height[i],height[j]);
        ans=max(ans,res);
        if(height[i]>height[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
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
	cout<<maxCandy(a,n);
}