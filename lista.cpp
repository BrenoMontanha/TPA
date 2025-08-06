#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string *names = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    sort(names, names + n);

    cout << names[k - 1] << endl;

    delete[] names;  // Free the dynamically allocated memory
    return 0;
}