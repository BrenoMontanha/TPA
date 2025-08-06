#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    vector<size_t> distinct_numbers;
    cin >> n;
    size_t max_count = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t x;
        cin >> x;
        if (find(distinct_numbers.begin(), distinct_numbers.end(), x) == distinct_numbers.end()) {
            distinct_numbers.push_back(x);
            if (distinct_numbers.size() > max_count) {
                max_count = distinct_numbers.size();
            }
        } else {
            auto it = find(distinct_numbers.begin(), distinct_numbers.end(), x);
            if (it != distinct_numbers.end()) {
                distinct_numbers.erase(it);
            }
            distinct_numbers.push_back(x);
            if (distinct_numbers.size() > max_count) {
                max_count = distinct_numbers.size();
            }
        }
    }
    cout << max_count << endl;
    return 0;
}