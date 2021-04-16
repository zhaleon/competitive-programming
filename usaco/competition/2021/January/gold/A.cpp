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

string S;

map<char, int> m;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> S;

	set<char> s;
	int ans = 0;

	rep(i,0,S.length()-1) {

		if (s.find(S[i]) != s.end()) {
			++ans;
			s.clear();
		}
		s.insert(S[i]);
	}

	cout << ans+1 << endl;

    
    return 0;
}








