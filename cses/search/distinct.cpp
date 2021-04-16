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

int N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	set<int> s;

	rep(_,0,N) {
		int x;
		cin >> x;
		s.insert(x);
	}

	cout << s.size() << endl;
    
    return 0;
}








