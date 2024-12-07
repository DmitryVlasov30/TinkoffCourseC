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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr;
    for(int i = 0; i < n; ++i){
        ll el;
        cin >> el;
        arr.emplace_back(el);
    }
    ll left = 0, right = 1e18;
    while (right - left > 1){
        ll mid = (left+right)/2;
        ll count = 0;
        for(int i = 0; i < n; ++i){
            count += arr[i]/mid;
        }
        if (count >= k){
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left;
}

