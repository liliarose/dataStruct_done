#include <iostream>
#include <string>
#include <stdexcept> 
#include <exception>
#include <list> 
#include <unordered_map>

using namespace std; 

struct node{
	node *next;
	int value; 
	node(int data = 0){
		value = data;
		next = nullptr; 
	}

};

void hanoi(int n, char from, char to, char via, int step = 0);

class myqueue{
	public:
		myqueue(){
			count = 0;
			head = nullptr; 
			tail = nullptr;
		}
		void push(int &val){
			if(count != 0){
				tail -> next = new node(val);
				tail = tail -> next;
			}
			else{
				head = new node(val);
				tail = head; 
			}
			count++;
		}
		void pop(){
			if(count == 0){
				throw string("empty queue- can't pop");
			}
			else if(count == 1){
				delete head; 
				head = nullptr; 
				tail = nullptr; 
			}
			else{
				node * n = head; 
				head = head -> next; 
				delete n; 
			}
			count--;
		}
		int& front(){
			if(count != 0)
				return head -> value;
			else
				throw string("empty queue - can't return front value");
		}
		int& back(){
			if(count != 0)
				return tail -> value;
			else
				throw string("empty queue - can't return back value");
		}
		bool empty() const {
			return count == 0; 	
		}
		int size() const{
			return count; 
		}
		void swap(myqueue &other){
			node *temp = other.head; 
			other.head = this->head; 
			head = temp; 

			temp = other.tail; 
			other.tail = this->tail; 
			tail= temp;

			int t = other.count; 
			other.count = this->count; 
			count = t;
			return;
		}
		~myqueue(){
			cout << "destructing: ";
			while(!empty()){
				cout << front() << " ";
				pop();
			}
			cout << endl;
		}

	private:
		node *head, *tail; 
		int count;
};

void print(myqueue &q){
	int size = q.size(); 
	for(int i = 0, temp; i < size; i++){
		temp = q.front();
		cout << temp << " ";
		q.pop();
		q.push(temp);
	}
	cout << "\n";
}

int main(){
	myqueue a, b;
	for(int i = 0; i < 10; i++){
		a.push(i);
	}
	for(int i = 11; i < 20; i++){
		b.push(i);
	}
	/*cout << a.empty() << endl;
	print(a);
	print (b);
	cout << "swapping" << endl;
	a.swap(b);
	print(a); 
	print(b);
//	delete a; 
//	delete b;
	*/
	hanoi(3, 'A', 'B', 'C');
	cout << "address of a: " << a << "\taddress of b: " << b<< endl;
}



void hanoi(int n, char from, char to, char via, int step){
	if(n == 1){
		cout << "Step " << step << ": move " << n << " from " << from << " to " << to << endl;
		return;
	}
	else{
		hanoi(n-1, from, via, to, step +1);
		cout << "Step " << step << ": move " << n << " from " << from << " to " << to << endl;
		hanoi(n-1, via, to, from, 2*step +1);
	}
}
