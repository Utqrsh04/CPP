#include<bits/stdc++.h>
using namespace std ;


int main(){

  // n : no of nodes and m : no of edges 
  int n , m;
  cin >> n >> m;

  //for adjacency matrix method
/*  
  //declare the adjacent matrix
  int adj[n+1][n+1];

  //take edges as inputs
  for(int i =0 ; i<m ; i++){
    int u , v;
    cin >> u >> v;

    adj[u][v] = 1;
    adj[v][u] = 1;

  } 
*/
  // ------------------------------------------------------

  //For Adjacency List

  //Declare Adjacency List of n+1 size ( 1 based Graph index ) 
  vector<int> adj[n+1];
  /* 
  For weighted Graph 
  vector<pair<int,int>> adj[n+1] 
  */

  for(int i=0 ; i<m ; i++)  {
    int u , v;
    cin >> u >> v;

    /* 
    For weighted Graph
    cin >> u >> v >> weight ;  
    */
    

    adj[u].push_back(v);
    /*
    For weighted Graph
    adj[u].push_back( {v,weigh} );
    adj[v].push_back( {u,weigh} );
    */


    // For directed graph omit this line
    adj[v].push_back(u);
  }

  
  return 0;
}