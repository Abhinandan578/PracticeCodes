#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}
int minSwaps(int A[], int N){
    /*Your code here */
    int smaller[N];
    int cnt;
    bool set[N];
    for(int i=0;i<N;i++)
    {
        set[i]=false;
        cnt=0;
        for(int j=0;j<N;j++)
        {
            if(A[i]>A[j])
            {
                cnt++;
            }
        }
        smaller[i]=cnt;
        cout<<"Cnt is "<<cnt<<" ";
    }
    int ans=0,i=0;
    cnt=0;
    while(cnt!=N-1)
    {
        if(smaller[i]!=i)
        {
            int index=smaller[i];
            cout<<"Index is "<<index<<endl;
            swap(A[index],A[i]);
            swap(smaller[index],smaller[i]);
            ans++;
            set[index]=true;
            cnt++;
            cout<<A[index]<<" "<<A[i]<<endl;
            cout<<smaller[index]<<" "<<smaller[i]<<endl;
        }
        else
        {
            if(set[i]==false)
            {
                set[i]=true;
                cnt++;
            }
        }
        if(i==N-1)
            i=0;
        else
            i++;
    }
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<smaller[i]<<" ";
    }
    cout<<endl;
    return ans;
}
