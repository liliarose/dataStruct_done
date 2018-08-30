#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#define MAX 150

using namespace std;

struct lineSeg{
    int x1, x2, y1, y2;
    lineSeg(){
        x1 = 0, y1 = 0;
        x2 = 0, y2 = 0;
    }
    lineSeg(int a, int b, int c, int d){
        x1 = a, y1 = b;
        x2 = c, y2 = d;
    }
    friend ostream &operator <<(ostream &out, lineSeg &l){
        out << l.x1 << " " << l.y1 << " " << l.x2 << " " << l.y2;
        return out;
    }
};

lineSeg fence[MAX];
int N;

double dist(double x1, double y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1 - y2)*(y1 - y2));
}

double pt_ls(double x, double y, lineSeg l){
    if(x >= l.x1 && x <= l.x2) return abs(y - l.y1);
    else    double dx = min((l.x1 - x), (x - l.x2));
    if(y >= l.y1 && y <= l.y2) return abs(x - l.x1);
    else    double dy = min((l.x1 - x), (x - l.x2));
    return sqrt(dx*dx + dy*dy);
}

double totDist(double x, double y){
    double tot = 0; 
    //cout << x << " " << y << ": ";
    for(int i = 0; i < N; i++){
        //cout << pt_ls(x, y, fence[i])  << " ";
        tot += pt_ls(x, y, fence[i]);
    }
    //cout << " = " << tot << endl;
    return tot;
}
void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b; // a - b + b 
    a = a ^ b; //  
}

bool accept(double delta, double temper){
    if(delta < 0) return true;
        // return rand() <= exp((-delta) / temper) * RAND_MAX;
    return false;
}

int main(){
    ifstream fin("fence3.in");
    ofstream fout("fence3.out");

    fin >> N;
    //int minX = 100, minY = 100, maxX = 0, maxY = 0;
    for(int i = 0; i < N; i++){
        fin >> fence[i].x1 >> fence[i].y1 >> fence[i].x2 >> fence[i].y2;
        if(fence[i].x1 > fence[i].x2) swap(fence[i].x2, fence[i].x1);
        if(fence[i].y1 > fence[i].y2) swap(fence[i].y2, fence[i].y1);
        //if(minX > fence[i].x1) minX = fence[i].x1;
        //if(minY > fence[i].y1) minY = fence[i].y1;
        //if(maxX < fence[i].x2) maxX = fence[i].x2;
        //if(maxY < fence[i].y2) maxY = fence[i].y2;
    }
    // binary search 

    fout << fixed << setprecision(1) << mx << " " << my << " " << min << endl;
    cout << fixed << setprecision(1) << mx << " " << my << " " << min << endl;
}


