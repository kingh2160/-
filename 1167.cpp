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

int V, N, A, B;
int start;
int ans = -INF;
vector<P> v[100000];
bool visited[100000];

void DFS( int vertex, int value ){
    visited[vertex] = true;
    if( ans < value ){
        ans = value;
        start = vertex;
    }
    for( int i=0; i<(int)v[vertex].size(); ++i ){
        int next = v[vertex][i].first;
        int val = v[vertex][i].second;
        if( !visited[next] ) DFS( next, value+val );
    }
}

int main(){
    fastio;
    cin >> V;
    for( int i=0; i<V; ++i ){
        cin >> N;
        while( 1 ){
            cin >> A;
            if( A == -1 ) break;
            cin >> B;
            v[N-1].push_back( {A-1, B} );
        }
    }
    memset( visited, 0, sizeof(visited) );
    DFS( 0, 0 );
    memset( visited, 0, sizeof(visited) );
    DFS( start, 0 );
    cout << ans;
    return 0;
}
