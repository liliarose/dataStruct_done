#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*First public-key cryptosystem: public-private key pair (e, d) and big number n 
encryption:  (m**e) mod n
decryption:  (m**d) mod n

Find the public-private key pair (e, d):
1. choose two prime number p and q
2. n=p*q
3. compute totient = (p-1)*(q-1) or lcm((p-1)(q-1))
4. choose a number e (1<e<totient), which is co-prime with totient: gcd(e, totient) = 1, or e=(totient)**(-1)
5. choose a d such that (e*d) mod totient =1, or we can say d=1/e (mod totient)
Now we have public key (e, n) and private key(d, n).

rule of thumb: e is smaller, and d is bigger, which means d is more difficult to be cracked down.
*/

int e, d, n;

int modp(int x, int pow, int n);
//int crypt(int m, int d, int n);
int gcf(int a, int b);
int lcm(int a, int b);
void keyGen(int p, int q);

int main() {
    //modp(2, 2, 6);
    keyGen(23, 89);
    int m = 12;
    int pub_m = modp(m, e, n);
    int prv_m = modp(pub_m, d, n);
    cout << "message" << endl;
    cout << m << endl;
    cout << pub_m << endl;
    cout << prv_m << endl;
}
/*
int crypt(int m, int d, int n){
    for(int i `)
}
*/

void keyGen(int p, int q){
    n = p * q;
    int tt= lcm(p-1, q-1);
    for(e = 3; e < tt; e++){
        if(gcf(e, tt) == 1) break;
    }
    for(d = e+1; d < tt; d++){
        //cout << (e*d)%tt << endl;
        if((e*d)%tt == 1) break;
    }
    cout << "n: " << n << "\ntt: " << tt << "\ne: " << e << "\nd: " << d << endl;
}

int modp(int b, int pow, int n){
    int t = 1;
    for(int i = 0; i < pow; i++){
        t *= b;
        t%=n;
    }
    //cout << t << endl;
    return t;
}

int lcm(int a, int b){
    int t = gcf(a, b);
    //cout << "t: " << t << endl;
    return a*b/t;
}
int gcf(int a, int b){
    //cout << a << "%" << b << " " << a % b << endl;
    if(a % b == 0) return b;
    return gcf(b, a%b);
}


