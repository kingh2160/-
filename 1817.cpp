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
typedef pair<char, int> P;
const int MAX_V = 50;

int main(void) {
    
    int N, M;
    int cal = 0;
    int ans = 0;
    
    scanf("%d %d", &N, &M);
    if( N == 0 ){
        printf("0");
        return 0;
    }
    cal = M;
    for( int i=0; i<N; ++i ){
        int tmp;
        scanf("%d", &tmp);
        if( cal >= tmp ){
            cal -= tmp;
        }else{
            ans++;
            cal = M;
            cal -= tmp;
        }
    }
    printf("%d", ans+1);
    return 0;
}
