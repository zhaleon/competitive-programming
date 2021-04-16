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

int N, a, b;

double ways[101][601];

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> a >> b;
   	ways[0][0] = 1;
	for (int cur = 1; cur <= N; cur++) {
		for (int roll = 1; roll <= 6; roll++) {
			for (int v = roll; v <= 6*N; v++) {
				ways[cur][v] += ways[cur-1][v-roll];
			}
		}
		for (int v = 1; v <= 6*N; v++)
			ways[cur][v] /= 6.0;
	}

	double ans = 0;

	rep(i,a,b+1) 
		ans += ways[N][i];
	
	printf("%.6f\n", ans);

    return 0;
}








