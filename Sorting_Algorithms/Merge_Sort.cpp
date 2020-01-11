//Algoritme fonamental de merge sorting
#include <iostream>
#include <vector>
using namespace std;

void sort(vector <double>& v, vector <double> v1, vector <double> v2) {
    int i = 0;
    int j = 0;
    int x = v1.size();
    int y = v2.size();
    int cont = 0;
    while (i < x and j < y) {
        if (v1[i] < v2[j]) v[cont++] = v1[i++];
        else if (v2[j] < v1[i]) v[cont++] = v2[j++];
        else {
            v[cont++] = v1[i++];
            v[cont++] = v2[j++];
        }
    }
    while (i < x) v[cont++] = v1[i++];
    while (j < y) v[cont++] = v2[j++];
}


void ordena_per_fusio(vector<double>& v) {
    int a = v.size();
    int m = a/2;
    if (m < 1) return;
    int u = 0;
    vector <double> v1(m), v2(a - m);
    for (int k = 0; k < m; ++k) v1[k] = v[k];
    for (int g = m; g < a; ++g) v2[u++] = v[g];
    ordena_per_fusio(v1);
    ordena_per_fusio(v2);
    sort(v,v1,v2);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> v(n);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
        }
        ordena_per_fusio(v);
        for (int i=0; i<n; ++i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
}
