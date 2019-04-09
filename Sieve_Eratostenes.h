//Garbell Eratostenes
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
vector<bool> primer(int n){
        vector<bool> pri(MAX + 1, true);  //Tauler dels nombres
        pri[0] = pri[1] = false;
        int i = 2;
        while (i*i <= n){  //Analitzem n%i per 2 <= i <= sqrt(n)
                for (int j = 2; i*j <= n; ++j) pri[i*j] = false;
                ++i;
                while (not pri[i]) ++i; //Aixi nomes dividirem per multiples de 2 la primera vegada
        }
        return pri;
}
 
int main(){
        int n;
        vector<bool> pri(MAX + 1);
        pri = primer(MAX + 1);
        while (cin >> n){
                cout << n;
                if (not pri[n]) cout << " no";
                cout << " es primer" << endl;
        }
}