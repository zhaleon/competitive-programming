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

int N, M, K;
int arr[200000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

	rep(i,0,N) cin >> arr[i];

	sort(arr, arr+N);
	
	vector<int> people;

	rep(_,0,M) {
		int b; cin >> b;
		people.PB(b);
	}

	sort(people.begin(), people.end());

	int pt = 0, ans = 0;
	for (auto q : people) {
		if (arr[pt] > q + K) continue;
		while (pt < N && arr[pt] < q-K) pt++;
		if (pt == N) break;
		if (arr[pt] <= q+K) {
			pt++;
			ans++;
		}
	}

	cout << ans << endl;

    return 0;
}








