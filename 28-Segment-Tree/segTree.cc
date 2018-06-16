#include <iostream>
#include <string>

using namespace std;

class segtree{

private:
    struct segnode{
        segnode *left, *right;
        int sum;
        segnode(){
            sum = 0;
            left = nullptr;
            right = nullptr;
        }
    };
    int N; 
    segnode *root;
    segnode* build(int arr[], int s, int e){
        segnode * tmp = new segnode();
        int t = (s+e)/2;
        if(s != e){
            tmp->left = build(arr, s, t);
            tmp->right= build(arr, t+1, e);
            tmp-> sum = tmp->left->sum + tmp->right->sum; 
        } else {
            tmp->sum = arr[s];
        }
        cout << "building: [" << s << ", " << e << "] -> " << tmp-> sum << endl;
        return tmp;
    }

    void update(segnode *n, int s, int e, int id, int diff){
        //cout << "changed: [" << s << ", " << e << "] -> " << n->sum  << " + " << diff << endl;
        n->sum += diff;
        if(s == e) return;
        int t = (s+e)/2;
        if(id <= t ){
            update(n->left, s, t, id, diff);
        } else{
            update(n->right, t+1, e, id, diff);
        }
    }

    int query(segnode *n, int s, int e, int l, int r){
        if(s >= l && e <= r){
            //cout << l << ", " << r << ": [" << s << ", " << e << "] -> " << n->sum << endl;
            return n->sum;
        }
        if(e < l || s > r){  return 0; }
        int t = (s+e)/2;
        return query(n->left, s, t, l, r) + query(n->right, t+1, e, l, r); 
    }
    void deleteTree(segnode * t){
        if(t->left != nullptr && t->left != nullptr){
            deleteTree(t->left);
            deleteTree(t->right);
        }
        cout << "Deleting sum: " << t -> sum << endl;
        delete t;
    }

public:
    segtree(int arr[], int len){
        N = len - 1;
        root = build(arr, 0, N);
    }

    void update(int id, int diff){
        update(root, 0, N, id, diff);
    }

    int query(int l, int r){
        return query(root, 0, N, l, r);
    }
    ~segtree(){
        deleteTree(root);
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


