
#### `Try not to become a man of success, but rather try to become a man of value. `

        -- Albert Einstein

    不自见故明；不自是故彰；不自伐故有功；不自矜 故长。
    夫唯不争，故天下莫能与之争。

# Session 14:  Strongly Connected Components (SCC)

### Data Structure Review (C++ STL):

    array(array), dynamic array (vector)
    doubly linked list (list), singly linked list (forward_list)
    stack, queue, priority_queue (heap structure)
    binary tree, binary search tree (BST)
    graph (adjacent list, adjacent matrix, edge list)
    union-find data structure 

A directed graph is strongly connected if there is a path between all pairs of vertices.

https://en.wikipedia.org/wiki/Strongly_connected_component


### Kosaraju’s algorithm

    1. Do DFS and push the vertex to stack S.

    For each vertex u of the graph, mark u as unvisited in visited[] array. Let Stack S be empty.
    For each vertex u of the graph do dfs(u, visited, S), where dfs() is the recursive subroutine:
        mark u as visited:
        for each out-neighbour vertex v
            If v is unvisited then:
                dfs(v, visited, S)
        push u to the stack S
    
    2. Reverse directions of all arcs to obtain the transpose graph.

    3. Do second DFS based on Stack S to get the SCC

        while (stack no empty) {
            pop the vertex u from stack S
            if u is not visited
                do dfs2() to print get SCC
        }

### Transpose graph: the same graph with the direction of every edge reversed

    Theory (??) : you can visit every vertex in forward direction, and you can also visit all vertex in reverse direction === SCC

https://www.geeksforgeeks.org/strongly-connected-components/
https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm



### Tarjan’s Algorithm to find Strongly Connected Components

    The main idea: find the head of each CC
    For an SCC, any vertex can be head.  We can assign the vertex, which is visited first, as the head of SCC.
    using two arrays:
        disk[V]: the visiting order of the vertex.
        low[V]: the disk of the head of SCC, which is visited first for this SCC.
        in-stack[V]: check if the vertex is in stack
        stack: store the vertex being visited via DFS

### Head of SCC: 

https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm



### DP study:
I: Given a sequence a[n], find the length of the longest palindromic subsequence in it.

### solution:
1. brute force: list all the subsequences (1<<n) and do the palindrome check.
2. recursive: 
3. dp-top-down
4. dp-bottom-up

### DP analysis:

    state: dp[i][j]: the length of the longest between i and j inclusive
    initial state:
        dp[i][i] = 1
        dp[i][i+1] = 1 or 2 depends on if a[i] == a[i+1]
    state transition:
        dp[i][j] = 2+ dp[i+1][j-1] if a[i] = a[j]
        dp[i][j] = max(dp[i+1][j], dp[i][j-1]) if not 
    result: dp[0][n-1]

https://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

### II: In computer science, the longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

    1. brute force
    2. recursive
    3. DP bottom-up

      state: state[i]: longest subsequence ended at i
      initial state: dp[0] = 1
      state transition:
        dp[i] = 1+ max of all dp[j] where j<i and a[j] < a[i]

      result: max value in dp[] array.


https://www.geeksforgeeks.org/longest-increasing-subsequence/


### Future Study:

#### Articulation Points (or Cut Vertices) in a Graph
https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

#### Bridges in a graph
https://www.geeksforgeeks.org/bridge-in-a-graph/
 
#### Biconnected graph
https://www.geeksforgeeks.org/biconnectivity-in-a-graph/


