#include<bits/stdc++.h>
using namespace std;
int Maximum_Sum(vector<vector<int>> &mat,int N,int k)
{
    vector<vector<int> >pre(N,vector<int> (N,0));
    pre[0][0]=mat[0][0];
    for(int i=1;i<N;i++)
    {
        pre[0][i]=mat[0][i]+pre[0][i-1];
    }
    for(int i=1;i<N;i++)
    {
        pre[i][0]=mat[i][0]+pre[i-1][0];
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            pre[i][j]=pre[i-1][j]+pre[i][j-1]+mat[i][j]-pre[i-1][j-1];
        }
    }
    int total=0;
    int maxi=-1;
    for(int i=k-1;i<N;i++)
    {
        for(int j=k-1;j<N;j++)
        {
           total=pre[i][j];
           if(i-k>=0)
           total=total-pre[i-k][j];
           if(j-k>=0)
           total=total-pre[i][j-k];
           if(i-k>=0 && j-k>=0)
           total=total+pre[i-k][j-k];
           maxi=max(maxi,total);
        } 
    }
    return maxi;
}  
int main()
{
	int n,k;
	cin>>n>>k;
	vector<vector<int> >v(n,vector<int> (n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
		}
	}
	cout<<Maximum_Sum(v,n,k);
}