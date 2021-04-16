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

ll pref[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	rep(i,1,N+1) {
		cin >> pref[i];
		pref[i] ^= pref[i-1];
	}

	rep(i,0,Q) {
		int a, b;
		cin >> a >> b;
		cout << (pref[b]^pref[a-1]) << endl;
	}
    
    return 0;
}








