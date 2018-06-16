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

double dist(pt a, pt b);
double brf_cl_pt(vector <pt> a);
double lsw_cl_pt(vector <pt> a);
double f_cl_pt(vector <pt> a);

int main(){
	vector <pt> v;
	v.push_back(pt(2, 3));
    v.push_back(pt(12, 30));
    v.push_back(pt(40, 50));
    v.push_back(pt(5, 1));
    v.push_back(pt(12, 10));
    v.push_back(pt(3, 4));
	//v.push_back(pt(3, 5));
	cout << brf_cl_pt(v) << endl;
	cout << lsw_cl_pt(v) << endl;
}

double brf_cl_pt(vector <pt> a){
	double minD = INT_MAX;
	int lim = a.size();
	for(int i = 0; i < lim - 1; i++){
		for(int j = i + 1; j < lim; j++){
			double t = dist(a[i], a[j]);
			if(t < minD){
				minD = t;
			}
		}
	}
	return minD;
}
/*
double lsw_cl_pt(vector <pt> a){
	sort(a.begin(), a.end());
	double minD = dist(a[0], a[1]), lim = a.size();
	set <pt> curr;
	curr.insert(a[0]);
	curr.insert(a[1]);
	for(int i = 2; i < lim; i++){
		for(::set<pt>::iterator it = curr.begin(); (a[i].x - (*it).x) > minD && it != curr.end();){
				//cout << "@ " << "\tErasing: (" << (*it).x << ", " << (*it).y << ")\n";
				curr.erase(it++);
		}
		for(::set<pt>::iterator it = curr.begin(); it != curr.end();it++){
			if(abs( (a[i].y -(*it).y)) < minD){
				double t = dist(a[i], *it);
				if(t < minD){
					minD = t;
					//cout << a[i].x << ", " << a[i].y << "/ " << (*it).x << (*it).y << ": " << t << endl;
				}
			}
			//cout << minD << endl;
		}
		curr.insert(a[i]);
	}
	return minD;
}
*/


double lsw_cl_pt(vector <pt> a){
	sort(a.begin(), a.end());
    double minD = dist(a[0], a[1]), lim = a.size();
    set <pt> curr;
    curr.insert(a[0]);
    curr.insert(a[1]);
    for(int i = 2, j = 0; i < lim; i++){
        for(; j < i && ((a[i].x - a[j].x) > minD) ; j++){
			//cout << "Erasing: " << a[i].x << ", " << a[i].y << "/ " << a[j].x << a[j].y << endl;
		}
		for(int k = j; k < i; k++){
            if(abs( (a[i].y - a[j].y)) < minD){
                double t = dist(a[i], a[j]);
                if(t < minD){
                    minD = t;
                    //cout << a[i].x << ", " << a[i].y << "/ " << a[j].x << a[j].y << ": " << t << endl;
                }
            }
            //cout << minD << endl;
        }
        curr.insert(a[i]);
    }
    return minD;	
}


double dist(pt a, pt b){
	return sqrt((double)(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); 
}




