#include<bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string A, string B) 
{
    int n=A.size();
    int m=B.size();
    string s=A;
    for(int i=1;i<=m/n+2;i++)
    {
        if(s.find(B)!=string::npos)
        {
            return i;
        }
        s+=A;
    }
    return -1;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<repeatedStringMatch(s1,s2);
}