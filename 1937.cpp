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

int N;
int ans = 0;
int arr[500][500];
int dp[500][500];
int dir_x[4] = { -1, 1, 0, 0 };
int dir_y[4] = { 0, 0, -1, 1 };
/*
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
*/ 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=N ) return false;
	else return true;
}

int DFS( int x, int y ){
    if( dp[x][y] ) return dp[x][y];
    dp[x][y] = 1;
    for( int i=0; i<4; ++i ){
        int dx = x + dir_x[i];
        int dy = y + dir_y[i];
        if( check(dx, dy) && arr[x][y] < arr[dx][dy] ){
            dp[x][y] = max( dp[x][y], DFS(dx,dy)+1 );
        }
    }
    return dp[x][y];
}

int main(){
    memset( dp, 0, sizeof(dp) );
    memset( arr, 0, sizeof(arr) );
    cin >> N;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            ans = max( ans, DFS(i, j) );
        }
    }
    printf("%d", ans);
    return 0;
}
