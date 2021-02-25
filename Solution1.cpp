#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void helpclassmates(ll a[],ll n)
{
    vector<ll> b(a,a+n);
    for(int i=0;i<n;i++)
    {
        a[b[i]]=b[b[b[i]]];
    }
}
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	helpclassmates(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}