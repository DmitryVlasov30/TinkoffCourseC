#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> arr;
	for (int i = 0; i < n; ++i) {
		ll b;
		cin >> b;
		arr.emplace_back(b);
	}
	ll max_sum = arr[0], sum = 0, start = 1, end = 1, c_start = 1;
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
	cout << max_sum << '\n';
}
