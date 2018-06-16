#include <iostream>
#include <iomanip>
#include <queue>
#define MAX 15
#define INF 2147483647

using namespace std; 

int graph[MAX][MAX], M, N;

void add_edge(int from, int to){
    graph[from][to] = 1;
}

int maxM();
/*bool bfs(int s, int f, int parent[]);
*/
void print(int parent[], int lim);

int main(){
/*  M = 4;
    N = 4;
    addEdge(3, 1);
    addEdge(3, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);
*/
    M = 4;
    N = 4;
    add_edge(1, 1); 
    add_edge(1, 2); 
    add_edge(2, 3); 
    add_edge(2, 1); 
    add_edge(2, 2); 
    add_edge(3, 1); 
    //add_edge(3, 2);
    //add_edge(3, 3);

    cout << maxM() << endl;
    return 0;
}

bool bfs(int pairX[], int pairY[], int lvl[]){
    queue<int> q;
    for(int i = 0; i < M; i++){
        if(!pairX[i]){
            lvl[i] = 0; 
            q.push(i);
        } else {
            lvl[i] = INF;
        }
    }
    lvl[0] = INF;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(lvl[t] < lvl[0]){
            for(int i = 0; i < N; i++){
                if(graph[t][i] && lvl[pairY[i]] == INF){
                    lvl[pairY[i]] = lvl[t] + 1;
                    //cout << t << ", " << pairY[i] << endl;
                    q.push(pairY[i]);
                }
            }
        }
    }
    //print(lvl, M);
    return (lvl[0] != INF);
}

bool dfs(int x, int pairX[], int pairY[], int lvl[]){   
    //base case
    if(x == 0) return true;
    //step 
    for(int i = 0; i < N; i++){
        //if has connection & is next "lvl" & there is a path ending @ 0 or free node --> dfs, add pair & return 
        if(graph[x][i] && lvl[x] +1 == lvl[pairY[i]] && dfs(pairY[i], pairX, pairY, lvl)){
            pairY[i] = x;
            pairX[x] = i;
            return true;
        }
    }
    return false;
}

int maxM(){
    int match = 0, pairX[M], pairY[N], lvl[M];
    memset(pairX, 0, sizeof(pairX));
    memset(pairY, 0, sizeof(pairY));
    while(bfs(pairX, pairY, lvl)){
        for(int i = 1; i < N; i++){
            if(!pairX[i] && dfs(i, pairX, pairY, lvl)){
                match++;
            }
        }
    
    }
    return match;
}

void print(int parent[], int lim){
    for(int i = 0; i < lim; i++){
        cout << parent[i] << " ";
    }
    cout << endl;
}

















//answers to questions -->
/*
 * why dist[dummy vertex NIL] = INF?
 * b/c otherwise we could not be able to add a point to it --> different statuses --> 0, lvl#, or INF (as in matched) --> it can't be zero, as it isn't a free vertex (it's a dummy vertex) + can't be a lvl# b/c it can only serve as the last end lvl, which is unknown at this time (if there is a free vertex)+ INF is the only one that makes sense/that would make it work since it needs to be able to form a connection w/ the last (free) vertex.   
 *      
 * Why use 0 instead of -1 in hopcoft-karp algorithm in C++? If -1 or other value is used, how does the code look ugly?
 *  If -1 or any other # were used, then for bfs, an extra if statement would be needed or not use the dummy & check every time or return right then and there + we could technically used the biggest as well & instead of 0, set everything to a const o
 * 
 * Why one augmenting path only increase max_match by only one?
 * B/c there'd would only be 1 since it's an alternating path & ends w/ free vertices --> can only add 1 more matched edge  
 * 
 * If level of vertex is less than vertex of dummy vertex, we process it, otherwise we do not need to do it (why?) 
 * B/c it's either already matched or the dummy vertex is matched  
 *
 * If dummy vertex has a finite (not INF) level, there is augmenting path (why?)
 * B/c we've changed the status/level, so the path ends are free vertices (&alternating path), and thus an augmenting paths 
 *
 * use dfs to update match (pairV[], also pairU[], why do we use pairU if pariV has all the matching information?)
 * B/c we don't want to use an extra for loop everytime we try to find other match --> set A and set B --> B[] & w/o A[], then we would need to search the whole array to find the one w/ B[#] but w/ A[], we can just find the other one w/ A[z]  
 * 
 * if there is vertex in U with dist[u]+1 (next level), we find one possible augmenting path (are we sure this is augmenting path?, definitely it is alternating path.)
 * if ends @ 0, then yes b/c ends w/ free vertices (0 represents the dummy node for free node), & that's why the base case is x == 0 
 *
 * if we find the augmenting path, update all match information (pairV and also pairU, why do we update pairU, can we use another data structure, like matched[], or visited[]?)
 * technically, yes, but it's most likely uglier. 
 *
 */












