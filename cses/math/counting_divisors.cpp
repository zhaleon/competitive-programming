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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;

	vector<ll> answers;
	
	vi divisors(1000001);

	rep(i,1,1000001) {
		for (int j = i; j <= 1000000; j += i) {
			divisors[j]++;
		}
	}
	
	int reps = 0;
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		cout << divisors[x] << endl;
	}
	assert(reps <= N);
    return 0;
}








