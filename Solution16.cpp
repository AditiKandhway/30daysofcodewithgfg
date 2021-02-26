#include<bits/stdc++.h>
using namespace std;
string Reduced_String(int k,string s1){
    int n=s1.size();
   
    stack<pair<char,int> > s;
    
    s.push({'A',1});
    
    for(int i=0;i<n;i++)
    {
        char x=s.top().first;
        int y=s.top().second;
        if(x==s1[i])
        {
            if(y==k-1)
            {
                for(int i=0;i<k-1;i++)
                {
                    s.pop();
                }
            }
            else
            {
                s.push({s1[i],y+1});
            }
        }
        else
        {
            s.push({s1[i],1});
        }
    }
    string res="";
    if(k==1)
    {
        return res;
    }
    while(!s.empty())
    {
        res.push_back(s.top().first);
        s.pop();
    }
    res.pop_back();
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
	int k;
	cin>>k;
	string s;
	cin>>s;
	cout<<Reduced_String(k,s);
}