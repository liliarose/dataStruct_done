#include <iostream>
#include <string>

using namespace std;

// ALPHABET_SIZE
const int ASIZE = 128;

class trie {
public:
    struct tnode
    {
        bool end;
        tnode *children[ASIZE];

        tnode()
        {
            end = false;
            for (int i = 0; i < ASIZE; i++)
                children[i] = nullptr;
        }
    };

private:
    tnode *root;
	void traverse(tnode *p, string &s){
		if(p->end){
			cout << s << endl;
		}	
		for(int i = 0; i < ASIZE; i++){
			if(p->children[i] != nullptr){
				s.push_back(((char)i));
				traverse(p->children[i], s);
				s.pop_back();
			}
		}
	} 
    
	bool deletion(tnode *p, string &key, int level){	
		if(level == key.size()){
			p->end = false;
			return is_free_node(p);
		} 
		tnode *child = p->children[((int)key[level])];
		if((child != nullptr) && deletion(child, key, level +1)){
			delete child; 
			p->children[((int)key[level])] = nullptr;
			return is_free_node(p) && !is_leaf_node(p);
		}
		return false;
	}
    
	bool is_leaf_node(tnode *p){
		return p->end;
	}

    bool is_free_node(tnode *p){
		for(int i = 0; i < ASIZE; i++){
			if(p->children[i] != nullptr) return false;
		}
		return true;
	}
	void delete_tree(tnode *p){
		for(int i = 0; i < ASIZE; i++){
			if(p->children[i] != nullptr){
				delete_tree(p->children[i]);
				p->children[i] = nullptr;
			}
		}
		delete p;
	}

public:
    trie() {
        root = new tnode();
    }

    void insert(const string &key){
        tnode *tmp = root;
        for(int i = 0; i < key.size(); i++){
            if(tmp->children[((int)key[i])] == nullptr){
                tmp->children[((int)key[i])] = new tnode();
            }   
            tmp = tmp->children[((int)key[i])];
        }   
        tmp->end = true;
    }   

    bool search(const string &key){
        tnode *tmp = root;
        for(int i = 0; i < key.size(); i++){
            if(tmp == nullptr){
                return false;
            }   
        }   
        return true;
    }   
    void deletion(string &key){
        deletion(root, key, 0); 
    }   
    void traverse(){
        string empty = "";
		traverse(root, empty);
    	cout << endl;
	}   
    ~trie() {
        delete_tree(root);
        cout << "finished deletion\n";
    }

};

int main(){
	trie t1;
	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
	for(int i = 0; i < 8; i++){
		t1.insert(keys[i]);	
	}
	t1.traverse();
	for(int i = 0; i < 8; i++){
		t1.deletion(keys[i]);
		t1.traverse();
	}

}



