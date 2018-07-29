#include<bits/stdc++.h>
using namespace std;
int findNext2(int n)
{
    int i=0,temp=n;
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
void createST(int* segTree,int arr[],int low,int high,int pos)
{
    if(low==high)
    {    
      segTree[pos]=arr[low]; 
      return;
    }
    int mid=(low+high)/2;
    createST(segTree,arr,low,mid,2*pos+1);
    createST(segTree,arr,mid+1,high,2*pos+2);
    segTree[pos]=(segTree[2*pos+1]+segTree[2*pos+2]);
    // cout<<"STI is "<<pos<<" value "<<segTree[pos]<<endl;
    
}
int *constructST(int arr[],int n)
{
  //Your code here
  int np2=findNext2(n);
//   cout<<"Size is "<<np2<<endl;
  int size=np2*2-1;
  int* segTree = (int *)malloc(sizeof(int)*size);
  int low=0,high=n-1,pos=0;
  createST(segTree,arr,low,high,pos);
//   cout<<"ST "<<segTree[0]<<endl;
  for (int i = 0; i < size; ++i)
  {
    cout<<segTree[i]<<" ";
  }
  cout<<endl;
  return segTree;
}
int SQUtil(int st[],int low,int high,int qlow,int qhigh,int pos)
{
    if(qlow<=low&&qhigh>=high)
        return st[pos];
    else if(qlow>high||qhigh<low)
        return 0;
    else{
        int mid=(low+high)/2;
        return (SQUtil(st,low,mid,qlow,qhigh,2*pos+1)+SQUtil(st,mid+1,high,qlow,qhigh,2*pos+2));
    }
}
/* The functions returns the
 min element in the range
 from a and b */
int SQ(int st[] , int n, int a, int b)
{
    //Your code here
    int low=0,high=n-1,pos=0;
    int ans=SQUtil(st,low,high,a,b,pos);
    return ans;
}
void updateSegmentTree(int st[],int lt[],int low,int high,int qlow,int qhigh,int delta,int pos)
{
    if(low>high)
      return;
    if(lt[pos]!=0)
    {
      st[pos]+=lt[pos];
      if(low!=high)
      {
          lt[2*pos+1]=lt[pos];
          lt[2*pos+2]=lt[pos];
      }
      lt[pos]=0;
    }
    if(qlow<=low&&qhigh>=high)
    {
        st[pos]+=delta;
        if(low!=high)
        {
            lt[2*pos+1]=lt[pos];
            lt[2*pos+2]=lt[pos];  
        }
    }
    else if(qlow>high||qhigh<low)
      return;
    else
    {
        int mid=(low+high)/2;
        updateSegmentTree(st,lt,low,mid,qlow,qhigh,delta,2*pos+1);
        updateSegmentTree(st,lt,mid+1,high,qlow,qhigh,delta,2*pos+2);
        st[pos]=st[2*pos+1]+st[2*pos+2];
    }
}
int rangeSumQuery(int st[],int lt[],int low,int high,int qlow,int qhigh,int pos)
{
    if(low>high)
      return 0;
    if(lt[pos]!=0)
    {
      st[pos]+=lt[pos];
      if(low!=high)
      {
          lt[2*pos+1]=lt[pos];
          lt[2*pos+2]=lt[pos];
      }
      lt[pos]=0;
    }
    if(qlow<=low&&qhigh>=high)
    {
        return st[pos];
    }
    else if(qlow>high||qhigh<low)
      return 0;
    else
    {
        int mid=(low+high)/2;
        return (rangeSumQuery(st,lt,low,mid,qlow,qhigh,2*pos+1)+rangeSumQuery(st,lt,mid+1,high,qlow,qhigh,2*pos+2));
    }
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int* ST=constructST(arr,n);
  int np2=findNext2(n);
  int size=np2*2-1;
  int* lazyTree = (int *)malloc(sizeof(int)*size);
	cout<<"Sum of values in given range = "<<SQ(ST, n, 1, 3)<<endl;
  cout<<"Updating values of 0,2 by +3"<<endl;
  updateSegmentTree(ST,lazyTree,0,n-1,0,2,3,0);
  for (int i = 0; i < size; ++i)
  {
    cout<<ST[i]<<" ";
  }
  cout<<endl;
  cout<<"Sum of values in given range = "<<rangeSumQuery(ST,lazyTree,0, n-1, 1, 3,0)<<endl;
}