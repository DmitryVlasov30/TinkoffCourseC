//#define _GLIBCXX_DEBUG
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
#include <stdio.h>
#include <strstream>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;

    vector<deque<int>> arr(n);
    vector<int> num(p);
    for (int i = 0; i < p; i++) {
        cin >> num[i];
        --num[i];
        arr[num[i]].emplace_back(i);
    }


    int count = 0;
    set<int> cars;
    priority_queue<pair<int, int>> el;
    for (int i = 0; i < p; i++){
        arr[num[i]].pop_front();

        if (cars.find(num[i]) == cars.end()){
            if (cars.size() >= k) {
                cars.erase(el.top().second);
                el.pop();
            }
            count++;
            cars.insert(num[i]);
        }
        if (arr[num[i]].empty()){ 
            el.emplace(1e9, num[i]);
        } else {
            el.emplace(arr[num[i]].front(), num[i]);
        }
    }
    cout << count << '\n';
}
