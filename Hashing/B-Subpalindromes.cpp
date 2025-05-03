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

    vector<int> pow_el(maxn), hash_reverse(len(s) + 1), hash(len(s) + 1);
    pow_el[0] = 1;
    for (int i = 1; i < maxn; ++i){
        pow_el[i] = (pow_el[i - 1] * p) % mod;
    }

    hash[0] = hash_reverse[0] = 0;
    for (int i = 0; i < len(s); ++i){
        hash[i+1] = (hash[i] * p + (s[i] - 'a' + 1)) % mod;
    }

    string rev_s = s; reverse(all(rev_s));
    for (int i = 0; i < len(rev_s); ++i){
        hash_reverse[i+1] = (hash_reverse[i] * p + (rev_s[i] - 'a' + 1)) % mod;
    }

    vector<int> odd_ans(maxn), even_ans(maxn);
    for (int i = 0; i < len(s); ++i){
        int left = 0, right = min(i+1, (int)len(s) - 1 - i);
        while (left <= right){
            int mid = (right + left) / 2;
            if (hash_sub(i - mid + 1, i + mid, hash, pow_el) == hash_sub(len(s) - 1 - (i + mid), len(s) - 1 - (i - mid + 1), hash_reverse, pow_el)){
                even_ans[i] = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

    }


    for (int i = 0; i < len(s); ++i){
        int left = 0, right = min(i, (int)len(s) - 1 - i);
        while (left <= right){
            int mid = (right + left) / 2;
            if (hash_sub(i - mid, i + mid, hash, pow_el) == hash_sub(len(s) - 1 - (i + mid), len(s) - 1 - (i - mid), hash_reverse, pow_el)){
                odd_ans[i] = mid+1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

    }

    int ans = 0;
    for (int i = 0; i < len(s); ++i){
        ans += even_ans[i] + odd_ans[i];
    }

    cout << ans;
}