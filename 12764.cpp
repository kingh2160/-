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

bool compare( const P& a, const P& b ){
    if( a.second == b.second ) return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    
    int pos[100000];
    int N, A, B;
    int ans = 0;
    vector<P> v;
    priority_queue<P, vector<P>, greater<P>> pq;
    priority_queue<int, vector<int>, greater<int>> com;
    
    scanf("%d", &N);
    memset( pos, 0, sizeof(pos) );
    for( int i=0; i<N; ++i ){
        scanf("%d %d", &A, &B);
        v.push_back(P(A,B));
    }
    sort( v.begin(), v.end() );
    for( int i=1; i<N; ++i ) com.push( i );
    pq.push({v[0].second, 0});
    pos[0]++;
    for( int i=1; i<N; ++i ){
        while( !pq.empty() && pq.top().first < v[i].first ){
            com.push( pq.top().second );
            pq.pop();
        }
        pq.push( {v[i].second, com.top()} );
        pos[com.top()]++;
        com.pop();
        ans = max( ans, (int)pq.size() );
    }
    printf("%d\n", ans);
    for( int i=0; i<ans; ++i ) printf("%d ", pos[i]);
    return 0;
}
