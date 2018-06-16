#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#define INF INT_MAX
#include <algorithm>

using namespace std;

struct pt{
	int x, y;
	pt(){
		x = 0, y = 0;
	}
	pt(int a, int b){
		x = a, y = b;
	}
	bool operator < (const pt &p2) const{
		return x < p2.x;
	}
};

void jarvis(vector <pt> v);

int orient(pt &a, pt &b, pt &c);

int main(){
	vector <pt> v;
	v.push_back(pt(0, 3));
    v.push_back(pt(2, 2));
    v.push_back(pt(1, 1));
    v.push_back(pt(2, 1));
    v.push_back(pt(3, 0));
    v.push_back(pt(0, 0));
	v.push_back(pt(3, 3));
	jarvis(v);
}

void jarvis(vector <pt> v){
	int lim = v.size(), l = 0;
	for(int i = 1; i < lim; i++){
		if(v[i].x < v[l].x)	l = i;
	}
	vector <pt> res;
	int a = l, b;
	do{
		b = (a+1)%lim;
		for(int c = 0; c < lim ; c++){
			if(orient(v[a], v[b], v[c]) > 0){
				b = c;
			}
		}	
		res.push_back(v[a]);
		a = b;
	}while(a != l);
	//cout << "Entering output\n";
	for(int i = 0; i < res.size(); i++){
		cout << res[i].x << ", " << res[i].y << endl;
	}
}



int orient(pt &a, pt &b, pt &c){
    return (a.x - c.x)*(a.y - b.y) - (a.x - b.x)*(a.y - c.y);
}





