/*
 ID: lionz202
 TASK: maze1
 LANG: C++
 */
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <cstring>
#include <queue>

using namespace std;

#define MAXW 100
#define MAXH 250

ofstream fout("maze1.out");
ifstream fin("maze1.in");

int Width, Height;
bool visited[MAXH][MAXW];
int distances[MAXH][MAXW];
int answer[MAXH][MAXW];
int answer2[MAXH][MAXW];
int way[9] = {1, -1, 0, 0, 0, 0, 1, -1};

typedef struct node node;
struct node {
    int x, y;
    int distance;
};

node makeNode(int a, int b, int c) {
    node temp;
    temp.x = a;
    temp.y = b;
    temp.distance = c;
    return temp;
}

queue<node> bfs;
node first, second;

char x;
int main() {
    fin >> Width >> Height;
    //x = fin.get();
    
    for (int i = 0; i < 2*Height+1; i++) {
        for (int j = 0; j < 2*Width+1; j++) {
            x = fin.get();
            if (x == '\n') {
                x = fin.get();
            } if (x == ' ') {
                distances[i][j] = 1;
            } else {
                distances[i][j] = 0;
            }
        }
    }
    
    bool foundOne = false;
    for (int i = 1; i < 2*Height+1; i += 2) {
        if (distances[i][0] == 1) {
            if (!foundOne) {
                first.x = i;
                first.y = 1;
                foundOne = true;
            } else {
                second.x = i;
                second.y = 1;
            }
        }
        if (distances[i][2*Width] == 1) {
            if (!foundOne) {
                first.x = i;
                first.y = 2*Width-1;
                foundOne = true;
            } else {
                second.x = i;
                second.y = 2*Width-1;
            }
        }
    }
    for (int i = 1; i < 2*Width+1; i += 2) {
        if (distances[0][i] == 1) {
            if (!foundOne) {
                first.x = 1;
                first.y = i;
                foundOne = true;
            } else {
                second.x = 1;
                second.y = i;
            }
        }
        if (distances[2*Height][i] == 1) {
            if (!foundOne) {
                first.y = i;
                first.x = 2*Height-1;
                foundOne = true;
            } else {
                //fout << "WORKS";
                second.y = i;
                second.x = 2*Height-1;
            }
        }
    }
    bool v[205][105] = {0};
    for (int i = 0; i < 202; i++) {
        for (int j = 0; j < 100; j++) {
            v[i][j] = 0;
        }
    }
    bfs.push(first);
    while(!bfs.empty()) {
        node cur = bfs.front();
        bfs.pop();
        if (v[cur.x][cur.y]) continue;
        v[cur.x][cur.y] = 1;
        answer[cur.x][cur.y] = cur.distance;
        for (int i = 0; i < 4; i++) {
            if (cur.x + way[i] < 1 || cur.y + way[i+4] < 1 || cur.x + way[i] > 2*Height || cur.y + way[i+4]> 2*Width) continue;
            if (distances[cur.x + way[i]][cur.y + way[i+4]] != 0) {
                //if (cur.x + way[i]*2 < 1 || cur.y+ way[i+4]*2 < 1 || cur.x + way[i]*2 > 2*Height || cur.y + way[i+4]*2> 2*Width) continue;
                //answer[cur.x+way[i]*2][cur.y+way[i+4]*2] = cur.distance;
                bfs.push(makeNode(cur.x+way[i]*2, cur.y+way[i+4]*2, cur.distance+1));
            }
        }
        
    }
    for (int i = 0; i < 202; i++) {
        for (int j = 0; j < 100; j++) {
            v[i][j] = 0;
        }
    }
//    for (int i = 0; i < 2*Height+1; i++) {
//        for (int j = 0; j < 2*Width+1; j++) {
//            //fout << distances[i][j];
//        }
//        //fout << endl;
//    }
    bfs.push(second);
    while(!bfs.empty()) {
        node cur = bfs.front();
        bfs.pop();
        //assert(cur.x > 0 && cur.y > 0 && cur.x < 2*Height+1 && cur.y < 2*Width+1);
        if (v[cur.x][cur.y]) continue;
        v[cur.x][cur.y] = 1;
        answer2[cur.x][cur.y] = cur.distance;
        for (int i = 0; i < 4; i++) {
            if (cur.x < 1 || cur.y < 1 || cur.x > 2*Height || cur.y > 2*Width) continue;
            if (distances[cur.x + way[i]][cur.y + way[i+4]] != 0) {
                //if (cur.x + way[i]*2 < 1 || cur.y+ way[i+4]*2 < 1 || cur.x + way[i]*2 > 2*Height || cur.y + way[i+4]*2> 2*Width) continue;
                //answer2[cur.x+way[i]*2][cur.y+way[i+4]*2] = cur.distance;
                bfs.push(makeNode(cur.x+way[i]*2, cur.y+way[i+4]*2, cur.distance+1));
            }
        }
    }
    
    int best = 0;
    for (int i = 0; i < 2*Height+1; i++) {
        for (int j = 0; j < 2*Width+1; j++) {
            int temp = min(answer[i][j], answer2[i][j]);
            best = max(temp, best);
            //fout << answer[i][j] << answer2[i][j] << ' ';
        }
        //fout << endl;
    }
    fout << best + 1 << endl;
    return 0;
}

