#include<bits/stdc++.h>
using namespace std;

int RulingPair(vector<int> arr, int n) 
{ 
	vector<pair<int,int> > v;
	int maxi=-1;
	for(int i=0;i<n;i++)
	{
	    int sum=0;
	    int n=arr[i];
	    while(n)
	    {
	        sum+=n%10;
	        n=n/10;
	    }
	    v.push_back({sum,arr[i]});
	}
	std::sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)
	{
	    if(a.first==b.first)
       {
        return a.second>b.second;
        }
       return a.first>b.first;
	});
	for(int i=1;i<n;i++)
	{
	    int sum=0;
	    if(v[i].first==v[i-1].first)
	    {
	        sum+=v[i].second+v[i-1].second;
	    }
	    maxi=max(sum,maxi);
	}
	return maxi?maxi:-1;
}   
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<RulingPair(a,n);
}