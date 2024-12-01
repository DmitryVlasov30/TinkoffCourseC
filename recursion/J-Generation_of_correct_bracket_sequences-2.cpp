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

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second

using namespace std;

void gen(vector<char>& pref, vector<char>& st, int n, int open){
    if (len(pref) == n){
        for(auto el : pref){
            cout << el;
        }
        cout << "\n";
        return;
    }

    if (len(st) > n - len(pref)){
        return;
    }

    if (open < n/2){
        pref.emplace_back('(');
        st.emplace_back('(');
        gen(pref, st, n, open+1);
        pref.pop_back();
        st.pop_back();
    } if (open < n/2){
        pref.emplace_back('[');
        st.emplace_back('[');
        gen(pref, st, n, open+1);
        pref.pop_back();
        st.pop_back();
    } if (!st.empty() && st.back() == '(') {
        pref.emplace_back(')');
        st.pop_back();
        gen(pref, st, n, open);
        pref.pop_back();
        st.emplace_back('(');
    } if (!st.empty() && st.back() == '['){
        pref.emplace_back(']');
        st.pop_back();
        gen(pref, st, n, open);
        pref.pop_back();
        st.emplace_back('[');
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n % 2 != 0){
        return 0;
    }
    vector<char> pref, st;
    gen(pref, st, n, 0);
}

