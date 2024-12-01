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

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> arr;
    for (int i = 0; i < n; ++i) {
        int el; cin >> el; arr.emp(el);
	}
	int max_sum = arr[0], sum = 0, start = 1, end = 1, c_start = 1;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
		if (sum > max_sum) {
			max_sum = sum;
			start = c_start;
			end = i + 1;
		}
		if (sum < 0) {
			sum = 0;
			c_start = i + 2;
		}
	}
	cout << start << " " << end << " " << max_sum;
}
