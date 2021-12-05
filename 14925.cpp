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
int dp[1000+1][1000+1];
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

int main(){
    scanf("%d %d", &N, &M);
    memset( arr, 0, sizeof(arr) );
    memset( dp, 0, sizeof(dp) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    ans = 0;
    for( int i=1; i<=N; ++i ){
        for( int j=1; j<=M; ++j ){
            if( arr[i-1][j-1] == 0 ){
                dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] ) + 1;
                ans = max( ans, dp[i][j] );
            }
        }
    }
    printf("%d", ans);
    return 0;
}










