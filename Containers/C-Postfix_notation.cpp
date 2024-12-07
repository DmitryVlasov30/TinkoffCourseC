#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    stack<int> arr;
    for(int i = 0; i < n; ++i){
        int num, func, a, b;
        cin >> func;
        if (func == 0){
            cin >> num;
            arr.push(num);
        }
        else if (func == 1){
            a = arr.top();
            arr.pop();
            b = arr.top();
            arr.pop();
            arr.push(b+a);
        }
        else if(func == 2){
            a = arr.top();
            arr.pop();
            b = arr.top();
            arr.pop();
            arr.push(b-a);
        }
        else if(func == 3){
            a = arr.top();
            arr.pop();
            b = arr.top();
            arr.pop();
            arr.push(b*a);
        }
    }
    cout << arr.top();
    
}
