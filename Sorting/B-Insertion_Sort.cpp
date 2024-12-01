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
#define emp emplace_back

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e7;


vector<int> insection_sort(vector<int> arr, int n){
    for(int i = 0; i < n; ++i){
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            --j;
        }
    }
    return arr;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }

    arr = insection_sort(arr, n);
    
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}
