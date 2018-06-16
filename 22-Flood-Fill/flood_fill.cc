#include <iostream>
#include <fstream>
#include <queue>
#define N_MAX 10
#define M_MAX 10
#define SIZE 4

struct pt{
	int x, y;
	pt(int a = 0, int b = 0){
		x = a;
		y = b;
	}
};

using namespace std;

int maze[N_MAX][M_MAX];

int p[SIZE] = {-1, 1};

bool floodfill_dfs(int M, int N);
bool floodfill_dfs(int x, int y, bool visited[][N_MAX], int M, int N);
bool floodfill_bfs(int M, int N);

int main(){
	ifstream fin("maze.in");
	ofstream fout("maze.out");
	int M, N;
	fin >> M >> N;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			fin >> maze[i][j];
			//cout << maze[i][j];
		}
		//cout << endl;
	}
	fout << floodfill_dfs(M, N) << endl;
	//cout << "bfs\n";
	fout << floodfill_bfs(M, N) << endl;
}

bool floodfill_bfs(int M, int N){
	queue<pt> q;
	bool visited[M][N];
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			visited[i][j] = false;
		}
	}
	q.push(pt(0, 0));
	pt tmp;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		visited[tmp.x][tmp.y] = true;
		if(tmp.x == M-1 && tmp.y == N-1 && maze[tmp.x][tmp.y]){
			return true;
		} else {
			for(int i = 0, tX, tY; i < SIZE; i++){
        		if(i&1){
            		tX = tmp.x + p[i/2], tY = tmp.y;
        		} else {
            		tY = tmp.y + p[i/2], tX = tmp.x;
        		}
				//cout << tX << ", " << tY << endl;
				if(tX >= 0 && tY >= 0 && tX < M  && tY < N && maze[tX][tY]  && !visited[tX][tY]){
					//cout << tX << ", " << tY << endl;
					q.push(pt(tX, tY));
				}
			}
		}
	}
	return false;
}

bool floodfill_dfs(int M, int N){
	bool visited[M][N_MAX];
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			visited[i][j] = false;
		}
	}
	return floodfill_dfs(0, 0, visited, M, N);	
}
// maze -> 1 = okay, 0 = !okay
bool floodfill_dfs(int x, int y, bool visited[][N_MAX], int M, int N){
	if(x < 0 || y < 0 || x > M || y > N || maze[x][y] == 0 || visited[x][y]){
		return false;
	}
	//cout << x << ", " << y << endl;
	if(x == M-1 && y == N-1 && maze[x][y]){
		return true;
	}
	visited[x][y] = true;
	for(int i = 0, tX, tY; i < SIZE; i++){
		if(i&1){
			tX = x + p[i/2], tY = y;
		} else {
			tY = y + p[i/2], tX = x;
		}
		if(floodfill_dfs(tX, tY, visited, M, N))
			return true;
	}
	return false;
}

