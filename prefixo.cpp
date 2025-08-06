#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    char *p1 = new char[n + 1];
    cin >> p1;

    cin >> m;
    char *p2 = new char[m + 1];
    cin >> p2;

    int prefixLength = 0;
    for (int i = 0; i < (n < m ? n : m); ++i) {
        if (p1[i] == p2[i]) {
            prefixLength++;
        } else {
            break;
        }
    }

    cout << prefixLength << endl;

    delete[] p1;
    delete[] p2;

    return 0;
}