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
typedef pair<pair<int, int>, int> P;
const int MAX_V = 50;

bool compare( P A, P B ){
    return A.first.second < B.first.second;
}

int main(void) {
    
    int N, C, A, B, M, cost;
    vector<P> v;
    scanf("%d %d", &N, &C);
    scanf("%d", &M);
    vector<int> space(N);
    for( int i=0; i<M; ++i ){
        scanf("%d %d %d", &A, &B, &cost);
        v.push_back(P(make_pair(A-1,B-1),cost));
    }
    sort( v.begin(), v.end(), compare );
    
    ll ans = 0;
    for( int i=0; i<M; ++i ){
        int start = v[i].first.first;
        int end = v[i].first.second;
        int weight = v[i].second;
        int tmp = 0;
        int possible = 0;
        
        for( int j=start; j<end; ++j ){
            tmp = max( tmp, space[j] );
        }
        if( tmp+weight <= C ) possible = weight;
        else possible = C-tmp;
        for( int j=start; j<end; ++j ) space[j] += possible;
        ans += possible;
    }
    printf("%lld", ans);
    return 0;
}
