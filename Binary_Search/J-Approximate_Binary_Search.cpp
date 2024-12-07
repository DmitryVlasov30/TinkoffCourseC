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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr;
    for(int i = 0; i < n; ++i){
        ll el;
        cin >> el;
        arr.emplace_back(el);
    }    
    //cout << len(arr) << "---\n";
    for (int i = 0; i < m; ++i){
        ll el;
        cin >> el;
        ll left = 0, right = n-1;
        while(right - left > 1){
            ll mid = (left+right)/2;
            if(arr[mid] > el){
                right = mid;
            } else {
                left = mid;
            }
        }
        ll el1 = el-arr[left], el2 = arr[right] - el;
        if (el1 <= el2){
            cout << arr[left];
        } else {
            cout << arr[right];
        }
        cout << "\n";

    }
}
