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

#warning consider shuffling the labels on the tree

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int min_N = 10;
int max_N = min_N + 10;

void tree() {
	int N = rand(min_N, max_N);
	
	cout << N << '\n';
	rep(i,2,N) 
		cout << rand(1,i-1) << ' ' << i << '\n'; 	
}

void line_tree() {
	int N = rand(min_N, max_N);
	
	cout << N << '\n';
	rep(i,2,N) 
		cout << i-1 << i << '\n';
}

void star_tree() {
	int N = rand(min_N, max_N);
	
	cout << N << '\n';
	rep(i,2,N)
		cout << 1 << i << '\n';
}

void prufer_tree() {
	int N = rand(min_N, max_N);

	cout << N << '\n';
}

void binary_tree() {
	int N = rand(min_N, max_N);

	cout << N << '\n';
	rep(i,2,N)
		cout << i/2 << ' ' << i << '\n';
}



int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

    if (argv[2])
		min_N = atoi(argv[2]);
	if (argv[3])
		max_N = atoi(argv[3]);

	tree();

    return 0;
}








