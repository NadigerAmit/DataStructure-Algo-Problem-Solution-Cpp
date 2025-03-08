#include <iostream>
#include <vector>

using namespace std;
vector<int> rotate(vector<int>& v, int N) {
    
    for(auto i = 0;i<N;i++) {
        int temp = v[v.size()-1];
        for(int j = v.size()-2; j >= 0;j-- ) {
            v[j+1] = v[j];
        }
        //cout<<"-----------";
        v[0] = temp;
    }
    return v;
}
int main() {
    vector<int> v = {3, 8, 9, 7, 6};
    vector<int> result = rotate(v,3);
    for(auto i: result) {
        cout<<i<<endl;
    } 
}
/*
9
7
6
3
8
*/