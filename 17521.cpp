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
using namespace std;
#define INF 1e9
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<char, int> P;
const int MAX_V = 50;

int main(void) {
    
    int N, W;
    int arr[15];
    
    scanf("%d %d", &N, &W);
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<N; ++i ){
        scanf("%d", &arr[i]);
    }
    
    ll ans = W;
    for( int i=0; i<N-1; ++i){
        if( arr[i] < arr[i+1] ){
            ll cnt = ans/arr[i];
            ans %= arr[i];
            ans += cnt*arr[i+1];
        }
    }
    printf("%lld", ans);
    return 0;
}
