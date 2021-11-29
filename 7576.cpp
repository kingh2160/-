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
typedef pair<int, int> P;
const int MAX_V = 50;

int N, M;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x < 0 || y < 0 || x >= N || y >= M ) return false;
    else return true;
}

int main(void) {
    
    int tmp, zero=0;
    int date = 0;
    int arr[1000][1000];
    queue<pair<pair<int, int>, int>> q;
    
    memset( arr, 0, sizeof(arr) );
    scanf("%d %d", &M, &N);
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            scanf("%d", &arr[i][j]);
            if( arr[i][j] == 0 ) zero++;
            if( arr[i][j] == 1 ){
                q.push(make_pair(P(i,j), date));
            }
        }
    }
    if( zero == 0 ){
        printf("0");
        return 0;
    }
    
    int ans = -1;
    while( !q.empty() ){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int val = q.front().second;
        
        for( int i=0; i<4; ++i ){
            int dix = x+dir_x[i];
            int diy = y+dir_y[i];
            if( check(dix,diy) && arr[dix][diy] == 0 ){
                arr[dix][diy] = 1;
                q.push(make_pair(P(dix, diy),val+1));
                ans = max( ans, val );
            }
        }
        q.pop();
    }
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( arr[i][j] == 0 ){
                printf("-1");
                return 0;
            }
        }
    }
    cout << ans+1;
    return 0;
}
