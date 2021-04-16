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
#define int ll

int N;
int parent[1001];
vi child[1001];
int v[1001];
int ans[1001];
int times[1001];

struct data {
	int x, y, dir, dist, id;
	data() {};
	data(int x, int y, int dir, int id) : x(x), y(y), dir(dir), id(id) {};
};

bool comp1(data a, data b) {
	return a.dist < b.dist;
}

void dfs(int cur = 1, int p = -1) {
	v[cur] = 1;
	ans[cur] = 1; 

	for (auto &edge : child[cur]) {

		if (!v[edge]) {
			dfs(edge);
			ans[cur] += ans[edge];
		}
	}
}

struct cowpair {
	int f, s, t;
	cowpair(int f, int s, int t) : f(f), s(s), t(t) {};
};

bool comp(cowpair a, cowpair b) {
	return a.t < b.t;
}

int32_t main(int32_t argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	vector<data> cows;
	rep(i,1,N) {
		char a;
		int b, c;
		cin >> a >> b >> c;

		if (a == 'N') {
			cows.emplace_back(b,c,0,i);
		} else if (a == 'E') {
			cows.emplace_back(b,c,1,i);
		}
	}

	memset(times, 0x3f, sizeof(times));
	vector<cowpair> isects;

	for (int i = 0; i < cows.size(); i++) {
		for (int j = 0; j < cows.size(); j++) {
			if (cows[i].dir == 0) {

				if (cows[j].dir == 1 && cows[j].x <= cows[i].x && cows[j].y >= cows[i].y)
					isects.emplace_back(i+1,j+1, max(cows[i].x-cows[j].x, cows[j].y-cows[i].y));	

			} else if (cows[i].dir == 1) {

				if (cows[j].dir == 0 && cows[i].x <= cows[j].x && cows[i].y >= cows[j].y) 
					isects.emplace_back(i+1,j+1, max(cows[j].x-cows[i].x, cows[i].y-cows[j].y));

			}
		}
	}
	sort(isects.begin(), isects.end(), comp);

	for (auto k : isects) {
		int l = k.f;
		int r = k.s;
		//cout << l << ' ' << r << " TEST " << endl;
		if (parent[r] && parent[l]) continue;

		if (cows[l-1].dir == 0) {
			if (cows[r-1].dir == 1) {
				int t1 = cows[l-1].x - cows[r-1].x; //time for cow R to arrive
				int t2 = abs(cows[l-1].y - cows[r-1].y); //time for cow L to arrive
				if (t2 == t1) continue;
				
				if (t1 > t2) { //east arrives first
					if (!parent[r] && times[l] > t2)
						parent[r] = l, times[r] = k.t;
				} else {
					if (!parent[l] && times[r] > t1)
						parent[l] = r, times[l] = k.t;
				}
			} 
		} else if (cows[l-1].dir == 1) {
			if (cows[r-1].dir == 0) {
				int t1 = cows[l-1].y - cows[r-1].y; 
				int t2 = abs(cows[l-1].x - cows[r-1].x);
				if (t2 == t1) continue;

				if (t1 > t2) { //east arrives first
					if (!parent[r] && times[l] > t1)
						parent[r] = l, times[r] = k.t;
				} else {
					if (!parent[l] && times[r] > t2)
						parent[l] = r, times[l] = k.t;
				}
			} 
		}
	}


	rep(i,1,N) 
		if (parent[i])
			child[parent[i]].PB(i);
	
	rep(i,1,N) 
		if (!v[i] && !parent[i])
			dfs(i);

	rep(i,1,N)
		cout << ans[i]-1 << endl;

	return 0;
}








