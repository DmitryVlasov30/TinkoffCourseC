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
const int maxn = 1e6;
const int logn = 20;
const int p = 31;


int norm(int el){
    el %= mod;
    if (el < 0) el += mod;
    return el;
}

int hash_sub(int l, int r, vector<int>& h, vector<int>& pow_el){
    return norm(h[r] - h[l] * pow_el[r - l]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    vector<int> pow_el(maxn), hash_reverse(n + 1), hash(n + 1);
    pow_el[0] = 1;
    for (int i = 1; i < maxn; ++i){
        pow_el[i] = (pow_el[i - 1] * p) % mod;
    }

    hash[0] = hash_reverse[0] = 0;
    for (int i = 0; i < n; ++i){
        hash[i+1] = (hash[i] * p + arr[i]) % mod;
    }

    for (int i = n-1; i >= 0; --i){
        hash_reverse[n-i] = (hash_reverse[n-i-1] * p + arr[i]) % mod;
    }

    vector<int> ans;
    ans.emp(n);
    for (int i = 1; i * 2 <= n; ++i){
        int hash1 = hash_sub(0, 2 * i, hash, pow_el);
        int hash2 = hash_sub(n - 2 * i, n, hash_reverse, pow_el);
        if (hash1 == hash2){
            ans.emp(n - i);
        }
    }

    reverse(all(ans));
    for (int num : ans){
        cout << num << " ";
    }
}