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
    ld a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < 0){
        a = -a; b = -b; c = -c; d = -d;
    }
    ld left = -1e8, right = 1e8;
    for(int i = 0; i < 100; ++i){
        ld mid = (left + right)/2;
        ld ans_prom = a*(mid*mid*mid) + b*(mid*mid) + c*mid + d;
        if(ans_prom < 0){
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << fixed << setprecision(4) << left;

}
