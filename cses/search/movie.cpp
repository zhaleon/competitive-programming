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

int N;

pii movie[200000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;

	rep(i,0,N) cin >> movie[i].S >> movie[i].F;

	sort(movie, movie+N);
    
	int last_seen = movie[0].F, ans = 1;

	rep(i,1,N) {
		if (movie[i].S >= last_seen) {
			last_seen = movie[i].F;
			ans++;
		}
	}

	cout << ans << endl;

    return 0;
}








