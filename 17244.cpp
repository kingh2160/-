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

P S, E;
map<P,int> itemidx;
struct pos{
    int x;
    int y;
    int item;
};
int N, M;
int total = 0;
int ans = 1e9;
char arr[52][52];
int visited[52][52][1<<6];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

void BFS(){
    queue<pos> q;
    visited[S.first][S.second][0] = 1;
    q.push( { S.first, S.second, 0 } );
    while( !q.empty() ){
        int dx = q.front().x;
        int dy = q.front().y;
        int cnt = q.front().item;
        for( int i=0; i<4; ++i ){
            int dix = dx + dir_x[i];
            int diy = dy + dir_y[i];
            if( arr[dix][diy] != '#' && !visited[dix][diy][cnt] ){
                if( arr[dix][diy] == 'X' ){
                    int target = itemidx[{dix,diy}];
                    if( cnt & (1 << target) ){
                        visited[dix][diy][cnt] = visited[dx][dy][cnt] + 1;
                        q.push({dix,diy,cnt});
                    }else{
                        visited[dix][diy][cnt|(1<<target)] = visited[dx][dy][cnt] + 1;
                        q.push({dix,diy,cnt|(1<<target)});
                    }
                }else if( arr[dix][diy] == 'E' ){
                    if( cnt == (1<<total)-1 ) ans = min( ans, visited[dx][dy][cnt] );
                }else{
                    visited[dix][diy][cnt] = visited[dx][dy][cnt] + 1;
                    q.push({dix,diy,cnt});
                }
            }
        }
        q.pop();
    }
}

int main(void) {
    
    scanf("%d %d", &M, &N);
    memset( visited, 0, sizeof(visited) );
    for( int i=0; i<N; ++i ){
        scanf("%s", arr[i]);
        for( int j=0; j<M; ++j ){
            if( arr[i][j] == 'S' ) S = {i,j};
            else if( arr[i][j] == 'E' ) E = {i,j};
            else if( arr[i][j] == 'X' ) itemidx[P(i,j)] = total++;
        }
    }
    BFS();
    printf("%d", ans);
    return 0;
}
