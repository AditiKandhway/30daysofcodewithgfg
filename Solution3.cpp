#include<bits/stdc++.h>
using namespace std;
long long smallestpositive(vector<long long> array, int n)
{
    sort(array.begin(),array.end());
    long long maxi=array[0];
    if(array[0]!=1)
    {
        return 1;
    }
    for(int i=1;i<n;i++)
    {
        if(array[i]>(maxi+1))
        {
            break;
        }
        else
        {
            maxi+=array[i];
        }
    }
    return maxi+1;
} 
int main()
{
	long long n;
	cin>>n;
	vector<long long> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	long long ans=smallestpositive(v,n);
	cout<<ans;
}