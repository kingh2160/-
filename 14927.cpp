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
int ans = INF;
int cp[18][18];
int arr[18][18];

bool check( int x, int y ){
    if( x < 0 || y < 0 || x >= N || y >= N ) return false;
    else return true;
}

void TOGGLE( int x, int y ){
    cp[x][y] ^= 1;
    if( check(x-1, y) ) cp[x-1][y] ^= 1;
    if( check(x+1, y) ) cp[x+1][y] ^= 1;
    if( check(x, y-1) ) cp[x][y-1] ^= 1;
    if( check(x, y+1) ) cp[x][y+1] ^= 1;
}

int DO( int value ){
    int ret = 0;
    for( int i=0; i<N; ++i ){
        if( value & (1<<i) ){
            TOGGLE( 0, i );
            ret++;
        }
    }
    for( int i=1; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            if( cp[i-1][j] & 0x1 ){
                TOGGLE( i, j );
                ret++;
            }
        }
    }
    for( int i=0; i<N; ++i ) if( cp[N-1][i] & 0x1 ) return INF;
    return ret;
}

int main(){
    memset( arr, 0, sizeof(arr) );
    memset( cp, 0, sizeof(cp) );
    cin >> N;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    for( int i=0; i<(1<<N); ++i ){
        memcpy( cp, arr, sizeof(arr) );
        ans = min( ans, DO( i ) );
    }
    if( ans == INF ) printf("-1");
    else printf("%d", ans);
    return 0;
}
