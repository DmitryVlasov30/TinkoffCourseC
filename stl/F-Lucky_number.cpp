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

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        map<int, int> num;
        for(int i = 0; i < n; ++i){
            int el;
            cin >> el;
            arr.emplace_back(el);
            num[el]++;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int num2 = k-arr[i];
            if (num.find(num2) != num.end()){
                ans += num[num2];
                if (arr[i] == num2){
                    ans--;
                }
            }
        }
        cout << ans/2 << "\n";
    }
}
