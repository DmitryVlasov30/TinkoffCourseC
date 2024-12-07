#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n+1, 0);
    vector<ll> diff(n, 0);
    for (int i = 1; i < n; ++i){
        diff[i] = arr[i] - arr[i-1];
    }
    for (int i = 0; i < q; ++i){
        ll left, right, x;
        cin >> left >> right >> x;
        left--; right--;
        diff[left] += x;
        diff[right+1] -= x;
    }
    ll p = 0;
    for (int i = 0; i < n; ++i){
        p += diff[i];
        cout << p << " ";
    }
}
