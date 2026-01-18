#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int size;
    vector<int> tree;

    Fenwick(int n) : size(n), tree(n + 1, 0) {}

    void add(int index, int val) {
        for (; index <= size; index += index & -index)
            tree[index] += val;
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += tree[index];
        return sum;
    }
};

struct Robot {
    int id;
    int costL;
    int costR;
};

bool compareRobots(const Robot& a, const Robot& b) {
    return a.costL < b.costL;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    string gdCode;
    cin >> gdCode;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<Robot> robots(n);
    vector<int> all_costR;
    all_costR.reserve(n);

    for (int i = 0; i < n; ++i) {
        robots[i].id = i;
        
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        
        if (it != b.end()) {
            long long dist = (long long)*it - a[i];
            robots[i].costL = (dist > k) ? k + 1 : (int)dist;
        } else {
            robots[i].costL = k + 1;
        }

        if (it != b.begin()) {
            long long dist = (long long)a[i] - *prev(it);
            robots[i].costR = (dist > k) ? k + 1 : (int)dist;
        } else {
            robots[i].costR = k + 1;
        }

        all_costR.push_back(robots[i].costR);
    }

    sort(robots.begin(), robots.end(), compareRobots);
    sort(all_costR.begin(), all_costR.end());

    Fenwick ft(k + 2);
    int ptr = 0;

    int cur = 0;
    int mx = 0;
    int mn = 0;

    for (char c : gdCode) {
        if (c == 'L') {
            cur--;
        } else {
            cur++;
        }
        mx = max(mx, cur);
        mn = min(mn, cur);

        int R_thresh = mx;
        int L_thresh = -mn;

        while (ptr < n && robots[ptr].costL <= R_thresh) {
            ft.add(robots[ptr].costR, 1);
            ptr++;
        }

        int countL = ptr;
        
        auto itR = upper_bound(all_costR.begin(), all_costR.end(), L_thresh);
        int countR = (int)(itR - all_costR.begin());

        int overlap = ft.query(L_thresh);

        int dead = countL + countR - overlap;
        cout << n - dead << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
        while (t--) {
            solve();
        }
    
}