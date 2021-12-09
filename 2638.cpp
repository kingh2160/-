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
#define MOD 10000
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

int N, M;
int arr[100][100];
bool visited[100][100];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
bool check( int x, int y ){
    if( x<0 || y<0 || x>=N || y>=M ) return false;
    else return true;
}

void BFS(){
    queue<P> q;
    q.push({0,0});
    visited[0][0] = true;
    memset( visited, 0, sizeof(visited) );
    while( !q.empty() ){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for( int i=0; i<4; ++i ){
            int dix = x + dir_x[i];
            int diy = y + dir_y[i];
            if( check(dix,diy) && !visited[dix][diy] && arr[dix][diy] == 0 ){
                q.push({dix,diy});
                visited[dix][diy] = true;
            }else if( check(dix,diy) && arr[dix][diy] > 0 ) arr[dix][diy]++;
        }
    }
}

bool GO(){
    bool flag = false;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( arr[i][j] > 2 ){
                flag = true;
                arr[i][j] = 0;
            }else if( arr[i][j] == 2 ) arr[i][j]--;
        }
    }
    return flag;
}

int main(){
    fastio;
    cin >> N >> M;
    memset( visited, 0, sizeof(visited) );
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    while( 1 ){
        BFS();
        if( GO() ) ans++;
        else break;
    }
    cout << ans;
    return 0;
}
