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


bool comp(string a, string b){
    int a_int = stoi(a.substr(0, len(a)-1)), b_int =  stoi(b.substr(0, len(b)-1));
    char a_str = a[len(a)-1], b_str = b[len(b)-1];
    return a_int < b_int || a_int == b_int && a_str < b_str;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, map<string, pair<string, string>>, decltype(&comp)> Map(comp);
    for(int i = 0; i < n; ++i){
        string clas, last_name, name, date;
        cin >> last_name >> name >> clas >> date;
        Map[clas][last_name] = {name, date};

    }

    for (auto el : Map){
        for (auto el1 : el.second){
            cout << el.first << " " << el1.first << " " << el1.second.first << " " << el1.second.second << "\n";
        }
    }
}
