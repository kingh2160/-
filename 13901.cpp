#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <list>
#include <deque>
#include <numeric>
#include <set>
#include <climits>
#include <utility>
#include <map>
#include <float.h>
typedef long long ll;
typedef unsigned long long ull;
inline int max( int x, int y ){ return x > y ? x : y ; }
inline int min( int x, int y ){ return x < y ? x : y ; }
inline ll max( ll x, ll y ){ return x > y ? x : y ; }
inline ll min( ll x, ll y ){ return x < y ? x : y ; }
inline ull max( ull x, ull y ){ return x > y ? x : y ; }
inline ull min( ull x, ull y ){ return x < y ? x : y ; }
//ull GCD( ull a, ull b ) { return b ? GCD( b , a%b ) : a; }
int GCD( int a, int b ) { return b ? GCD( b , a%b ) : a; }
#define	ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;
#define INF 1e9
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;


int N, M, ans=1e9, K, A, B, sx, sy;
int arr[1000][1000];
bool visited[1000][1000];
int rotation[4];
int dir_x[4] = { -1, 1, 0, 0 };
int dir_y[4] = { 0, 0, -1, 1 };
/*
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
*/ 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=M ) return false;
	else return true;
}

bool EXIT( int x, int y ){
    if( check(x-1, y) && arr[x-1][y] != 1 && !visited[x-1][y] ) return false;
    if( check(x+1, y) && arr[x+1][y] != 1 && !visited[x+1][y] ) return false;
    if( check(x, y-1) && arr[x][y-1] != 1 && !visited[x][y-1] ) return false;
    if( check(x, y+1) && arr[x][y+1] != 1 && !visited[x][y+1] ) return false;
    return true;
}

void GO(){
    int now_x, now_y;
    visited[sx][sy] = true;
    now_x = sx;
    now_y = sy;
    while( 1 ){
        for( int i=0; i<4; ++i ){
            int dx = now_x + dir_x[rotation[i]-1];
            int dy = now_y + dir_y[rotation[i]-1];
            if( check(dx, dy) && arr[dx][dy] != 1 && !visited[dx][dy] ){
                now_x = dx;
                now_y = dy;
                visited[dx][dy] = true;
                --i;
            }
        }
        if( EXIT(now_x, now_y) ) break;
    }
    printf("%d %d", now_x, now_y);
}


int main(){
    memset( arr, 0, sizeof(arr) );
    memset( visited, 0, sizeof(visited) );
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    for( int i=0; i<K; ++i ){
        scanf("%d %d", &A, &B);
        arr[A][B] = 1;
    }
    scanf("%d %d", &sx, &sy);
    for( int i=0; i<4; ++i ) scanf("%d", &rotation[i]);
    GO();
    return 0;
}
