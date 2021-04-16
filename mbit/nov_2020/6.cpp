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
int dp[80441][401];

int row[80411];

int  blue[80441][3];
int   red[80441][3];
int green[80441][3];
 

void ckmax(int& ans, int a, int b, int c, int d = 0) {
    ans = max(ans, max(max(a,b),c) + d);
}

void precomp() {
    for (int j = N*(N+1)/2; j > 0; j--) {
        int elem = j - row[j]*(row[j]-1)/2;
        int color = board[row[j]][elem];
        if (row[j] == N) {
            blue[j][0] = blue[j][1] = (color == 3);
            red[j][0] = red[j][1] = (color == 1);
            green[j][0] = green[j][1] = (color == 2);
        } else {
            // 0 means down left 1 means down right
            bool b = (color == 3), g = (color == 2), r = (color == 1);
            blue[j][0] = blue[j+row[j]][0] + b;
            blue[j][1] = blue[j+row[j]+1][1] + b;
            
            red[j][0] = red[j+row[j]][0] + r;
            red[j][1] = red[j+row[j]+1][1] + r;
            
            green[j][0] = green[j+row[j]][0] + g;
            green[j][1] = green[j+row[j]+1][1] + g;
            
        }
    }
    
    int r = N;
    for (int i = 1; i <= r*(r+1)/2; i++) {
        int elem = i - row[i]*(row[i]-1)/2;
        int color = board[row[i]][elem];
        red[i][2] = red[i-1][2] + (color == 1);
        green[i][2] = green[i-1][2] + (color == 2);
        blue[i][2] = blue[i-1][2] + (color == 3);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    rep(i,1,N+1) {
        rep(j,1,i+1) {
            cin >> board[i][j];
        }
    }
 
    int test = 0;
    for (int i = 1; i <= 80401; i++) {
        while (test*(test+1)/2 < i) test++;
        row[i] = test;
    }
    
    precomp();	
    
    for (int depth = 2; depth <= N; depth++) {
        for (int j = 1; j <= (N-depth+1)*(N-depth+2)/2; j++) {
            int r = 0, g = 0, b = 0; 
            
            int d = row[j] + depth - 1;
            int start = j - row[j]*(row[j]-1)/2;
        
            for (int i = start; i < start + depth; i++) {
                //cerr << d << ' ' << i << ' ' << start << ' ' << j << ' ' << depth << endl;
                assert(d <= N && i <= N);
                int color = board[d][i];
                if (color == 1) r++;
                else if (color == 2) g++;
                else b++;
            }	
            
            int x = j + (2*row[j]+depth-2)*(depth-1)/2;

            r = red[x+depth-1][2] - red[x-1][2];
            g = green[x+depth-1][2] - green[x-1][2];
            b = blue[x+depth-1][2] - blue[x-1][2];
            
            ckmax(dp[j][depth], r, g, b, dp[j][depth-1]);	
            
            r = g = b = 0;

            for (int i = 0; i < depth; i++) {
                assert(row[j]+i <= N && start + i <= N);
                int color = board[row[j]+i][start+i];
                if (color == 1) r++;
                else if(color == 2) g++;
                else b++;
            }

            x += (depth-1);
            r = red[j][1];
            g = green[j][1];
            b = blue[j][1];
            if (row[j] != N) {
                r -= red[x+row[x]+1][1];
                g -= green[x+row[x]+1][1];
                b -= blue[x+row[x]+1][1];
            }

            ckmax(dp[j][depth], r, g, b, dp[j+row[j]][depth-1]);

            r = g = b = 0;

            for (int i = 0; i < depth; i++) {
                assert(row[j]+i <= N && start <= N);
                int color = board[row[j]+i][start];
                if (color == 1) r++;
                else if (color == 2) g++;
                else b++;
            }	
            
            x -= (depth-1);
            r = red[j][0];
            g = green[j][0];
            b = blue[j][0];
            if (row[j] != N) {
                r -= red[x+row[x]][0];
                g -= green[x+row[x]][0];
                b -= blue[x+row[x]][0];
            }

            ckmax(dp[j][depth], r, g, b, dp[j+row[j]+1][depth-1]);

        }
        
    }

    //2040
    
    cout << dp[1][N] << endl;

    return 0;
}

















