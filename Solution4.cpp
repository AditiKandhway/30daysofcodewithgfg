#include<bits/stdc++.h>
using namespace std;

int find_min(int a[], int n, int k) 
{
    long long sum=0;
    long long pair=0;
    long long opt=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        pair+=(a[i]/2);
        if(a[i]%2==1)
        {
            opt+=(a[i]-1)/2;
        }
        else
        {
            opt+=(a[i]-2)/2;
        }
    }
    if(sum<(2*k))
    {
        return -1;
    }
    else if(pair<k)
    {
        return -1;
    }
    if(k>opt)
    {
        return (2*opt+n+k-opt);
    }
    return ((n+1)+2*(k-1));
}
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<find_min(a,n,k);
}