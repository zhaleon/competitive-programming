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

int N, X;
int w[20];

pii dp[1 << 20];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> X;
    rep(i,0,N-1) cin >> w[i];
    
    dp[0] = {1,0};
    
    for (int i = 1; i < (1 << N); i++) {
        dp[i] = {INF, INF};
        
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                
                pii cur = dp[i ^ (1 << j)];
                
                if (cur.S + w[j] <= X) {
                    cur.S += w[j];
                } else {
                    cur.F++;
                    cur.S = w[j];
                }
                
                dp[i] = min(dp[i], cur);
            }
        }
        
    }
    
    cout << dp[(1 << N)-1].F << endl;
    
    return 0;
}