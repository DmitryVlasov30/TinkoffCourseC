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
#include <numbers>
#include <cmath>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    ll left = 0, right = 1e18;
    while(right - left > 1){
        ll mid = (left+right)/2;
        ll wi = a + 2*mid, hi = b + 2*mid;
        ll col = w / wi, row = h / hi; 
        ll col1 = h / wi, row1 = w / hi;
        if (max(col * row, col1 * row1) >= n){
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left;
}
