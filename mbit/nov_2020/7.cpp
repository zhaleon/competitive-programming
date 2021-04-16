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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N;
int board[401][401];
int dp[401][401];

int row[401];

void ckmax(int& ans, int a, int b, int c, int d = 0) {
	ans = max(ans, max(max(a,b),c) + d);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,1,N+1) {
		rep(j,1,i+1) {
			cin >> board[i][j];
		}
	}
   	  
	for (int i = 1; i <= 400; i++) {
		int k = 0;
		while (k*(k+1)/2 < i) k++;
		row[i] = k;
	}
	

	for (int depth = 2; depth <= N; depth++) {
		for (int j = 1; j <= (N-depth+1)*(N-depth+2)/2; j++) {
			int r = 0, g = 0, b = 0; 
			
			int d = row[j] + depth - 1;
			int start = j - row[j]*(row[j]-1)/2;
		
			for (int i = start; i < start + depth; i++) {
				int color = board[d][i];
				if (color == 1) r++;
				else if (color == 2) g++;
				else b++;
			}	

		
			ckmax(dp[j][depth], r, g, b, dp[j][depth-1]);	
			
			r = g = b = 0;

			for (int i = 0; i < depth; i++) {
				int color = board[row[j]+i][start+i];
				if (color == 1) r++;
				else if(color == 2) g++;
				else b++;
			}

			ckmax(dp[j][depth], r, g, b, dp[j+row[j]][depth-1]);

			r = g = b = 0;

			for (int i = 0; i < depth; i++) {
				int color = board[row[j]+i][start];
				if (color == 1) r++;
				else if (color == 2) g++;
				else b++;
			}	

			ckmax(dp[j][depth], r, g, b, dp[j+row[j]+1][depth-1]);

		}
	}

	cout << dp[1][N] << endl;

    return 0;
}








