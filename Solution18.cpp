#include<bits/stdc++.h>
using namespace std;

bool recreationalSpot(int arr[], int n){
	int max=arr[0];
	int min=arr[0];
	for(int i=0;i<n;i++)
	{
	    if(arr[i]>max)
	    {
	        max=arr[i];
	    }
	    else if(arr[i]<max && arr[i]>min)
	    {
	        return true;
	    }
	    else{
	        min=arr[i];
	    }
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(recreationalSpot(a,n))
	{
		cout<<"True";
	}
	else{
		cout<<"False";
	}
}