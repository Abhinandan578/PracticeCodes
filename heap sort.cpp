#include<iostream>
using namespace std;
void swap(int& a,int& b)
{
	int temp=a;
	a=b;
	b=temp;
}
void maxHeapify(int arr[],int i,int n)
{
	int left=2*i;
	int right=2*i+1;
	int largest=i;
	if(left<=n&&arr[largest]<arr[left])
	{
		largest=left;
	}
	if(right<=n&&arr[largest]<arr[right])
	{
		largest=right;
	}
	if(largest!=i)
	{
		swap(arr[largest],arr[i]);
		maxHeapify(arr,largest,n);
	}

}
void buildHeap(int arr[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		maxHeapify(arr,i,n);
	}
}
void heapSort(int arr[],int n)
{
	buildHeap(arr,n);
	// cout<<"after buildHeap value at top"<<arr[1]<<endl;
	int k=n;
	for(int i=1;i<n;i++)
	{
		swap(arr[1],arr[k]);
		k--;
		maxHeapify(arr,1,k);
		// cout<<"after maxHeapify value at top"<<arr[1]<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	heapSort(arr,n);
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}