#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()


using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin >> q;
    
    stack<ll> arr, min_arr;
    for(int i = 0; i < q; ++i){
        ll func, num;
        cin >> func;
        if(func == 1){
            cin >> num;
            arr.push(num);
            if (!min_arr.empty()){
                min_arr.push(min(num, min_arr.top()));
            } 
            else {
                min_arr.push(num);
            }
        }
        else if(func == 2){
            cout << arr.top() << "\n";
            arr.pop();
            min_arr.pop();
        }
        else {
            cout << min_arr.top() << "\n";
        }
    }
}
