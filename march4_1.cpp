#include<bits/stdc++.h>
using namespace std;
long long findDays(long long mid,vector<long long > arr)
{
	long long sum=0;
	long long j=0,temp;
	while(j<arr.size())
	{
		temp=arr[j];
		sum+=temp/mid;
		temp=temp%mid;
		if(temp!=0)
			sum+=1;
		j++;
	}
	return sum;
}
int main()
{
	long long int t,n,h;
	cin>>t;
	while(t--)
	{
		cin>>n>>h;
		vector<long long> arr(n);
		long long max=LONG_MIN;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]>max)
			{
				max=arr[i];
			}
		}
		long long low=1,high=max;
		long long ans=0;
		while(low<=high)
		{
			long long mid=(low+high)/2;
			long long check=findDays(mid,arr);
			if(check<=h)
			{
				ans=mid;
				high=mid-1;
			}
			else if(check>h)
			{
				low=mid+1;
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
			