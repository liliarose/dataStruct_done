#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int BASE = 1000000000; //9 0s
const int BWID = 10;
const int ZERO = 48;
int dig[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};


class bigNum{
public:
    bigNum(){
        for(int i = 0; i < BWID; i++){
            num[i] = 0;
            len = 1;
        }
    }
    
    bigNum(const string &str){
        int lim = str.size();
        len = lim/9;
        if(lim%9 != 0){
            len++;
        }
    for(int i = lim -1, k = 0; k < len; k++){
            num[k] = 0;
            for(int j = 0; j < 9 && i >= 0; j++, i--){
//              cout << "j: " << j << "\t";
//              cout << str[i] << "\t" << (((int)str[i] - ZERO)*dig[j]) << endl;
                num[k] += (((int)str[i] - ZERO)*dig[j]);
            }   
        }
    }
    bigNum(const int &i){
        len = 1;
        num[0] = i;
    }

    bigNum &operator + (const bigNum &x){
        int carry = 0, i;
        bigNum *t = new bigNum();
        t->len = (len > x.len) ?(len):(x.len);
        //cout << t->len << endl;
        
        for(i = 0; i < t->len; i++){
            t->num[i] = num[i] + carry + x.num[i];
            //cout << "before: " << t->num[i] << "\nafter: ";
            carry = 0;
            if(t->num[i] >= BASE*2) {
                carry = 2;
                t->num[i] -= BASE*2;
            } else if(t->num[i] >= BASE){
                carry = 1; 
                t->num[i] -= BASE;
            }
            //cout << t->num[i] << "\n\n";
        }
        if(carry != 0){
            t->num[t->len] = carry;
            t->len++;
        }
        return *t;
    }

    void print(){
        cout << num[len -1];
        for(int i = len - 2; i >= 0; i--){
            cout << setfill ('0') << setw(9) << num[i];
        }
        cout << endl;
    }
    
    ~bigNum(){
        //cout << "deleted: ";
        //this->print();
    }

private:
    int num[BWID], len;
};

int main(){
    bigNum t1;
    string str = "abcd";
    int base = 256;
    for(int i = str.size() -1, b = 1; i >= 0; i--){
         bigNum t2(((int)str[i]*b));
         cout << str[i] << ": ";         
         t2.print();
         cout << b << "\n\n";
         t1 = t1 + t2; 
         b *=base;
    }
    t1.print();
    //cout << "1111111111111111111111110\n";
}



