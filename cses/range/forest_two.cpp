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
bool grid[1001][1001];
int bit[1001][1001];

void update(int x, int y) {
	int delta = 1;
	if (grid[x][y])
		delta = -1;

	grid[x][y] = !grid[x][y];

	while (x < N+1) {
		int k = y;
		while (k < N+1) {
			bit[x][k] += delta;
			k += k & -k;
		}
		x += x & -x;
	}
}

int sum(int x, int y) {
	int res = 0;
	while (x) {
		int k = y;
		while(k) {
			res += bit[x][k];
			k -= k & -k;
		}
		x -= x & -x;
	}
	return res;
}

int sum(int a, int b, int c, int d) {
	return sum(c,d) + sum(a-1,b-1) - sum(a-1, d) - sum(c, b-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	cout << endl;

	rep(i,1,N+1) {
		rep(j,1,N+1) {
			char a; cin >> a;
			if (a == '*')
				update(i,j);
			//cout << grid[i][j];
		} //cout << endl;
	}

	rep(i,0,Q) {
		int a,b,c,d,e;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(b, c);
		} else {
			cin >> b >> c >> d >> e;
			cout << sum(b,c,d,e) << endl;
		}
	}
    return 0;
}








