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

int K;

double res[64][64];
double adj[64][64];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 8, -8};

bool ok(int x, int dx, int dy) { 
	if (dx)
		return (x % 8 + dx) < 8 && (x % 8 + dx) >= 0;
	return x+dy < 64 && x+dy >= 0;
}

template<size_t N> void mult(double (&a)[N][N], double (&b)[N][N]) {
	double temp[N][N];
	rep(i,0,N) rep(j,0,N) temp[i][j] = 0.0;

	rep(i,0,N)
		rep(j,0,N)
			rep(k,0,N)
				temp[i][j] += a[i][k] * b[k][j];

	rep(i,0,N)
		rep(j,0,N) 
			a[i][j] = temp[i][j];

}

void process() {
	rep(i,0,64) {
		int neighbors = 0;
		rep(j,0,4) 
			if (ok(i, dx[j], dy[j]))
				neighbors++;
			
		rep(j,0,4)
			if (ok(i, dx[j], dy[j])) 
				adj[i][i+dx[j]+dy[j]] = 1.0/neighbors;
	}
}

int main() {

	cin >> K;

	rep(i,0,64) res[i][i] = 1;
	
	process();

	while (K) {
		if (K & 1) 
			mult<64>(res, adj);
		mult<64>(adj, adj);
		K >>= 1;
	}

	double ans = 0;
	rep(i,0,64) {
		double P = 1.0;
		rep(j,0,64) P *= (1 - res[j][i]);
		//if (i % 8 == 0) cerr << '\n';
		//cerr << fixed << setprecision(6) << P << ' ';
		ans += P;
	}
	cout << fixed << setprecision(6) << ans << endl;

    return 0;
}








