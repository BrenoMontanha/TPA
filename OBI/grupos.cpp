#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t e, m, d;
    vector<pair<size_t, size_t>> same;
    vector<pair<size_t, size_t>> diff;
    cin >> e >> m >> d;
    for (size_t i = 0; i < m; ++i) {
        size_t x, y;
        cin >> x >> y;
        same.push_back({x, y});
    }
    for (size_t i = 0; i < d; ++i) {
        size_t x, y;
        cin >> x >> y;
        diff.push_back({x, y});
    }
    size_t count = 0;
    size_t i, j, k;
    for (size_t l = 0; l < e/3; ++l) {
        cin >> i >> j >> k;
        if (find(same.begin(), same.end(), make_pair(i, j)) == same.end() &&
            find(same.begin(), same.end(), make_pair(i, k)) == same.end() &&
            find(same.begin(), same.end(), make_pair(j, i)) == same.end() &&
            find(same.begin(), same.end(), make_pair(j, k)) == same.end() &&
            find(same.begin(), same.end(), make_pair(k, j)) == same.end() &&
            find(same.begin(), same.end(), make_pair(k, i)) == same.end()) 
        {
            count++;
        } else if (find(diff.begin(), diff.end(), make_pair(i, j)) != diff.end() ||
                   find(diff.begin(), diff.end(), make_pair(i, k)) != diff.end() ||
                   find(diff.begin(), diff.end(), make_pair(j, i)) != diff.end() ||
                   find(diff.begin(), diff.end(), make_pair(j, k)) != diff.end() ||
                   find(diff.begin(), diff.end(), make_pair(k, i)) != diff.end() ||
                   find(diff.begin(), diff.end(), make_pair(k, j)) != diff.end()) 
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}