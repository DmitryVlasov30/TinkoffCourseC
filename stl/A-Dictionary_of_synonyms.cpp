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
    map<string, string> Map;
    for(int i = 0; i < n; ++i){
        string el1, el2;
        cin >> el1 >> el2;
        Map[el1] = el2;
    }
    string search_word;
    cin >> search_word;
    for (auto el : Map){
        if (search_word == el.first){
            cout << el.second;
            break;
        } else if (search_word == el.second) {
            cout << el.first;
            break;
        }
    }
}

