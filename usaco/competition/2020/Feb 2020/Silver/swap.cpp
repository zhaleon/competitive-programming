#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <math.h>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int afterSwap[32][100001];
int cows[100001];
int L, R;
int N, M, K;

void stuff(int l, int r, int p) {
    for (int j = l; j <= (l+r)/2; j++) {
        swap(afterSwap[p][j], afterSwap[p][r-j+l]);
    }
}

void preCompute(int a) {
    for (int i = 1; i <= N; i++) {
        afterSwap[a+1][i] = afterSwap[a][i];
    }
    for (int i = 1; i <= N; i++) {
        afterSwap[a+1][i] = afterSwap[a][afterSwap[a][i]];
    }
}

int main() {
    setIO("swap");
    
    
    cin >> N >> M >> K;
    
    loop(i,1,N+1) {
        afterSwap[1][i] = afterSwap[0][i] = i;
    }
    
    for (int i = 1; i <= M; i++) {
        cin >> L >> R;
        stuff(L, R, 1);
    }
    
    for (int i = 1; i < 31; i++) {
        preCompute(i);
    }
    
    
    for (int i = 30; i >= 0; i--) {
        if (K & (1 << i)) {
            
            for (int j = 1; j <= N; j++) {
                afterSwap[0][j] = afterSwap[i+1][afterSwap[0][j]];
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << afterSwap[0][i] << endl;
    }
    
   
    return 0;
}



