#### `I am a slow walker, but I never walk back. `

              -- Abraham Lincoln

# Linked List

### Types of Linked List
#### Following are the various types of linked list.
    - Simple Linked List − Item navigation is forward only.
    - Doubly Linked List − Items can be navigated forward and backward.
    - Circular Linked List − Last item contains link of the first element as next and the first element has a link to the last element as previous.

### Basic Operations
#### Following are the basic operations supported by a list.
    - Insertion − Adds an element at the beginning of the list.
    - Deletion − Deletes an element at the beginning of the list.
    - Display − Displays the complete list. — Traverse
    - Search − Searches an element using the given key.
    - Delete − Deletes an element using the given key.

### Code:

    class  node 
    {
        public:
        node *next;
        int key;
        int data;  // maybe more
        node(int val) {key=val; next=nullptr;}
    };

### API designed:
    void insert(node *&head, int key, int pos=0)
    void delete(node *&head, int key)
    void reverse(node *&head)

### Problem:

    - How to implement the following API:
    - All APIs takes head pointer (not reference) as the formal parameter, and all return the head of new list.

    node * insert(node *head, int key, int pos=0);
    node * delete(node *head, int key);
    node *  reverse(node *head);

### Usage can be:

    node *head;

    head = insert(head, key, 0);
    head = delete(head, key);
    head = reverse(head);

