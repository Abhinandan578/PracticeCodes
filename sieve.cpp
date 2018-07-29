#include<bits/stdc++.h>
using namespace std;
int main()
 {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        long int prime[n+1]={0};
        for(long int i=2;i*i<=n;i++)
        {
            if(prime[i]==0)
            {
                prime[i]=i;
                for(long int j=i*i;j<=n;j=j+i)
                {
                    prime[j]=i;
                }
            }
        }
        cout<<prime[n]<<endl;
    }
    return 0;
}