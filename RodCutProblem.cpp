#include<bits/stdc++.h>
using namespace std;
int maxProfit(int profit[],int n)
{
	if(n==0)
	{
		return 0;
	}
	int temp=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		temp=max(temp,profit[i]+maxProfit(profit,n-i));
	}
	return max(temp,profit[n]);
}
int topDownSolUtil(int profit[],int n,int r[])
{
	if(r[n]>=0)
	{
		return r[n];
	}
	if(n==0)
	{
		return 0;
	}
	int temp=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		temp=max(temp,profit[i]+topDownSolUtil(profit,n-i,r));
	}
	r[n]=temp;
	return temp;
}
int topDownSol(int profit[],int n)
{
	int r[n+1];
	for(int i=1;i<=n;i++)
	{
		r[i]=INT_MIN;
	}
	r[0]=0;
	return topDownSolUtil(profit,n,r);

}
int bottomUp(int profit[],int n)
{
	int q;
	int r[n+1];
	r[0]=0;
	for(int i=1;i<=n;i++)
	{
		q=INT_MIN;
		for(int j=1;j<=i;j++)
		{
			q=max(q,profit[j]+r[i-j]);
		}
		r[i]=q;
	}
	return r[n];
}
int main()
{
	int n;
	cout<<"Enter the size of rod"<<endl;
	cin>>n;
	int profit[n+1];
	cout<<"Enter profit for each cut of size 1 to n"<<endl;
	profit[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>profit[i];
	}
	int ans=bottomUp(profit,n);
	cout<<"Max Profit is = "<<ans<<endl;

}