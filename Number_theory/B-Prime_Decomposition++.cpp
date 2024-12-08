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

int gcd(int a, int b){
    if (b == 0){
        return a;
    } 
    return gcd(b, a % b);
}

map<int,int> factorize(int n){
    map<int,int> result;
    for (int i = 2; i*i <= n; ++i){
        while (n % i == 0){
            n /= i;
            result[i] += 1;
        }
    }
    if (n != 1){
        result[n] += 1;
    }
    return result;
}


int32_t main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    map<int, int> ans = factorize(n);
    string s = "";
    for (auto el : ans){
        if (el.second != 1){s += to_string(el.first) + "^" + to_string(el.second) + "*";}
        else {s += to_string(el.first) + "*";}
        
    }
    s.pop_back();
    cout << s;
}
