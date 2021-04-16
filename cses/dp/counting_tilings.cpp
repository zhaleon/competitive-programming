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

const int mod = 1e9+7;
int N, M;
ll ans[1 << 10];
ll next_row[1 << 10];

int cur_mask = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    ans[0] = 1;

    rep(j,1,M) {
        rep(i,0,N-1) {
            rep(mask,0,(1 << N)-1) {
                next_row[mask] = ans[mask ^ (1 << i)];
                if (i && !(mask & (3 << (i-1))))
                    next_row[mask] += ans[mask ^ (1 << (i-1))];

                if (next_row[mask] >= mod) next_row[mask] -= mod;
            }
            rep(i,0,(1 << N)-1) ans[i] = next_row[i];
        }
    }

    cout << ans[0] << endl;

    return 0;
}








