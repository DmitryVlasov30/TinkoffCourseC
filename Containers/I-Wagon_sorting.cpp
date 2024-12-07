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
    ll n;
    cin >> n;
    deque<ll> arr_2, tupik;
    ll num = 1;
    vector<pair<ll, ll>> ans;
    for (int i = 0; i < n; ++i){
        ll el;
        cin >> el;
        if (!tupik.empty() && el > tupik.back()){
            cout << 0;
            return 0;
        }
        tupik.emplace_back(el);

        ans.emplace_back(1, 1);
        while(!tupik.empty() && tupik.back() == num){
            ans.emplace_back(2, 1);
            arr_2.emplace_back(tupik.back());
            tupik.pop_back();
            num++;
        }
    }
    cout << len(ans) << "\n";
    for(int i = 0; i < len(ans); ++i){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

}
