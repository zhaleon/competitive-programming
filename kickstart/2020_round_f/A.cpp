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

int T;

ll N, X;

ll arr[100001];
ll idx[100001];

bool comp(ll a, ll b) {
	if (arr[a]/X * X < arr[b] && (arr[a]/X+1)*X >= arr[b]) {
		//return a < b;
	}
	if (arr[a] == arr[b]) return a < b;
	return arr[a] < arr[b];
}

bool comp2(ll a, ll b) {
	if (arr[a]/X * X < arr[b] && (arr[a]/X+1)*X >= arr[b]) {
		return a < b; 
	}
	if (arr[a] == arr[b]) return a < b;
	return arr[a] < arr[b];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	for (int Case = 1; Case <= T; Case++) {
		cin >> N >> X;
		rep(i,1,N+1) cin >> arr[i];
		rep(i,1,N+1) idx[i] = i;

		sort(idx+1,idx+1+N,comp2);
		cout << "Case #" << Case << ": ";
		rep(i,1,N+1) {
			cout << idx[i];
			if (i == N) cout << "\n";
			else cout << ' ';
		}

	}
    
    return 0;
}








