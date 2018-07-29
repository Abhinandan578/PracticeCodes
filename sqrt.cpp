#include<iostream>
using namespace std;
int sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int low=0;
    int high=A/2;
    int mid,ans;
    long long int x;
    while(low<=high)
    {
        mid=(low+high)/2;
        x=mid*mid;
        cout<<"mid is "<<mid<<" low is "<<low<<" high"<<high<<endl;
        if(x==A)
        {
            return mid;
        }
        else if(x>A)
        {
            high=mid-1;
        }
        else if(x<A)
        {
            low=mid+1;
            ans=mid;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int ans=sqrt(n);
    cout<<"Ans is "<<ans<<endl;
}