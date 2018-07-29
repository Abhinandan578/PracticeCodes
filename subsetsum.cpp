#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            // sum+=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            // cin>>arr[i];
            sum+=arr[i];
        }
        cout<<"Hello "<<sum<<endl;
        if(sum%2!=0)
            cout<<"NO"<<endl;
        else
        {
            cout<<"Here "<<endl;
            sum=sum/2;
            bool mat[n+1][sum+1];
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=sum;j++)
                {
                    if(j==0)
                    {
                        mat[i][j]=true;
                    }
                    else if(i==0)
                    {
                        mat[i][j]=false;
                    }
                    else
                    {
                    	cout<<arr[i-1]<<" here "<<i<<" "<<j<<endl;
                        if(arr[i-1]<=j)
                        {
                            mat[i][j]=mat[i-1][j]||mat[i-1][j-arr[i]];
                        }
                        else
                        {
                        	// cout<<"j "<<endl;
                            mat[i][j]=mat[i-1][j];
                        }
                    }
                }
            }
            // for(int i=0;i<=n;i++)
            // {
            //     for(int j=0;j<=sum;j++)
            //     {
            //         cout<<mat[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            if(mat[n][sum])
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
	return 0;
}