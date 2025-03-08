#include <iostream>
#include <vector>
#include <set>
using namespace std;

int OddOccurrencesInArray(vector<int>& v) {
    set<int> s;
    for(int i = 0;i<v.size(); i++) {
        if(s.find(v[i]) != s.end()) {
            s.erase(v[i]);
        } else {
            s.emplace(v[i]);
        }
    }
    if(s.size()>0) {
        return *s.begin();
    }
    return -1009;
}
int main() {
    vector<int> v = {9,3,9,3,9,7,9};
    cout<<"Non paired element "<<OddOccurrencesInArray(v);
}
/*
Non paired element 7
*/