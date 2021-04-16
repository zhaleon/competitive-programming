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
string S;
int X, Y;

int test_range(int l, int r) {
    if (l == r) return min((S[l-1] == 'J')*Y + (S[r+1] == 'J')*X, (S[l-1] == 'C')*X + (S[r+1] == 'C')*Y);
    

    int res = 10000000;
    res = min(res, (S[l-1] == 'J') * Y + (S[r+1] == 'C') * Y + X);
    res = min(res, (S[l-1] == 'C') * X + (S[r+1] == 'J') * X + Y);
    res = min(res, (S[l-1] == 'J') * Y + (S[r+1] == 'J') * X);
    res = min(res, (S[l-1] == 'C') * X + (S[r+1] == 'C') * Y);
    // C J
    // J C
    // C C
    // J J

    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(Case,1,T) {
        cin >> X >> Y >> S;

        int tot = 0;
        for (int i = 0; i < (int) S.length() - 1; ++i) {
            if (S[i] == 'C' && S[i+1] == 'J') tot += X; 
            else if (S[i] == 'J' && S[i+1] == 'C') tot += Y;
        }

        int L = 0, R = S.length() - 1;

        while (L < (int) S.length() && S[L] == '?') ++L;
        while (R > 0 && S[R] == '?') --R;

        for (int i = L; i <= R; ++i) {
            if (S[i] == '?') {
                int j = i;
                while (j < R && S[j+1] == '?') ++j;
                tot += test_range(i,j);                    
                i = j;
            }
        }

        printf("Case #%i: %i\n", Case, tot);
    }
    
    return 0;
}








