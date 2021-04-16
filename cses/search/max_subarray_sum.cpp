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
ll arr[200000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	ll running = 0, ans = -INF*(ll)INF;
	rep(i,0,N) {
		cin >> arr[i];
		running += arr[i];
		ans = max(ans, running);
		if (running < 0) running = 0;
	}

	cout << ans << endl;
    
    return 0;
}








