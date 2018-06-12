#### ` Anyone who has never made a mistake has never tried anything new. `

               -- Albert Einstein

### Implement search function of singly linked list:

    node *search(node *head, int key);

### What is the time complexity of search function: O(n)
big O notation of algorithm analysis: time complexity, space complexity

### How to improve the search algorithm? hash table

    hash: 
      a mess, jumble, or muddle.
      a dish of diced or chopped meat and often vegetables, as of leftover corned beef or veal and potatoes, sautéed in a frying pan or of meat, potatoes, and carrots cooked together in gravy.

### Bit operation:
    int swap(int &a, int &b); use xor^

    symmetric encryption:  text^key = secret, secret^key=text
    asymmetric encryption: base on (m)**p**q %n = m
        encryption: message**p %n = secret,  secret **q%n = message

### hash function: generate index 0...n bucket. (% mod operation).

    shell environment: bash programming
    CLI command: int main(int argc, char *argv[], char *argvp[]);

### hash table:

    node * hash[nsize];  //nsize buckets.
    bool insert(node *hash, int key);
    bool delete(node *hash, int key);
    node * find(node *hash, int key);  //return value or node structure

### C++ STL data structure:
    unordered_set, unordered_map


Problem:
use only shift(<<), and(&), or (|), xor(^) operation to implement add operation.
int add(int a, int b); 
int count (int a);

