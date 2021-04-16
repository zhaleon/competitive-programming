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

int Q;

int tree_id[100001];
int depth[100001];
bool root[100001];

int subtree_id[100001];
int diam_a[100001];
int diam_b[100001];

int cur_v = 0;
int tree_num = 0;

void add(int a) {
	++cur_v;

	if (a == -1) {

		tree_id[cur_v] = ++tree_num;
		root[cur_v] = depth[cur_v] = 1;
		diam_a[tree_num] = diam_b[tree_num] = cur_v;

	} else {

		tree_id[cur_v] = tree_id[a];
		depth[cur_v] = depth[a]+1;
		
		if (root[a]) {
			
		}

	}


	

}

int query(int a) {
	return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> Q;
   
	rep(i,1,Q) {
		char a;
		int b;
		cin >> a >> b;

		if (a == 'B') 
			add(b);
		else 
			cout << query(b) << endl;
	}

    return 0;
}








