int JS(int D[],int p[],int n,int k)
{
	D[0]=0;
	J[0]=0;
	k=1;
	J[1]=1;
	for(i=2;i<=n;i++)
	{
		r=k;
		while(D[J[r]]>D[i]&&D[J[r]]!=r)
		{
			r--;
		}
		if(D[J[r]]<=D[i]&&D[i]>r)
		{
			for(int l=k;l>=r+1;l--)
			{
				J[l+1]=J[l];
			}
			J[r+1]=i;
			k++;
		}
	}
}