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
    ll n;
    cin >> n;
    vector<ll> arr;
    for(int i = 0; i < n; ++i){
        ll el;
        cin >> el;
        arr.emplace_back(el);
    }

    ll l = 0, r = n-1, min_ans = abs(arr[0] - arr[n-1]), sl = arr[0], sr = arr[n-1], pred_l = l, pred_r = r;
    pair<ll,ll> best = {l, r};
    while (true){
        pred_r = r; pred_l = l;
        if (sl < sr && l+1 != r){
            ++l;
            sl += arr[l];
        } else if (sr < sl && r-1 != l) {
            --r;
            sr += arr[r];
        }

        if (min_ans > abs(sl-sr)){
            min_ans = abs(sl-sr);
            best.first = l;
            best.second = r;
        }
        if (pred_l == l && pred_r == r){
            break;
        }
    }
    cout << min_ans << " " << ++best.first << " " << ++best.second;
}
