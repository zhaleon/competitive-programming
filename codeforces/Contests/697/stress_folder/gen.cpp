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

#warning Remember to try big N, overflows, edge cases

void gen_case() {
	int N = 10;
	int M = RAND_MAX * rand() + rand();
   	M = rand() % 10;
	//if (M > 1e9) M >>= 1;

	cout << N << ' ' << M << '\n';

	rep(i,1,N) cout << rand() % 10 << ' ';
	cout << '\n';
	rep(i,1,N) cout << 1+(rand() & 1) << ' '; 
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
	
	srand(atoi(argv[1]));
	cout << 100 << '\n';

	rep(i,1,100) gen_case();

    return 0;
}








