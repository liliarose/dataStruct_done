#### `Learning without thought is labor lost.`

            -- Confucius

### Bit operation

    set, clear, flip the bits at location [a, b) for variable x
    def manip_bit(a,b,x):
        bitmask= (1<<(b-a)) -1
        bitmask <<= a
        print bin(bitmask)
        print bin(x)
        y=x|bitmask
        print "\nset bits"
        print "x: " + bin(x)
        print "y: " + bin(y)
        y=x&~bitmask
        print "\nclear bits"
        print "x: " + bin(x)
        print "y: " + bin(y)
        y=x^bitmask
        print "\nflip bits"
        print "x: " + bin(x)
        print "y: " + bin(y)

## doubly linked list

    struct node {
        node *next, *prev;
        int key;
        node(int x=0): key(x) {
            //key =x; 
            next=prev=nullptr;
        }
        
    };

    Implement doubly-linked list template class:

    template<typename T>
    class dlist
    {
    public:
        dlist() {}
        virtual ~dlist() {}
        void insert(int pos, int val) {    }
        void erase(int pos=0) {    }
        bool remove(int val) {    }
        int& front() {    }
        int& back() {    }
        bool empty() {    }
        int size() {    }
        void swap(dlist & other) {    }

    private:
        node * head, *tail;
        int count;
    };

    void testcase1()
    {
    }

    void testcase2()
    {
    }

    #define DLINK_TEST 1
    #if DLINK_TEST
    int main() 
    {
        testcase1();
        return 0;
    }
    #endif

### circular arrary/linked list

#### circular linked list:

    node *head, * tail, 
        operation: insertion, deletion, display, find, size(), empty()
        https://www.geeksforgeeks.org/circular-linked-list/

#### circular array:

    int head, tail (mod operation %arraysize)
        https://www.geeksforgeeks.org/circular-array/


### C++ iostream:

    fstream, ifstream, ofstream: all derived from basic stream
    redirect: cin(filename), cout(filename)
    ifstream(filename), ofstream(filename)

### python input: 
    input(), raw_input(), print, __str__, __repr__
    help(int), print(int.__doc__, __module__, __dict__, __base__, __name__)
    print json.dumps(a, sort_keys=True, indent=4)
    Anything is object: int is a class.  Is bin a object, class?
    Is funtion, class also object? 
    Python data model: type() object
    private member function? _xxx, __yyy
    operator overloding? __add__(...)

### Exercise: 

    1. Write a program that prompt user to input two integers.  Then compute the sum of two integers.  If the sum is a multiple of 5, display "HiFive".  If it is divisible by 2, display "HiTwo".  Otherwise display "HiOther". 
    2. home of range: file
    3. shopping

### Compiler g++:
    g++ and memory map script for ld: 
        sections: text, data, bss, self-defined "bar"
        extern void foobar (void) __attribute__ ((section ("bar")));
        stack, heap (not a section, but system wide)
    different stage: -E, -S, -c 
    output option: -o
    memory sections: text, bss, data, stack, heap

### Summary of data structure:

    circular linked list: https://www.geeksforgeeks.org/circular-linked-list/
    circular array:  https://www.geeksforgeeks.org/circular-array/

    singly linked list: https://www.geeksforgeeks.org/linked-list-set-1-introduction/
    doubly linked list: https://www.geeksforgeeks.org/doubly-linked-list/

    queue:  https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
    stack: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/

    hash table: https://www.geeksforgeeks.org/hashing-set-1-introduction/
    https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/

    array, string (array of character), matrix, multi-dimensional array

### Preview:

binary search tree: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
