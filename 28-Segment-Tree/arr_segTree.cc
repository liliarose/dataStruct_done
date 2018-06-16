#include <iostream>
#include <string>
#define MAX 50

using namespace std;

class segtree{

private:
    int tree[MAX], size; 
    void build(int arr[], int s, int e, int id){
        if(s == e){
            tree[id] = tree[s];
        } else {
            int mid = (s+e)/2, t = id*2;
            build(arr, s, mid, t+1);
            build(arr, mid + 1, e, t+2);
            tree[id] = tree[t+1] + tree[t+2];
        }
        //cout << "building: [" << s << ", " << e << "] -> " << tmp-> sum << endl;
    }

public:
    segtree(int arr[], int len){
        size = len;
        root = build(arr, 0, size - 1, 0);
    }

    void update(int id, int diff){
        tree[i] += diff;
        for(int i = 0, s = 0, e = N - 1, mid; s != e; i = 2*i + 1){
            mid = (s+e)/2;
            if(i <= mid){
                e = mid;
            } else {
                i++;    s = mid;
            }
            tree[i] += diff;
        }
    }

    int query(int l, int r){
        
    }
    ~segtree(){
        cout << "deleting tree\n";
    }
};


int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    segtree sg(arr, n);
    cout << "1, 3 : " << sg.query(1, 3) << endl;
    //sg.update(1, 10);
    cout << "1, 3 : " << sg.query(1, 3) << endl;
}


