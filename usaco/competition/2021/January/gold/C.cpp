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

int N, K, M;

pii swaps[200001];

set<int> s[100001];
set<int> ans[100001];

int nxt[100001];
int nxt2[100001];

int cows[100001];
int temp[100001];

int parent[100001];
int size[100001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;

	if (size[a] < size[b]) swap(a,b);

	size[a] += size[b];
	parent[b] = a;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K >> M;

   	rep(i,1,K) cin >> swaps[i].F >> swaps[i].S;

	iota(cows+1, cows+1+N, 1);
	iota(parent+1, parent+1+N, 1);
	fill(size+1, size+1+N, 1);

	rep(i,1,N) s[i].insert(i), ans[i].insert(i);

	// nlogn
	rep(i,1,K) {
		int a = swaps[i].F, b = swaps[i].S;
		swap(cows[a], cows[b]);
		s[cows[a]].insert(a);
		s[cows[b]].insert(b);
	}

	rep(i,1,N) nxt[cows[i]] = i, nxt2[i] = cows[i];

	if (M - K <= K) {
		rep(i,1,M-K) {
			int a = swaps[i].F, b = swaps[i].S;
			swap(cows[a], cows[b]);
			s[cows[a]].insert(a);
			s[cows[b]].insert(b);
		}
		rep(i,1,N) cout << s[i].size() << '\n';
		return 0;
	}

	rep(j,1,int(1e7)/N) {
		rep(i,1,N) {
			for (auto it : s[i]) ans[cows[i]].insert(it);
		}
		rep(i,1,N) temp[i] = cows[i];
		rep(i,1,N) cows[i] = temp[nxt2[i]];
	}
	rep(i,1,N) cout << ans[i].size() << '\n';

    return 0;
}








