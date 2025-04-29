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
const int maxn = 1e5;
const int logn = 20;
const int p = 29;


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
    int q; cin >> q;

    vector<int> pow_arr(maxn), h(len(s) + 1);
    pow_arr[0] = 1;
    for (int i = 1; i < maxn; ++i){
        pow_arr[i] = (pow_arr[i-1] * p) % mod;
    }

    h[0] = 0;
    for (int i = 0; i < len(s); ++i){
        h[i+1] = (h[i] * p + (s[i] - 'a' + 1)) % mod;
    }

    for (int i = 0; i < q; ++i){
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        --l1; --r1; --l2; --r2;
        // cout << hash_sub(l1, r1, h, pow_arr) << " " << hash_sub(l2, r2, h, pow_arr) << "\n";
        if (hash_sub(l1, r1, h, pow_arr) == hash_sub(l2, r2, h, pow_arr)) cout << "Yes\n";
        else cout << "No\n";
    }


}