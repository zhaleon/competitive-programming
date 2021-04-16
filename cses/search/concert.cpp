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

int N, M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	map<int, int> m;

	rep(i,0,N) {
		int h; cin >> h;
		m[h]++;
	}

	rep(i,0,M) {
		int t; cin >> t;
		
		auto it = m.upper_bound(t);

		if (it != m.begin()) --it;
		
		if (m.empty() || it->F > t) {
			cout << -1 << endl;
		} else {
			cout << it->F << endl;
			it->S--;
			if (!it->S) m.erase(it);
		}

	}


    
    return 0;
}








