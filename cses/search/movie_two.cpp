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

vpi things;

bool comp(pii a, pii b) {
	if (a.S == b.S) return a.F < b.F;
	return a.S < b.S;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	rep(i,0,N) {
		int a, b;
		cin >> a >> b;
		things.emplace_back(a, b);
	}
	
	sort(things.begin(), things.end(), comp);

	multiset<int> m;
		
	int score = 0;
	rep(i,0,N) {
		auto it = m.upper_bound(things[i].F);

		if (it != m.begin()) m.erase(--it);
		
		if (m.size() < K) {
			m.insert(things[i].S);
			score++;		
		}	
	}

	cout << score << endl;

    
    return 0;
}








