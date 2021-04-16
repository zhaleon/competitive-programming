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

int X, N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> X >> N;

	set<int> s;
	multiset<int> lengths;
	s.insert(0);
	s.insert(X);
	lengths.insert(X);

	rep(i,0,N) {
		int p; cin >> p;

		auto nxt = s.upper_bound(p);
		auto pre = --s.upper_bound(p); 
	
		s.insert(p);

		lengths.erase(lengths.find(*nxt-*pre));
		lengths.insert(*nxt-p);
		lengths.insert(p-*pre);

		cout << *lengths.rbegin() << endl;	
	}
    
    return 0;
}








