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

int N, M, ans=INF;
int arr[50][50];
int lab[50][50];
bool visited[50][50];
vector<P> v;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x<0 || y<0 || x>=N || y>=N ) return false;
    else return true;
}

void VIEW(){
    cout << "\n";
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            cout << lab[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void BFS(){
    int ret = 0;
    queue<P> q;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            if( lab[i][j] == 2 ){
                q.push({i,j});
                visited[i][j] = true;
                lab[i][j] = 0;
            }
        }
    }
    while( !q.empty() ){
        int dx = q.front().first;
        int dy = q.front().second;
        ret = max( ret, lab[dx][dy] );
        q.pop();
        for( int i=0; i<4; ++i ){
            int dix = dx + dir_x[i];
            int diy = dy + dir_y[i];
            if( check(dix,diy) && arr[dix][diy] != 1 && !visited[dix][diy] ){
                lab[dix][diy] = lab[dx][dy] + 1;
                visited[dix][diy] = true;
                q.push({dix,diy});
            }
        }
    }
    bool flag = false;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            if( !visited[i][j] && lab[i][j] == 0 ){
                flag = true;
                break;
            }
        }
        if( flag ) break;
    }
    if( !flag ) ans = min( ans, ret );
}

int main(){
    fastio;
    cin >> N >> M;
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            cin >> arr[i][j];
            if( arr[i][j] == 2 ) v.push_back({i,j});
        }
    }
    vector<int> comb;
    for( int i=0; i<M; ++i ) comb.push_back( 1 );
    for( int i=0; i<(int)v.size()-M; ++i ) comb.push_back( 0 );
    
    do{
        memcpy( lab, arr, sizeof(arr) );
        memset( visited, 0, sizeof(visited) );
        for( int i=0; i<(int)v.size(); ++i ){
            if( comb[i] == 0 ) lab[v[i].first][v[i].second] = 0;
        }
        BFS();
        //VIEW();
    }while(prev_permutation(comb.begin(), comb.end()));
    if( ans == INF ) cout << -1;
    else cout << ans;
    return 0;
}
