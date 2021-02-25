#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll findNth(ll N)
{
	ll ans=0;
    ll p=1;
    while(N>0)
    {
        long long rem=N%9;
        N=N/9;
        ans+=(p*rem);
        p=p*10;
    }
    return ans;
}
int main()
{
   ll n;
   cin>>n;
   ll ans=findNth(n);
   cout<<ans;
}