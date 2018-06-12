#### `It is the theory that decides what can be observed`

                -- Albert Einstein
BST for future learning:
iterative insert, deletenode, buildtree(1, n)

Review C++ STL:
1. vector: dynamic arrary
2. list, forward_list:
3. queue:
4. stack:
5. priority_queue:
6. unordered_map/set/multimap/multiset:
7. map/set/multimap/multiset

boost 

For coding: do it in right way, then in best way.

Graph:

A graph is an ordered pair G = (V, E) comprising a set V of vertices or nodes or points together with a set E of edges or arcs or lines, which are 2-element subsets of V (i.e. an edge is associated with two vertices, and that association takes the form of the unordered pair comprising those two vertices).

1. directed and undirected
2. finite and infinite
3. cyclic, acyclic (DAG directed acyclic graph)
4. edge representation: adjacent list (less memory requirement), adjacent matrix (fast access)

terms: 
degree: The degree or valency of a vertex is the number of edges that connect to it, where an edge that connects a vertex to itself (a loop) is counted twice.


https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-graphs-and-their-data-structures-section-1/
https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/




Graph Representation:
adjacent list
https://www.geeksforgeeks.org/graph-and-its-representations/
https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs

class graph {
public:
    graph(int size) {
        V=size;
        adj = new list<int>[V];
    }

    void add_edge(int src, int dst) {
    }

    void dfs() {
    }

    void bfs() {
    }

    it_dfs() {  // must use stack<int> st
    }

    // Find if there is a path between two vertices in a directed graph
    bool reachable(int u, int v) {
    }

private:
    int V;
    list<int> *adj;
}

Graph DFS
explore as far as possible along one branch before backtracking, 
use a boolean visited array for each vetex.
recursive utility for DFS (graph, visited)

DFS(u):
  visited[u] = true
  for each successor v of u:
    if not visited[v]:
       DFS(v)

dfs_help(int u, bool visited[]);

https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/


Graph BFS
visited adjacent nodes first, then their adjacent
use queue to store the node to be visited
use a boolean visited array for each vetex.

BFS(G, s):
  Q = an empty queue
  mark[] = array of booleans, one per vertex, initially false
  mark[s] = true
  push(s, Q)
  while Q is not empty:
    u = pop(Q)
    DoSomethingTo(u)
    for each successor v of u:
      if mark[v] = false:
        push(v, Q)

https://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/


Iterative graph DFS 
The same as recursive DFS
use C++ STL stack instead of function call stack
https://www.geeksforgeeks.org/iterative-depth-first-traversal/



Graph Representation using matrix
global variable: spaghetti code, but reduce the number of parameters to pass to the calling function
directed: not 
