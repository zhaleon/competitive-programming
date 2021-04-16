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

vi adj[2501];
int times[2501];
int temp[2501];
int counter = 0;
int N;

int visited[2501][2501];

bool works = true;
void dfs(int start, int cur) {
    if (visited[start][cur]) return;
    visited[start][cur] = 1;
    
    for (int i = 0; i < adj[cur].size(); i++) {
        if (!visited[start][adj[cur][i]]) {
            temp[adj[cur][i]]++;
            temp[adj[cur][i]] = (temp[adj[cur][i]]-1) % 12 + 1;
            dfs(start, adj[cur][i]);
            temp[cur]++;
            temp[cur] += (12 - temp[adj[cur][i]]);
            temp[cur] = (temp[cur]-1)%12 + 1;
        }
    }
}

int main() {
    setIO("clocktree");

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> times[i];
    }
    
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    for (int i = 1; i <= N; i++) {
        copy(times, times+2501, temp);
        works = true;
        dfs(i, i);
        if (temp[i] - 1 == 12 || temp[i]-1 == 0 || temp[i] == 0 || temp[i] == 12) counter++;
    }

    cout << counter << endl;
   
    return 0;
}



