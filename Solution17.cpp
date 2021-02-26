#include<bits/stdc++.h>
using namespace std;
vector<int> help_classmate(vector<int> arr, int n) 
{ 
    vector<int> res(n);
    stack<int> stk;
    for(int i=n-1;i>=0;i--)
    {
        if(stk.empty())
        {
            res[i]=-1;
            stk.push(i);
        }
        else{
            while(!stk.empty() && arr[stk.top()]>=arr[i])
            {
                stk.pop();
            }
            res[i]=stk.empty()?-1:arr[stk.top()];
            stk.push(i);
        }
    }
    return res;
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
	vector<int> v=help_classmate(a,n);
	for(int i=0;i<v.size();i++)
	{
        cout<<v[i]<<" ";
	}
}