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
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	vpi adj = {{1,2}, {3,4}};
	adj.emplace_back(4,5);
	
	for (const auto &[i,j] : adj) {
		cout << i << ' ' << j << endl;
	}

			
    return 0;
}
