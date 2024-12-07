#include <iostream>
#include <stack>
#include <queue>
 
using namespace std;
 
int main() {
    stack<char> open_skobki;
    string skobki;
    cin >> skobki;
    bool flag = false;
    for(int i = 0; i < skobki.size(); ++i){
        if (skobki[i] == '('){
            open_skobki.push('(');
        }
        else if (skobki[i] == ')' && open_skobki.empty()){
            flag = true;
            break;
        }
        else if(skobki[i] == ')') {
            open_skobki.pop();
        }
    }
    if (open_skobki.empty() && flag == false){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}
