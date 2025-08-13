#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int result = (k - (n-1))/n;

    cout << result << endl;
}