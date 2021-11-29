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
    
    ull N;
    ull lo = 0;
    ull hi = 3037000500;
    ull mid = 0;
    ull ans = 3037000500;
    
    cin >> N;
    if( N == 0 ){
        printf("0");
        return 0;
    }else if( N > 9223372030926249001 ){
        printf("3037000500");
        return 0;
    }
    while( lo+1 < hi ){
        mid = (lo+hi)/2;
        if( mid*mid < N ) lo = mid;
        else{
            hi = mid;
            ans = min( ans, mid );
        }
    }
    cout << ans;
    return 0;
}
