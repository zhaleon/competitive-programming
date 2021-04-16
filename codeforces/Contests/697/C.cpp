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
#define rep(i,a,b) for (int i = a; i <= b; i++)

int T;

int A, B, K;
int a[200001];
int b[200001];


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> A >> B >> K;

		map<int, int> l; //in pair
		map<int, int> r; //
		map<pii, int> s;

		ll ans = 0;

		rep(i,1,K) cin >> a[i];
		rep(i,1,K) cin >> b[i];

		rep(i,1,K) {

			ans += i-1 - (l[a[i]] + r[b[i]]) + s[{a[i], b[i]}];

			++l[a[i]];
			++r[b[i]];
			++s[{a[i], b[i]}];
		}

		cout << ans << endl;
	}
    
    return 0;
}








