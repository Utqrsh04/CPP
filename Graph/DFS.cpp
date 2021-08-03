#include <bits/stdc++.h>
using namespace std;

class DFS
{
  void dfs(int node , vector<int> &vis , vector<int> adj[] , vector<int> &storeDfs) {

    storeDfs.push_back(node);
    vis[node] = 1;
    for( auto it : adj[node]) {
      if(!vis[it])  {

        dfs(it , vis , adj , storeDfs);
      }
    }


  }
public:
  vector<int> dfsOfGraph(int v, vector<int> adj[])
  {

    vector<int> storeDfs;
    vector<int> vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
    {
      if (!vis[i])
      {
        dfs(i, vis, adj, storeDfs);
      }
    }
  }

};

int main()
{

  // Vertices are numbered from 1 - n

  // n : no of nodes and e : no of edges
  int n, e;
  cin >> n >> e;

  //Declare Adjacency List of n+1 size ( 1 based Graph index )
  vector<int> adj[n + 1];

  cout << "Enter edges with source and target vertex " << endl;
  for (int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }


  DFS d ;
  vector<int> ans = d.dfsOfGraph(n , adj); 

  cout << "DFS traversal " << endl;
  for (auto it : ans)
    cout << it << " ";

  return 0;
}