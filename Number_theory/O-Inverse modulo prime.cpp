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


int bin_pow(int a, int n, int m){
    if (n == 0) return 1;
    if (n % 2 == 1){return a * bin_pow(a, n-1, m) % m;}
    else {
        int b = bin_pow(a, n/2, m);
        return (b*b)%m;
    }
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p; cin >> n >> p;
    cout << bin_pow(n, p-2, p);
}
