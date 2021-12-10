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
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define INF 1e9+7
#define MOD 1000000000
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

int N, M;
int bans=0, wans=0;
char input[100][100];
bool visited[100][100];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x<0 || y<0 || x>=N || y>=M ) return false;
    else return true;
}

void WBFS( int x, int y ){
    int tmp = 0;
    queue<P> q;
    visited[x][y] = true;
    q.push({x,y});
    while( !q.empty() ){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        tmp++;
        for( int i=0; i<4; ++i ){
            int dx = x + dir_x[i];
            int dy = y + dir_y[i];
            if( check(dx,dy) && !visited[dx][dy] && input[dx][dy] == 'W' ){
                q.push({dx,dy});
                visited[dx][dy] = true;
            }
        }
    }
    wans += tmp*tmp;
}

void BBFS( int x, int y ){
    int tmp = 0;
    queue<P> q;
    visited[x][y] = true;
    q.push({x,y});
    while( !q.empty() ){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        tmp++;
        for( int i=0; i<4; ++i ){
            int dx = x + dir_x[i];
            int dy = y + dir_y[i];
            if( check(dx,dy) && !visited[dx][dy] && input[dx][dy] == 'B' ){
                q.push({dx,dy});
                visited[dx][dy] = true;
            }
        }
    }
    bans += tmp*tmp;
}

int main(){
    //fastio;
    memset( visited, 0, sizeof(visited) );
    memset( input, 0, sizeof(input) );
    scanf("%d %d", &M, &N);
    for( int i=0; i<N; ++i ) scanf("%s", input[i]);
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( input[i][j] == 'W' && !visited[i][j] ) WBFS( i, j );
        }
    }
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( input[i][j] == 'B' && !visited[i][j] ) BBFS( i, j );
        }
    }
    printf("%d %d", wans, bans);
    return 0;
}
