#include<bits/stdc++.h>
using namespace std;
int findSmallRow(vector<int> arr,int low,int high,int key)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        cout<<"mid is "<<mid<<endl;
        if(arr[mid]<=key&&arr[mid+1]>key)
        {
            cout<<"A"<<endl;
            return mid+1;
        }
        else if(arr[mid]<key)
        {
            cout<<"B"<<endl;
            return findSmallRow(arr,mid+1,high,key);
        }
        else if(arr[mid]>key)
        {
            cout<<"C"<<endl;
            return findSmallRow(arr,low,mid-1,key);
        }
    }
    if(low==high)
    {
        if(arr[low]<=key)
            return low+1;
        else if(arr[low]>key)
            return 0;

    }
}
int findSmall(vector<vector<int> > &A,int key)
{
    int sum=0;
    for(int i=0;i<A.size();i++)
    {
        int low=0;
        int high=A[0].size()-1;
        int count=findSmallRow(A[i],low,high,key);
        cout<<"count for row "<<i<<" is "<<count<<endl;
        sum+=(count);
    }
    return sum;
}
int findMedian(vector<vector<int> > &A) {
    int low=1;
    int high=INT_MAX;
    int k=(A.size()*A[0].size())/2;
    cout<<"K = "<<k<<endl;
    k++;
    while(low<=high)
    {
        int mid=(low/2+high/2);
        cout<<"key is "<<mid<<endl<<"low is "<<low<<" high is "<<high<<endl;
        int cntSmall=findSmall(A,mid);
        cout<<"Count Small is "<<cntSmall<<endl;
        if(cntSmall==k)
        {
            cout<<"D"<<endl;
            return mid;
        }
        else if(cntSmall>k)
        {
            cout<<"E"<<endl;
            high=mid-1;
        }
        else if(cntSmall<k)
        {
            cout<<"F"<<endl;
            low=mid+1;
        }
    }
    return 0;
}
int main()
{
    int r,c;
    cin>>r>>c;
    vector< vector<int> > mat(r,vector<int>(c));
    for(int i=0;i<r;i++)
    {
        for (int j = 0; j < c; ++j)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int ans=findMedian(mat);
    cout<<"Ans is "<<ans<<endl;

}