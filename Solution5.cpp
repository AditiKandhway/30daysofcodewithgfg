#include<bits/stdc++.h>
using namespace std;
int findK(vector<vector<int>> &a, int n, int m, int k)
{
    int sr=0;
	int sc=0;
	int er=n-1;
	int ec=m-1;
	k--;
	while(sr<=er&&sc<=ec)
	{
		for(int i=sc;i<=ec;i++,k--)
		{
		    if(k==0)
			return a[sr][i];
		}
		sr++;
		for(int i=sr;i<=er;i++,k--)
		{
		    if(k==0)
			return a[i][ec];
		}
		ec--;
        if(sr<=er){
		for(int i=ec;i>=sc;i--,k--)
		{
		    if(k==0)
		    return a[er][i];
		}
		er--;
		}
        if(sc<=ec)
		{
		for(int i=er;i>=sr;i--,k--)
		{
		    if(k==0)
			return a[i][sc];
		}
		sc++;
		}
	}
    return 0;   
 }
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> >v(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>v[i][j];
    	}
    }
    cout<<findK(v,n,m,k);
}