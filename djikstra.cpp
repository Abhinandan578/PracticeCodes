#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> graph[],int src,int dest,int wt)
{
	graph[src].push_back(make_pair(dest,wt));
	// graph[dest].push_back(src);
}
int find_Curr(vector<int> &path_len,vector<bool> &is_Perm)
{
	int min_index=-1;
	int min_path=INT_MAX;
	for(int i=0;i<path_len.size();i++)
	{
		if(!is_Perm[i])
		{
			if(path_len[i]<min_path)
			{
				min_path=path_len[i];
				min_index=i;
			}
		}
	}
	is_Perm[min_index]=true;
	return min_index;
}
void djikstra(vector<pair<int,int>> graph[],int s,int V)
{
	vector<int> path_len(V,INT_MAX);
	vector<bool> is_Perm(V);
	path_len[s]=0;
	for(int i=0;i<V;i++)
	{
		int j=find_Curr(path_len,is_Perm);
		cout<<"Selected "<<j<<endl;
		vector<pair<int,int>>::iterator it=graph[j].begin();
		for(;it!=graph[j].end();it++)
		{
			cout<<"working on "<<(*it).first<<endl;
			if(!is_Perm[(*it).first]&&path_len[j]+(*it).second<path_len[(*it).first])
			{
				path_len[(*it).first]=path_len[j]+(*it).second;
			}
		}
	}
	cout<<"Min Path value from Source "<<s<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<" i "<<i<<" "<<path_len[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int V;
	int E;
	int src,dest,wt;
	cout<<"Enter the vertices "<<endl;
	cin>>V;
	vector<pair<int,int>> graph[V];
	cout<<"Enter the number of edges "<<endl;
	cin>>E;
	for(int i=0;i<E;i++)
	{
		cout<<"Enter the Src and Dest and wt"<<endl;
		cin>>src>>dest>>wt;
		addEdge(graph,src,dest,wt);
	}
	cout<<"Enter the source vertex"<<endl;
	int s;
	cin>>s;
	djikstra(graph,s,V);
	

}
//0 1 4 0 7 8 1 7 11 1 2 8 7 8 7 7 6 1 2 8 2 8 6 6 2 3 7 2 5 4 6 5 2 3 5 14 3 4 9 5 4 10