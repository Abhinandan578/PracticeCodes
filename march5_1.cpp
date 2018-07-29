#include<bits/stdc++.h>
using namespace std;
int findMax(long long max)
{
	int i=0;
	while(max)
	{
		max=max>>1;
		i++;
	}
	return i;
}
long long int findAns(long long int arr[],long long int l,long long int r,int maxBit)
{
	long long int count1[31]={0},count0[31]={0};
	int j;
	long long res=0,temp;
	for (int i = l-1; i <r ; ++i)
	{	
		j=0;	
		while(j<maxBit)
		{
			temp=1<<j;
			if((temp&arr[i]))
			{
				count1[j]++;
				// cout<<"count1["<<j<<"] is "<<count1[j]<<endl;
			}
			else
			{
				count0[j]++;
				// cout<<"count0["<<j<<"] is "<<count0[j]<<endl;	
			}	
			j++;
		}
	}

	for (int i = 0; i < 31; ++i)
	{
		if(i<maxBit)
		{
			cout<<"count1["<<i<<"] is "<<count1[i]<<endl;
			cout<<"count0["<<i<<"] is "<<count0[i]<<endl;	
			if(count1[i]<count0[i])
			{	
				cout<<"Inside"<<endl;
				res=res^(1<<i);
			}
		}
		else
		{
			res=res^(1<<i);
		}
	}
	return res;
	
}
int main()
{
	int q,n;
	cin>>n>>q;
	long long arr[n];
	long long left,right,max=LONG_LONG_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	int maxBit=findMax(max);
	for (int i = 0; i < q; ++i)
	{
		cin>>left>>right;
		cout<<findAns(arr,left,right,maxBit)<<endl;
	}
	return 0;
}