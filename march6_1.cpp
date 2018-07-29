#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long arr[n];
		vector<long long > cf(n,0);
		vector<long long > ans(n,0);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(i==0)
			{
				cf[i]=arr[i];
			}
			else
			{
				cf[i]=cf[i-1]+arr[i];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(i!=j)
				{
					long long value =abs(cf[i]-cf[j]);
					if(i>j)
					{
						value-=arr[i];
					}
					else
					{
						value-=arr[j];
					}
					if(value<=arr[i])
					ans[j]+=1;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}
			