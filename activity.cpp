#include<bits/stdc++.h>
using namespace std;
struct activity
{
	int start;
	int end;
};
int maxActivitySchedule(activity arr[],int low,int high,int start,int end)
{
	if(low>high)
		return 0;
	int q=0;
	int l1,r1,left,right;
	for(int i=low;i<=high;i++)
	{
		if(arr[i].start>=start&&arr[i].end<end)
		{
			left=maxActivitySchedule(arr,low,i-1,start,arr[i].start);
			right=maxActivitySchedule(arr,i+1,high,arr[i].end,end);
			if(left+right+1>q)
			{
				l1=i;
				q=left+right+1;
				cout<<"value of q is "<<q<<endl;
			}
		}
	}
	// cout<<"l1 = "<<l1<<"for low = "<<low<<"high = "<<high<<endl;
	if(q==0)
	{
		return 0;
	}
	else
	{
		cout<<"l1 = "<<l1<<"for low = "<<low<<"high = "<<high<<endl;
		cout<<"value returned  left = "<<left<<" right = "<<right<<endl;
		return q;
	}
}
void swapActivity(activity& a,activity& b)
{
	activity temp;
	temp=a;
	a=b;
	b=temp;
}
int partition(activity arr[],int low,int high)
{
	int pivot=arr[high].end;
	int i=low-1;
	for(int j=low;j<=high;j++)
	{
		if(arr[j].end<=pivot)
		{
			swapActivity(arr[++i],arr[j]);
		}
	}
	return i;
}
void sortActivity(activity arr[],int low,int high)
{
	if(low>high)
		return;
	int index =partition(arr,low,high);
	sortActivity(arr,low,index-1);
	sortActivity(arr,index+1,high);
}
int maxActivityScheduleGreedy(activity arr[],int n)
{
	sortActivity(arr,0,n-1);
	int count=1;
	int k=0;
	for(int i=1;i<n;i++)
	{
		if(arr[k].end<=arr[i].start)
		{
			count++;
			k=i;
		}
	}
	return count;
}
int main()
{
	int n;
	cout<<"Enter number of activities "<<endl;
	cin>>n;
	activity arr[n];
	cout<<"Enter the start time of each activity"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].start;
	}
	cout<<"Enter the end time of each activity"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].end;
	}
	int ans=maxActivitySchedule(arr,n);
	cout<<"Activites are = "<<ans<<endl;
}
