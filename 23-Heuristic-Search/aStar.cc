#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
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
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
};

int fX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int fY[] = {0, 1, -1, 1, -1, 1, 0, -1};

struct pt{
    int f, x, y, g;
    pt(){
        f = INF;
        x = -1;
        y = -1;
    }
    pt(int a, int b, int c = 0){
        x = a;
        y = b;
        f = c;
    }
    bool operator < (const pt &o) const{
        return f > o.f;
    }
};

void dijkstra(const pt &src, const pt &dst);

int main(){
    R = 9;
    C = 10;
    dijkstra(pt(0, 0), pt(8, 0));
}

int euclid(int x, int y, pt b){
    return (int)sqrt((x-b.x)*(x-b.x) + (y - b.y)*(y - b.y));
}

bool isValid(int x, int y){
    return x >= 0 && x < R && y >= 0 && y < C && graph[x][y];   
}

void dijkstra(const pt &src, const pt &dst){
    fstream fout("euclid.txt");
    bool visited[R][C];
    pt fPar[MAX][MAX];
    for(int i = 0; i < R; i++){
        for(int k = 0; k < C; k++){
            //fPar[i][k].f = INF;
            visited[i][k] = false;
        }
    }
    priority_queue<pt> q;
    pt tmp(src.x, src.y, 0);
    q.push(tmp);
    
    while(!q.empty()){
       tmp = q.top();
       q.pop();
       fout << "Processing: " << tmp.x << ", " << tmp.y << "\n";
       visited[tmp.x][tmp.y] = true;
       if(tmp.x == dst.x && tmp.y == dst.y) {
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    cout << "(" << fPar[i][j].x << ", " << fPar[i][j].y << ") ";
                 }
                 cout << endl;
            }
            cout << "START\n";
            int x = dst.x, y = dst.y;
            while(x != -1 && y != -1){
               cout << "(" << x << ", " << y << ")\n";
               int tx = x, ty = y;
               x = fPar[tx][ty].x;
               y = fPar[tx][ty].y;
            }
            cout << "END\n\n";
            return;
       }
       for(int i = 0, tx, ty; i < 8; i++){
           tx = tmp.x + fX[i];
           ty = tmp.y + fY[i];
           if(isValid(tx, ty) && !visited[tx][ty] ){
                int g = fPar[tmp.x][tmp.y].g + 1;
                int f = g + euclid(tx, ty, dst);
                if(f  < fPar[tx][ty].f){
                    fPar[tx][ty].f = f;
                    fPar[tx][ty].g = g;
                    fPar[tx][ty].x = tmp.x;
                    fPar[tx][ty].y = tmp.y;
                    q.push(pt(tx, ty, f));
                }
           }
       }
    }
    /*cout << fPar[dst.x][dst.y].x << ", " << fPar[dst.x][dst.y].y << endl;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << "(" << fPar[i][j].x << ", " << fPar[i][j].y << ") ";
        }
        cout << endl;
    }*/
    cout << "PATH NOT FOUND\n";
}







