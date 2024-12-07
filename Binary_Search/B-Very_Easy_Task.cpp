#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <algorithm>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, x, y;
    cin >> n >> x >> y;
    ll left = 0, right = 1e18;
    while(right != left){
        ll mid = (right+left)/2;
        if (mid/x + mid/y < n-1){
            left = mid+1;
        } else {
            right = mid;
        }
    }  
    cout << right+min(x, y);

}
