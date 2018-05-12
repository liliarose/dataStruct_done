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
			node *left, *right; 
			node (int val = 0){
				key = val;
				left = nullptr; 
				right = nullptr;
			}
		};
		node * root;
		node * insert(node * tmp, int val){
			if(tmp == nullptr){
				tmp = new node(val);
			} else if(tmp -> key > val){
				tmp -> left = insert(tmp -> left, val);
			} else if(tmp -> key < val){
				tmp -> right = insert(tmp -> right, val);
			}
			return tmp;
		}
	public: 
		bst(){
			root = nullptr;
		}
		void insert(int val){
			insert(root, val);
		}
		void visit(node * n){
			cout << n -> key << " ";
		}
		void inorder_it(){
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
};

int main(){
	int arr[] = {1, 2, 4, 6, 7, 10, 13, 14};
	//node * tree_root = nullptr;
	bst b;
	b.insert(10);
	for(int i = 3; i >= 0; i++){
		b.insert(10+i);
		b.insert(10-i);
	}
	/*for(bst::iterator it = b.begin(); it != b.end(); ++it){
		cout << *it << " ";
	}*/

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



