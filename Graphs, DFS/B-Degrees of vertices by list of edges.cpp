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
const int inf = 1e18;


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> m >> n;
    map<int,int> ver_graf;
    for (int i = 1; i <= m; ++i){
        ver_graf[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        int st, fin; cin >> st >> fin;
        ver_graf[st] += 1; ver_graf[fin] += 1;
    }
    for (auto el : ver_graf){
        cout << el.sec << " ";
    }
}
