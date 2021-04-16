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

int T, N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(_,1,T) {
        cin >> N;
        if (N & 1) {
            rep(i,1,N) {
                rep(j,i+1,N) {
                    if ((j + (i & 1)) & 1) cout << -1 << ' ';
                    else cout << 1 << ' ';
                }
            }
        } else {
            rep(i,1,N) {
                rep(j,i+1,N) {
                    if (j == i+1 && i & 1) cout << 0 << ' ';
                    else if ((j+ (i & 1)) & 1) cout << -1 << ' ';
                    else cout << 1 << ' ';
                }
            }
        }
        cout << '\n';
    }
    
    return 0;
}








