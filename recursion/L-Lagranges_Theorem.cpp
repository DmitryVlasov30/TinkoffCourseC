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

using namespace std;



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<pair<int, int>, int> memory;
    for (int i = 0; i * i <= n; ++i){
        for (int j = 0; j * j <= n; ++j){
            //cout << i << " " << j << "\n";
            if (i*i + j*j < n){
                //cout << i << " " << j << "<--\n";
                memory[make_pair(i, j)] = 1;

            }
        }
    }
    if (n == 1){
        cout << 1 << " " << 0 << " " << 0 << " " << 0;
        return 0;
    } else if (n == 2){
        cout << 1 << " " << 1 << " 0 0";
        return 0;
    } else if (n == 3){
        cout << "1 1 1 0";
        return 0;
    }
    for(auto el : memory){
        int ost = n - ((el.fir.fir * el.fir.fir) + (el.fir.sec * el.fir.sec));
        for (auto el1 : memory){
            int x = ((el.fir.fir * el.fir.fir) + (el.fir.sec * el.fir.sec));
            int y = (el1.fir.fir * el1.fir.fir) + (el1.fir.sec * el1.fir.sec);
            if (ost == (el1.fir.fir * el1.fir.fir) + (el1.fir.sec * el1.fir.sec) && x + y == n){
                cout << el.fir.fir << " " << el.fir.sec << " " << el1.fir.fir << " " << el1.fir.sec << " ";
                return 0;
            }
        }

    }
}
