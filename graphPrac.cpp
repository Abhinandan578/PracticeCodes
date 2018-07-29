#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[],int src,int dest)
{
	graph[src].push_back(dest);
	// graph[dest].push_back(src);
}
void dfsUtil(int i,vector<int> graph[],vector<bool> &vis)
{
	vis[i]=true;
	cout<<i<<" ";
	for(int j=0;j<graph[i].size();j++)
	{
		if(!vis[graph[i][j]])
		{
			dfsUtil(graph[i][j],graph,vis);
		}
	}
}
void dfs(vector<int> graph[],int V)
{
	vector<bool> vis(V,false);
	for(int i=0;i<V;i++)
	{
		if(vis[i]==false)
		{
			dfsUtil(i,graph,vis);
		}
	}
}
void bfs(vector<int> graph[],int V)
{
	vector<bool> vis(V,false);
	queue<int> q;
	q.push(5);
	vis[5]=true;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int j=0;j<graph[node].size();j++)
		{
			if(!vis[graph[node][j]])
			{
				vis[graph[node][j]]=true;
				q.push(graph[node][j]);
			}
		}
	}
}
void topologicalSortUtil(int i,vector<int> graph[],vector<bool> &vis,stack<int> &st)
{
	vis[i]=true;
	for(int j=0;j<graph[i].size();j++)
	{
		if(!vis[graph[i][j]])
		{
			topologicalSortUtil(graph[i][j],graph,vis,st);
		}
	}
	// cout<<"Here "<<i<<endl;
	st.push(i);
}
void topologicalSort(vector<int> graph[],int V)
{
	stack<int> st;
	vector<bool> vis(V,false);
	for(int i=0;i<V;i++)
	{
		if(!vis[i])
		{
			// cout<<"in "<<i<<endl;
			topologicalSortUtil(i,graph,vis,st);
		}
	}
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
int main()
{
	int V;
	int E;
	int src,dest;
	cout<<"Enter the vertices "<<endl;
	cin>>V;
	vector<int> graph[V];
	cout<<"Enter the number of edges "<<endl;
	cin>>E;
	for(int i=0;i<E;i++)
	{
		cout<<"Enter the Src and Dest "<<endl;
		cin>>src>>dest;
		addEdge(graph,src,dest);
	}
	cout<<"DFS is ";
	dfs(graph,V);
	cout<<endl;
	cout<<"BFS is ";
	bfs(graph,V);
	cout<<endl;
	cout<<" Topological Sort ";
	topologicalSort(graph,V);
	cout<<endl;

}