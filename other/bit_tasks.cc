#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <climits> 

using namespace std;
// flip, set, clear

void print(int x){ 
    int count = 0;
    int temp = x;
    while(temp != 0){
        temp /= 2;
        count++;
    }
    
    bool bit[32] = {0}; 
    
    for(int i = 0, temp = x, power; temp > 0; i++){
        power = pow(2, count - i - 1);
        if(temp >= power){
            bit[i] = 1;
            temp -= power;
//          cout << "pow: " << power << "\ti: " << i << endl;
        }
    }
    cout << x << ": ";
    for(int i = 0; i < count; i++){
        cout << bit[i]; 
    }
    cout << endl;
}

 
void bitop(int x, int a, int b){
    print(x);
    int mask = 1;
    //flip 
    //int flipped = x ;
    for(int i = a; i <= b; i++){
        mask = mask << i; 
    }
    
    print(mask);
    //set 
    int set = x | (mask); 
    cout << "setting - ";
    print (set);
    //clear
    cout << "clearing - ";
    int clear = x & (~mask);
    print (clear);
}

int main(){
    bitop(16, 1, 3);    
    //print(11);
    int test = (1 << (4 - 1)) - 1; 
    cout << test << endl;
    return 0;
}

