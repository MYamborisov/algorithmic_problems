#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (size_t i = 0; i < n; ++i) {
        int T, L;
        cin >> T >> L;
        v.emplace_back(T, 1);
        v.emplace_back(T + L, 0);
    }
    std::sort(v.begin(), v.end());
    int current = 0, maximum = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i].second == 1) {
            ++current;
        } else {
            --current;
        }
        maximum = max(maximum, current);
    }
    cout << maximum;
}

