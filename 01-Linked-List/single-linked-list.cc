#include <cmath>
#include <iostream>

using namespace std;

struct node{
    node * next;
    node * prev;
    int data;
    node(int val) {key=val; next=nullptr; prev = nullptr; }
}


/*
    - Insertion − Adds an element at the beginning of the list.
    - Deletion − Deletes an element at the beginning of the list.
    - Display − Displays the complete list. — Traverse
    - Search − Searches an element using the given key.
    - Delete − Deletes an element using the given key.
*/

class dlist_rec{
    public:
        dlist_rec(){
            head = nullptr;
            tail = nullptr;
            count = 0;
        }
        void insert(int val){
            if(head == nullptr){
               head->data = val; 
            } else {
               node* t = new node(val);
               t->next = head;
               head->prev = t;
               head = t;
            }
        }
        void deletion(){
            node* t = head;
            head = head -> next;
            delete t;
        }
        void display(){
            node * t = head;
            while(t!= nullptr){
                cout << t->data << " ";
                t = t -> next;
            }
        }
        node* search(int key){
            node* t = head;
            while(t != nullptr && t->data != key){
                t = t->next;
            }
            return t;
        }
        void deleteV(int key){
            node *curr = search(key);
            if(key != nullptr){
                node* pr = curr -> prev;
                node* nxt= curr -> next;
                pr -> next = nxt;
                nxt -> prev = pr;
                delete curr
            }
        }
        ~dlist_rec(){
            cout << "deleting list\n";
            deleteRecur(head);
        }
    private:
        node* head;
        node* tail;
        int count;
};

int main(){

}


