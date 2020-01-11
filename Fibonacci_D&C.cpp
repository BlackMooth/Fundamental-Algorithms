#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > matrix;

matrix Identitat = { {1, 0}, {0, 1} };
matrix fib_exp = { {1, 1}, {1, 0} };

matrix producte (matrix& M1, matrix& M2, int m){
    matrix M (2, vector<int> (2));
    for (int i = 0; i < 2; ++i) 
        for (int j = 0; j < 2; ++j) 
            for (int k = 0; k < 2; ++k) M[i][j] = (M[i][j] + M1[i][k]*M2[k][j])%m;
    return M;
}

matrix quick_exponentiation (matrix& M, int n, int m) {
    
    if (n == 0) return Identitat;
    else {
        matrix y (2, vector<int> (2));
        y = quick_exponentiation(M, n/2, m);
        if (n%2 == 0) {
            return producte(y, y, m);
        }
        else {
            matrix z (2, vector<int> (2));
            z = producte (y, y, m);
            return producte(z, M, m);
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        matrix Mn (2, vector<int> (2));
        Mn = quick_exponentiation(fib_exp, n, m);
        int resultat = (Mn[1][0]);
        cout << resultat << endl;
    }
}
