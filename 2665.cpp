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

int N;
int arr[50][50];
int ans[50][50];
bool visited[50][50];
vector<P> v;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x<0 || y<0 || x>=N || y>=N ) return false;
    else return true;
}

void BFS(){
    deque<P> dq;
    visited[0][0] = true;
    dq.push_back({0,0});
    while( !dq.empty() ){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        for( int i=0; i<4; ++i ){
            int dx = x + dir_x[i];
            int dy = y + dir_y[i];
            if( check(dx, dy) && !visited[dx][dy] ){
                if( arr[dx][dy] == 1 ){
                    ans[dx][dy] = ans[x][y];
                    visited[dx][dy] = true;
                    dq.push_front({dx,dy});
                }else{
                    ans[dx][dy] = ans[x][y] + 1;
                    visited[dx][dy] = true;
                    dq.push_back({dx,dy});
                }
            }
        }
    }
}

int main(){
    //fastio;
    scanf("%d", &N);
    memset( arr, 0, sizeof(arr) );
    memset( ans, 0, sizeof(ans) );
    memset( visited, 0, sizeof(visited) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            scanf("%1d", &arr[i][j]);
        }
    }
    BFS();
    printf("%d", ans[N-1][N-1]);
    return 0;
}
