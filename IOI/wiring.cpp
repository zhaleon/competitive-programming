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

int64_t min_total_length(vi r, vi b) {
    int N = r.size(), M = b.size();
    
    vpi points;
    
    rep(i,0,N-1) points.emplace_back(r[i], 1);
    rep(i,0,M-1) points.emplace_back(b[i], 0);
    
    vector<ll> dp(N+M+1, 0);
    
    
    
    return res;
}