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
typedef pair<int, int> P;
const int MAX_V = 50;

int N, M, ans=0;
int arr[20][20];
bool visited[20][20];
vector<P> v;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x < 0 || y < 0 || x >= N || y >= M ) return false;
    else return true;
}

int BFS( int x, int y ){
    bool flag = true;
    int ret = 0;
    queue<P> q;
    q.push({x,y});
    visited[x][y] = true;
    while( !q.empty() ){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        ret++;
        for( int i=0; i<4; ++i ){
            int dix = dx + dir_x[i];
            int diy = dy + dir_y[i];
            if( !check(dix, diy) ) continue;
            if( arr[dix][diy] == 0 ) flag = false;
            else if( arr[dix][diy] == 2 && !visited[dix][diy] ){
                visited[dix][diy] = true;
                q.push({dix,diy});
            }
        }
    }
    if( !flag ) return 0;
    else return ret;
}

void DO(){
    int ret = 0;
    memset( visited, 0, sizeof(visited) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( !visited[i][j] && arr[i][j] == 2 ){
                ret += BFS( i, j );
            }
        }
    }
    ans = max( ans, ret );
}

int main(){
    int cnt = 0;
    scanf("%d %d", &N, &M);
    memset( arr, 0, sizeof(arr) );
    memset( visited, 0, sizeof(visited) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            scanf("%d", &arr[i][j]);
            if( arr[i][j] == 0 ){
                v.push_back(P(i,j));
                cnt++;
            }
        }
    }
    vector<int> Combination;
    for( int i=0; i<(int)v.size()-2; ++i ) Combination.push_back( 0 );
    for( int i=0; i<2; ++i ) Combination.push_back( 1 );
    do{
        for( int i=0; i<(int)Combination.size(); ++i ) if( Combination[i] == 1 ) arr[v[i].first][v[i].second] = 1;
        DO();
        for( int i=0; i<(int)Combination.size(); ++i ) if( Combination[i] == 1 ) arr[v[i].first][v[i].second] = 0;
    }while(next_permutation(Combination.begin(), Combination.end()));
    printf("%d", ans);
    return 0;
}




