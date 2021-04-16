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
#define rep(i,a,b) for (int i = a; i <= b; i++)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int q) {
	cout << "? " << q << endl;
	int cards;
	cin >> cards;
	return cards;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	int N, K;
	cin >> N >> K;

	uniform_int_distribution<int> thing(1, N);

	int num_queries = 1;

	int j = thing(rng);
	while (query(j) == K) {

		

		++num_queries;
		j = thing(rng);
	}
    
    return 0;
}








