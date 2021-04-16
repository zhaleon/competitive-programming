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

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	//srand(atoi(argv[1]));
   
	int N = 16;

	set<int> x, y;
	vi l, r;

	while (x.size() < N) {
		int j = rand() % 11;
		if (x.find(j) == x.end()) {
			x.insert(j);
			l.PB(j);
		}
	}

	while (y.size() < N) {
		int j = rand() % 11;
		if (y.find(j) == y.end()) {
			y.insert(j);
			r.PB(j);
		}
	}

	cout << N << '\n';
	for (int k = 0; k < N; k++) {
		char a;
		if (rand() & 1)
			a = 'N';
		else
			a = 'E';
		cout << l[k] << ' ' << r[k] << '\n';	
	}



    return 0;
}








