#include<bits/stdc++.h>
using namespace std;
long long ValidPair(int a[], int n) 
{ 
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            v1.push_back(abs(a[i]));
        }
        else
        {
            v2.push_back(a[i]);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    long long cnt=0;
    for(int i=0;i<v2.size();i++)
    {
        cnt+=i;
        int itr=lower_bound(v1.begin(),v1.end(),v2[i])-v1.begin();
        cnt+=itr;
    }
    return cnt;
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
	cout<<ValidPair(a,n);
}