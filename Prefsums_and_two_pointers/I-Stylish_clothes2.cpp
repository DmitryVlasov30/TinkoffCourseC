#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, n1, n2, n3;
    cin >> n;
    vector<ll> arr_c, arr_t, arr_s, arr_b;
    for(int i = 0; i < n; ++i){
        ll el;
        cin >> el;
        arr_c.emplace_back(el);
    }
    cin >> n1;
    for(int i = 0; i < n1; ++i){
        ll el;
        cin >> el;
        arr_t.emplace_back(el);
    }
    cin >> n2;
    for(int i = 0; i < n2; ++i){
        ll el; 
        cin >> el;
        arr_s.emplace_back(el);
    }
    cin >> n3;
    for(int i = 0; i < n3; ++i){
        ll el;
        cin >> el;
        arr_b.emplace_back(el);
    }
    sort(all(arr_c)); sort(all(arr_t)); sort(all(arr_s)); sort(all(arr_b));
    ll b = 0, c = 0, s = 0, t = 0, ans = 1e9;
    ll ans_b = 0, ans_c = 0, ans_t = 0, ans_s = 0;

    while (c < n && t < n1 && s < n2 && b < n3){
        ll cap = arr_c[c], t_shirt = arr_t[t], shorts = arr_s[s], boots = arr_b[b];
        ll max_el = max(cap, max(t_shirt, max(shorts, boots)));
        ll min_el = min(cap, min(t_shirt, min(shorts, boots)));

        if (max_el - min_el < ans){
            ans = max_el - min_el;
            ans_t = t_shirt;
            ans_b = boots;
            ans_s = shorts;
            ans_c = cap;
        }

        if (min_el == cap){
            c++;
        } else if (min_el == boots){
            b++;
        } else if (min_el == t_shirt) {
            t++;
        } else {
            s++;
        }
    }
    cout << ans_c << " " << ans_t << " " << ans_s << " " << ans_b;

}
