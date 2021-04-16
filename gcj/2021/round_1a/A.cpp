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
#define rep(i,a,b) for (int i = a; i <= (int) b; ++i)

int T, N;
string x[101];

bool bigger(string a, string b) {
    if (a.length() == b.length()) return a > b;
    return a.length() > b.length();
}

void inc(string& a) {
    int p = a.length() - 1;
    while (p >= 0) {
        if (a[p] != '9') {
            ++a[p];
        } else {
            a[p] = '0';
            --p;
        }
    }
    if (p == -1) a = "1" + a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    rep(Case,1,T) {
        cin >> N;
        rep(i,1,N) cin >> x[i];
        ll ans = 0;

        rep(i,2,N) {
            if (bigger(x[i], x[i-1])) continue;
            /* if (stoi(x[i-1]) < stoi(x[i])) continue; */
            assert(x[i-1].length() >= x[i].length());

            unsigned int j = 0;
            while (j < x[i].length() && x[i][j] == x[i-1][j]) ++j;

            if (x[i] == x[i-1]) {
                ++ans;
                x[i] += "0";
                continue;
            }

            if (j == x[i].length()) {
                while (j < x[i-1].length() && x[i-1][j] == '9') x[i] += "9", ++j, ++ans;

                if (x[i] == x[i-1]) {
                    ++ans;
                    x[i] += "0";
                    continue;
                }

                while (x[i].length() < x[i-1].length()) x[i] += x[i-1][j++], ++ans;

                inc(x[i]);
                /* x[i] = to_string(stoi(x[i]) + 1); */ 
            } else {
                if (x[i][j] > x[i-1][j]) {
                    while (x[i].length() < x[i-1].length()) x[i] += "0", ++ans;
                } else if (x[i][j] < x[i-1][j]) {
                    while (x[i].length() <= x[i-1].length()) x[i] += "0", ++ans;
                }
            }

            if (x[i] == x[i-1]) ++ans, x[i] += "0";
        }

        printf("Case #%i: %lli\n", Case, ans);
        /* rep(i,1,N) cout << x[i] << ' '; cout << endl; */
    }

    
    return 0;
}








