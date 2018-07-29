#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long next_2,next_3,next_5,nextNumber;
        long long i2=0,i3=0,i5=0;
        long long arr[n];
        arr[0]=1;
        next_2=arr[i2]*2;
        next_3=arr[i3]*3;
        next_5=arr[i5]*5;
        // cout<<next_2<<" "<<next_3<<" "<<next_5<<endl;
        for(long long i=1;i<n;i++)
        {
            nextNumber=min(next_2,min(next_3,next_5));
            arr[i]=nextNumber;
            if(nextNumber==next_2)
            {
                i2++;
                next_2=arr[i2]*2;
            }
            if(nextNumber==next_3)
            {
                i3++;
                next_3=arr[i3]*3;
            }
            if(nextNumber==next_5)
            {
                i5++;
                next_5=arr[i5]*5;
            }
            // cout<<next_2<<" "<<next_3<<" "<<next_5<<endl;
            
        }
        cout<<arr[n-1]<<endl;
    }
	return 0;
}