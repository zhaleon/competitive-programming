#include "highway.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)

typedef struct node {
	int vertex, edge, dist;
	node() {};
	node(int a, int b, int c) : vertex(a), edge(b), dist(c) {};
} node;

vpi adj[90000];
vi tree_adj[90000];
vi edge_dist[90000];
bool seen[90000];
int subtree_sizes[90000];
int depth[90000];

void make_spanning_tree(int cur) {
	seen[cur] = 1;
	for (auto p : adj[cur]) {
		int edge = p.F;
		if (!seen[edge]) {
			make_spanning_tree(edge);
			tree_adj[cur].PB(edge);
			tree_adj[edge].PB(cur);
		}
	}
}

void find_sizes(int cur) {
	seen[cur] = 1;
	subtree_sizes[cur] = 1;
	for (auto edge : tree_adj[cur]) {
		if (!seen[edge]) {
			find_sizes(edge);
			subtree_sizes[cur] += subtree_sizes[edge];
		}
	}
}

int find_centroid(int N) {
	find_sizes(0);
	int centroid = 0, largest_subtree, nxt = 0;
	do {
		centroid = nxt;
		largest_subtree = 0;
		for (auto edge : adj[centroid]) {
			if (subtree_sizes[edge.F] > largest_subtree) {
				largest_subtree = subtree_sizes[N];
				nxt = edge.F;
			}	
		}
	} while(largest_subtree >= N/2+5 && N - subtree_sizes[centroid] >= N/2+5);
	return centroid;
}

void get_depths(int source) {
	queue<pii> bfs;
	bfs.push(MP(source, 1));
	while(!bfs.empty()) {
		
	}
}

void find_pair(int N, vi U, vi V, int A, int B) {
	int S = 0, T = 0, M = V.size();
	ll dist;
	
	vi w(M, 0); //query edge list
	
	rep(i,0,M) {
		adj[U[i]].emplace_back(V[i], i);
		adj[V[i]].emplace_back(U[i], i);
	}
	
	make_spanning_tree(0);
	memset(seen, 0, sizeof(seen));
	
	queue<pii> bfs;
	int root = find_centroid(N);
	//root = 0;
	//cerr << "root " << root << endl;
	bfs.push(MP(root, 1));
	
	int tree_height = 0;
	memset(seen, 0, sizeof(seen));
	seen[root] = 1;
	depth[root] = 1;
	while (!bfs.empty()) {
		pii cur = bfs.front(); bfs.pop(); //vertex, distance
		//depth[cur.F] = cur.S;
		tree_height = max(tree_height, cur.S);
		
		for (auto edge : adj[cur.F]) {
			if (!seen[edge.F]) {
				seen[edge.F] = 1;
				depth[edge.F] = cur.S+1;
				bfs.push(MP(edge.F, cur.S+1));	
			}
			if (depth[edge.F] > cur.S) edge_dist[cur.S].PB(edge.S);
		}
	}
	
	assert(A > 0);
	dist = ask(w)/A;
	
	int low = 1, high = tree_height;
	while (low < high) {
		int mid = (low + high)/2;
		
		for (int i = tree_height-1; i >= mid; i--) for (auto edge : edge_dist[i]) w[edge] = 1;
		ll res = ask(w);
		for (int i = tree_height-1; i >= mid; i--) for (auto edge : edge_dist[i]) w[edge] = 0;
		
		if (res > dist*A) low = mid+1;	
		else high = mid;
	}
	
	int lower_point = (low > 1) ? low-1 : low; //depth of lower point
	assert(edge_dist[lower_point].size() > 0);
	low = 0, high = edge_dist[lower_point].size()-1;
	
	bool test = false;
	//56305, 39836
	cerr << 1 << ' ' << tree_height << endl;
	cerr << lower_point << ' ' << depth[56305] << ' ' << depth[39836] << endl;
	for (auto p : edge_dist[lower_point]) if (U[p] == 56305 || V[p] == 56305) test = true;
	assert(test);
	
	while (low < high) {
		int mid = (low + high)/2;
		
		for (int i = 0; i <= mid; i++) w[edge_dist[lower_point][i]] = 1;
		ll res = ask(w);
		for (int i = 0; i <= mid; i++) w[edge_dist[lower_point][i]] = 0;
		
		if (res > dist*A) high = mid;	
		else low = mid+1;
	}

	if (depth[U[edge_dist[lower_point][low]]] > depth[V[edge_dist[lower_point][low]]]) S = U[edge_dist[lower_point][low]];
	else S = V[edge_dist[lower_point][low]];
	
	memset(seen, 0, sizeof(seen));
	memset(depth, 0, sizeof(depth));
	for (auto& vec : edge_dist) vec.clear();
	
	bfs.push(MP(S, 1));
	seen[S] = 1;
	depth[S] = 1;
	while (!bfs.empty()) {
		pii cur = bfs.front(); bfs.pop(); //vertex, distance
		//depth[cur.F] = cur.S;
	
		for (auto edge : adj[cur.F]) {
			if (!seen[edge.F]) {
				seen[edge.F] = 1;
				depth[edge.F] = cur.S+1;
				bfs.push(MP(edge.F, cur.S+1));	
			}
			if (depth[edge.F] > cur.S) edge_dist[cur.S].PB(edge.S);
		}
	}
	
	//cerr << "DEPTH: " << edge_dist[2].size() << endl;
	cerr << "DIST: " << dist << endl;
	
	low = 0, high = (int)edge_dist[dist].size()-1;
	cerr << low << ' ' << high << endl;
	
	while (low < high) {
		int mid = (low + high)/2;
		
		for (int i = 0; i <= mid; i++) w[edge_dist[dist][i]] = 1;
		ll res = ask(w);
		for (int i = 0; i <= mid; i++) w[edge_dist[dist][i]] = 0;
		
		if (res > dist*A) high = mid;	
		else low = mid+1;
	}
	cerr << "LOW: " << low << ' ' << dist << endl;
	int edge_id = edge_dist[dist][low];
	cerr << "EDGE: " << U[edge_id] << ' ' << V[edge_id] << endl;
	T = (depth[U[edge_id]] > depth[V[edge_id]]) ? U[edge_id] : V[edge_id];
	cerr << S << ' ' << T << endl;// << ' ' <<  U[candidates[low]] << ' ' << V[candidates[low]] << endl;
	answer(S, T);
}
