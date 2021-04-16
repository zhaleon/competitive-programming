/*
 ID: lionz202
 TASK: castle
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
using namespace std;

#define MAXN 51
#define MAXM 51

int N, M, segment = 0, bigRoom = 1, biggerRoom = 0, a = 0, b = 51, map[MAXN][MAXM];
int castle[MAXN][MAXM], adjacency[MAXN][MAXM], numRoom[MAXN];
bool visited[MAXN][MAXM] = {false};
char d;

void color(const int i, const int j) {
    map[i][j] = segment;
    if (visited[i][j]) return;
    visited[i][j] = true;
    for (int x = 0; x < 4; x++) {
        if (!(castle[i][j]%2)) {
            switch(x) {
                case 0: color(i, j-1); break;
                case 1: color(i-1, j); break;
                case 2: color(i, j+1); break;
                case 3: color(i+1, j); break;
            }
        }
        castle[i][j]/=2;
    }
}

void flood()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M ; j++) {
            if (map[i][j] == 0) {
                segment++;
                color(i,j);
            }
        }
    }
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin >> M >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M ; j++) {
            fin >> castle[i][j];
        }
    }
    flood();
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            numRoom[map[i][j]]+=1;
//            if (map[i][j]/10 < 1) fout << map[i][j] << "  ";
//            else fout << map[i][j] << ' ';
        }
//        fout << endl;
    }
    
    for (int i = 1; i <= segment; i++) {
        bigRoom = max(bigRoom, numRoom[i]);
        //fout << numRoom[i] << ' ';
    }
    
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            if (col < M && map[row][col] != map[row][col+1]) {
                if (biggerRoom <= numRoom[map[row][col]] + numRoom[map[row][col+1]]) {
                    
                    if (biggerRoom < numRoom[map[row][col]] + numRoom[map[row][col+1]] || col < b || (col==b && row > a)) {
                        a = row;
                        b = col;
                        d = 'E';
                    }
                    biggerRoom = numRoom[map[row][col]] + numRoom[map[row][col+1]];
                }
            }
            if (row < N && map[row][col] != map[row+1][col]) {
                if (biggerRoom <= numRoom[map[row][col]] + numRoom[map[row+1][col]]) {
                    
                    if (biggerRoom < numRoom[map[row][col]] + numRoom[map[row+1][col]] || col < b || (col==b && row + 1> a)) {
                        a = row + 1;
                        b = col;
                        d = 'N';
                    }
                    biggerRoom = numRoom[map[row][col]] + numRoom[map[row+1][col]];
                }
            }
        }
    }
    
    fout << segment << endl;
    fout << bigRoom << endl;
    fout << biggerRoom << endl;
    fout << a << ' ' << b << ' ' << d << endl;
    return 0;
}
