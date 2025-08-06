#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    int n, x;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x == 0)
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            s.push(x);
        }
    }
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;

    return 0;
}