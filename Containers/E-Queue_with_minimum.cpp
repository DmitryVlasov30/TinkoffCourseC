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
    ll q;
    cin >> q;
    deque<ll> arr;
    multiset<ll> min_arr;
    for (int i = 0; i < q; ++i){
        ll func, num;
        cin >> func;
        if (func == 1){
            cin >> num;
            arr.emplace_back(num);
            min_arr.insert(num);
        }
        else if(func == 2){
            cout << arr.front() << "\n";
            min_arr.erase(min_arr.find(arr.front()));
            arr.pop_front();
        }
        else if (func == 3){
            cin >> num;
            cout << arr[num-1] << "\n";
        }
        else if(func == 4){
            cout << *min_arr.begin() << "\n";
        }
    }
}
