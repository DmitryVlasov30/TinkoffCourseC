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

vector<vector<int>> all_posl;
void gen(int n, vector<int>& curr, int min_num){
    if (n == 0){
        all_posl.emplace_back(curr);
        return;
    }

    for (int number = 1; number <= n; ++number){
        if (number <= min_num){
            curr.emplace_back(number);
            gen(n-number, curr, number);
            curr.pop_back();
        }
    }
    
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    map<int, int> num;
    for(int i = 0; i < n; ++i){
        int el;
        cin >> el;
        arr.emplace_back(el);
        num[el] += 2;
    }
    vector<int> curr;
    vector<int> ans;
    gen(k, curr, k);
    for (int i = 0; i < len(all_posl); ++i){
        int count = k;
        map<int, int> el;   
        for (int j = 0; j < len(all_posl[i]); ++j){
            el[all_posl[i][j]] += 1;
        }
    
        bool flag = true;
        for (auto index : el){
            //cout << index.first << " num: " << num[index.first] << " el: " << index.second << "\n";
            if (num[index.first] < index.second){
                flag = false;
            }
        }
        if (flag == true){
            ans = all_posl[i];
        }
    
    }
    if (len(ans) != 0){
        cout << "Yes\n" << len(ans) << "\n";
        for (int i = 0; i < len(ans); ++i){
            cout << ans[i] << " ";
        } 
    } else {
        cout << "No";
    }
}
