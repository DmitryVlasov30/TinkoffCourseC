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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    deque<pair<ll, ll>> arr; 
    for (int i = 0; i < n; ++i) {
        ll func;
        cin >> func;
        if (func == 1) {
            ll x, count;
            cin >> x >> count;
            arr.emplace_back(x, count); 
        } else if (func == 2) { 
            ll count;
            cin >> count;
            ll result = 0;
            while (count > 0) {
                auto& front = arr.front(); 
                if (front.second > count) {
                    result += count * front.first; 
                    front.second -= count; 
                    count = 0; 
                } else {
                    result += front.second * front.first; 
                    count -= front.second; 
                    arr.pop_front();
                }
            }
            cout << result << "\n";

        }
    }
}
