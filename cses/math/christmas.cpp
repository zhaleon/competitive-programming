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
ll mod = 1e9+7;
ll d[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	d[0] = 1;
	rep(i,2,1000001) {
		d[i] = (i-1) * (d[i-1] + d[i-2]); 
		d[i] %= mod;
	}

	cout << d[N] << endl;
    
    return 0;
}








