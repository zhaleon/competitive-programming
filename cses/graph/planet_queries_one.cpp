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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N, Q;
int t[200001];

int nxt[200001][30];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	rep(i,1,N) { 
		cin >> t[i];
		nxt[i][0] = t[i];
	}

	rep(i,1,29) 
		rep(j,1,N)
			nxt[j][i] = nxt[nxt[j][i-1]][i-1];
	

	rep(i,1,Q) {
		int a, b;
		cin >> a >> b;

		int jump = 0;
		while (b) {

			if (b & 1)
				a = nxt[a][jump];

			b >>= 1;
			jump++;
		}
		cout << a << endl;
	}

    return 0;
}








