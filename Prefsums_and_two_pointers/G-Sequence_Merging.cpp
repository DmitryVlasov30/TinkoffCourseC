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
    ll x;
    cin >> x;
    ll i = 1, j = 1, result;
    while(x--){
        ll ai = i*i, bj = j*j*j;
        if (ai < bj){
            result = ai;
            i++;
        } else if (bj < ai) {
            result = bj;
            j++;
        } else {
            result = ai;
            i++; j++;
        }
    }
    cout << result;
}
