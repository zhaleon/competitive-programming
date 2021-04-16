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

int N, K;
ll arr[200000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	rep(i,0,N) cin >> arr[i];
   
	ll low = 1, high = 1e15;

	auto works = [](ll X) {
		int pt = 0;
		rep(i,0,K) {
			ll running = 0;
			while (pt < N && running + arr[pt] <= X) running += arr[pt++];
		}
		return pt == N;
	};

	while (low + 1 < high) {
		ll mid = (low+high)/2;
		if (works(mid)) high = mid;
		else low = mid;
	}	
	
	cout << high << endl;

    return 0;
}








