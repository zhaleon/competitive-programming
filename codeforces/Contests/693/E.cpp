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

int T, N;

pii p[200001];
int ans[200001];

bool comp(pii a, pii b) {
	return min(a.F,a.S) < min(b.F,b.S);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> p[i].F >> p[i].S;
		rep(i,1,N) ans[i] = -1;

		sort(p+1, p+1+N);

		map<int, int> m;

		rep(i,1,N) {
			int small = INF;
			int j = 0;
			while (i < N && p[i].F == p[i+1].F) {
				if (p[i].S <
				i++;
			}
			if (m.upper_bound(p[i].S) == m.end()) 
				continue;
			else
				ans[i] = m.upper_bound(p[i].S)->S;
				
			m[p[i].S] = i; 
		}

		//sort(p+1, p+1+N, comp);

		map<int, pii> om;

		rep(i,1,N) {

			if (om.upper_bound(p[i].F) == om.end())
				continue;
			else 
				ans[i] = om.upper_bound(p[i].F)->S.S;

			auto it = --om.end();

			while (it != om.begin() && (it->S).F > p[i].F) om.erase(it--); 

			om[p[i].S] = {p[i].F, i};
		}

		rep(i,1,N) cout << ans[i] << ' '; cout << '\n';
	}

    return 0;
}








