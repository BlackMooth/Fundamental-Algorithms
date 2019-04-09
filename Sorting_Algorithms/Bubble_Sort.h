//Algoritme fonamental de sorting
#include <iostream>
#include <vector>
using namespace std;
 
void ordena_per_bombolla(vector<double>& v) {
    int i = 1;
    int n = v.size();
    bool ordenat = false;
    while (i < n and not ordenat) {
        ++i;
        ordenat = true;
        for (int j = 0; j <= n - i; ++j) {
            if (v[j] > v[j+1]) {
                ordenat = false;
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}