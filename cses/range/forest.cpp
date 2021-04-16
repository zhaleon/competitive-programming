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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N, Q;

int forest[1001][1001];
int   pref[1001][1001];

int query(int a, int b, int c, int d) {
	return pref[c][d] + pref[a-1][b-1] - pref[c][b-1] - pref[a-1][d];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	rep(i,1,N+1) {
		rep(j,1,N+1) {
			char a;
			cin >> a;
			if (a == '*') forest[i][j] = 1;
		}
	}
   
   	rep(i,1,N+1) {
		rep(j,1,N+1) {
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + forest[i][j];
		}
	}	

	rep(i,0,Q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << query(a,b,c,d) << endl;
	}

    return 0;
}








