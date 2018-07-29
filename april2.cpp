#include<bits/stdc++.h>
using namespace std;
long long power1(long long a,long long n)
{
	long long sum=1;
	for (int i = 0; i < n; ++i)
	{
		sum=(sum*10)%1000000007;
	}
	return sum;
}
int main()
{
	long long int t,n,w,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>w;
		ans=(power1(10,n-2)*(9-abs(w))%1000000007)%1000000007;
		cout<<ans<<endl;
	}
}