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
const int inf = 1e18;

bool name_sort_comp(vector<string> a, vector<string> b){
    return a[0] < b[0];
}

bool surname_sort_comp(vector<string> a, vector<string> b){
    return a[1] < b[1];
}

bool date_sort_comp(vector<string> a, vector<string> b){
    if (a[2] != b[2]){
        return stoi(a[2]) < stoi(b[2]);
    } else if (a[3] != b[3]){
        return stoi(a[3]) < stoi(b[3]);
    } else {
        return stoi(a[4]) < stoi(b[4]);
    }
}

bool rating_sort_comp(vector<string> a, vector<string> b){
    return stoi(a[5]) > stoi(b[5]);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, int> univer;
    for (int i = 0; i < n; ++i) {
        string el;
        int col;
        cin >> el >> col;
        univer[el] += col;
    }

    int m;
    cin >> m;
    vector<vector<string>> el;
    for (int i = 0; i < m; ++i) {
        string na, sur;
        string d, m, y, rait, count_univer;
        cin >> na >> sur >> d >> m >> y >> rait >> count_univer;
        vector<string> arr;
        arr.emp(na);
        arr.emp(sur);
        arr.emp(d);
        arr.emp(m);
        arr.emp(y);
        arr.emp(rait);
        string all_unik = "";
        for (int j = 0; j < stoi(count_univer); ++j) {
            string un;
            cin >> un;
            all_unik += un + " ";
        }
        arr.emp(all_unik);
        el.emp(arr);
    }
    sort(all(el), name_sort_comp);
    stable_sort(all(el), surname_sort_comp);
    stable_sort(all(el), date_sort_comp);
    stable_sort(all(el), rating_sort_comp);
    /*
    cout << "-----\n";
    for(int i = 0; i < len(el); ++i){
        for (int j = 0; j < len(el[i]); ++j){
            cout << el[i][j] << " ";
        }
        cout << "\n";
    }
    */
    map<string, vector<vector<string>>> ans;
    for (int i = 0; i < len(el); ++i){
        string univers = el[i][6];
        istringstream is(univers);

        string univ;
        vector<string> arr;
        while(is >> univ){
            arr.emp(univ);
        }
        //cout << len(arr) << " " << el[i][0] << " " << el[i][1] << "\n";
        for (auto j : arr){
            if (univer[j] != 0){
                --univer[j];
                vector<string> prom;
                prom.emp(el[i][0]);
                prom.emp(el[i][1]);
                prom.emp(el[i][2]);
                prom.emp(el[i][3]);
                prom.emp(el[i][4]);
                ans[j].emp(prom);
                break;
            }
        }
    }

    for(auto i : univer){
        if (ans.find(i.fir) == ans.end()){
            ans[i.fir] = {};
        }
    }
    for(auto i : ans){
        cout << i.fir;
        vector<vector<string>> arr = i.sec;
        sort(all(arr), date_sort_comp);
        sort(all(arr), name_sort_comp);
        sort(all(arr), surname_sort_comp);
        for(int j = 0; j < len(arr); ++j){
            cout << "\t" << arr[j][0] << " " << arr[j][1];
        }
        cout << "\n";

    }

}
