# Network Flow: Maximum flow (USACO 4.2-max-flow, 5.4-min-cut)

### Once you replace negative thoughts with positive ones, you'll start having positive results. 
-- Willie Nelson

### Plan review:
    - python: 2 or 3
    - iterator, generator, input, etc.
    - decorator

### Flow network

Definition:  Flow network (also known as a transportation network) is a directed graph where each edge has a capacity and each edge receives a flow. 
1. The amount of flow on an edge cannot exceed the capacity of the edge. 
2.  the amount of flow into a vertex equals the amount of flow out of it, unless it is a source, which has only outgoing flow, or sink, which has only incoming flow. 

https://en.wikipedia.org/wiki/Maximum_flow_problem


### Max-flow greedy algorithm:

- Greedy approach to the maximum flow problem is to start with the all-zero flow and greedily produce flows with ever-higher value. The natural way to proceed from one to the next is to send more flow on some path from s to t

### Residual Graphs and Augmenting Paths

- Residual Graph: The idea is to extend the naive greedy algorithm by allowing “undo” or "cancel" operations.  For example, if wen have already assigned 1 unit of flow from vertex A to Vertex B, then passing 1 unit of flow from B to A is interpreted as cancelling or undoing one unit of the original flow from A to B.

- Augmenting Path:  A path constructed by repeatedly finding a path of positive capacity from a source to a sink and then adding it to the flow.  Augmenting path does not contain cycles.  

- Optimality condition:  Given a network G, a flow f is maximum in G if there is no s−t augment path in the residual graph.

### The Ford–Fulkerson augmenting path algorithm  or Ford–Fulkerson algorithm (FFA) 

- It was discovered in 1956 by Ford and Fulkerson. This algorithm is sometimes referred to as a method because parts of its protocol are not fully specified and can vary from implementation to implementation. An algorithm typically refers to a specific protocol for solving a problem, whereas a method is a more general approach to a problem.

- The Ford-Fulkerson Algorithm computes a maximum flow in a iterative manner by starting with a valid flow, and then making adjustments that fulfill the constraints and increase the flow. Here is the algorithm:
    1. Start with initial flow as 0.
    2. While there is a augmenting path from source to sink, add this path-flow to flow.
    3. Return flow.

The Ford-Fulkerson method does not explicitly state how to find the augmenting paths, and works with and path finding algorithm. However, the choice of strategy has an impact on the (worst case) runtime of the algorithm. Depth-first search is a comparatively bad choice, using Breadth-first search (BFS) gives better results.

####  Edmond Karp Implementation O(VE2)

    1. initial max flow is 0, build one residual graph
    2. While there is an s-t path in residual graph, do:

      a. use bfs/dfs to find the augmenting path and save it in parent array (actually it is a linked list)
      b. get the path flow f by using parent array
      c. Augment the max flow  by f, and update the residual graph GR accordingly.
    3. return max flow

https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/


#### Dinic’s algorithm for Maximum Flow O(EV2)

    - Blocking flow: a flow saturates at least one edge for every s-t path in residual graph.
    - Level of each vertex: the shortest path to the source vertex
    - edge: tree, forward, backward, cross

    1. Initialize residual graph to be equal to G. Initialize the flow to be zero in all edges.
    2. While there is an s-t path in residual graph do:
      a. Construct graph level of residual graph using a BFS.
      b. Find a blocking flow f in residual graph using the blocking flow algorithm.
      c. Augment the max flow  by f, and update the residual graph GR accordingly.
    3. return max flow


https://www.geeksforgeeks.org/dinics-algorithm-maximum-flow/


### Future Studies:

- Bipartie matching
- Max-flow min-cut theorem (Minimum cut == Maximum flow)
- General Push Relabel Algorithm


https://www.topcoder.com/community/data-science/data-science-tutorials/maximum-flow-section-1/
https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/tutorial/


### dfs:

    bool dfs(bool vis[V], int p, int s, int t, int parent[])
    {
        parent[s] = p;
        if(s == t) return true;
        vis[s] = true;

        for(int i=0; i< V; ++i) {
            if ((vis[i] == false)&&rGraph[s][i]>0) {
                if (dfs(rGraph, vis, s, i, t, parent)) return true;
            }
        }

        //vis[s] = false;  // this is not needed as it is not backtracking
        return false;
    }

    bool dfs(int s, int t, int parent[])
    {
        bool vis[V];
        for (int i=0; i< V; ++i) {
            vis[i] == false;
        }
        return dfs(rGraph, vis, -1, s, t, parent);
    }

