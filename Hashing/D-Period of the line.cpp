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
const int p = 31;


int norm(int el){
    el %= mod;
    if (el < 0) el += mod;
    return el;
}

int hash_sub(int l, int r, vector<int>& h, vector<int>& pow_el){
    return norm((h[r+1] - h[l] * pow_el[r - l + 1] + mod) % mod);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = len(s);

    vector<int> hash(maxn), pow_el(maxn + 1);
    pow_el[0] = 1;
    for (int i = 1; i <= maxn; ++i){
        pow_el[i] = (pow_el[i-1] * p) % mod;
    }

    hash[0] = 0;
    for (int i = 0; i <= n; ++i){
        hash[i+1] = (hash[i] * p + (s[i] - 'a' + 1)) % mod;
    }

    for (int kol = 1; kol <= n; ++kol){
        if (n % kol == 0){
            int length = kol;
            int ans = n / kol;
            bool flag = true;

            int first_hash = hash_sub(0, length-1, hash, pow_el);
            for (int left = length; left < n; left += length){
                int hash_submission = hash_sub(left, left + length - 1, hash, pow_el);
                if (first_hash != hash_submission){
                    flag = false;
                    break;
                }
            }

            if (flag){
                cout << ans;
                return 0;
            }
        }
    }
}