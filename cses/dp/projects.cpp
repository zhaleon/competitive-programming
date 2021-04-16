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
ll dp[400001];

map<int, int> m;

int a[200001];
int b[200001];
int p[200001];

vpi starts[400001];
vpi ending[400001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
   
	rep(i,1,N+1) {
		cin >> a[i] >> b[i] >> p[i];
	   	m[a[i]], m[b[i]];
	}

	int index = 0;
	for (auto &elem : m) elem.S = ++index;

	rep(i,1,N+1) {
		starts[m[a[i]]].emplace_back(p[i], a[i]);
		ending[m[b[i]]].emplace_back(p[i], a[i]);
	}

	rep(i,1,2*N+1) {
		dp[i] = dp[i-1];
		for (auto project : ending[i]) {
			dp[i] = max(dp[i], dp[m[project.S]-1] + project.F);
		}	
	}	

	cout << dp[index] << endl;

    return 0;
}








