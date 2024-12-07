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
        if (skobki[i] == '(' || skobki[i] == '{' || skobki[i] == '['){
            open_skobki.push(skobki[i]);
            //cout << open_skobki.top() << '\n';
        }
        else if ((skobki[i] == ')' || skobki[i] == '}' || skobki[i] == ']') && open_skobki.empty()){
            flag = true;
            break;
        }
        else if((skobki[i] == ')' && open_skobki.top() == '(') || (skobki[i] == '}' && open_skobki.top() == '{') || (skobki[i] == ']' && open_skobki.top() == '[')) {
            open_skobki.pop();
        }
        else{
            flag = true;
        }
    }
    if (open_skobki.empty() && flag == false){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}
