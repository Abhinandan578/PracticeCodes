#include<iostream>
#include<algorithm>
using namespace std;

int main() {

int a[100000],n;
cin>>n;

int f[100000]={0};
for(int i=0;i<n;++i)
{
    cin>>a[i];
}
 
 
 for(int i=0 ;i<n;++i)
{
    ++f[a[i]];
}



for(int i=1;i<100000;++i)
{
    f[i]+=f[i-1];
}
    

int out[100000];

for(int i=0;i<n;++i)
{
    out[f[a[i]]-1]=a[i];
    --f[a[i]];
}

for(int i=0;i<n;i++)
   
       a[i]=out[i];



for(int i=0;i<n;i++)
   cout<<a[i]<<",";

	return 0;
}