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
int X, Y;
string S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    cin >> X >> Y >> S;
    
    int N = S.length();
    
    map<int, int> m;
    int k = 0;
    for (int i = 0; i < N; ++i) if (S[i] == '?') m[i] = k++;
   
    int ans = INF;
    for (int mask = 0; mask < (1 << k); mask++) {
        int tot = 0;
        for (int i = 0; i < N-1; ++i) {
            // 1 == C, 0 == J
            int a = (S[i] == '?') ? (mask & (1 << m[i])) > 0 : S[i] == 'C'; 
            int b = (S[i+1] == '?') ? (mask & (1 << m[i+1])) > 0: S[i+1] == 'C'; 
            tot += (a < b) * Y;
            tot += (b < a) * X;
        }
        ans = min(tot, ans);
    }
    cout << "Case #1: " << ans << endl;


    return 0;
}








