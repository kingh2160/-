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
int A, B, C, D;
int arr[100][100];
bool visited[100][100];
bool lighton[100][100];
vector<P> light[100][100];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x<0 || y<0 || x>=N || y>=N ) return false;
    else return true;
}

void BFS(){
    int cnt = 0;
    queue<P> q;
    arr[0][0] = 1;
    visited[0][0] = true;
    lighton[0][0] = true;
    q.push({0,0});
    while( !q.empty() ){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for( int i=0; i<light[x][y].size(); ++i ){
            int dx = light[x][y][i].first;
            int dy = light[x][y][i].second;
            arr[dx][dy] = 1;
        }
        for( int i=0; i<4; ++i ){
            int dx = x + dir_x[i];
            int dy = y + dir_y[i];
            if( check(dx,dy) ) lighton[dx][dy] = true;
        }
        
        for( int i=0; i<N; ++i ){
            for( int j=0; j<N; ++j ){
                if( !visited[i][j] && lighton[i][j] && arr[i][j] == 1 ){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
    }
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            if( arr[i][j] == 1 ) cnt++;
        }
    }
    printf("%d", cnt);
}

int main(){
    fastio;
    cin >> N >> M;
    memset( arr, 0, sizeof(arr) );
    memset( visited, 0, sizeof(visited) );
    memset( lighton, 0, sizeof(lighton) );
    for( int i=0; i<M; ++i ){
        cin >> A >> B >> C >> D;
        light[A-1][B-1].push_back({C-1,D-1});
    }
    BFS();
    return 0;
}
