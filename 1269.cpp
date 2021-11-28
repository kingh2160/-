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
ull GCD( ull a, ull b ) { return b ? GCD( b , a%b ) : a; }
#define	ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;
#define INF 1e9
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<string, int> P;
const int MAX_V = 50;

bool compare( const P& a, const P& b ){
    if( a.second == b.second ) return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    
    int N, M;
    int arr[200000];
    int arr2[200000];
    
    scanf("%d %d", &N, &M);
    for( int i=0; i<N; ++i ) scanf("%d", &arr[i]);
    for( int i=0; i<M; ++i ) scanf("%d", &arr2[i]);
    sort( arr, arr+N );
    sort( arr2, arr2+M );
    
    int ans = 0;
    for( int i=0; i<N; ++i ){
        if( !binary_search(arr2, arr2+M, arr[i]) ) ans++;
    }
    for( int i=0; i<M; ++i ){
        if( !binary_search(arr, arr+N, arr2[i]) ) ans++;
    }
    printf("%d", ans);
    return 0;
}
