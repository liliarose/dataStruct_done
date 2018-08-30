#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#define MAX 10
#define INF 0X1F1F1F
using namespace std;

int R, C, graph[MAX][MAX] = {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }};

int fX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int fY[] = {0, 1, -1, 1, -1, 1, 0, -1};

struct pt{
    int f, x, y;
    pt(){
        f = INF, x = -1, y = -1;
    }
    pt(int a, int b, int c = 0){
        x = a, y = b, f = c;
    }
    bool operator < (const pt &o) const{
        return f > o.f;
    }
};
void dijkstra(const pt &src, const pt &dst);
bool isValid(int x, int y){
    return x >= 0 && x < R && y >= 0 && y < C && graph[x][y];   
}

void dijkstra(const pt &src, const pt &dst){
    bool visited[R][C];
    memset(visited, 0, sizeof(visited));
    pt fPar[MAX][MAX];
    priority_queue<pt> q;
    q.push(src);
    while(!q.empty()){
       pt tmp = q.top();
       q.pop();
       visited[tmp.x][tmp.y] = true;
       //cout << "Processing: " << tmp.x << ", " << tmp.y << "\n";
       if(tmp.x == dst.x && tmp.y == dst.y) {
            for(int x = dst.x, y = dst.y, tx, ty; x != -1 && y != -1; tx = x, ty = y, x = fPar[tx][ty].x, y = fPar[tx][ty].y){
               cout << "(" << x << ", " << y << ")\n";
            }
            return;
       }
       for(int i = 0, tx, ty; i < 8; i++){
           tx = tmp.x + fX[i], ty = tmp.y + fY[i];
           if(isValid(tx, ty) && !visited[tx][ty] && tmp.f+ 1 < fPar[tx][ty].f){
                fPar[tx][ty].f = tmp.f + 1;
                fPar[tx][ty].x = tmp.x;
                fPar[tx][ty].y = tmp.y;
                q.push(pt(tx, ty, tmp.f + 1));
           }
       }
    }
    cout << "PATH NOT FOUND\n";
}

int main(){
    R = 9, C = 10; 
    dijkstra(pt(0, 0), pt(8, 0));
}


