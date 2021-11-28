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
    
    int N;
    int tmp;
    int A[100000];
    int B[100000];
    vector<P> v;
    ll ans = 0;
    
    scanf("%d", &N);
    memset( A, 0, sizeof(A) );
    memset( B, 0, sizeof(B) );
    for( int i=0; i<N; ++i ) scanf("%d", &A[i]);
    for( int i=0; i<N; ++i ) scanf("%d", &B[i]);
    for( int i=0; i<N; ++i ){
        if( A[i] < B[i] ){
            tmp = ( B[i]-A[i]+29 )/30;
            A[i] += tmp*30;
            ans += tmp;
        }
        v.push_back({B[i],A[i]});
    }
    sort( v.begin(), v.end() );
    
    int target = 0;
    for( int i=0; i<N; ++i ){
        int cnt = i+1;
        while( cnt < N && v[cnt].first == v[cnt-1].first ) cnt++;
        for( int j=i; j<cnt; ++j ){
            if( v[j].second < target ){
                int x = (target-v[j].second+29)/30;
                ans += x;
                v[j].second += 30*x;
            }
        }
        sort( v.begin()+i, v.begin()+cnt );
        target = max( target, v[cnt-1].second );
        i = cnt-1;
    }
    printf("%lld", ans);
    return 0;
}
