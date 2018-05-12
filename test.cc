#include <iostream>
#include <iomanip>

using namespace std; 
void f2();
void print_call_stack_frame(unsigned long int * start);
void f1(unsigned long int x){
	unsigned long tmp = 50;
	cout << &x << endl;
	cout << "Function 1 " << x << endl;
	cout << "Function 1 " << (void *) f1<< endl;
	cout << "Function 2 " <<  (void *) f2 << endl;
}

void f2(){
	cout << "fun2, but not called\n";
}

void f0(){
	f1(100);
	cout << "returning from func1\n";
}

int main(){
	
	f0();
	print_call_stack_frame((unsigned long int *)f1);
	return 0;
}

void print_call_stack_frame(unsigned long int * start){
	start += 16; 
	for(unsigned long int i = 0; i < 32; i++){
		cout << setfill('0') << hex << start << ":" << setfill('0') << hex << *start << endl;
		start --;
	}
}

