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
long long int findAns(long long int arr[],long long int l,long long int r,int maxBit,long long int count1[][31],long long int count0[][31])
{
	int j;
	long long res=0,temp,num;
	int check1,check0;
	for (int i = 0; i < 31; ++i)
	{
		if(i<maxBit)
		{
			if(l==1)
			{
				check1=count1[r-1][i];
				check0=count0[r-1][i];
			}
			else
			{
				check1=count1[r-1][i]-count1[l-2][i];
				check0=count0[r-1][i]-count0[l-2][i];
			}
				// cout<<"Check1 on "<<i<<"is "<<check1<<endl;
				// cout<<"Check0 on "<<i<<"is "<<check0<<endl;
			if(check1<check0)
			{
				// cout<<"Inside "<<endl;
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
	long long left,right,max=LONG_LONG_MIN,temp;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	int maxBit=findMax(max);
	long long int count1[n][31],count0[n][31];
	for (int i = 0; i <n ; ++i)
	{	
		for (int j = 0; j < 31; ++j)
		{
			count1[i][j]=0;
			count0[i][j]=0;
		}
		int j=0;	
		while(j<maxBit)
		{
			temp=1<<j;
			if((temp&arr[i]))
			{
				if(i==0)
				{
					count1[i][j]=1;
					count0[i][j]=0;
				}
				else
				{
					count1[i][j]=count1[i-1][j]+1;
					count0[i][j]=count0[i-1][j];
				}
			}
			else
			{
				if(i==0)
				{
					count1[i][j]=0;
					count0[i][j]=1;
				}
				else
				{
					count1[i][j]=count1[i-1][j];
					count0[i][j]=count0[i-1][j]+1;
				}
			}	
			j++;
		}
	}
	for (int i = 0; i < q; ++i)
	{
		cin>>left>>right;
		cout<<findAns(arr,left,right,maxBit,count1,count0)<<endl;
	}
	return 0;
}
			
