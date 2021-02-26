#include<bits/stdc++.h>
using namespace std;

int transfigure(string A, string B)
{
	int n=A.size();
	int m=B.size();
	map<char,int> mp1;
	map<char,int> mp2;
	for(int i=0;i<n;i++)
	{
	    mp1[A[i]]++;
	}
	for(int i=0;i<m;i++)
	{
	    mp2[B[i]]++;
	}
	if(mp1!=mp2)
	{
	    return -1;
	}
	int i=n-1;
	int j=m-1;
	int cnt=0;
	while(i>=0 && j>=0)
	{
	    if(i<0)
	    {
	        break;
	    }
	    if(j<0)
	    {
	        break;
	    }
	    if(A[i]==B[j])
	    {
	        i--;
	        j--;
	    }
	    else
	    {
	        cnt++;
	        i--;
	    }
	}
	return cnt;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<transfigure(s1,s2);
}