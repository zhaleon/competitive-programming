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

int N, X;
ll arr[200001];
ll pref[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> X;
	rep(i,1,N+1) cin >> arr[i];

	int pt = 0, ans = 0;
	rep(i,1,N+1) {
		pref[i] = pref[i-1] + arr[i];
		
		while (pt < i && pref[i] - pref[pt] > X) pt++; 
		
		if (pref[i] - pref[pt] == X) ans++;
	}

	cout << ans << endl;
   		
    return 0;
}








