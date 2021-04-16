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

int t, N;
int a[1001][1001];
int b[1001][1001];

void swap_row(int j) {
	rep(i,1,N) a[j][i] = !a[j][i];
}

void swap_col(int j) {
	rep(i,1,N) a[i][j] = !a[i][j];
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> N;
		
		rep(i,1,N) {
			rep(j,1,N) {
				char x; cin >> x;
				a[i][j] = x == '1';
			}
		}

		rep(i,1,N) {
			rep(j,1,N) {
				char x; cin >> x;
				b[i][j] = x == '1';
			}
		}

		rep(i,1,N) if (a[1][i] != b[1][i]) swap_col(i);
		
		bool works = 1;
		rep(i,2,N) {
			bool match = a[i][1] == b[i][1];
			rep(j,2,N) {
				works = works && (match == (a[i][j] == b[i][j]));
			}
		}

		if (works) cout << "YES\n";
		else cout << "NO\n";
	}
    
    return 0;
}








