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


void gen(int n, vector<int>& curr){
    if (len(curr) == n){
        for (int i : curr){
            cout << i;
        }
        cout << "\n";
        return;
    }
    
    for (int number = 0; number <= 1; ++number){
        curr.emplace_back(number);
        gen(n, curr);
        curr.pop_back();
    }
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> curr;
    gen(n, curr);    
}


