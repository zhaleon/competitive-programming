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


ll T, N, M, X;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> N >> M >> X;
        ll row = (X-1) % N + 1;
        ll col = (X-1) / N + 1;

        cout << (row - 1) * M + col << endl;
    }
    
    
    return 0;
}








