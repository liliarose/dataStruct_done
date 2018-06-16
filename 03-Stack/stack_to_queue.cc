#include <iostream>
#include <stack>

using namespace std;

class squeue{

public:
    void push(const int &val){
        s1.push(val);
    }
    void pop(){
        if(s2.empty()){
            move();
        }
        else{
            s2.pop();
        }
    }
    int &front(){
        if(s2.empty()){
            move();
        }
        return s2.top();
    }
    /*int &back(){
        if(!s1.empty()){
            return s1.top();
        }
        else{
            
        }
    }
    */
    bool empty(){
        return (s1.empty() && s2.empty());
    }
    int size(){
        return (s1.size() + s2.size());
    }


private:
    stack<int> s1, s2;
    void move(){
        if(s1.empty()){
            throw string("empty s1 - can't move s1 to s2");
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
};

int main(){ 
    squeue q; 
    for(int i = 0; i < 10; i++){
        q.push(i);
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}



