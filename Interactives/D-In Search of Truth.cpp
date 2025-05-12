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
const int maxn = 2e6;
const int logn = 20;
const int p = 31;


int query(int idx){
    cout << "? " << idx << endl;
    int val; cin >> val;
    return val;
}


signed main() {
    int n, k; cin >> n >> k;
    int left = 1, right = n;
    int peak = -1;
    while (left <= right){
        int mid = (left + right) / 2;
        int ans = query(mid), ans2 = -1;
        if (mid < n){
            ans2 = query(mid + 1);
        }

        if (ans < ans2){
            left = mid + 1;
        } else {
            right = mid - 1;
            peak = mid;
        }
    }

    left = 1, right = peak;
    while (left <= right){
        int mid = (left + right) / 2;
        int ans = query(mid);
        if (ans == k){
            cout << "! " << mid << endl;
            return 0;
        } else if (ans < k){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = peak+1, right = n;
    while (left <= right){
        int mid = (left + right) / 2;
        int ans = query(mid);
        if (ans == k){
            cout << "! " << mid << endl;
            return 0;
        } else if (ans < k){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

}