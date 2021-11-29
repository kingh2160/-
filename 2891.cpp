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
    
    int N, S, R, tmp;
    int boat[10];
    
    scanf("%d %d %d", &N ,&S, &R);
    for( int i=0; i<10; ++i ) boat[i] = 1;
    for( int i=0; i<S; ++i ){ scanf("%d", &tmp); boat[tmp-1]--; }
    for( int i=0; i<R; ++i ){ scanf("%d", &tmp); boat[tmp-1]++; }
    
    for( int i=0; i<N; ++i ){
        if( boat[i] == 0 ){
            if( i-1 >= 0 && boat[i-1] == 2 ){
                boat[i-1]--;
                boat[i]++;
            }else if( i+1 < N && boat[i+1] == 2 ){
                boat[i+1]--;
                boat[i]++;
            }
        }
    }
    int ans = 0;
    for( int i=0; i<N; ++i ) if( boat[i] == 0 ) ans++;
    printf("%d", ans);
    return 0;
}
