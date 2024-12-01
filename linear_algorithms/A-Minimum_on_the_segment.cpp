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

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    deque<pair<int,int>> q1, q2;
    for (int i = 0; i < n; ++i){
        int el; cin >> el;
        q2.push_back({el, i});
        while (!q1.empty() && q1.back().fir > el){
            q1.pop_back();
        }
        q1.push_back({el, i});
        if (i >= k-1){
            cout << q1.front().fir << " ";
            if (q2.front().sec == q1.front().sec){
                q1.pop_front();
            }
            q2.pop_front();
        }
    }
}
