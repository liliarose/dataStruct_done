#### `An Englishman, even if he is alone, forms an orderly queue of one.`

            -- George Mikes

### queue: Using linked list or circular array.

    using namespace std;

    class myqueue {
    public:
        queue();
        void push(int &val);
        void pop();
        int &front();
        int &back();
        bool empty() const;
        int size() const;
        swap(myqueue & other);

    private:
        node *head, *tail;
        node dummy;  //use as dummy
        int count;
    };

### Stack revisited:

    where is the top/bottom of stack? 
    different stack interface: C++ STL(pop, top), Java stack(pop, peek)

    function call stack:  stack frame structure 
    https://en.wikipedia.org/wiki/Call_stack

#### global static, auto variable,

#### function call
    recursive call: space complexity O(depth)
    hanoi tower:  
    https://www.mathsisfun.com/games/towerofhanoi.html

    //print all steps
    void hanoi(int n, char fr om, char to, char via)
    {
    }

    recursive call/iterative call
    iterative call

### dynamic programming
https://stackoverflow.com/questions/1065433/what-is-dynamic-programming



