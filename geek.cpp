/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The functions which 
builds the segment tree */
int findNext2(int n)
{
    int i=0;
    while(n>0)
    {
        n=n>>1;
        i++;
    }
    return 1<<i;
}
void createST(int segTree[],int arr[],int low,int high,int pos)
{
    if(low==high)
        segTree[pos]=arr[low]; return;
    int mid=(low+high)/2;
    createST(segTree,arr,low,mid,2*pos+1);
    createST(segTree,arr,mid+1,high,2*pos+2);
    segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
    
}
int *constructST(int arr[],int n)
{
  //Your code here
  int np2=findNext2(n);
  int size=np2*2-1;
  int* segTree = (int *)malloc(sizeof(int)*size);
  for(int i=0;i<size;i++)
  {
      segTree[i]=INT_MAX;
  }
  int low=0,high=n-1,pos=0;
  createST(segTree,arr,low,high,pos);
  return segTree;
}
int RMQUtil(int st[],int low,int high,int qlow,int qhigh,int pos)
{
    if(qlow<=low&&qhigh>=high)
        return st[pos];
    else if(qlow>high||qhigh<low)
        return INT_MAX;
    else{
        int mid=(low+high)/2;
        return min(RMQUtil(st,low,mid,qlow,qhigh,2*pos+1),RMQUtil(st,mid+1,high,qlow,qhigh,2*pos+2));
    }
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    //Your code here
    int low=0,high=n-1,pos=0;
    int ans=RMQUtil(st,low,high,a,b,pos);
    return ans;
}