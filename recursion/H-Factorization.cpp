#define _GLIBCXX_DEBUG
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


void gen(int n, vector<int>& curr, int m){
    if (n == 1){
        for (int i = 0; i < len(curr); ++i){
            if (i == len(curr)-1){
                cout << curr[i];
            } else {
                cout << curr[i] << "*";
            }
        }
        cout << "\n";    
        return;
    }

    for (int number = m; number <= n; ++number){
        if (n % number == 0){
            curr.emplace_back(number);
            gen(n/number, curr, number);
            curr.pop_back();
        }
    }
    
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> curr;
    gen(n, curr, m);    
}
