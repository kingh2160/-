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
int arr[1000][1000];
int ans[1000][1000][2];
bool visited[1000][1000][2];
queue<pair<pair<int, int>, int>> q;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x < 0 || y < 0 || x >= N || y >= M ) return false;
    else return true;
}

void BFS(){
    q.push({{0,0},1});
    visited[0][0][1] = true;
    visited[0][0][0] = true;
    while( !q.empty() ){
        int dx = q.front().first.first;
        int dy = q.front().first.second;
        int cnt = q.front().second;
        for( int i=0; i<4; ++i ){
            int dix = dx + dir_x[i];
            int diy = dy + dir_y[i];
            if( check(dix, diy) ){
                if( cnt == 1 ){
                    if( arr[dix][diy] == 1 && !visited[dix][diy][0] ){
                        visited[dix][diy][0] = true;
                        ans[dix][diy][0] = ans[dx][dy][1] + 1;
                        q.push({{dix,diy},cnt-1});
                    }
                }
                if( arr[dix][diy] == 0 && !visited[dix][diy][cnt] ){
                    visited[dix][diy][cnt] = true;
                    ans[dix][diy][cnt] = ans[dx][dy][cnt] + 1;
                    q.push({{dix,diy},cnt});
                }
            }
        }
        q.pop();
    }
}


int main(void) {
        
    scanf("%d %d", &N, &M);
    memset( arr, 0, sizeof(arr) );
    memset( visited, 0, sizeof(visited) );
    memset( ans, 0, sizeof(ans) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            scanf("%1d", &arr[i][j]);
        }
    }
    BFS();
    int tmp = 1e9;
    if( visited[N-1][M-1][0] ) tmp = min( tmp, ans[N-1][M-1][0] );
    if( visited[N-1][M-1][1] ) tmp = min( tmp, ans[N-1][M-1][1] );
    if( tmp == 1e9 ) printf("-1");
    else printf("%d", tmp+1);
    return 0;
}
