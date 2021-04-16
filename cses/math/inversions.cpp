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

int N;
double r[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N+1) cin >> r[i];

	double ans = 0;
	rep(j,1,N+1) 
		rep(i,j+1,N+1)
			if (r[j] > r[i]) {
				ans += r[i]*(r[i]-1)/(2*r[j]*r[i]) + (r[j]-r[i]) / r[j]; 
			} else {
				ans += r[j]*(r[j]-1)/(2*r[j]*r[i]);
			}

	cout << fixed << setprecision(6) << ans << endl;
    return 0;
}








