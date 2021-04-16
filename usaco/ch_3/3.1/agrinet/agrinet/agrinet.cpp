/*
 ID: lionz202
 TASK: agrinet
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <bitset>

using namespace std;

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

int N, cost = 0;

int adj[101][101];
int distances[101];
int inTree[101];


int main()
{
    fin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            fin >> adj[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        distances[i] = adj[1][i];
    }
    int treeSize = 1;
    inTree[1] = true;
    while (treeSize <= N) {
        int nextNode = 0;
        int bestSoFar = 1000000;
        for (int i = 1; i <= N; i++) {
            if (inTree[i]) {
                for (int j = 1; j <= N; j++) {
                    if (adj[i][j] != 0 && adj[i][j] < bestSoFar && !inTree[j]) {
                        bestSoFar = adj[i][j];
                        nextNode = j;
                    }
                }
            }
        }
        if (nextNode == 0) break;
        //if (nextNode != 0) {
        treeSize++;
        cost += bestSoFar;
        inTree[nextNode] = 1;
        for (int i = 1; i <= N; i++) {
            if (distances[i] > adj[nextNode][i]) {
                distances[i] = adj[nextNode][i];
            }
        }
        //}
    }
    
    fout << cost << endl;
    
    fin.close();
    fout.close();
    return 0;
}

