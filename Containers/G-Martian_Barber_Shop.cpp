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
    deque<ll> clients;
    deque<ll> ans;
    ll queue_len = 0;
    for (int i = 0; i < n; ++i){
        ll hh, mm, terp;
        cin >> hh >> mm >> terp;
        ll time = hh*60+mm;
        if(!clients.empty()){
            ll last_time = clients.front();
            if (last_time <= time){
                while(!clients.empty() && clients.front() <= time){
                    clients.pop_front();
                    queue_len--;
                } 
            }
        }
        if (queue_len == 0){
            queue_len++;
            clients.emplace_back(time+20);
            ans.emplace_back(time+20);          
            continue;
        }
        if (queue_len <= terp){
            ll end_time = clients.back(); 
            queue_len++;
            clients.emplace_back(end_time+20);
            ans.emplace_back(end_time+20);  
            continue;
        }
        if (len(clients) > terp){
            ans.emplace_back(time);
        }

    }
    for (int i = 0; i < len(ans); ++i){
        cout << ans[i]/60 << " " << ans[i]%60 << "\n";
    }
}
