#include<bits/stdc++.h>
using namespace std;

 void bfs(vector<vector<char> >& matrix,vector<vector<int> >&ans,int n,int m)
{
    queue<pair<int,int> >q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]=='B')
            {
                ans[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int rr=x+dx[i];
            int cc=y+dy[i];
            if(rr<0 || cc<0 || rr>=n || cc>=m)
            {
                continue;
            }
            if(ans[rr][cc]==-1 && matrix[rr][cc]=='O')
            {
                ans[rr][cc]=ans[x][y]+1;
                q.push({rr,cc});
            }
        }
    }
}
vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
{
    vector<vector<int> > ans(M,vector<int> (N,-1));
    bfs(matrix,ans,M,N);
    return ans;
} 
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char> >v(n,vector<char> (m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>v[i][j];
		}
	}
	vector<vector<int> > ans=findDistance(v,n,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}