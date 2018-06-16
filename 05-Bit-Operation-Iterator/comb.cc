#include <string>
#include <iostream>
using namespace std;

void print(const string &s, string &r, int id = 0);
void print(const string &s);

int main(){
    string a("abcd");
    string r("");
    print(a);
}

void print(const string &s){
    int max = (1 << s.length());
    for(int i = 0; i < max; i++){
        cout << i << ": ";
        for(int j = 0; j < s.length(); j++){
            if(i&(1 << j)){
                cout << s[j];
            }
        }
        cout << "\n";
    }
}


void print(const string &s, string &r, int id){
    if(id == s.length()){
        cout << r << endl;
    }else {
        r.push_back(s[id]);
        print(s, r, id+1);
        r.pop_back();
        print(s, r, id+1);
    }
}


