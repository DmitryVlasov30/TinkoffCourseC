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
    ll w, h, n;
    cin >> w >> h >> n;
    ll left = -1, right = max(h, w)*n;
    while (right - left > 1){
        ll mid = (left+right)/2;
        ll size = (mid/h) * (mid/w);
        if (size >= n){
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right;
    
    
}
