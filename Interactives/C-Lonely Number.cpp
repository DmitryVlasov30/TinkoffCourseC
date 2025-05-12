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


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int left = 0, right = n-1;
    map<int, int> memory;
    while (left < right){
        int mid = (left + right) / 2, ans1 = -1, ans2 = -1;
        if (memory.find(mid + 1) != memory.end()){
            ans1 = memory[mid+1];
        }
        if (memory.find(mid + 2) != memory.end()){
            ans2 = memory[mid + 2];
        }
        if (ans1 == -1) {
            cout << "? " << mid+1 << endl;
            cin >> ans1;
        }
        if (ans2 == -1){
            cout << "? " << mid+2 << endl;
            cin >> ans2;
        }
        memory[mid+1] = ans1; memory[mid+2] = ans2;
        if (mid % 2 == 0){
            if (ans1 == ans2){
                left = mid + 1;
            } else {
                right = mid;
            }
        } else {
            if (ans1 != ans2){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }

    int res = -1;
    if (memory.find(left + 1) != memory.end()) {
        res = memory[left + 1];
        cout << "! " << res;
        return 0;
    }
    cout << "? " << left + 1 << endl;
    cin >> res;
    cout << "! " << res << endl;
}