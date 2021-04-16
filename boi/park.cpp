#include <bits/stdc++.h>

using namespace std;

#define int long long

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


struct tree {
	int x, y, r, id;
	tree() {};
	tree(int x, int y, int r, int id) : x(x), y(y), r(r), id(id) {};
};

struct visitor {
	int s, r, id;
	visitor() {};
	visitor(int s, int r, int id) : s(s), r(r), id(id) {};
	
	bool operator<(const visitor &o) const {
		return r < o.r;
	}
};

struct dsu {
	vi parent;
	vi size;
	dsu() {};
	dsu(int N) {
		parent.resize(N+1);
		iota(parent.begin(), parent.end(), 0);
		assert(parent[N] == N && parent[1] == 1);
		size.assign(N+1, 1);
	};

	int find(int x) {
		if (x == parent[x]) return x; 
		return parent[x] = find(parent[x]);
	}

	bool merge(int a, int b) {
		a = find(a), b = find(b);

		if (a == b) return 0;
		if (size[a] < size[b]) swap(a,b);
		
		size[a] += size[b];
		parent[b] = a;
		return 1;
	}

	bool connected(int a, int b) {
		return find(a) == find(b);
	}
};

struct edge {
	int a, b;
	double dist;
	edge(int a, int b, double dist) : a(a), b(b), dist(dist) {};
	bool operator<(const edge &o) const {
		return dist < o.dist;
	}
};

double dist(tree a, tree b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y)) - (a.r + b.r);
}

int N, M;
int w, h;
visitor visitors[100001];
tree trees[2001];
int ans[100001][5];
int starts[100001];
pii m[5] = {{0,0}, {4,1}, {4,3}, {3,2}, {2,1}};

edge make_edge(tree a, tree b, int wall = 0) {
	if (!wall)
		return edge(a.id,b.id, dist(a,b));

	if (!wall) 
		assert(dist(a,b) >= 0);
	else
		assert(a.id > 4);

	if (wall == 1) { //left wall
		return edge(a.id,1,a.x-a.r); 
	} else if (wall == 2) { //top wall
		return edge(a.id,2,h-a.y-a.r);
	} else if (wall == 3) { //right wall
		return edge(a.id,3,a.y-a.r);
	} else { //bottom wall
		return edge(a.id,4,w-a.x-a.r);
	}
}


int32_t main(int32_t argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> w >> h;
    
	rep(i,1,N) {
		int x, y, r;
		cin >> x >> y >> r;
		trees[i] = tree(x,y,r,i+4);
	}

	rep(i,1,M) {
		int s, r;
		cin >> r >> s;
		visitors[i] = visitor(s,r,i);
		starts[i] = s;
		rep(j,1,4) ans[i][j] = 1;
	}

	sort(visitors+1, visitors+1+M);

	vector<edge> edge_list;
	vector<edge> wall_edge;

	rep(i,1,N) {

		wall_edge.PB(make_edge(trees[i], trees[i], 1));
		wall_edge.PB(make_edge(trees[i], trees[i], 2));
		wall_edge.PB(make_edge(trees[i], trees[i], 3));
		wall_edge.PB(make_edge(trees[i], trees[i], 4));

		rep(j,i+1,N) 
			edge_list.PB(make_edge(trees[i],trees[j]));
	
	}

	sort(edge_list.begin(), edge_list.end());
	sort(wall_edge.begin(), wall_edge.end());

	int p = 0;
	int p2 = 0;
	dsu park = dsu(N+4);

	rep(i,1,M) {
		
		while (p < edge_list.size() && edge_list[p].dist - 1e-12 < 2*visitors[i].r) { 
			park.merge(edge_list[p].a, edge_list[p].b);
			++p;
		}

		while (p2 < wall_edge.size() && wall_edge[p2].dist - 1e-12 < 2*visitors[i].r) {
			park.merge(wall_edge[p2].a, wall_edge[p2].b);
			++p2;
		}

		int cur_start = visitors[i].s;
		int cur_id = visitors[i].id;
		bool locked = park.connected(m[cur_start].F, m[cur_start].S);
		/* cout << "TEST: " << cur_start << endl; */
		if (cur_start != 4 && (park.connected(m[4].F, m[4].S) || locked)) ans[cur_id][4] = 0; 
		if (cur_start != 3 && (park.connected(m[3].F, m[3].S) || locked)) ans[cur_id][3] = 0; 
		if (cur_start != 2 && (park.connected(m[2].F, m[2].S) || locked)) ans[cur_id][2] = 0;
		if (cur_start != 1 && (park.connected(m[1].F, m[1].S) || locked)) ans[cur_id][1] = 0;
	}

	rep(i,1,M) {

		rep(j,1,4) if (ans[i][j]) cout << j; 

		cout << '\n';
	}

    return 0;
}








