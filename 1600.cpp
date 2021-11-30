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

int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
int dir_hx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dir_hy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
queue<pair<pair<int, int>, int>> q;
int K, W, H;
int ans[200][200][31];
int arr[200][200];
bool visited[200][200][31];

bool check( int x, int y ){
    if( x < 0 || y < 0 || x >= H || y >= W ) return false;
    else return true;
}

void BFS(){
    q.push( {{0, 0}, K} );
    visited[0][0][K] = true;
    while( !q.empty() ){
        int dx = q.front().first.first;
        int dy = q.front().first.second;
        int cnt = q.front().second;
        if( cnt > 0 ){
            for( int i=0; i<8; ++i ){
                int dix = dx + dir_hx[i];
                int diy = dy + dir_hy[i];
                if( check(dix, diy) && arr[dix][diy] != 1 && !visited[dix][diy][cnt-1] ){
                    ans[dix][diy][cnt-1] = ans[dx][dy][cnt] + 1;
                    visited[dix][diy][cnt-1] = true;
                    q.push( {{dix,diy},cnt-1} );
                }
            }
        }
        for( int i=0; i<4; ++i ){
            int dix = dx + dir_x[i];
            int diy = dy + dir_y[i];
            if( check(dix, diy) && arr[dix][diy] != 1 && !visited[dix][diy][cnt] ){
                ans[dix][diy][cnt] = ans[dx][dy][cnt] + 1;
                visited[dix][diy][cnt] = true;
                q.push({{dix,diy}, cnt});
            }
        }
        q.pop();
    }
}

int main(void) {
        
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    memset( arr, 0, sizeof(arr) );
    memset( ans, 0, sizeof(ans) );
    memset( visited, 0, sizeof(visited) );
    for( int i=0; i<H; ++i ){
        for( int j=0; j<W; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    BFS();
    int tmp = 1e9;
    for( int i=0; i<=K; ++i ){
        if( visited[H-1][W-1][i] ) tmp = min( tmp, ans[H-1][W-1][i] );
    }
    if( tmp == 1e9 ) printf("-1");
    else printf("%d", tmp);
    return 0;
}
