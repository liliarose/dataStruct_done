#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct node{
    node *left, *right;
    int key, height;
    node(int n = 0){
        left = nullptr;
        right = nullptr;
        key = n;
        height = 1;
    }
};
void print(node *n);
void print2(node *n);
void bfs(node *n);
node* rebalance(node* root);
int height(node *n){
    if(n == nullptr) return 0;
    return n->height;
}

void visit(node* n);
void visit2(node* n);
node* left_rotate(node* tr){
    node * n = tr-> right;
    tr -> right = n -> left;
    n -> left = tr;
    tr -> height = max(height(tr->right), height(tr->left)) + 1;
    n -> height = max(height(n->right), height(n->left)) + 1;
    return n;
}

node* right_rotate(node* tr){
    node * n = tr -> left;
    tr -> left = n -> right;
    n -> right = tr;
    tr -> height = max(height(tr->right), height(tr->left)) + 1;
    n -> height = max(height(n->right), height(n->left)) + 1;
    return n;
}

bool balanced(node* root){
   //cout << "BALANCED?\n";
   //cout << root->key << endl;
   //cout << height(root -> left) << " ";
   //cout << height(root->right) << endl << endl;
   return abs(height(root -> left) - height(root->right)) <= 1; 
}

//assumes that the key doesn't repeat 
node* insert(node * root, int key){
    if(root == nullptr) {
        root = new node(key);
        return root;
    } else if(root -> key <  key){
        root -> right = insert(root -> right, key);
        /*root -> height = max(height(root->right), height(root->left)) + 1;
        if(!balanced(root)){
            //cout << "Unbalanced right side\n";
            cout << key << " " <<  root -> right -> key << endl;
            if(key < root -> right -> key){
                //cout << "EXTRA\n";
                root -> right = right_rotate(root -> right);
            }   
            root = left_rotate(root);
        } */  
    } else if(root -> key > key) {
        root -> left = insert(root -> left, key);
        /*root -> height = max(height(root->right), height(root->left)) + 1;
        if(!balanced(root)){
            //cout << "Unbalanced left side\n";
            if(key > root -> left -> key){
                //cout << "EXTRA\n";
                root -> left = left_rotate(root -> left);
            }   
            root = right_rotate(root);
        } */  
    }   
    return rebalance(root);
}

/*
node* insert(node * root, int key){
    if(root == nullptr) {
        root = new node(key);
    } else if(root -> key <  key){
        root -> right = insert(root -> right, key);
        root -> height = max(height(root->right), height(root->left)) + 1;
        if(!balanced(root)){
            //cout << "Unbalanced right side\n";
            cout << key << " " <<  root -> right -> key << endl;
            if(key < root -> right -> key){
                //cout << "EXTRA\n";
                root -> right = right_rotate(root -> right);
            } 
            root = left_rotate(root);
        }
    } else if(root -> key > key) {
        root -> left = insert(root -> left, key);
        root -> height = max(height(root->right), height(root->left)) + 1;
        if(!balanced(root)){
            //cout << "Unbalanced left side\n";
            if(key > root -> left -> key){
                //cout << "EXTRA\n";
                root -> left = left_rotate(root -> left);
            }
            root = right_rotate(root);
        }
    }
    return root;
}
*/

int minV(node* n){
   while(n->left != nullptr){
        n = n -> left;
   } 
   return n->key;
}

node* rebalance(node* root){
    root-> height = max(height(root->right), height(root->left)) + 1;
    int t = height(root -> left) - height(root->right);
    if(t  > 1){
        node* tmp = root -> left;
        //cout << root->key << ": left side longer\t" << height(tmp->left) << " " << height(tmp->right) << endl;
        if(height(tmp->right) > height(tmp-> left)){
            //cout <<  root -> left -> key << ": EXTRA\n"; 
            root -> left = left_rotate(root->left);
        }
        return right_rotate(root);
    } else if (t < -1){
        node*tmp = root ->right;
        //cout << root->key << ": right side longer\t" << height(tmp->left) << " " << height(tmp->right) << endl;
        if(height(tmp->right) < height(tmp-> left)){
            //cout << tmp -> left-> key << ": EXTRA\n";
            root -> right = right_rotate(root->right);
        }
        return left_rotate(root);
    }
    return root;
}

node* del(node *root, int key){
    if(root == nullptr) return root;
    if(key == root -> key){
        node* tmp = root;
        //cout << "Deleting " << key << endl;
        if(root -> right == nullptr && root -> right == nullptr){
            //cout << "no children\n";
            delete root;
            root = nullptr;
        } else if(root -> right == nullptr){
            //cout << "only left child\n";
            root = root -> left;
            delete tmp;
        } else if(root -> left == nullptr){
            //cout << "only right child\n";
            root = root -> right;
            delete tmp;
        } else {
            //cout << "2 children\n";
            int t = minV(root -> right);
            root -> key = t;
            root -> right = del(root->right, t);
            return rebalance(root);
        }
        return root;
    } else if(key < root -> key){
        root -> left = del(root -> left, key);
    } else if(key > root -> key){
        root -> right = del(root -> right, key);
    }
    return rebalance(root);

}

void preOrder(node* root){
    if(root!= nullptr){
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void it_preOrder(node* root){
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* n = st.top();
        st.pop();
        visit(n);
        if(n->right != nullptr) st.push(n->right);
        if(n->left != nullptr) st.push(n->left);
    }
    cout << endl;
}

void it_inOrder(node* root);
void it_inOrder1(node* root);

void postOrder(node* root){
    if(root!= nullptr){
        postOrder(root->left);
        postOrder(root->right);
        visit(root);
    }
}

void it_postOrder(node* root){
    stack<node*> st;
    node* curr = root;
    node* prev = root;
    while(curr != nullptr || !st.empty()){
       if(curr != nullptr){
           if(curr->right != nullptr) st.push(curr->right);
           st.push(curr);
           curr = curr -> left;
       } else{ 
           curr = st.top();
           st.pop();
           //cout << "NULLPTR\n";
           if(curr-> right != nullptr && !st.empty() && curr->right == st.top()){
               node*tmp = st.top();
               st.pop();
               st.push(curr);
               curr = tmp;
           } else {
               //cout << "NO children\n";
               visit(curr);
               curr = nullptr;   
           }
       }
    }
    cout << endl;
}
/*
void it_postOrder2(node* root){
    
}*/
int main(){
    node *n = nullptr;
    n = insert(n, 40);
    n = insert(n, 30);
    n = insert(n, 20);
    n = insert(n, 10);
    n = insert(n, 15);
    n = insert(n, 50);
    n = insert(n, 60);
    n = insert(n, 1);
    bfs(n);
    n = del(n, 40);
    n = del(n, 50);
    n = del(n, 15);
    for(int i = 0; i < 10; i++){
        n = insert(n, i);
    }
}

void visit(node* n){
    cout << n -> key << " ";
}

void visit2(node* n){
    cout << n -> key << ": " << n->height << "\t";
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    int N = 1, n = 0, ct = 1;
    while(!q.empty()){
        cout << "level " << ct << ": ";
        for(int i = 0; i < N; i++){
            root = q.front();
            q.pop();
            cout << root->key << " ";
            if(root->right!=nullptr) { q.push(root->right);     n++;}
            if(root->left!=nullptr) { q.push(root->left);     n++;}
        }
        cout << endl;
        N = n, n = 0, ct++;
    }
}

void it_inOrder1(node* root){
    cout << "Printing nodes of " << root -> key << endl;
    node* curr = root;
    while(curr != nullptr){
        if(curr -> left != nullptr){
            node* n = curr->left;
            while(n->right != nullptr && n->right != curr){
                n = n-> right;
            }
            if(n->right == nullptr){
                //cout << "added" << curr->key << endl;
                n->right = curr;
                curr = curr -> left;
            } else {
               //cout << "deleted\n";
               n -> right = nullptr; 
               visit(curr);
               curr = curr -> right;
            }
        } else {
            visit(curr);
            curr = curr->right;
        }
    }
    cout << endl;
}

void it_inOrder(node* root){
    cout << "Printing nodes of " << root -> key << endl;
    stack <node*> st;
    node* curr = root;
    while(curr != nullptr || !st.empty()){
        if(curr == nullptr){
            curr = st.top();
            st.pop();
            visit(curr);
            curr = curr -> right;
        } else {
            st.push(curr);
            curr = curr -> left;
        }
    }
    cout << endl;
}

void print(node *n){
    if(n != nullptr){
        //cout << "left side ";
        print(n -> left);
        cout << n -> key << ": " << n->height << endl;
        //cout << "right side ";
        print(n -> right);
    }
}






