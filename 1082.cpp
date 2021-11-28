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

int N, M;
int arr[10];
int get_idx( int start ){
    int ret = arr[start];
    int pos = start;
    if( N == 1 ) return 0;
    else{
        for( int i=start+1; i<N; ++i ){
            if( arr[i] < ret ){
                ret = arr[i];
                pos = i;
            }
        }
    }
    return pos;
}

int main(void) {
    
    scanf("%d", &N);
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<N; ++i ) scanf("%d", &arr[i]);
    scanf("%d", &M);
    
    int idx = get_idx( 1 );
    string ans = "";
    if( arr[idx] <= M ){
        M -= arr[idx];
        ans += '0'+idx;
    }
    idx = get_idx( 0 );
    while( arr[idx] <= M ){
        M -= arr[idx];
        ans += '0'+idx;
    }
    if( ans.length() > 1 ){
        if( ans[0] == '0' && ans[1] == '0' ){
            cout << '0';
            return 0;
        }
    }
    
    for( int i=0; i<ans.length(); ++i ){
        for( int j=N-1; j>0; --j ){
            if( j > ans[i]-'0' && M >= arr[j]-arr[(ans[i]-'0')]  ){
                M -= arr[j]-arr[(ans[i]-'0')];
                ans[i] = '0'+j;
            }
        }
    }
    cout << ans;
    return 0;
}
