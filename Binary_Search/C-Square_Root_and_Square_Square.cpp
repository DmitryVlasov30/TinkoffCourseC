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
    ld c;
    cin >> c;
    ld l = 0, r = 1e18;
    for (int i = 0; i < 100; ++i){
        ld mid = (l+r)/2;
        ld ans_prom = (mid*mid) + sqrt(mid);
        if (ans_prom > c){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(9) << l;
    
}
