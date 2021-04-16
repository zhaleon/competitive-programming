#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int T, N, K;
int cur[1000000];
int nxt[1000000];
int temp[1000000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(Case,1,T) {
        cin >> N >> K;
        rep(i,0,N-1) cin >> nxt[i];
        iota(cur,cur+N,0);
        rep(j,1,K) {
            rep(i,0,N-1) temp[nxt[i]] = cur[i];
            rep(i,0,N-1) cur[i] = temp[i];
        }
        cout << "Case #" << Case << ": ";
        rep(i,0,N-1) cout << cur[i] << " \n"[i == N-1];
    }
    
    return 0;
}








