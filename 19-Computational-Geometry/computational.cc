#include <iostream>
#include <cmath>

using namespace std;

struct pt{
    int x, y;
    pt(){
        x = 0, y = 0;
    }
    pt(int a, int b){
        x = a, y = b;
    }
    bool operator < (pt &p2) const{
        return x < p2.x;
    }
};
struct vect{
    int dx, dy;
    vect(pt &a, pt &b){
        dx = a.x - b.x;     dy = a.y - b.y;
    }
};
struct line_seg{
    pt start;
    pt end; 
    line_seg(pt &a, pt &b){
        start.x = a.x;      start.y = a.y;
        end.x = b.x;        end.y = b.y;
    }
};

double dist(pt a, pt b);
double pt_line_dist(pt l1, pt p2, pt a);
int cross_product(line_seg, line_seg);
int dot_product(line_seg l, line_seg l2);
double pt_line_seg_dist(line_seg l, pt p);

// >0 ccw, <0 cw, = 0 line
int orient(pt &a, pt &b, pt &c){
    return (a.x - c.x)*(a.y - b.y) - (a.x - b.x)*(a.y - c.y);
}

int main(){
    pt p1(0, 0);
    pt p2(0, 2);
    pt p3(4, -1);
    
    line_seg l(p1, p3);
    line_seg l2(p1, p2);
    cout << orient(p1, p2, p3) << endl;
    cout << cross_product(l, l2) << endl;
    cout << pt_line_dist(p1, p3, p2) << endl;
    cout << pt_line_seg_dist(l, p2) << endl;
}
int cross_product(line_seg l, line_seg l2){
    return (l.start.x - l.end.x)*(l2.start.y - l2.end.y) - (l.start.y - l.end.y)*(l2.start.x - l2.end.x);
}
int dot_product(line_seg l, line_seg l2){
    return (l.start.x - l.end.x)*(l2.start.x - l2.end.x) + (l.start.y - l.end.y)*(l2.start.y - l2.end.y);
}

double pt_line_seg_dist(line_seg l, pt p){
    line_seg l1(l.start, p);
    line_seg l2(l.end, p);
    if(dot_product(l1, l) < 0){
        return dist(l.start, p);
    } else if(dot_product(l1, l) < 0){
        return dist(l.end, p);
    } else {
        return pt_line_dist(l.start, l.end, p);
    }
}

double pt_line_dist(pt l1, pt l2, pt a){
    
    return abs(((l1.y - l2.y)*a.x - (l1.x - l2.x)*a.y + (l1.x*l2.y - l2.x*l1.y))/dist(l1, l2));
}

double dist(pt a, pt b){
    return sqrt((double)(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); 
}




