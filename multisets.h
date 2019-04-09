#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<string> set;

typedef struct {
  string id;
  int num;
} MultiElem;

typedef vector<MultiElem> MultiSet;

 set read_set() {
  int n;
  cin >> n;
  set s(n);
  for (int i=0; i<n; ++i)
    cin >> s[i];
  return s;
}

void writeMultiSet(const MultiSet& m) {
  for (int i=0; i<m.size(); ++i)
    cout << "(" << m[i].id << " , " << m[i].num << ")" << endl;
}

bool empty(const set& s) {
  return s.size() == 0;
}

bool comp (MultiElem& a, MultiElem& b) {
  return a.id < b.id;
}

MultiSet unionMultiSets(MultiSet& m, set& s1) {
  for (int i = 0; i < s1.size(); i++){
    bool trobat = false;
    for (int j = 0; j < m.size(); j++) {
      if (s1[i] == m[j].id) {
        m[j].num += 1;
        trobat = true;
      }
    }
    if (!trobat) {
      MultiElem e;
      e.id = s1[i];
      e.num = 1;
      m.push_back (e);
    }
  }
  return m;
}

int main() {
  set s;
  MultiSet m3;
  s = read_set();
  if (not empty (s)){
    
    for (int i = 0; i < s.size(); i++){
      MultiElem e;
      e.id = s[i];
      e.num = 1;
      m3.push_back(e);
    }
    
    set s1;
    s1 = read_set();
   }
  sort (m3.begin(), m3.end(), comp);
  writeMultiSet (m3);
 }

