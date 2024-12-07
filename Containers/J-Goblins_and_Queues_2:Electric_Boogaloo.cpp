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
    ll q;
    cin >> q;
    deque<ll> front_arr, back_arr;
    for (int i = 0; i < q; ++i){
        char s;
        cin >> s;
        if (s == '-'){
            cout << front_arr.front() << "\n";
            front_arr.pop_front();
        } else if (s == '+') {
            ll el;
            cin >> el;
            back_arr.emplace_back(el);
        } else {
            ll el;
            cin >> el;
            front_arr.emplace_back(el);
        }
        if (len(front_arr) < len(back_arr)){
            front_arr.emplace_back(back_arr.front());
            back_arr.pop_front();
        } else if (len(front_arr) > len(back_arr) + 1){
            back_arr.emplace_front(front_arr.back());
            front_arr.pop_back();
        }
    }

}


