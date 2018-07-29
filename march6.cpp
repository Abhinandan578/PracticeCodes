#include<bits/stdc++.h>
using namespace std;
int findNext2(long long int n)
{
    long long int i=0,temp=n;
    while(n%2==0)
    {
        n=n/2;
        if(n==1)
            return temp; 
    }
    n=temp;
    while(n>0)
    {
        n=n>>1;
        i++;
    }
    return 1<<i;
}
void createST(long long int* segTree,long long int arr[],long long int low,long long int high,long long int pos)
{
    if(low==high)
    {    segTree[pos]=arr[low]; 
         return;
    }
    long long int mid=(low+high)/2;
    createST(segTree,arr,low,mid,2*pos+1);
    createST(segTree,arr,mid+1,high,2*pos+2);
    segTree[pos]=(segTree[2*pos+1]+segTree[2*pos+2]);
    // cout<<"STI is "<<pos<<" value "<<segTree[pos]<<endl;
    
}
long long int *constructST(long long int arr[],long long int n)
{
  //Your code here
  long long int np2=findNext2(n);
//   cout<<"Size is "<<np2<<endl;
  long long int size=np2*2-1;
  long long int* segTree = (long long int *)malloc(sizeof(long long int)*size);
  long long int low=0,high=n-1,pos=0;
  createST(segTree,arr,low,high,pos);
//   cout<<"ST "<<segTree[0]<<endl;
  // for (long long int i = 0; i < size; ++i)
  // {
  //   cout<<segTree[i]<<" ";
  // }
  // cout<<endl;
  return segTree;
}
long long int SQUtil(long long int st[],long long int low,long long int high,long long int qlow,long long int qhigh,long long int pos)
{
    if(qlow<=low&&qhigh>=high)
        return st[pos];
    else if(qlow>high||qhigh<low)
        return 0;
    else{
        long long int mid=(low+high)/2;
        return (SQUtil(st,low,mid,qlow,qhigh,2*pos+1)+SQUtil(st,mid+1,high,qlow,qhigh,2*pos+2));
    }
}
/* The functions returns the
 min element in the range
 from a and b */
long long int SQ(long long int st[] , long long int n, long long int a, long long int b)
{
    //Your code here
    long long int low=0,high=n-1,pos=0;
    long long int ans=SQUtil(st,low,high,a,b,pos);
    return ans;
}
int main()
{
	long long int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		long long int* ST=constructST(arr,n);
		vector<long long> ans(n,0);
		long long int value;
		for (long long int i = 0; i < n; ++i)
		{
			for (long long int j = i; j < n; ++j)
			{
				if(i==j||j-i==1)
					value=0;
				else
				{	
					value=SQ(ST,n,i,j);
					value=value-(arr[i]+arr[j]);
				}
				if(i!=j&&arr[i]>=value)
					ans[j]+=1;
				if(i!=j&&arr[j]>=value)
					ans[i]+=1;
			}
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		
		
		
	}
	return 0;
}
			