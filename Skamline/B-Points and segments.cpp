//#define _GLIBCXX_DEBUG
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdio.h>
#include <strstream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <deque>

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 2*1e5;

struct Event {
    int x, type, idx;
    Event(int x, int type, int idx) : x(x), type(type), idx(idx) {};
};

bool comp(Event a, Event b){
    return make_pair(a.x, a.type) < make_pair(b.x, b.type);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<Event> events; 
    for (int i = 0; i < n; ++i){
        int s, f; cin >> s >> f;
        events.emp(Event(min(s, f), 0, -1));
        events.emp(Event(max(s, f), 2, -1));
    }

    for (int i = 0; i < m; ++i){
        int el; cin >> el; 
        events.emp(Event(el, 1, i));
    }

    sort(all(events), comp);
    int bal = 0;
    vector<int> arr(m);
    for (auto el : events){
        if (el.type == 0) ++bal;
        else if (el.type == 1) arr[el.idx] = bal;
        else --bal;
    }
    for(auto el : arr){
        cout << el << " ";
    }
}