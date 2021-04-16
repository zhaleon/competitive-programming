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

bool isPrime(int x) {
	for (int i = 2; i < 101; i++) {
		if (x % i) return false;
	}
	return true;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int t, N;

	cin >> t;
	//103
	while(t--) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j == i || j == (i+1)%N) cout << 1 << ' ';
				else cout << 0 << ' ';
			} 
			cout << '\n';
		}

			
	}
    
    return 0;
}








