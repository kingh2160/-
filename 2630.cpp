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
#define INF 1e9+7
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

int N;
int blue=0, white=0;
int arr[1<<7][1<<7];

bool check( int x, int y, int k ){
    for( int i=x; i<x+k; ++i ){
        for( int j=y; j<y+k; ++j ){
            if( arr[x][y] != arr[i][j] ) return false;
        }
    }
    return true;
}

void GO( int x, int y, int k ){
    if( k == 1 ){
        if( arr[x][y] == 0 ) white++;
        else blue++;
        return ;
    }
    if( check(x,y,k) ){
        if( arr[x][y] == 0 ) white++;
        else blue++;
        return ;
    }else{
        GO( x, y, k/2 );
        GO( x, y+k/2, k/2 );
        GO( x+k/2, y, k/2 );
        GO( x+k/2, y+k/2, k/2 );
    }
}

int main(){
    scanf("%d", &N);
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    GO( 0, 0, N );
    printf("%d\n%d", white, blue);
    return 0;
}
