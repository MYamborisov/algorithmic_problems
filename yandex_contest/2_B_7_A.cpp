#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (size_t i = 0; i < n; ++i) {
        int L, R;
        cin >> L >> R;
        v.emplace_back(L, 0);
        v.emplace_back(R, 1);
    }
    std::sort(v.begin(), v.end());
    int current = 0, length = 0, prev;
    for (auto [time, id] : v) {
        if (current == 0) {
            prev = time;
        }
        if (id == 0) {
            ++current;
        } else {
            --current;
        }
        if (current == 0) {
            length += time - prev;
        }
    }
    cout << length;
}

