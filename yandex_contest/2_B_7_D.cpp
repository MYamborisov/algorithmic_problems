#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (size_t i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.emplace_back(a, 0);
    }
    for (size_t i = 0; i < m; ++i) {
        int L, R;
        cin >> L >> R;
        v.emplace_back(L, -(i + 1));
        v.emplace_back(R, (i + 1));
    }
    std::sort(v.begin(), v.end());
    vector<int> count(m + 1);
    unordered_set<int> current;
    int cats_now = 0;
    for (auto [time, id] : v) {
        if (id == 0) {
            ++cats_now;
        } else if (id < 0) {
            for (auto now : current)
                count[now] += cats_now;
            cats_now = 0;
            current.insert(-id);
        } else {
            for (auto now : current)
                count[now] += cats_now;
            cats_now = 0;
            current.erase(id);
        }
    }
    for (size_t i = 1; i < count.size(); ++i)
        cout << count[i] << " ";
}

