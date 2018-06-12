#include <iostream>
#include <fstream>
#include <cmath>

using namespace std; 

void pArg(int argc, char* argv[]);
void pArgp(char* argp[]);
char crypt(char c, char key);

int main(int argc, char* argv[], char* argp[]){
	pArg(argc, argv);
	pArgp(argp);
	if (argc <= 2) return 0;
	
	ifstream fin (argv[1]);
	ofstream fout (argv[2]);
	char c;
	cin >> c;
	char key;

	while(fin.get(key)){
		char t = crypt(c, key);
		fout << t;
		//cout << t;
	}
}

void pArg(int argc, char* argv[]){
	for(int i = 0; i < argc; i++){
		cout << i << ": " << argv[i] << endl;
	}
}

void pArgp(char* argp[]){
	for(int i = 0; argp[i] != NULL; i++){
		cout << argp[i] << endl;
	}
}

char crypt(char c, char key){
	return c ^ key;
}


