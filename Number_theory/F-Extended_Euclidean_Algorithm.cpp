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

int gcd_evklid(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd_evklid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int gcd_num = __gcd(a, b);
    if (c % gcd_num != 0){
        cout << "Impossible";
        return 0;
    }
    int x, y;
    int gcd_el = gcd_evklid(a, b, x, y);
    int a_n = a / gcd_num, b_n = b / gcd_num, c_n = c / gcd_num;
    int x_ans = c_n * x, y_ans = c_n * y;
    while(x_ans >= 0){x_ans -= b_n; y_ans += a_n;}
    while(x_ans < 0) {x_ans += b_n; y_ans -= a_n;}
    cout << gcd_el << " " << x_ans << " " << y_ans; 
}
