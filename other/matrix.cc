#include <iostream>

using namespace std;

struct matrix
{
public:
    matrix(int n) {
        r.bsize = n;
        r.b = new int(n*n);
    }
    ~matrix() {
        delete r.b;
    }

    struct onerow {
        int &operator[] (int j) {
            return b[i*bsize+j];
        }
        int i;
        int bsize;
        int *b;
    };

    int size() const {return r.bsize;}

    onerow &operator [](int i) {
        r.i = i;
        return r;
    }

private:
    onerow r;
        
};

void dp_multiplication_table(matrix &m)
{
    for (int j = 0; j < m.size(); j++)
        m[0][j] = j+1;

    for (int i =1; i < m.size(); ++i)
        for (int j =0; j<m.size(); ++j)
            m[i][j] = m[i-1][j] + j + 1;
}

int main()
{
    matrix m(9);
    dp_multiplication_table(m);
    for (int i =0; i < m.size(); ++i) {
        for (int j =0; j<m.size(); ++j) {
           cout.width(3);
           cout << m[i][j];
        }
        cout << endl;
    }

    return 0;
}

