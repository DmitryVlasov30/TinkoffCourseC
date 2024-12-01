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
#include <random>

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

void quick_sort(vector<int>& arr, int left, int right){
    if (left >= right){
        return;
    }
    
    int a = arr[(left+right)/2];
    int i = left, j = right;
    while (i <= j){
        while (arr[i] < a){i++;}
        while (arr[j] > a){j--;}
        if (i <= j){
            swap(arr[i], arr[j]);
            j--; i++;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
    
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }
    quick_sort(arr, 0, n-1);
    for (int i = 0; i < len(arr); ++i){
        cout << arr[i] << " ";
    }
}   
