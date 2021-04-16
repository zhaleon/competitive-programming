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

int K, N;
int ranks[11][21];
int pairs[21][21];

ofstream fout ("gymnastics.out");
ifstream fin ("gymnastics.in");
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fin >> K >> N;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            fin >> ranks[i][j];
        }
    }
    
    int answer = 0;
    for (int layer = 1; layer <= K; layer++) {
        
        for (int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                int a = ranks[layer][i], b = ranks[layer][j];
                if (a > b) {
                    pairs[a][b]++;
                    if (pairs[b][a] > 0) {
                        pairs[b][a] = pairs[a][b] = -1*INF;
                    }
                } else if (a < b) {
                    pairs[a][b]++;
                    if (pairs[b][a] > 0) {
                        pairs[b][a] = pairs[a][b] = -1*INF;
                    }
                }
            }
        }
        
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            if (pairs[i][j] > 0) {
//                cout << i << ' ' << j << endl;
                answer++;
            }
        }
    }
    
    
    fout << answer << endl;
    
    return 0;
}



