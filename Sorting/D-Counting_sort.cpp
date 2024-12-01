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
#define emp emplace_back

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e7;


pair<vector<int>, vector<int>> count_sort(vector<int> arr, int n){
    int max_num = 0, min_num = inf;
    for(int i = 0; i < n; ++i){
        if (arr[i] > max_num){max_num = arr[i];}
        if (arr[i] < min_num){min_num = arr[i];}
    }
    //cout << max_num;
    vector<int> all_number_p(max_num+1, 0), all_num_m(abs(min_num)+1, 0);
    //cout << min_num << "--- min_num\n";
    if (min_num > 0){all_num_m = {}; min_num = 0;}
    for (int i = 0; i < n; ++i){
        if(arr[i] > 0){
            all_number_p[arr[i]]++; 
            continue;
        }
        if (len(all_num_m) != 0){
            all_num_m[abs(arr[i])]++;
        }
        
    }
    
    vector<int> min_arr, max_arr;
    int last = 0;
    for (int i = 0; i <= max_num; ++i){
        for (int j = 0; j < all_number_p[i]; ++j){
            max_arr.emp(i);
        }
    }
    //cout << len(all_num_m) << "allnum/n";
    for (int i = 0; i <= abs(min_num); ++i){
        for(int j = 0; j < all_num_m[i]; ++j){
            min_arr.emp(-i);
        }
    }
        
    return make_pair(max_arr, min_arr);
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

    pair<vector<int>, vector<int>> el = count_sort(arr, n);
    //cout << len(el.fir) << " " << len(el.sec) << " len \n";
    reverse(all(el.sec));
    //cout << " --- ";
    for(int i = 0; i < len(el.second); ++i){
        cout << el.second[i] << " ";
    }
    for(int i = 0; i < len(el.first); ++i){
        cout << el.first[i] << " ";
    }
}
