#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath> 

using namespace std; 


class bst{
private: 
struct node{
    int key; 
    node * left;
    node * right;
    node (int val = 0){
        key = val;
        left = nullptr; 
        right = nullptr; 
    }
};
node * root;

public:

bst(node * n = nullptr){
    root = n;
}

node * insert(int val, node *tmp = this -> root){
    if(tmp == nullptr){
        tmp = new node(val);
    } 
    else if(tmp -> key > val){
        tmp -> left = insert(tmp -> left, val);
    }
    else if(tmp -> key < val){
        tmp -> right = insert(tmp -> right, val);
    }
    return tmp; 
}

void visit(node* n){
    cout << n -> key << " ";
}
/*
void print(node * root){
    queue <int> tmp;
    node * curr = root; 
    if(root != nullptr)
        do{
            tmp         
        }while(!tmp.empty);
    }
}
*/

/*
void preorder(node *n = root){
    if(n != nullptr){
        visit(n);
        preorder(n -> left); 
        preorder(n -> right);
    }
}

void preorder_it(node *n = root){
    stack <node *> st; 
    while(root != nullptr || !st.empty()){
        if(root != nullptr){
            visit(root);
            st.push(root);
            root = root -> left;
        }
        else{
            root = st.top();
            st.pop();
            root = root -> right;
        }
    }
    cout << endl;
}

void postorder(node *root){
    if(root != nullptr){
        postorder(root -> left);
        postorder(root -> right);
        visit(root);
    }
}

void postorder_it(node *root){
    stack<node *> st; 
    node * flag;
    while(root != nullptr || !st.empty()){
        if(root != nullptr){
            st.push(root); 
            root = root -> left;
        } else{
            node * tmp = st.top();
            if(tmp -> right == nullptr || tmp -> right == flag){
                visit(tmp);
                flag = tmp; 
                st.pop();
            } else{
                root = tmp -> right;
            }
        }
    }
    cout << endl;
}

void inorder(node *root){
    if(root != nullptr){
        inorder(root -> left);
        visit(root);
        inorder(root -> right);
    }
}

void inorder_it(node * root){
    stack<node *> st; 
    while(root != nullptr || !st.empty()){
        if(root != nullptr){
            st.push(root);
            root = root -> left;
        }
        else{
            root = st.top();
            st.pop();
            visit(root);
            root = root -> right;
        }
    }
    cout << endl;
}

node * min_val(node *root){
    node * curr = root;
    if(curr != nullptr){
        while(curr -> left != nullptr){
            curr = curr -> left; 
        }
    }
    return curr; 
}

node * max_val(node *root){
    node * curr = root;
    if(curr != nullptr){
        while(curr -> right != nullptr){
            curr = curr -> right; 
        }   
    }
    return curr; 
}

int height(node *root){
    if(root == nullptr) return 0; 
    int l = height(root -> left);
    int r = height(root -> right);
    return (l > r) ? (l+1): (r+1);
}

int size(node *root){
    if(root == nullptr) return 0;
    return size(root -> left) + size(root -> right) + 1;
}

bool bal (node *root){
    int l = height(root -> left);
    int r = height (root -> right);
    return (abs(l-r) <= 1);
}
*/
/*
bool is_bst(node *root){
    queue <int> tmp;
    put_in(root, tmp);
    while()
}

void put_in(node *curr, queue &tmp){
    if(curr != nullptr){
        put_in(curr -> left, tmp);
        tmp.push(curr -> key);
        put_in(curr -> right, tmp);
    }
}
*/

/*
node * del_node(node * root, int val){
    int * key = search(val);
    if(root != nullptr){
    
    }
}
*/
/*
node * find_next(node* root, int val){
    node * tmp = nullptr;
    node * curr = root;
    while(curr != nullptr){
        if(curr -> key == val){
            if(curr -> right == nullptr){
                return tmp; 
            }
            return min_val(curr -> right); 
        } 
        else if(curr -> key < val) 
            curr = curr -> right;
        else{
            tmp = curr;     
            curr = curr -> left;
        }
    }
    return nullptr;
}


bool is_bst(node *curr, int max = INT_MAX, int min = INT_MIN){
    if(curr != nullptr){
        bool i = is_bst(curr -> left, curr -> key, INT_MIN);
        bool k = is_bst(curr -> right, INT_MAX, curr -> key);
        return ((curr -> key > min) && (curr -> key < max) && i && k);
    }
    return true;
}

void deletetree(node *root){
    if(root != nullptr){
        deletetree(root -> left);
        deletetree(root -> right);
        delete root;
    }
}

node* search(node *root, int key){
    node * curr = root; 
    while(curr != nullptr){
        if(curr -> key == key){
            return curr; 
        } else if(curr -> key > key){
            curr = curr -> left; 
        } else{
            curr = curr -> right; 
        }
    }
    return nullptr;
}*/
/*
node *deletenode(node *root, int key){
    node * curr = root, prev, temp;
    while(curr != nullptr){
        if(curr -> val == key){
            break;
        }
        prev = curr;
        if(curr -> val > key){
            curr = curr -> left;
        } else {
            curr = curr -> right;
        }
    }
    if(curr == nullptr) return root;
    if(curr -> right != nullptr){
        tmp = min_val(curr -> right);
    }
    else{ 
        tmp = max_val(curr -> left);
    }
    if(curr == root){
        return 
    }
}

node *deletenode(node *root, int val)
{
    node *cur=root;
    
    node **parent=nullptr;
    while(cur) {
        if(cur->key==val) {
            if(cur->left&&cur->right) {
                node *n=max_val(cur->left);
                cur->key = n->key;
                //cur->left = deletenode(cur->left, cur->key);
                cur=cur->left;
                val = n->key;
            } else {
                if(parent) {
                    *parent = (cur->left)?cur->left:cur->right;
                } else {
                    root = (cur->left)?cur->left:cur->right;
                }
                delete cur;
            }
        } else if(cur->key < val){
            cur =cur->right;
            parent = &(cur->right);
        } else {
            cur = cur->left;
            parent = &(cur->left);
        }
    }

    return root;
}
*/
/*
node *deletenode(node *root, int val)
{
    node *cur=root;
    node *n = new node(val);

    while(cur) {
        if(cur->key==val) {
            return root;
        } else if(cur->key < val){
            if (cur->right == nullptr) {
                cur->right =n;
                break;
            } else {
                cur =cur->right;
            }
        } else {
            if (cur->left == nullptr) {
                cur->left =n;
                break;
            } else {
                cur =cur->left;
            }
        }
    }   

    return cur?root:n;
}
*/
/*
node *deletenode(node *root, int val){
    if(root == nullptr) return nullptr; 
    if(root -> key == val){
        node * tmp = nullptr; 
        if(root -> right != nullptr && root -> left != nullptr){
            tmp = max_val(root -> left);
            root -> key = tmp -> key; 
            root -> left = deletenode(root -> left, tmp -> key);
        } else{
            if(root -> right != nullptr){
                tmp = root -> right;        
            } else if(root -> left != nullptr){
                tmp = root -> left;
            }
            delete root; 
            return tmp; 
        }
    } else if(root -> key < val){
        root -> right= deletenode(root -> right, val);
    } else{
        root -> left = deletenode(root -> left, val);
    }
    return root; 
}
*/
/*
void pprint2(node *root){
    int h = height(root), thislvl = 1;
    node * curr = root;
    queue <node *> tmp;
    for(int i = 0, space; i < h; i++){
        for(int k = 0; k < thislvl; k++){
            cout << 
        }
    }    
}
*/
/*
bool st(node *a, node*b);

bool same_tree(node *a, node *b){
    if(a == nullptr && b == nullptr){
        return true;        
    }else{
        int h1 = height(a); 
        int h2 = height(b);
        if(h1 == h2){
            return st(a, b);
        }
        else if(h1 > h2){
            node * tmp = search(a, b -> key);
            if(tmp != nullptr){
                return st(tmp, b);
            }
            return false;
        }
        else{
            node * tmp = search(b, a -> key);
            if(tmp != nullptr){
                return st(tmp, a);
            }
            return false;
        }
    }
    return false; 
}
bool st(node *a, node*b){
    if(a == nullptr && b == nullptr) return true; 
    if(a -> key == b -> key){
        return st( a-> left, b -> left) && st (a -> right, b -> right);
    }
    return false;
}

void pprint2(node *root, int indent = 0){
    if(root -> right != nullptr){
        pprint2(root -> right, indent +1);
    }
    for(int i = 0; i < indent; i++){
        cout << "\t";
    }
    cout << root -> key << endl;
    if(root -> left != nullptr){
        pprint2(root -> left, indent +1);
    }
}
void bfs_print(node *root){
    queue <node*> tmp;
    node * curr = root;
    tmp.push(root);
    while(!tmp.empty()){
        curr = tmp.front();
        tmp.pop();
        cout << curr -> key << " ";
        if(curr -> left != nullptr){
            tmp.push(curr -> left);
        }
        if(curr -> right != nullptr){
            tmp.push(curr -> right);
        }
    }
    cout << endl;
}
*/
};

int main(){
    int arr[] = {1, 2, 4, 6, 7, 10, 13, 14};
    //node * tree_root = nullptr;


    tree_root = insert(tree_root, 8); 
    tree_root = insert(tree_root, 3);
    tree_root = insert(tree_root, 10);
    tree_root = insert(tree_root, 1);
    tree_root = insert(tree_root, 6);
    tree_root = insert(tree_root, 4);
    tree_root = insert(tree_root, 14);
    tree_root = insert(tree_root, 7);
    tree_root = insert(tree_root, 13);
    
    bfs_print(tree_root);
    pprint2(tree_root);
    cout << "preorder: " << endl;
    preorder(tree_root);
    cout << endl;
    preorder_it(tree_root);
    cout << "postorder: " << endl; 
    postorder(tree_root);
    cout << endl;
    postorder_it(tree_root);
    cout << "inorder: " << endl;
    inorder(tree_root);
    cout << endl;
    inorder_it(tree_root);
/*
    node * temp = min_val(tree_root);
    cout << temp -> key<< endl;
    temp = max_val(tree_root);
    cout << temp -> key << endl;
    cout << height(tree_root) << endl;
    cout << size (tree_root) << endl;
    cout << bal(tree_root) << endl;
    cout << is_bst(tree_root) << endl;
*/
}





