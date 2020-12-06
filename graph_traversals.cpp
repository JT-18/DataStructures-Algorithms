#include<iostream>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	void DFS(int,int[]);
	void DFS(int,int[],stack<int>&);
	public:
		Graph(int V)
		{
			this->V = V;
			adj = new list<int>[V]; 
		}
		addEdge(int v,int w)
		{
			adj[v].push_back(w);
		}
		~Graph()
		{
			delete[] adj;
		}
		void BFS(int);
		void DFSDriver(int);
		void topologicalSort(int);
		
};

void Graph::BFS(int s)
{
	bool vis[V] = {false};									//Initailize a visited array
	queue<int> q;
	q.push(s);											//Push the 1st node in Q
	vis[s] = 1;											// Mark that node as visited
	list<int>::iterator i;
	while(!q.empty())									//Till Q is not empty
	{
		s = q.front();									//Pop the emelent in the Q
		q.pop();
		cout<<s<<ends;									// Process the node
		for(i = adj[s].begin();i!= adj[s].end();i++)	//Iterate over the adjacents 
		{
			if(!vis[*i])								// If not visited push it into Q and mark it visited.
			{
				vis[*i] = true;
				q.push(*i);
			}
		}
	}	
}


void Graph::DFSDriver(int s)
{
	int vis[V] = {0};									//Initialize a visited array
	vis[s] = 1;
	DFS(s,vis);
}

void Graph::DFS(int s,int vis[])
{
	cout<<s<<ends;										// Process the node
	list<int>::iterator i;
	for(i =adj[s].begin();i!= adj[s].end();i++)			// Iterate over adjacents
	{
		if(!vis[*i])									//If not visited mark it as visited call dfs on that node.
		{
			vis[*i] = 1;
			DFS(*i,vis);
		}
	}
}

void Graph::topologicalSort(int s)
{
	int vis[V] = {0};						//Initialize a visited array
	stack<int> st;
	DFS(s,vis,st);							// Mainitain a stack
	for(int i=0;i<V;i++)
	{
		if(vis[i] == 0)
			DFS(i,vis,st);							//Call DFS on the node.
	}
					
	while(!st.empty())
	{
		cout<<st.top()<<ends;				//At the end after visiting all the nodes print the stack
		st.pop();
	}
	
}

void Graph::DFS(int s,int vis[],stack<int>& st)		// Same as dfs with a stack extra along with function stack.
{
	vis[s] = 1;
	list<int>::iterator i;
	for(i =adj[s].begin();i!= adj[s].end();i++)
	{
		if(!vis[*i])
		{
			DFS(*i,vis,st);
		}
	}
	st.push(s);									//only push the current node in the stack at the end so all recursive calls are handled.
}

int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,3);
	cout<<"Breadth First Search: ";
	g.BFS(0);
	cout<<endl<<"Depth First Search: ";
	g.DFSDriver(0);
	cout<<endl<<"Topological Sort: ";
	g.topologicalSort(3);
	
}
