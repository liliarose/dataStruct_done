#include <iostream>

using namespace std; 

struct node{
    node * prev;
    node * next; 
    int key; 
    node(int x = 0){
        key = x; 
        next = nullptr;
        prev = nullptr; 
    }
};

class dlist{
private:
    node *head;
    node *tail;
    int count;
    void del(node * curr){
        if(curr  == head){
            head = curr-> next;
            head -> prev = nullptr;
        }
        else if(curr == tail){
            tail  = curr -> prev; 
            tail -> next = nullptr; 
        }
        else{
            node * temp = curr -> prev; 
            temp -> next = curr -> next; 
            temp = curr -> next; 
            temp -> prev = curr -> prev; 
        }
        if(head == nullptr){
            tail = nullptr; 
        }
        delete curr; 
        count--; 
    }

public: 
    dlist(){
        head = nullptr; 
        tail = nullptr; 
        count= 0; 
    }
    class iterator{
    public:
        iterator(node * n = nullptr){
            curr = n;
        }
        bool operator != (iterator &o) const{
            return (curr != o.curr);
        }

        iterator &operator ++(){
            curr = curr -> next;
            return *this;
        }
        int operator *(){
            return curr -> key;
        }
        iterator &begin(){
            return iterator(head);
        }
        iterator &end(){
            return iterator(tail);
        }
    private:
        node *curr;
    };

    int &front(){
        if(count != 0)
            return (head -> key);
        else
            throw "front: empty list";
    }
    int &back(){
        if(count != 0)
            return (tail -> key);
        else 
            throw "back: empty list";
    }
    void insert(int &val, int pos = 0){
        node * add = new node(val);
        node * temp = head;
        if(count == 0){
            head = add; 
            tail = head; 
        }
        else if(pos <= 0){
            head -> prev = add;
            add -> next = head; 
            head = add;
        }
        else if(pos > count || count == 1){
            tail -> next = add; 
            add -> prev = tail; 
            tail = add; 
        }
        else{
            for(int i = 0;i < pos && i < count; i++){
                temp = temp -> next;
            }
            add -> next = temp -> next; 
            add -> prev = temp; 
            temp -> next = add; 
            temp = add -> next; 
            temp -> prev = add; 
        }
        count++;
    }
    void erase(int pos = 0){
        if(count > 0 && count >= pos){
            node *curr = head; 
            for(int i = 0; i < pos; i++){
                curr = curr -> next;
            }
            del(curr);
        }
        else{
            throw "erase: out of bounds";
        }
    }
    bool remove(int &val){
        if(count > 0){
            node *curr = head;
            while(curr != nullptr){
                if(curr -> key == val){
                    del(curr);
                    return true; 
                }
                curr = curr -> next;
            }
            return false; 
        }
        else{
            throw "remove: out of bounds";
        }
    }
    bool empty(){
        return (count == 0);
    }
    int size(){
        return count; 
    }
    void swap(dlist &other){
        node * thead = other.head;
        node *ttail = other.tail;
        int t = other.count; 

        head = other.head; 
        tail = other.tail;
        count = other.count;
        
        other.head = thead;
        other.tail = ttail;
        other.count = t;
    }
    void print(){
        node * curr = head; 
        while(curr != nullptr){
            cout << curr -> key << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
    ~dlist(){
        cout << "Destructing\n"; 
    }
};

int main(){
    dlist l1; 
    dlist l2; 
    for(int i = 0; i < 5; i++){
        l1.insert(i);
    }
    for(int i = 5; i < 10; i++){
        l2.insert(i); 
    }
    l1.print();
    l2.print();
    return 0;
}

