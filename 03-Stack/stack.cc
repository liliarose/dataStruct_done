#include <iostream>
#include <string>
#include <stdexcept> 
#include <exception>
#include <vector> 
#include <unordered_map>

using namespace std; 

template <typename T>
class mystack{
    public:
        mystack(){
            curr = 0; 
        };
        void push(T &val){
            if(curr <  MAX_SIZE){
                data[curr] = val;
                curr++; 
            }
            else{
                throw string("overflow");
            }
        };
        void pop(){
            if(curr == 0){
                throw string("underflow"); 
            }
            else{
                curr--;
            }
        }; 
        T top(){
            if(curr != 0){
                return data[(curr-1)]; 
            }
            else{
                throw string("empty stack"); 
            }
        };
        int size(){
            return curr; 
        }; 
        bool empty() const{
            return curr == 0; 
        };
    private:
        static const int MAX_SIZE = 128; 
        T data[MAX_SIZE]; 
        int curr; 
};

bool isValid(string str){
    unordered_map <char, char> dict; 
    dict[')'] = '(';
    dict['}'] = '{'; 
    dict[']'] = '[';

    mystack<char> stk;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            stk.push(str[i]); 
        }
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
            if(stk.empty() || dict[str[i]] != stk.top()){
                return false; 
            }
            stk.pop(); 
        }
    }
    return stk.empty(); 
}

int largestRectangleArea(vector<int> &arr){
    mystack<int> stk;
    int max = 0;
    for(int i = 0; i < arr.size(); i++){
        //cout << "reached testing: " << i << " & value: " << arr[i] << endl;
        if(stk.empty() || arr[stk.top()] <= arr[i]){
            stk.push(i);
            //cout << "pushing " << i << endl;  
        }
        else{
            while(stk.size() > 1 && stk.top() > arr[i]){
                int curr = stk.top(), size;
                stk.pop(); 
                //cout << "popped " << curr << endl;
                size = arr[curr] * (curr - stk.top()); 
                if(size > max){
                    max = size;
                }
                //cout << "size: " << size << " & max: " << max << endl;
            }
            stk.push(i);
            //cout << "pushed " << i << endl;
        }
        //cout << endl;
    }
    //cout << "next step" << endl;
    
    while(stk.size() > 1){
        int curr = stk.top(), size;
        stk.pop();
        //cout << "popped " << curr << endl;
        size = arr[stk.top()] * (curr - stk.top()); 
        if(size > max){
            max = size;
        }
        //cout << "size: " << size << " & max: " << max << endl;
    }
    if(stk.top()*arr.size() > max){
        max = stk.top()*arr.size();
    }
    return max;
}

/*
int largestRectangleArea(vector<int> &arr){
    mystack<int> stk; 
    int max = 0; 
    int save[arr.size()]; 
    arr[0] = 0; 
    count = 1; 
    for(i = 1; i < arr.size(); i++){
        if(arr[i] < arr[i-1]){
            arr[count] = i; 
        }
    }
    for(int i = count - 1; i >= 0; i++){
        
    }

}
*/

int main(){
/*  int arr[] = {2, 1, 5, 6, 5, 2, 3};
    vector<int> vec (arr, arr + sizeof(arr)/sizeof(int));
    //cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); i++){
        //cout << vec[i] << " "; 
    }
    //cout << endl;
    try{
        cout << largestRectangleArea(vec) << endl;
    }
    catch(string &str){
        cout << "EXCEPTION: " << str << endl;
*/
}

/*
    cout << isValid("([]() {} ") << endl; 
    cout << isValid("[] () {}}") << endl; 
    mystack <int> stk; 
try{
    for(int i = 0; i < 10; i++){
        stk.push(i); 
    }
    cout << "stack size: " << stk.size() << endl; 
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop(); 
    }
    cout << endl;
    stk.pop();
}
catch(string &str){
    cout << "EXCEPTION: " << str << endl; 
}

try{
    for(int i = 0; i < 140; i++){
        stk.push(i); 
    }
}
catch(string &str){
    cout << "EXCEPTION: " << str << endl; 
}
    cout << stk.empty() << endl; 
    return 0;
*/
}

