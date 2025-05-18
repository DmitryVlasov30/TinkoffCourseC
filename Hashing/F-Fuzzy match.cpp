//#define _GLIBCXX_DEBUG
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
const int maxn = 31;
const int logn = 20;
const int p_hash = 31;


int norm(int el) {
    el %= mod;
    if (el < 0) el += mod;
    return el;
}


int get_hash(int l, int r, vector<int>& hash, vector<int>& pow_el){
    return norm(hash[r] - hash[l] * pow_el[r - l]);
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string p, t; cin >> p >> t;
    int len_p = len(p), len_t = len(t);

    vector<int> pow_el(len_t + 1);
    pow_el[0] = 1;
    for (int i = 1; i < len_t; ++i){
        pow_el[i] = (pow_el[i-1] * p_hash) % mod;
    }

    vector<int> hash_t(len_t + 1), hash_p(len_p + 1);
    for (int i = 0; i < len_p; ++i){
        hash_p[i+1] = (hash_p[i] * p_hash + (p[i] - 'a' + 1)) % mod;
    }

    for (int i = 0; i < len_t; ++i){
        hash_t[i+1] = (hash_t[i] * p_hash + (t[i] - 'a' + 1)) % mod;
    }

    vector<int> ans;
    for (int k = 0; k < len_t - len_p + 1; ++k){
        int left = 0, right = len_p, max_pref = 0;
        while (left <= right){
            int mid = (left + right) / 2;
            int hash_pref_p = (mid == 0 ? 0 : get_hash(0, mid, hash_p, pow_el));
            int hash_pref_t = (mid == 0 ? 0 : get_hash(k, k + mid, hash_t, pow_el));
            if (hash_pref_p == hash_pref_t){
                max_pref = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (max_pref == len_p){
            ans.emp(k + 1);
        } else {
            if (len_p - max_pref - 1 >= 0){
                int hash_pref_p = get_hash(max_pref + 1, len_p, hash_p, pow_el);
                int hash_pref_t = get_hash(k + max_pref + 1, k + len_p, hash_t, pow_el);
                if (hash_pref_t == hash_pref_p){
                    ans.emp(k + 1);
                }
            }
        }
    }

    cout << len(ans) << "\n";
    for (int num : ans){
        cout << num << " ";
    }
}