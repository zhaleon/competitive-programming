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

int N;

struct trie {
	trie *l = nullptr, *r = nullptr;
	trie() : {};
	
	void insert(int k) {
		trie *cur = this;
		
		for (int i = 29; i >= 0; i--) {
			bool j = k & (1 << i) > 0;
			
			trie *nxt;
			
			if (j) 
				nxt = cur->r;	
			else 
				nxt = cur->l;
			
			if (nxt == nullptr) {
				if (j)
					cur->r = new trie(), nxt = cur->r;
				else
					cur->l = new trie(), nxt = cur->l;
			}
			
			cur = nxt;
		}
	}
	
	int complement(int k) {
		int res = 0;
		
		trie *cur = this;
		
		for (int i = 29; i >= 0; i--) {
			bool j = k & (1 << i) == 0;
			
			if (j && cur->r)
				res ^=
				
			
		}
		
		return res;
	}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	int res = 0;
	int ans = 0;
	
	rep(i,1,N) {
		int x; cin >> x;
		res ^= x;


	
	}
    
	cout << ans << endl;
	
    return 0;
}








