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

int mod = 1e9+7;
ll ways[62626];

void add(ll &a, ll b) {
	a += b;
	if (a > mod) a -= mod;
}

long long inv(long long base, long long mod) { //for prime modulo, there always exists ax + by = 1
    if (base == 0) return mod;
    
    long long res = (1-mod*inv(mod % base, base))/base;
    
    return (res < 0) ? res + mod : res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	ways[0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 62625; j >= i; j--) 
			add(ways[j], ways[j-i]);

	if (N*(N+1)/2 & 1) 
		cout << 0 << endl;
	else 
		cout << ways[N*(N+1)/4] * inv(2, mod) % mod << endl;
    
    return 0;
}








