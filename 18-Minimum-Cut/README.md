#####  `Success is the sum of small efforts - repeated day in and day out.`

# Network Flow: MaxFlow MinCut problem

### Connected Graph:  
- cut vertex (articulation point):
- cut edge (bridge):
- cut set of a graph: the set of edges.  If removed, graph is partitioned into two disjoint subgraphs or subsets.
- Minimum cut: the sum of weight of cut set.
- Maximum cut:

https://en.wikipedia.org/wiki/Cut_(graph_theory)


### Concept in flow network:
- Maxflow (Maximum flow): the largest possible flow from source S to sink T
- s-t cut of flow network: The set of edges.  Removing these edges in a cut will severe the source S from the sink T
- Capacity of a cut: The sum of the capacity of the edges in the cut
- Minimum cut: The cut in the network that has the smallest possible capacity
- Minimum cut capacity: the capacity of the minimum cut
- Max-flow min-cut theorem: For any network, the value of the maximum flow is equal to the capacity of the minimum cut.

http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/NetFlow/max-flow-min-cut.html
https://en.wikipedia.org/wiki/Max-flow_min-cut_theorem

Find minimum s-t cut in a flow network

    1.  Augmenting path theorem. Flow f is a max flow iff there are no augmenting paths.
    2.  Max-flow min-cut theorem. The value of the max flow === the value of the min cut capacity.
    3.  The Ford-Fulkerson algorithm for finding the maximum flow minimum cut:

      a. Construct the Residual Graph
      b. Find an augmenting path from the source to the sink with strictly positive flow. 
        while (augment path exists) 
            Update max flow, residual graph
      c. do a DFS search on residual graph for find all the reachable vertex from S
      d. The minimum (s,t)-cut is the set of edges between all vertices reachable from the source and those unreachable from S in original graph.

https://brilliant.org/wiki/max-flow-min-cut-algorithm/
https://www.geeksforgeeks.org/minimum-cut-in-a-directed-graph/

We can also use other maxflow algorithm like Dinic's

### Bipartite matching:
1. understand free vertex and matched/saturated vertex
2. understand maximal and maximum matching
3. understand alternating path and augmenting path

### Key Points:
    1. how to represent free vertex and matched vertex
    2. how to find the augmenting path
    3. how to represent bipartite graph (adjacent matrix, adjacent list/vector, edge list, edmonds matrix), 

We use edmonds matrix for the following two algorithm:

#### 1. DFS algorithm:
    - use (-1) to mark all the free vertex (match[] array)
    - DFS: always starts from free vertex from U, use DFS to find free vertex in V

#### 2. Hopcoft-karp
    - use 0 to mark all the free vertex(pairV[] array, pairU[] is assistant array), 0 is a dummy vertex too.
    - use bfs to find level for vertices in U, it also check if there is augmenting path:
        1. initialization: free vertex in U has 0 distance, matched vertex in U has longest distance (INF), including dummy vertex (why dist[dummy vertex NIL] = INF?).
        2. If level of vertex is less than vertex of dummy vertex, we process it, otherwise we do not need to do it (why?) 
        3. if dummy vertex has a finite (not INF) level, there is augmenting path (why?)

    - use dfs to update match (pairV[], also pairU[], why do we use pairU if pariV has all the matching information?)
        1. starting from free vertex in U
        2. if there is vertex in U with dist[u]+1 (next level), we find one possible augmenting path (are we sure this is augmenting path?, definitely it is alternating path.)
        3. if we find the augmenting path, update all match information (pairV and also pairU, why do we update pairU, can we use another data structure, like matched[], or visited[]?)

    https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm

### Questions: 
- Why use 0 instead of -1 in hopcoft-karp algorithm in C++? If -1 or other value is used, how does the code look ugly?
- Why one augmenting path only increase max_match by only one?

### Application of max-flow min-cut:
1. USACO pollutant problem, cut the flow with minimum cost

### Max flow extensions and applications:
    - Disjoint paths and network connectivity.
    - Bipartite matchings.
    - Circulations with upper and lower bounds.
    - Census tabulation (matrix rounding).
    - Airline scheduling.
    - Image segmentation.
    - Project selection (max weight closure).
    - Baseball elimination.

### Book Recommendation
1. CLRS book: Introduction to Algorithms, 3rd Edition
2. TAOCP: The Art of Computer Programming

