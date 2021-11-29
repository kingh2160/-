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

int main(void) {
    
    int N, A, B;
    int src, dest;
    vector<P> v;
    priority_queue<int> pq;
    
    scanf("%d", &N);
    for( int i=0; i<N; ++i ){
        scanf("%d %d", &A, &B);
        v.push_back({A,B});
    }
    scanf("%d %d", &dest, &src);
    sort( v.begin(), v.end() );
    
    ll ans = 0;
    int idx = 0;
    while( src < dest ){
        while( v[idx].first <= src && idx < N ){
            pq.push(v[idx].second);
            idx++;
        }
        if( pq.empty() ) break;
        src += pq.top();
        pq.pop();
        ans++;
    }
    if( src < dest ) printf("-1");
    else printf("%lld", ans);
    
    return 0;
}
