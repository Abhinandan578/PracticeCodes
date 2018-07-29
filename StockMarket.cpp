#include<bits/stdc++.h>
using namespace std;
struct subArray
{
	int left;
	int right;
	int sum;
};
subArray crossArr(int arr[],int low,int mid,int high)
{
	// cout<<"Inside crossArr"<<endl;
	// cout<<" low = "<<low<<" mid = "<<mid<<" high = "<<high<<endl;
	int temp=0;
	int lsum=INT_MIN,rsum=INT_MIN;
	int indexLeft,indexRight;
	for(int i=mid;i>=low;i--)
	{
		temp+=arr[i];
		if(temp>lsum)
		{
			lsum=temp;
			indexLeft=i;
		}
	}
	temp=0;
	for(int i=mid+1;i<=high;i++)
	{
		temp+=arr[i];
		if(temp>rsum)
		{
			rsum=temp;
			indexRight=i+1;
		}
	}
	subArray res;
	res.left=indexLeft;
	res.right=indexRight;
	res.sum=lsum+rsum;
	// cout<<"return crossArr = "<<res.sum<<endl;
	return res;
}
subArray find_max_sa(int arr[],int low,int high)
{
	int mid=(low+high)/2;
	// cout<<" low = "<<low<<" mid = "<<mid<<" high = "<<high<<endl;
	subArray temp;
	if(low<high)
	{
		subArray a1=find_max_sa(arr,low,mid);
		subArray a2=find_max_sa(arr,mid+1,high);
		subArray a3=crossArr(arr,low,mid,high);
		// return ( (a1.sum>a2.sum) ? ( (a1.sum>a3.sum) ? a1 : a3) : ( (a2.sum>a3.sum) ? a2 : a3) );
		if(a1.sum>a2.sum)
		{
			// cout<<"Inside a1 "<<endl;
			if(a1.sum>a3.sum)
			{
				// cout<<"return value  a1 = "<<a1.sum<<endl;
				return a1;
			}
			else
			{
				// cout<<"return value  a3= "<<a3.sum<<endl;
				return a3;
			}
		}
		else
		{
			if(a2.sum>a3.sum)
			{
				// cout<<"return value  a2 = "<<a2.sum<<endl;
				return a2;
			}
			else
			{
				// cout<<"return value  a3 in a2 = "<<a3.sum<<endl;
				return a3;
			}	
		}
	}
	else if(low==high)
	{
		temp.left=low;
		temp.right=high+1;
		temp.sum=arr[low];
		return temp;
	}
}
subArray fun(int arr[],int n)
{
	int min=arr[0];
	int max=arr[0];
	subArray ans;
	int indexLeft,indexRight;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			indexRight=i;
			max=arr[i];
		}
		if(arr[i]<min)
		{
			indexLeft=i;
			min=arr[i];
		}
	}
	if(indexLeft<indexRight)
	{
		ans.left=indexLeft;
		ans.right=indexRight;
		ans.sum=max-min;
		return ans;
	}
	else
	{
		max=arr[indexLeft];
		for(int i=indexLeft+1;i<n;i++)
		{
			if(arr[i]>max)
			{
				max=arr[i];			
			}
		}
	}
}
subArray kadane(int arr[],int n)
{
	int max_sum=arr[0];
	int curr_sum=arr[0];
	subArray ans;
	int indexLeft=0,indexRight;
	for(int i=1;i<n;i++)
	{
		if(curr_sum+arr[i]>arr[i])
		{
			// cout<<"inside 1 "<<i<<endl;
			// cout<<"curr_sum "<<curr_sum<<endl;
			indexRight=i+1;
			curr_sum+=arr[i];
		}
		else
		{
			// cout<<"inside 2 "<<i<<endl;
			indexLeft=i;
			indexRight=i+1;
			curr_sum=arr[i];
		}
		if(curr_sum>max_sum)
		{
			// cout<<"inside 3 "<<i<<endl;
			ans.right=indexRight;
			ans.left=indexLeft;
			max_sum=curr_sum;
			ans.sum=max_sum;
		}
	}
	return ans;
}
int main()
{
	cout<<"Enter the Number of days"<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the closing stock price on each day"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int change[n-1];
	cout<<"Change Array = "<<endl;
	for(int i=0;i<n-1;i++)
	{
		change[i]=arr[i+1]-arr[i];
		cout<<change[i]<<" ";
	}
	cout<<endl;
	subArray ans=find_max_sa(change,0,n-2);
	// subArray ans=kadane(change,n-1);
	cout<<"Maximum Sum = "<<ans.sum<<endl;
	cout<<"Index Left = "<<ans.left<<" Index Right = "<<ans.right<<endl;
	return 0;
}