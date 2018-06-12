#### `Courage is rightly esteemed the first of human qualities... because it is the quality which guarantees all others. `

                                ―-  Winston S. Churchill

### review of hash table: 

    why use linked list? hash collision
    hash table resizing: shrink or grow hash bucket size
    C++11: unordered_map<T>, unordered_set<T>, unordered_multimap, unordered_multiset, 
    python : dict, set, frozenset  (frozendict ??)  -- mutable or const
    Java: 
    javascript: JSON just like dict in python
    perl : %

### stack implementation: container, adaptor, iterator
    template <typename T, size=128>
    class mystack{  
    public:

    private:
        T arr[size];
    }

### Function call : call stack
    https://en.wikipedia.org/wiki/Call_stack


### Exercise:

    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
    bool isValid(string s)  or
    bool isValid(char s[]) 

### Homework:

    bool isValid(string s)  or
    bool isValid(char s[]) 
    https://leetcode.com/problems/largest-rectangle-in-histogram/description/

