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
#define INF 1e9+7
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;


int main(){
    int N, A, B;
    ll ans = 0;
    vector<P> v;
    scanf("%d", &N);
    
    for( int i=0; i<N; ++i ){
        scanf("%d %d", &A, &B);
        v.push_back({B,A});
    }
    sort( v.begin(), v.end() );
    int left = 0;
    int right = 0;
    int tmp = 0;
    for( int i=0; i<N; ++i ){
        if( i == 0 ) left = INF;
        else{
            if( v[i].first != v[i-1].first ) left = INF;
            else left = v[i].second - v[i-1].second;
        }
        if( i == N-1 ) right = INF;
        else{
            if( v[i].first != v[i+1].first ) right = INF;
            else right = v[i+1].second - v[i].second;
        }
        tmp = min( left, right );
        if( tmp != INF ) ans += tmp;
    }
    printf("%lld", ans);
    return 0;
}
