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
typedef pair<double, int> P;
const int MAX_V = 50;


int N, M;
int sx, sy, fx, fy;
int arr[1000][1000];
int ans[1000][1000][2];
bool visited[1000][1000][2];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=M ) return false;
	else return true;
}

void BFS(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx,sy}, 1});
    while( !q.empty() ){
        int dx = q.front().first.first;
        int dy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        for( int i=0; i<4; ++i ){
            int dix = dx + dir_x[i];
            int diy = dy + dir_y[i];
            if( cnt == 1 ){
                if( check(dix, diy) && !visited[dix][diy][cnt-1] && arr[dix][diy] == 1 ){
                    q.push({{dix,diy}, cnt-1});
                    visited[dix][diy][cnt-1] = true;
                    ans[dix][diy][cnt-1] = ans[dx][dy][cnt] + 1;
                }
            }
            if( check(dix, diy) && !visited[dix][diy][cnt] && arr[dix][diy] != 1 ){
                q.push({{dix,diy},cnt});
                visited[dix][diy][cnt] = true;
                ans[dix][diy][cnt] = ans[dx][dy][cnt] + 1;
            }
        }
    }
}


int main(){
    memset( arr, 0, sizeof(arr) );
    memset( ans, 0, sizeof(ans) );
    memset( visited, 0, sizeof(visited) );
    scanf("%d %d", &N, &M);
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &fx, &fy);
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    sx--; sy--; fx--; fy--;
    BFS();
    if( !visited[fx][fy][0] && !visited[fx][fy][1] ){
        printf("-1");
    }else{
        int tmp = 1e9;
        if( visited[fx][fy][0] ) tmp = min( tmp, ans[fx][fy][0] );
        if( visited[fx][fy][1] ) tmp = min( tmp, ans[fx][fy][1] );
        printf("%d", tmp);
    }
	return 0;
}










