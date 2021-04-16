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

constexpr pii swaps[] = {
	{0,1}, {1,2},
	{3,4}, {4,5},
	{6,7}, {7,8},

	{0,3}, {3,6},
	{1,4}, {4,7},
	{2,5}, {5,8}
};

unordered_map<string, int> m;
unordered_map<int, string> ms;

vi search(string s) {
	vi dist(362881, -1);
	queue<string> bfs;
	bfs.push(s);
	dist[m[s]] = 0;

	while (bfs.size()) { 
		string cur = bfs.front(); bfs.pop();
		int id = m[cur];
		int d = dist[id];
		
		if (d == 8) continue;
		
		rep(i,0,11) {
			int a = swaps[i].F, b = swaps[i].S;
			swap(cur[a], cur[b]);
			
			int nxt = m[cur];
			if (dist[nxt] == -1) {
				dist[nxt] = d+1;
				bfs.push(cur);
			}
			swap(cur[a], cur[b]);
		}
	}
	return dist;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	string start = "";
	rep(i,0,8) {
		int a;
		cin >> a; 
		start += (char)(a + '0');
	}

	string temp = "123456789";
	string goal = "123456789";
	int ind = 0;	
	do {
		m[temp] = ++ind;
		ms[ind] = temp;
	} while (next_permutation(temp.begin(), temp.end()));

	vi d1 = search(start), d2 = search(goal);

	int ans = INF*2;

	rep(i,1,326880) {
		if (d1[i] > 0 && d2[i] > 0)
			ans = min(ans, max(0, d1[i]) + max(0, d2[i]));
	}

	if (start != goal)
		cout << ans << endl;
	else
		cout << 0 << endl;


    return 0;
}








