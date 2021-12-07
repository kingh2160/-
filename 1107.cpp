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
typedef pair<int, string> P;
const int MAX_V = 50;

int N, K;
bool visited[10];
int ans = INF;

int GO( int x ){
    int ret = 0;
    if( x == 0 ){
        if( !visited[0] ) return 1;
        else return INF;
    }
    while( x ){
        int now = x%10;
        if( !visited[now] ) ret++;
        else return INF;
        x /= 10;
    }
    return ret;
}

int main(){
    fastio;
    int tmp;
    cin >> N;
    cin >> K;
    memset( visited, 0, sizeof(visited) );
    for( int i=0; i<K; ++i ){
        cin >> tmp;
        visited[tmp] = true;
    }
    ans = min( ans, ABS((N-100)) );
    for( int i=0; i<=1000000; ++i ){
        tmp = GO( i );
        if( tmp == INF ) continue;
        tmp += ABS( (N-i) );
        ans = min( ans, tmp );
    }
    cout << ans;
    return 0;
}
