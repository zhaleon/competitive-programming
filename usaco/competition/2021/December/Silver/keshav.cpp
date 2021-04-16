#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/* vector<int> adj[100001]; */
bool comp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
    return x.second < y.second;
}
map<int, set<int>> time_dead;
bool isdead[1001];
int whokilled[1001];
int main () {
    /* std::ios_base::sync_with_stdio(false);cin.tie(nullptr); */
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<char> type(n);
    for(int i = 0; i < n; i++) {
        cin >> type[i];
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0; i <= 1000 ;i++) {
        whokilled[i] = i;
    }
    vector<pair<pair<int, int>, int>> stopped;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(i == j) continue;
            if(type[i] == type[j]) continue;
            //wont intersect kekw
            //if east (x, y) goes to (x + 1, y)

            if(type[i] == 'E' and type[j] == 'N') {
                if(a[j].first < a[i].first) {
                    //never hit each other 
                    continue;
                }
                else {
                    int x = a[j].first;
                    int y = a[i].second;
                    /* printf("i: %d, j: %d, x: %d, y: %d\n", i, j, x, y); */
                    if(x - a[i].first < y - a[j].second) {
                        //i hit it first
                        /* adj[i].push_back(j); */
                        stopped.push_back({{i, j}, x - a[i].first});
                    }
                    else if(x - a[i].first > y - a[j].second) {
                        /* adj[j].push_back(i); */
                        stopped.push_back({{i, j}, y - a[j].second});
                    }
                }
            }

            else {
                if(a[i].first < a[j].first) {
                    continue;
                }
                int x = a[i].first;
                int y = a[j].second;
                if(x - a[j].first < y - a[i].second) {
                    //i hit it first
                    /* adj[j].push_back(i); */
                    stopped.push_back({{j, i}, x - a[j].first});
                }
                else if(x - a[j].first > y - a[i].second) {
                    /* adj[i].push_back(j); */
                    stopped.push_back({{i, j}, y - a[i].second});
                }
            }
        }
    }
    /* for(int i = 0; i < n; i++) { */
        /* for(auto j : adj[i]) { */
            /* printf("%d stopped %d\n", i + 1, j + 1); */
        /* } */
    /* } */
    sort(stopped.begin(), stopped.end(), comp);
    /* for(auto i : stopped) { */
        /* printf("(i, j) = (%d, %d), time: %d\n", i.first.first + 1, i.first.second + 1, i.second); */
    /* } */
    /* exit(0); */
    vector<ll> ans(n + 1);
    for(int i = 0; i < (int)stopped.size(); i++) {
        int x = stopped[i].first.first;
        int y = stopped[i].first.second;
        int t = stopped[i].second;
        if(!isdead[x] and !isdead[y]) {
            ++ans[x];
            time_dead[t].insert(y);
            isdead[y] = true;
            whokilled[y] = x;
            /* printf("processed %d killing %d at time %d\n", x+1, y+1, t); */
        }
        if(isdead[y]) continue;
        /* continue; */

        if(isdead[x] and time_dead[t].count(x)) {
            //trace back
            ll val = whokilled[x];
            while(val != whokilled[val]) {
                val = whokilled[val];
            }
            ++ans[val];
            isdead[y] = true;
            ++ans[x];
            whokilled[x] = val;
            time_dead[t].insert(y);
            /* printf("while processing %d killing %d, we traced back to %lld\n", x, y, val); */
        }

    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    /* cout << "0\n0\n1\n2\n1\n0\n"; */
    //draw edges

}

