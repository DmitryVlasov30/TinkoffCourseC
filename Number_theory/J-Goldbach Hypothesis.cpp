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
#include <random>
#include <deque>

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

vector<int> resheto(int n){
    vector<char> arr(n+1, '0');
    vector<int> ans;
    arr[1] = '1';
    for (int i = 2; i <= n; ++i){
        if (arr[i] == '0'){
            for (int j = i*i; j <= n; j+=i){
                arr[j] = '1';
            }
        }
    } 
    for (int i = 2; i <= n; ++i){
        if (arr[i] == '0'){
            ans.emp(i);
        }
    }
    return ans;
}


bool prime(int n){
    bool flag = true;
    for (int i = 2; i <= sqrt(n); ++i){
        if (n % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}


int32_t main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> prime_num = resheto(n);
    vector<pair<int, int>> arr;
    for (int i = 0; i < len(prime_num); ++i){
        arr.emp(make_pair(n-prime_num[i], prime_num[i]));
    }
    for (int i = 0; i < len(arr); ++i){
        if (prime(arr[i].fir)){
            cout << arr[i].fir << " " << arr[i].sec;
            break;
        }
    }
}


