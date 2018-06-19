#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>
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
    int f, x, y;
    pt(){
        f = INF;
        x = -1;
        y = -1;
    }
    pt(int a, int b, int c = 0){
        f = c;
        x = a;
        y = b;
    }
    bool operator < (const pt &o) const{
        return f > o.f;
    }
};
/*
struct node{
    int f, x, y, px, py;
    node(int a = 0, pt b, int d = -1, int e = -1){
        f = a;
        x = b.x;
        y = b.y;
        px = d;
        py = e
    }
    bool operator <(const node &o) const{
        return f > o.dist;
    }
};
struct node{
    int f, x, y;
    node(){
        f = INF;
        x = -1;
        y = -1;
    }
    node(pt b, int a = 0){
        f = a;
        x = b.x;
        y = b.y;
    }
};
*/

void dijkstra(pt src, pt dst);

int main(){
    R = 9;
    C = 10; 
    dijkstra(pt(0, 0, 0), pt(8, 0, 0));
}

bool isValid(int x, int y){
    return x >= 0 && x < R && y >= 0 && y < C && graph[x][y];   
}

void dijkstra(pt src, pt dst){
    bool visited[R][C];
    //memset(visited, 0x1F, memset(visited));
    pt fPar[MAX][MAX];
    for(int i = 0; i < R; i++){
        for(int k = 0; k < C; k++){
            fPar[i][k].f = INF;
            visited[i][k] = false;
        }
    }

    priority_queue<pt> q;
    pt tmp(src.x, src.y, 0);
    q.push(tmp);
    //cout << src.x << ", " << src.y << endl;
    //cout << dst.x << ", " << dst.y << endl;
    while(!q.empty()){
       tmp = q.top();
       q.pop();
       visited[tmp.x][tmp.y] = true;
       //cout << "CURENT PT: (" << tmp.x << ", " << tmp.y << ")\t Visiting: ";
       if(tmp.x == dst.x && tmp.y == dst.y) {
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    cout << "(" << fPar[i][j].x << ", " << fPar[i][j].y << ") ";
                 }
                 cout << endl;
            }
            cout << "START\n";
            while(tmp.x != -1 || tmp.y != -1){
               cout << "(" << tmp.x << ", " << tmp.y << ")\n";
               tmp.x = fPar[tmp.x][tmp.y].x;
               tmp.y = fPar[tmp.x][tmp.y].y;
            }
            cout << "END\n\n";
            //return;
       }
       for(int i = 0, tx, ty; i < 8; i++){
           tx = tmp.x + fX[i];
           ty = tmp.y + fY[i];
           //cout << "(" << tx << ", " << ty << ")\n";
           if(isValid(tx, ty) && !visited[tx][ty] && tmp.f+ 1 < fPar[tx][ty].f){
                //cout << "ADDED = " << tmp.f + 1 << "\t";
                fPar[tx][ty].f = tmp.f + 1;
                fPar[tx][ty].x = tmp.x;
                fPar[tx][ty].y = tmp.y;
                //cout << "(" << tx << ", " << ty << "): " << tmp.x << ", " << tmp.y << endl;
                q.push(pt(tx, ty, tmp.f + 1));
           }
       }
       //cout << endl;
    }
    /*cout << fPar[dst.x][dst.y].x << ", " << fPar[dst.x][dst.y].y << endl;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << "(" << fPar[i][j].x << ", " << fPar[i][j].y << ") ";
        }
        cout << endl;
    }*/
    /*
    if(fPar[dst.x][dst.y].f != INF){
        //stack <pt> st;
        pt n(dst.x, dst.y);
        cout << "BACKWARDS: ";
        
        while(n.x != src.x || n.y != src.y){
            //st.push(n);
            cout << "(" << n.x << ", " << n.y << ")\t";
            n.x = fPar[n.x][n.y].x;
            n.y = fPar[n.x][n.y].y;
        }
          cout << "\nFORWARD: ";
        while(!st.empty()){
            n = st.top();
            st.pop();
            cout << "(" << n.x << ", " << n.y << ")\n"; 
        }
    } else {
        cout << "PATH NOT FOUND\n";
    }*/
    cout << "PATH NOT FOUND\n";
}







