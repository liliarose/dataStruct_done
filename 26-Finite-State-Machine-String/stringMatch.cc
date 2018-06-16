#include <cstring>
#include <iostream>

using namespace std;

void print(int arr[], int lim);
void find(char * str, char * key);
void kmp(char * str, char * key);


int main(){
    char s1[10];
    char s2[100];
    cin >> s1;
    cin >> s2;
    for(int i = 0; i < strlen(s2); i++){
        cout << i;
    }
    cout << endl;
    kmp(s2, s1);
}

void prep(char * p, int *pl){
    int lim = strlen(p), i = 0, j = 2;
    pl[0] = -1;
    pl[1] = 0;
    while(j < lim){
        while(i >= 0 && p[i] != p[j]){
            i = pl[i];
        }
        j++;     i++;
        pl[j] = i;
    }
}

void kmp(char * str, char * key){
    int a = strlen(str), b = strlen(key);
    int pl[b+1];
    prep(key, pl);
    //print(pl, b+1);
    for(int i = 0, k = 0; i < a;){
        while(k >= 0 && key[k] != str[i])
            k = pl[k];
        i++, k++;
        //cout << "Not matched: " << i << ": " << str[i] << "\t" << k << ": " << key[k] << endl;
        if(k == b){
            cout << "Matched: " << i - k << endl;
        }
    }

}

void print(int arr[], int lim){
    for(int i = 0; i < lim; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//hash brute force 

//brute force
void find(char * str, char * key){
    int a = strlen(str);
    int b = strlen(key);

    for(int i = 0, j; i < a; i++){
        for(j = 0; j < b; j++){
            if(str[i+j] != key[j]) break;
        }
        if(j == b){
            cout << i << endl;
        }
    }

}


