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
string S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> N >> K;
        cin >> S;

        int ans = 0;

        for (int i = 0; i < (int)S.length(); ++i) {
            for (int j = i + K-1
        }
        cout << ans << endl;
    }
    
    return 0;
}








