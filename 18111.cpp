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

int N, M, B;
int ans_time=INF, ans_height=-1;
int arr[500][500];

void DO( int height ){
    int possible = B;
    int time = 0;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( arr[i][j] > height ){
                time += 2*(arr[i][j]-height);
                possible += arr[i][j]-height;
            }
        }
    }
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( arr[i][j] < height ){
                time += height-arr[i][j];
                possible -= height-arr[i][j];
            }
        }
    }
    if( possible >= 0 ){
        if( ans_time == time ) ans_height = max( ans_height, height );
        else if( ans_time > time ){
            ans_time = time;
            ans_height = height;
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &B);
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    for( int i=256; i>=0; --i ) DO( i );
    printf("%d %d", ans_time, ans_height);
    return 0;
}
