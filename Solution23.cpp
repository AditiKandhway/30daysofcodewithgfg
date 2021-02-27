#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> &a,pair<int,int> &b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first<b.first;
}
vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
{ 
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        v.push_back({abs(arr[i]-x),arr[i]});
    }
    sort(v.begin(),v.end(),compare);
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        res.push_back(v[i].second);
    }
    sort(res.begin(),res.end());
    return res;
} 
int main()
{
	int n,x,k;
	cin>>n>>x>>k;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector<int> ans=Kclosest(v,n,x,k);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}