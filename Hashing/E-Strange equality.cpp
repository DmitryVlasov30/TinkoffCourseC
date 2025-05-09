#define _GLIBCXX_DEBUG
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdio.h>
#include <strstream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <deque>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back
#define ins insert

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 2e6;
const int logn = 20;
const int p = 26;

int norm(int el) {
    el %= mod;
    if (el < 0) el += mod;
    return el;
}

int create_hash(const vector<int>& s, const vector<int>& pow_el) {
    int hash = 0;
    for (int i = 0; i < s.size(); ++i) {
        hash = (hash * p + s[i]) % mod;
    }
    return hash;
}

int get_hash(int l, int r, const vector<int>& pow_el, const vector<int>& hash) {
    return norm(hash[r] - hash[l] * pow_el[r - l]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s, t; cin >> s >> t;

    vector<int> pow_el(2 * n + 1);
    pow_el[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        pow_el[i] = (pow_el[i-1] * p) % mod;
    }

    vector<int> s_num(n), t_num(2 * n);
    for (int i = 0; i < n; ++i) {
        s_num[i] = s[i] - 'a';
        t_num[i] = t_num[i + n] = t[i] - 'a';
    }

    vector<int> hash(2 * n + 1);
    hash[0] = 0;
    for (int i = 0; i < 2 * n; ++i) {
        hash[i+1] = (hash[i] * p + t_num[i]) % mod;
    }


    for (int d = -25; d <= 25; ++d) {
        vector<int> s_shift(n);
        for (int i = 0; i < n; ++i) {
            s_shift[i] = (s_num[i] + d + p) % p;
        }
        int hash_shift = create_hash(s_shift, pow_el);
        for (int k = 0; k < n; ++k) {
            if (get_hash(k, k + n, pow_el, hash) == hash_shift) {
                cout << "Success\n";
                cout << k << " " << d << "\n";
                return 0;
            }
        }
    }
    cout << "Impossible";
}