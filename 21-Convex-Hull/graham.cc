#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
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
		if(y != p2.y) return y < p2.y;
		else {	return x < p2.x; }
	}
};

//pt o;

stack <pt> graham(vector <pt> v); 
bool cmp (pt &a, pt &b);
int orient(pt &a, pt &b, pt &c);
double dist(pt &a, pt &b);
void swap(pt &a, pt &b);
void print(stack <pt> v);
void print(vector <pt> v);


class comparing{
public:
	comparing(pt &p){
		o.x = p.x;
		o.y = p.y;
	}
	bool operator()(pt &a, pt &b){
		int t =  orient(o, a, b); 
		if(t > 0) return true;
    	if(t == 0) return dist(o, a) < dist(o, b); 
    	return false;	
	}
private:
	pt o;
};

void print(pt p){
	cout << "(" << p.x << ", " << p.y << ")\t";
}

int main(){
	vector <pt> v;
	v.push_back(pt(0, 3));
    v.push_back(pt(2, 2));
    v.push_back(pt(1, 1));
    v.push_back(pt(2, 1));
    v.push_back(pt(3, 1));
    v.push_back(pt(0, 0));
	v.push_back(pt(3, 3));
	v.push_back(pt(4, 4));
	v.push_back(pt(0, 4));
	stack <pt> st = graham(v);
	cout << "Printing output:\n";
	print(st);
}

stack <pt> graham(vector <pt> v){
	int l = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i] < v[l])
			l = i;
	}
	swap(v[l], v[0]);
	// print(v[0]); cout << endl;
	comparing cmp(v[0]);
	sort(v.begin() + 1, v.end(), cmp);
	//print(v);
	stack <pt> st;
	st.push(v[0]);
	st.push(v[1]);
	pt curr;
	for(int i = 2; i < v.size(); i++){
		do{
			curr = st.top();
			st.pop();
		}while(orient(st.top(), curr, v[i]) <= 0 && !st.empty());
		st.push(curr);
		st.push(v[i]);
	}
	return st;
}

void print(stack <pt> st){
	while(!st.empty()){
		cout << "(" << st.top().x << ", " << st.top().y << ")" << endl;
		st.pop();
	}
}

void print(vector <pt> v){
	for(int i = 0; i < v.size(); i++){
		print(v[i]);
		cout <<endl;
	}
}

void swap(pt &a, pt &b){
	int x = a.x, y = a.y;
	a.x = b.x;
	a.y = b.y;
	b.x = x;
	b.y = y;
}
/*
bool cmp (pt &a, pt &b) {
	int t = orient(o, a, b);
	cout << "T: " << t << "\t" ;
	print(o);
	print(a);
	print(b);
	cout << endl;
	
	if(t > 0) return true;
	if(t == 0) return dist(o, a) < dist(o, b);
	return false;
}
*/

double dist(pt &a, pt &b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int orient(pt &a, pt &b, pt &c){
    return (a.x - b.x)*(a.y - c.y) - (a.x - c.x)*(a.y - b.y);
}





