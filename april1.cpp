#include<bits/stdc++.h>
using namespace std;
bool check(long int i,long int j)
{
	if(i%2==0&&j%2==0)
		return true;
	else if(i%2!=0&&j%2!=0)
		return true;
	else
		return false;
}
int main()
{
	long int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long int arr[n];
		long int hash[2001]={0};
		for (long int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			hash[arr[i]+1000]++;
			// cout<<"hash["<<arr[i]+1000<<"] = "<<hash[arr[i]+1000]<<endl;
		}
		long int count=0,avg;
		for (long int i = 0;i<=2000; ++i)
		{
			for(long int j=i;j<=2000;j++)
			{
				if(hash[i]>=1&&hash[j]>=1&&check(i,j))
				{
					avg=(i+j-2000)/2;
					if(hash[avg+1000]>=1)
					{
						// cout<<"inside "<<i-1000<<" "<<j-1000<<endl;
						 if(i==j)
						 {	
						 	if(hash[i]>1)
							 {
							 	count+=hash[i]*(hash[i]-1)/2;
							 }
							 
						}
						else	
							count+=(hash[i]*hash[j]);
					}
				}
			}
		}
		cout<<count<<endl;

	}
}