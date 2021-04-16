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

int answers = 0;
int board[9][9];
int diag1[16], diag2[16];
int rowAttacked[9];
//15 diagonals in each direction
//r + c - 2 and r - c + 8
//board 0 is open 1 is occupied

void search(int col) {
    if (col == 9) {
        answers++;
        return;
    }
    for (int row = 1; row <= 8; row++) {
        if (!board[row][col] && !diag1[row + col - 2] && !diag2[row - col + 7] && !rowAttacked[row]) {
            board[row][col] = diag1[row + col - 2] = diag2[row - col + 7] = 1;
            rowAttacked[row] = 1;
            search(col+1);
            rowAttacked[row] = 0;
            board[row][col] = diag1[row + col - 2] = diag2[row - col + 7] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char read;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin.get(read);
            if (read == '.') {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
        cin.get(read);
    }
    
    search(1);
    cout << answers << "\n";
    
    return 0;
}



