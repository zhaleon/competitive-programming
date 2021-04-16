#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    
    vpi fences;
    
    rep(i,1,N) {
        int a;
        cin >> a;
        
        fences.emplace_back(a,i);
    }
    
    sort(fences.begin(), fences.end());
    
    set<int> s;
    s.insert(0);
    s.insert(N+1);
    
    ll ans = 0;
    rep(i,0,N-1) {
        auto nxt = s.upper_bound(fences[i].S);
        auto pre = prev(nxt);
        
        ans = max(ans, (ll)fences[i].F * (*nxt-*pre-1));
        
        s.insert(fences[i].S);
    }

    cout << ans << endl;
    
    return 0;
}