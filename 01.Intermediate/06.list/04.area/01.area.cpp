#include <iostream>
#include <vector>
using namespace std;

void print2dArray(vector<vector<int> > array2d) {
    for(int i=0; i<array2d.size(); i++) {
        for(int j=0; j<array2d[i].size(); j++) {
            cout << array2d[i][j] << endl;
        }
    }
}

int main(){
    vector<vector<int> > array2d = {{1,2,3},{4,5,6},{7,8,9}};
    print2dArray(array2d);
    return 0;
}