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
    string str;
    map<string, vector<string>> classification;
    while (getline(cin, str)){
        string prod = "";
        for (int i = 0; i < len(str); ++i){
            if (str[i] == ' '){
                break;
            } 
            string el(1, str[i]); 
            prod += el;
        }
        string fruit = "";
        for (int i = len(prod)+2; i < len(str); ++i){
            if (str[i] == ','){
                classification[fruit].emplace_back(prod);
                fruit = "";
                continue;
            }
            if (str[i] == ' '){
                continue;
            }
            string el(1, str[i]);
            fruit += el;
        }
        classification[fruit].emplace_back(prod);

    }
    cout << len(classification) << "\n";
    for (auto el : classification){
        string ans = el.first + " - ";
        for (int i = 0; i < len(el.second); ++i){
            if (i == len(el.second)-1){
                ans += el.second[i];
            } else {
                ans += el.second[i] + ", ";
            }
        }
        cout << ans << "\n";
        
    }

}
