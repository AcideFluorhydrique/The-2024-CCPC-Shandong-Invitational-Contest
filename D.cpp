#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <random>
#include <chrono>
#include <numeric>

#define ll long long

using namespace std;

// int T;

// struct NewPair {
//     int first;
//     int second;
//     int id;
// };
#define NewPair pair<int, int>

int n;
int k;

NewPair xy[10010];

// vector<int> res[60];

mt19937 myRand(chrono::steady_clock::now().time_since_epoch().count());

ll Truemod(ll a, ll b) {
    ll res = a % b;
    if (res < 0) {
        res += b;
    }
    return res;
}

ll ID(ll x, ll y, ll p, ll q) {
    return q * y - p * x;
}

void Solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i].first >> xy[i].second;
    }
    uniform_int_distribution<> distrib(1, n);
    // shuffle(xy + 1, xy + n + 1, myRand);
    while (true) {
        int a = distrib(myRand);
        int b = distrib(myRand);
        while (a == b) {
            b = distrib(myRand);
        }
        ll p = xy[a].second - xy[b].second;
        ll q = xy[a].first - xy[b].first;
        unordered_map<ll, vector<int>> curMap;
        for (int j = 1; j <= n; j++) {
            // cout << j << endl;
            curMap[ID(xy[j].first, xy[j].second, p, q)].push_back(j);
            if (curMap.size() > k) {
                break;
            }
        }
        if (curMap.size() == k) {
            bool flag = true;
            for (auto& [key, l] : curMap) {
                if (l.size() < 2) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (auto& [key, l] : curMap) {
                    cout << l.size();
                    for (auto& x : l) {
                        cout << ' ' << x;
                    }
                    cout << '\n';
                }
                return;
            }
        }
    }
    // int cc = 0;
    // for (int i = 0; i < k; i++) {
    //     if (res[i].size() < 2) {
    //         while (res[cc].size() < 3) {
    //             cc++;
    //         }
    //         res[i].push_back(res[cc].back());
    //         res[cc].pop_back();
    //     }
    // }
    // for (int i = 0; i < k; i++) {
    //     cout << res[i].size();
    //     for (auto& x : res[i]) {
    //         cout << ' ' << x;
    //     }
    //     cout << '\n';
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> T;
    // while (T--) {
    Solve();
    // }
    return 0;
}