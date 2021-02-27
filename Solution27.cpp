#include<bits/stdc++.h>
using namespace std;
int catchThieves(char arr[], int n, int k) 
{
    vector<int> thi,pol;
    for(int i=0;i<n;i++)
    {
        if(arr[i]=='P')
        {
            pol.push_back(i);
        }
        else{
            thi.push_back(i);
        }
    }
    int l=0,r=0,res=0;
    while(l<pol.size() && r<thi.size())
    {
        if(abs(pol[l]-thi[r])<=k)
        {
            res++;
            l++;
            r++;
        }
        else if(pol[l]<thi[r])
        {
            l++;
        }
        else{
            r++;
        }
    }
    return res;
}
int main()
{
	int n,k;
	cin>>n>>k;
	char a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<catchThieves(a,n,k);
}