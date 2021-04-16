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

int T;
string a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> a >> b;

        int ans = INF;

        for (int i = 0; i < (int) a.length(); ++i) {
            for (int l = 1; l <= (int) a.length(); ++l) {
                if (i + l - 1 >= (int) a.length()) break;
                for (int j = 0; j + l - 1 < (int) b.length(); ++j) {
                    if (b.substr(j,l) == a.substr(i,l)) {
                        ans = min(ans, 2*(int)(a.length()-l-1));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}








