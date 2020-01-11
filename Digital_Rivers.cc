#include <iostream>
#include <vector>
using namespace std;
 
int suma_digits(int n, int s){
        if (n/10 == 0) return s + n;
        return suma_digits (n/10, s + n%10);
}
 
int trobada_de_rius(int n){
        int a = 1, b = 3, c = 9;
        while (a != n and b != n and c != n){
                while (a < n) a = suma_digits(a, a);
                if (a != n){
                  while (b < n) b = suma_digits(b, b);
                  if (b != n){
                    while (c < n) c = suma_digits(c, c);
                    if (c != n){
                      while (n < a and n < b and n < c){
                        n = suma_digits(n, n);
                      }
                    }
                  }
                }
        }
        return n;
}
 
int main(){
        int n;
        while (cin >> n){
                cout << trobada_de_rius(n) << endl;
        }

    }
