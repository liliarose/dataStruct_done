#include <iostream>
#include <string>
#define ASIZE 2
#define bMAX 32

using namespace std;
void brf_max(int arr[], int lim);

struct tnode{
    tnode *child[ASIZE];
    tnode(){
        for(int i = 0; i < ASIZE; i++){
            child[i] = nullptr;
        }
    }
};

void insert(tnode *root, int x);
unsigned int find_max(tnode *root, int x);
//void del_tree(tnode *root);

int main(){
    int arr[] = {12, 15, 5, 1, 7, 9, 8, 6, 10, 13};
    int aSize = sizeof(arr)/sizeof(int);
    unsigned int max, tmp;
    //brf_max(arr, aSize);
    tnode root;
    for(int i = 0; i < aSize; i++){
        insert(&root, arr[i]);
        tmp = find_max(&root, arr[i]);
        if(tmp > max) max = tmp;
    }
    cout << max << endl;
}

void insert(tnode *root, int x){
    tnode *tmp = root;
    for(int i = bMAX - 1, id; i >= 0; i--){
        id = ((x >> i)&1); 
        //cout << id;
        if(tmp->child[id] == nullptr){
            tmp->child[id] = new tnode();   
        }
        tmp = tmp->child[id];
    }   
    //cout << endl;
}

unsigned int find_max(tnode *root, int x){
    unsigned int max = 0; 
    tnode *tmp = root;
    for(int i = bMAX - 1, id; i >= 0; i--){
        id = ((~x >> i)&1);
        if(tmp->child[id] != nullptr){
            max += (1 << i);
            tmp = tmp -> child[id];
        } else{
            tmp = tmp -> child[id ^ 1];
        }
    }
    return max;
}


void brf_max(int arr[], int lim){
    int a = 0, b = 0, xr = 0; 
    for(int i = 0; i < lim; i++){
        for(int j = i+1; j < lim; j++){
            int t = arr[i] ^ arr[j];
            if(t > xr){
                xr = t; 
                a = arr[i];
                b = arr[j];
            }
        }
    }
    cout << a << " ^ " << b << ": " << xr << endl;
}





