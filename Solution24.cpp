#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    static bool compare(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        return a.first>b.first;
    }
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        map<int,int> mp;
        vector<pair<int,int> >v;
        int n=array.size();
        for(int i=0;i<n;i++)
        {
            mp[array[i]]++;
        }
        for(auto x:mp)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),compare);
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(v[i].second);
        }
        return res;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}