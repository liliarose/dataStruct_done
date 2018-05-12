#include <iostream> 
#define HSIZE 4 

using namespace std; 

struct node{
	
	node *next; 
	int value; 
	node(int data = 0){
		value = data; 
		next = nullptr;
	}
};
// hash table

// node* hashTable[HSIZE];

// insert, delete, traverse, reverse, sort

void insert (node *&head, int data, int pos = 0);
bool del(node *& head, int data);
void reverse(node *&head);
void print(node *&head);
// void printMid(node *&head);
node* search(node *head, int key); 
void swap(int &a, int &b);

//hash table functions: insert, delete, search

class hashtable{
	private:
		node* table[HSIZE] = {nullptr};
		int hashf(int val){
			return ((val >> 24) ^ (val >> 8) ^ (val >> 16) ^ val)%HSIZE; 
		}
	public:
		void insert(int key){
			::insert(table[hashf(key)], key); 
		}
		void insert(int arr[], int size){
			for(int i = 0; i < size; i++){
				insert(arr[i]);
			}
		}
		node* search (int key){
			return ::search (table[hashf(key)], key);	
		}
		bool del (int key){
			cout << "deleting " << key << endl;
			return ::del (table[hashf(key)], key); 	
		}
		void print(){
			for(int i = 0; i < HSIZE; i++){
				::print(table[i]);
			}
		}	
};

int main(){
	hashtable* testing = new hashtable();
	int arr[] = {12345677, 2389493, 1943828, 12984, 28347, 3221, 3847};
	testing -> insert(arr, sizeof(arr)/sizeof(int)); 
	testing -> print();
	cout << testing -> del(5677) << endl; 
	testing -> print();
}

/*
void printMid(node *&head){
	node *curr = head;
	node *mid = head;
	int count, midCount = 0; 
	for(count = 0; curr -> next ! = 0;count++){
		
	}
	if(count%2 == 0){
		cout << "Even node, mid doesn't exist";
	}
	cout << mid -> value << endl;
}
*/
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
  //  	cout << data << endl;
		n -> next = curr -> next;
		curr -> next = n;
	}
	//print(head); 
}

bool del(node *& head, int data){
	node * prev = nullptr;
	node *curr = head;
    while(curr != nullptr && curr -> value != data){
		prev = curr; 
		curr = curr -> next; 
	}
	if(curr){
		if(prev == nullptr){
			head = curr -> next;
		}
		else{
			prev = curr -> next; 
		}
		delete curr;
		return true; 
	}
	return false; 
}

void reverse(node *&head){
	if(head == nullptr){
		return; 
	}
	node *prev = head;
    node *curr = prev -> next;
    node *temp;
    while(curr -> next != nullptr){;
        temp = curr -> next;
        curr -> next = prev;
        //reassign
        prev = curr;
        curr = temp;
    }
    curr -> next= prev;
    head -> next = nullptr;
	head = curr;
}

void print(node *head){
    while(head != nullptr){
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << endl;
}

node* search(node *head, int key){
	while(head && head -> value != key){
		head = head -> next; 
	}
	return head; 
}
















