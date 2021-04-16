#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

int turn[48];
int visited[8][8];
int ways = 0;


void search(int r, int c, int depth, int direc) {
	if (r > 7 || r < 1 || c > 7 || c < 1) return;
	if (depth == 49 && r == 7 && c == 7) {
		ways++;
		return;
    } else if (depth == 49) {
        return;
    }
//    if (depth < 49 && (r == 7 || c == 7)) {
//        cout << depth << endl;
//        return;
//    }
	switch (direc) {
		case 1: {
            if ((r+1 > 7) || c+1 == 7 || c-1 == 1 || (visited[r+1][c] && !visited[r+1][c+1] && !visited[r+1][c-1])) {
                return;
            }
            break;
        }
		case 2: {
            if (c-1 < 1 || r+1 == 7 || r-1 == 1 || (visited[r][c-1] && !visited[r+1][c-1] && !visited[r-1][c-1])) {
                return;
            }
            break;
        }
		case 3: {
            if (r-1 < 1 || c+1 == 7 || c-1 == 1 || (visited[r-1][c] && !visited[r-1][c-1] && !visited[r-1][c+1])) {
                return;
            }
            break;
        }
		case 4: {
            if (c+1 > 7 || r+1 == 7 || r-1 == 1 || (visited[r][c+1] && !visited[r-1][c+1] && !visited[r+1][c+1])) {
                return;
            }
            break;
        }
	}

    visited[r][c] = 1;
	if (depth == 1 && turn[0] == 0) {
		search(r+1,c,depth+1, 1);
	} else if (turn[depth-1] == 0) {
		search(r+1,c,depth+1,1);
		search(r-1,c,depth+1,3);
		search(r,c+1,depth+1,4);
		search(r,c-1,depth+1,2);
	} else {
		switch (turn[depth-1]) {
			case 1: {
                search(r+1,c,depth+1, 1);
                break;
            }
			case 2: {
                search(r,c-1,depth+1, 2);
                break;
            }
			case 3: {
                search(r-1,c,depth+1, 3);
                break;
            }
			case 4: {
                search(r,c+1,depth+1, 4);
                break;
            }
		}	
	}
	visited[r][c] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    cin >> n;
    
    loop(i, 0, n.length()) {
        if (n[i] == 'R') {
            turn[i] = 1;
        } else if (n[i] == 'U') {
            turn[i] = 2;
        } else if (n[i] == 'L') {
            turn[i] = 3;
        } else if (n[i] == 'D') {
            turn[i] = 4;
        }
    }
    //search(1,1,1,0);
    loop(i,0,n.length()) {
        cout << turn[i];
    } cout << endl;
    cout << ways*2 << '\n';
    return 0;
}



