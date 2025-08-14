#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, a = 1, b = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        swap(a, b);
        b += a;
    }
    cout << a << endl; 
    return 0;
}