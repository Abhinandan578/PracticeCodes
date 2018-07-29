#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int price[n],quantity[n],discount[n];
		for(int i=0;i<n;i++)
		{
			cin>>price[i]>>quantity[i]>>discount[i];
		}
		double totalLoss=0;
		for(int i=0;i<n;i++)
		{
			double increase = (double(100)+double(discount[i]))/100.00000000;
			cout<<(float(100)+float(discount[i]))/100.00<<endl; 	
			// cout<<"Increase is "<<increase<<endl;
			double newPrice = increase*double(price[i]);
			// cout<<"New Increased Price is "<<newPrice<<endl;

			double decrease = (double(100)-double(discount[i]))/100.00000;
			// cout<<"Decrease is "<<decrease<<endl;

			double salePrice = decrease*newPrice;
			// cout<<"Sale Price is "<<salePrice<<endl;

			double loss = double(price[i])-salePrice;
			// cout<<"Loss is "<<fixed<<setprecision(9)<<loss<<endl;
			loss = loss*double(quantity[i]);
			// cout<<"Final loss is "<<fixed<<setprecision(9)<<loss<<endl;

			totalLoss += loss;
		}
		cout<<fixed<<setprecision(5) << totalLoss << '\n';
	}
	return 0;
}
			