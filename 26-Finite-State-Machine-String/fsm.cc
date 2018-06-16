#include <cstring>
#include <iostream>
#define MAX_E 128

int transition(char *pat, int state, int event);
void build_FSM(char *pat, int fsm[][MAX_E]);
void search(char *pat, char *txt);

using namespace std;

int main(){
    char str[100]; 
    char str2[1000];
    cin >> str;
    cin >> str2;
    search(str, str2);
}

int transition(char *pat, int l, int state, int event){
    if(state < l && pat[state] == event){
        return state + 1;
    }
    for(int i = state - 1, k; i >= 0; i--){
        if(pat[i] == event){
            for(k = 0; k < i; k++){
                if(pat[k] != pat[state-i+k]){
                    break;  
                }
            }
            if(k == i){
                return i + 1;   
            }
        }
    }
    return 0;
}
void build_FSM(char *pat, int l, int fsm[][MAX_E]){
    for(int i = 0; i <= l; i++){
        for(int k = 0; k < MAX_E; k++){
            fsm[i][k] = transition(pat, l, i, k);
        }
    }
}

void print(int fsm[][MAX_E], int lim, char c){
    for(int i = 0; i <= lim; i++){
        cout << fsm[i][((int)c)] << " ";
    }
    cout << endl;
}

void search(char *pat, char *txt){
    int lim = strlen(pat);
    int limT = strlen(txt);
    int fsm[lim + 1][MAX_E];
    build_FSM(pat, lim, fsm);
    /*print(fsm, lim, 'A');
    print(fsm, lim, 'C');
    print(fsm, lim, 'G');
    print(fsm, lim, 'T');
    */
    int state = 0;
    for(int i = 0; i < limT; i++){
        state = fsm[state][((int)txt[i])];
        if(state == lim){
            cout << i +1 - lim << endl;
        }
    }

}












