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

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int el;
        cin >> el;
        arr.emplace_back(el);
    }

    deque<int> rez;
    for(int i = 0; i < n; ++i){
        if(!rez.empty() && i - rez.front() >= k){
            rez.pop_front();
        }
        
        while (!rez.empty() && arr[i] < arr[rez.back()]){
            rez.pop_back();
        }

        rez.push_back(i);
        
        if(i >= k-1){
            cout << arr[rez.front()] << " ";
        }
    }
}
