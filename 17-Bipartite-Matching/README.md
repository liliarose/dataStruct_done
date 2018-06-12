## “Success is stumbling from failure to failure with no loss of enthusiasm.”
    ― Winston S. Churchill

# Network Flow: Maximum flow (USACO 4.2-max-flow, 5.4-min-cut)

## Ford-Furkerson Max flow:

    max_flow = 0;
    while (exsited(augmenting path)) {
        max_flow += path_flow(augementing paht);
    }
    return max_flow

Correction to Dinic's blocking flow algorithm last time:

    1. blocking should have a visited array to avoid revisiting the node 
    2. start[] array can be used to avoid revisiting

### Matching, cover, color are the problems in Graph.

## Matching in Graph Theory

    A matching M is a subset of pairwise non-adjacent edges in G, i.e.  no two edges share a common vertex in M.
    A vertex is matched (or saturated) if it is an endpoint of one of the edges in the matching. Otherwise the vertex is unmatched.
    A maximal matching is a matching M of a graph G with the property that if any edge not in M is added to M, it is no longer a matching, that is, M is maximal if it is not a subset of any other matching in graph G. In other words, a matching M of a graph G is maximal if every edge in G has a non-empty intersection with at least one edge in M.
    A maximum matching (also known as maximum-cardinality matching) is a matching that contains the largest possible number of edges. There may be many maximum matchings. The matching number of a graph G is the size of a maximum matching. Note that every maximum matching is maximal, but not every maximal matching is a maximum matching.
    A perfect matching (a.k.a. 1-factor) is a matching which matches all vertices of the graph. That is, every vertex of the graph is incident to exactly one edge of the matching.  Every perfect matching is maximum and hence maximal. In some literature, the term complete matching is used. 
    A near-perfect matching is one in which exactly one vertex is unmatched. This can only occur when the graph has an odd number of vertices, and such a matching must be maximum. 
    An alternating path is a path that begins with an unmatched vertex and is a path in which the edges belong alternatively to the matching and not to the matching.
    An augmenting path is an alternating path that starts from and ends on free (unmatched) vertices.

https://www.tutorialspoint.com/graph_theory/graph_theory_matchings.htm
https://en.wikipedia.org/wiki/Matching_(graph_theory)

## Berge's lemma

    In graph theory, Berge's lemma states that a matching M in a graph G is maximum (contains the largest possible number of edges) if and only if there is no augmenting path (a path that starts and ends on free (unmatched) vertices, and alternates between edges in and not in the matching) with M.
    It was proven by French mathematician Claude Berge in 1957 (though already observed by Petersen in 1891 and Kőnig in 1931).

https://en.wikipedia.org/wiki/Berge%27s_lemma


## A Bipartite Graph: 

All vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

### Representation:
convert it to adjacent matrix


## Maximum Bipartite Matching Problem (Ford Fulkerson algorithm)

    1. use adjacent matrix (total vertex M+N+2), use Edward Karp or Dinic
    2. use Edwards Matrix: U (size M),V(size N) adj[M][N] 
        a. initially max_match = 0, match[N] is empty. 
        b. try all the path for u in U to v in V
            if v is not assigned (matched, saturated), assign it to match[v] = u 
            if  v is matched, try if we can assign match[v] to other with recursive call
            return true if there is a match, other false

key points for edward matrix adj[M][N]:

    match[N] : who is my match
    matched[N]: I (v) am already matched by specific u

https://www.geeksforgeeks.org/maximum-bipartite-matching/


## Hopcroft–Karp Algorithm for Maximum Matching

    1 Initialize Maximal Matching M as empty.
    2. While there exists an Augmenting Path p
        Remove matching edges of p from M and add not-matching edges of p to M
        This increases size of M by 1 as p starts and ends with a free vertex
    3. Return M.

https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-1-introduction/

## Future study

Hungarian algorithm (Kuhn–Munkres algorithm or Munkres assignment algorithm)


## Real Applications:

Assignment Problem:  There are a number of agents and a number of tasks. Any agent can be assigned to perform any task, incurring some cost that may vary depending on the agent-task assignment. It is required to perform all tasks by assigning exactly one agent to each task and exactly one task to each agent in such a way that the total cost of the assignment is minimized.

Hall's Marriage Theorem: Imagine two groups; one of n men, and one of n women. For each woman, there is a subset of the men, any one of which she would happily marry; and any man would be happy to marry a woman who wants to marry him. Consider whether it is possible to pair up (in marriage) the men and women so that every person is happy.


The Mutilated Chessboard Problem: Suppose a standard 8x8 chessboard has two diagonally opposite corners removed, leaving 62 squares. Is it possible to place 31 dominoes of size 2x1 so as to cover all of these squares?

## Difference between maximum and maximal:

The short answer is that, unless you are a mathematician or an economist, there is no difference. However, there is a distinction between the two terms in the context of partially ordered sets (i.e. sets in which not every pair of elements need be comparable).

An element is maximal if there is no other element greater.
An element is maximum if it is itself greater than every other element.

If the "elements" under discussion are numbers, the definitions coincide, but there are contexts in which the distinction matters.

For example, in an election one might say that candidate 1 is strictly better than candidate 2 if all potential voters prefer candidate 1 to candidate 2. Say that three candidates - Mitt, Barry, and Adolf - are running for president of a club.

The club members are divided into two contingents of equal size. One group unanimously prefers Barry to Mitt and Mitt to Adolf, while the other unanimously prefers Mitt to Barry and Barry to Adolf.

Barry and Mitt are both strictly better candidates than Adolf, as all members rank Adolf last. But since some members prefer Barry to Mitt and some prefer Mitt to Barry, neither is strictly better than the other. Thus neither can be maximum with respect to this ordering. However, because no candidates exist that are strictly better than either of them, both candidates are maximal with respect to this ordering.


Mathematicians make another distinction between the terms when considering sets that satisfy a certain property. For example, a "clique" is a set of people all of whom know each other. A clique is maximal if adding anyone else to the set destroys the clique property, that is, there is no larger clique that contains it. A clique is maximum if there is no larger clique. For example, if Alice, Bob, and Cam know each other, and Deb, Ed, Fran, and Gay know each other, but none of the first three know any of the other four, then Alice,Bob,Cam are a maximal clique but not a maximum clique. There can be many maximum cliques. Every maximum clique is maximal, but not vice-versa. The other answer about backtracking is another example of this distinction because backtracking in a search means removing an element from a set.


