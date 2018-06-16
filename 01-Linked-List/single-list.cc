#include <iostream> 

using namespace std; 

class list{

    class node{
        node *next;
        int value;
        node(int val = 0){
            val = value;
            next = nullptr;
        }
    }

    void insert (node *&head, int data, int pos){
        node *curr = head;
        node *n = new node(data);
    if(pos == 0 || head != nullptr){
        n->next= head;
        head = n;
    }
    else{
        for(int i = 0; i < pos - 1&& curr->next != nullptr; i++){
            curr = curr -> next;
        }
  //    cout << data << endl;
        n -> next = curr -> next;
        curr -> next = n;
    }
    //print(head); 
    }
}











