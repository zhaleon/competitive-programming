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

int t, N, M;

int arr[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> N >> M;

		rep(i,1,N+1) cin >> arr[i];

		int sum = 0;
		rep(i,1,N+1) sum += arr[i];

		cout << ((sum == M) ? "YES" : "NO") << endl;

	}
    
    return 0;
}








