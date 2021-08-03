#include <bits/stdc++.h>
using namespace std;

class BFS
{

public:
  vector<int> bfsOfGraph(int V, vector<int> adj[])
  {

    // vector for storing traversal nodes
    vector<int> storeBfs;

    // Visited array for marking
    vector<int> vis(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {

      // If the node is not visited then only apply bfs
      if (!vis[i])
      {

        // -------------This is BFS Code----------
        queue<int> q;

        // Insert starting node of Component into queue
        q.push(i);
        // Mark it as Visited
        vis[i] = 1;

        // Iterate till queue is not empty
        while (!q.empty())
        {
          // Take out First element from queue
          int node = q.front();
          q.pop();

          // We have traversed that node so push it into bfs vector
          storeBfs.push_back(node);

          // Traversing all the adjacent nodes of that node which were put into queue
          for (auto it : adj[node])
          {
            if (!vis[it])
            {

              // Which of the nodes that haven't been visited is pushed into queue and marked as visited , so that we do not push it again after sometime.
              q.push(it);
              vis[it] = 1;
            }
          }
        }
      }
    }

    return storeBfs;
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

  BFS b;
  vector<int> ans = b.bfsOfGraph(n, adj);

  cout << "BFS traversal " << endl;

  for (auto it : ans)
    cout << it << " ";

  return 0;
}