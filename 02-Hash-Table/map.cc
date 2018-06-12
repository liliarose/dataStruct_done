#include <iostream> 
#define HSIZE 4 

using namespace std; 

struct node{
	
	node *next; 
	int value, def; 
	node(int data = 0, int defin = 0){
		value = data; 
		def = defin;
		next = nullptr;
	}
};
// hash table

// node* hashTable[HSIZE];

// insert, delete, traverse, reverse, sort

void insert (node *&head, int data, int defin, int pos = 0);
bool del(node *& head, int data);
void reverse(node *&head);
void print(node *head);
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
		void insert(int key, int def){
			::insert(table[hashf(key)], key, def); 
		}
		void insert(int arr[], int arr_def[], int size){
			for(int i = 0; i < size; i++){
				insert(arr[i], arr_def[i]);
			}
		}
		// searches for value 
		node* search (int key){
			return ::search (table[hashf(key)], key);	
		}
		// deletes by value 
		bool del (int key){
			cout << "deleting " << key << endl;
			return ::del (table[hashf(key)], key); 	
		}
		void print(){
			for(int i = 0; i < HSIZE; i++){
				::print(table[i]);
			}
		}
		int &operator[](int key){
			node * curr = search(key); 
			if(curr){
				return curr -> def; 
			}
			else{
				throw "not found"; 
			}
		}
};

int main(){
	hashtable* testing = new hashtable();
	int arr[] = {12345677, 2389493, 1943828, 12984, 28347, 3221, 3847};
	int arr_def[] = {12345, 29493, 43828, 984, 347, 221, 847};
	testing -> insert(arr, arr_def, sizeof(arr)/sizeof(int)); 
	testing -> print();
	cout << testing -> del(5677) << endl; 
	testing -> print();
	
	cout << (*testing)[12345677] << endl;
	(*testing)[12345677] = 100;
	cout << (*testing)[12345677] << endl;
	testing -> print();
	//cout << (*testing)[12345] << endl; 
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
void insert (node *&head, int data, int defin, int pos){
    node *curr = head;
	node *n = new node(data, defin);
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

void print(node* head){
    while(head != nullptr){
        cout << head -> value << ": " << head -> def << " ";
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
















