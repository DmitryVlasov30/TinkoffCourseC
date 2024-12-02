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
const int inf = 1e7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }
    vector<int> rez_right, rez_left;
    stack<int> st;
    for (int i = n-1; i >= 0; --i){
        while (!st.empty() && arr[st.top() - 1] >= arr[i]){
            st.pop();
        }
        if (!st.empty()){
            rez_right.emp(st.top());
        } else {
            rez_right.emp(-1);
        }
        st.push(i+1);
    }
    reverse(all(rez_right));
    stack<int> st1;
    for (int i = 0; i < n; ++i){
        while (!st1.empty() && arr[st1.top() - 1] >= arr[i]){
            st1.pop();
        }
        if (!st1.empty()){
            rez_left.emp(st1.top());
        } else {
            rez_left.emp(-1);
        }
        st1.push(i+1);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i){
        int left = rez_left[i], right = rez_right[i], x = 0;
        if (right == -1 && left == -1){
            x = arr[i] * n;
        } else if (right == -1){
            x = arr[i] * (n - left);
        } else if (left == -1){
            x = arr[i] * (right-1);
        } else {
            x = arr[i] * (right - left - 1);
        }
        //cout << right << " " << left << " " << arr[i] << "\n";
        ans.emp(x);
    }
    sort(all(ans));
    cout << ans[n-1];
}
