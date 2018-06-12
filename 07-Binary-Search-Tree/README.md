#### `The possible solutions to a given problem emerge as the leaves of a tree, each node representing a point of deliberation and decision. `

binary search tree (contined ...)

void pprint(node *root, int level);

void deletetree(node *root)

node *deletenode(node *root, int key);
recursive (iterative can be late, use or not use dummy node)

iterative inorder/preorder/postorder implementation

DFS: Depth First Search
BFS: Breadth First Search

bfs_traversal(node *root);

bool same tree(node *a, node *b)
path_sum()

http://cslibrary.stanford.edu/110/BinaryTrees.html


Time permited:
AVL tree:

struct node {
    node *left;
    node *right;
    int key;
    int height;
    node(int key) {
        this.key=key;
        left = nullptr;
        right = nullptr;
        height = 1; // only difference from normal BST tree
    }
};

Function call stack frame: (will detailed in the future)

B() {}
A() {B(); ...}

Calling a function B() from function A():
B()    
{
}

A() 
{
    B(); 
    ...
}

Function A:
    push space for the return value
    push parameters
    push the return address
    jump to the function B
Function B:
    push the address of the previous stack frame
    push values of registers that this function uses (so they can be restored)
    push space for local variables
    do the necessary computation
    restore the registers
    restore the previous stack frame
    store the function result
    jump to the return address
Function A:
    pop the parameters
    pop the return value

