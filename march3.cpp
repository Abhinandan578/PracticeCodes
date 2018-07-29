#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int arr[n];
		map<long long ,long long> freq;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(freq.find(arr[i])!=freq.end())
			{
				freq[arr[i]]++;
			}
			else
			{
				freq[arr[i]]=1;
			}
			// cout<<"Freq is "<<freq[arr[i]]<<endl;
		}
		long long sum=0;
		map<long long,long long>::iterator it;
		for(it=freq.begin();it!=freq.end();it++)
		{
			// cout<<it->second<<endl;
			if(it->second>1)
				sum+=it->second-1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
			
