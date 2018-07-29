#include<bits/stdc++.h>
using namespace std;
struct items
{
	double price;
	double wt;
	double ratio;
};
void swapItems(items& a,items& b)
{
	items temp;
	temp=a;
	a=b;
	b=temp;
}
int partition(items arr[],int low,int high)
{
	double pivot=arr[high].ratio;
	int i=low-1;
	for(int j=low;j<=high;j++)
	{
		if(arr[j].ratio<=pivot)
		{
			swapItems(arr[++i],arr[j]);
		}
	}
	return i;
}
void sortItems(items arr[],int low,int high)
{
	if(low>high)
		return;
	int index =partition(arr,low,high);
	sortItems(arr,low,index-1);
	sortItems(arr,index+1,high);
}
int main()
{
	cout<<"Enter the number of items"<<endl;
	int n;
	cin>>n;
	items item[n];
	cout<<"Enter the price of n items"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>item[i].price;
	}
	cout<<"Enter the weight of n items"<<endl;
	double ratio[n];
	for(int i=0;i<n;i++)
	{
		cin>>item[i].wt;
		item[i].ratio=item[i].price/item[i].wt;
	}
	cout<<"Enter the weight of knapsack bag"<<endl;
	int totalWt;
	cin>>totalWt;
	sortItems(item,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<item[i].price<<" ";
	}
	cout<<endl;
	int totalSum=0;
	for(int i=n-1;i>=0;i--)
	{
		if(totalWt-item[i].wt>=0)
		{
			totalSum+=item[i].price;
			totalWt-=item[i].wt;
		}
		else
		{
			if(totalWt>0)
			{
				totalSum+=totalWt*item[i].ratio;
			}
			break;
		}
	}
	cout<<"The maximu cost possible is "<<totalSum<<endl;
	
}