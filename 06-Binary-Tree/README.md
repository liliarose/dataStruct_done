#### `If you don't like how things are, change it! You're not a tree. `

                -- Jim Rohn

Tree (file system)

node: parent, children (at least two children, otherwise it is linked list)
node type: 
leaf: no children (file)
internal node: at least one children (directory)
ancestor: 
descendent: 
root: the ultimate ancestor
siblings: has the same parent

edge: a connection
degree: the number of children
height of tree: height of node, root
depth: 
level: 
forest: a set of disjoint tree
subtree:


binary tree, binary search tree, 

avl tree, splay tree, red-black tree, B-tree 2-3-4 tree: self-balanced tree
segment tree, trie introduction

struct node
{
    int key;
    node *left;
    node *right;
    node(int key):key(key){
        left=nullptr;
        right=nullptr;
    }
};

// tree root
node *root=nullptr;

void visit(node *n) 
{
}

node * insert(node *root)
void inorder(node *root)
void preorder(node *root)
void postorder(node *root)

node * min_value(node *root)
node * max_value(node *root)
int height(node *root)
int size(node *root)

bool is_balanced(node *root)
bool is_bst(node *root)


node * deletenode(node *root)

node *find_next(node *root, int key)
node *find_prev(node *root, int key)

Q1: give an array, build a BST tree (balanced)
node * build_tree(int a[], int size)

Q2: delete binary tree
void delete_tree(node *root)

https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/


