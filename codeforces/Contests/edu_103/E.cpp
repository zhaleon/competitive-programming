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

int N, M, K;
string s[100001];
string p[100001];
int restraint[100001];

bool start[100001];

map<string, int> m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

	rep(i,1,N) cin >> s[i];
	rep(i,1,M) cin >> p[i] >> restraint[i];

	rep(i,1,N) m[s[i]] = i;

	rep(k,1,M) {
		rep(i,0,(1 << K)-1) {
			rep(j,0,K-1) {
				if ((1 << j) & i) {
						
				}
			}
		}
	}

	rep(i,1,M) {
		string cur = s[restraint[i]];
	}

    return 0;
}








