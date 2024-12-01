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
    int n; 
    cin >> n;

    vector<bool> rooms(1000000, false);
    set<int> free_rooms; 

    for (int i = 1; i < 1000000; ++i) {
        free_rooms.insert(i); 
    }

    for (int i = 0; i < n; ++i) {
        int el;
        cin >> el;

        if (el > 0) { 
            auto it = free_rooms.lower_bound(el); 
            if (it != free_rooms.end()) { 
                cout << *it << "\n"; 

                rooms[*it] = true; 
                free_rooms.erase(it); 
            }
        } else { 
            el = abs(el);

            if (rooms[el]) {
                rooms[el] = false; 
                free_rooms.insert(el); 
            }
        }
    }
}
