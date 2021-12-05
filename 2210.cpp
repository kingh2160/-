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
#define INF 1e9
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

set<string> s;
int arr[5][5];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x < 0 || y < 0 || x > 4 || y > 4 ) return false;
    else return true;
}

void DFS( int x, int y, string str ){
    if( str.length() == 6 ){
        s.insert(str);
        return ;
    }
    for( int i=0; i<4; ++i ){
        int dx = x + dir_x[i];
        int dy = y + dir_y[i];
        if( check(dx, dy) ) DFS( dx, dy, str+to_string(arr[dx][dy]) );
    }
    return ;
}

int main(){
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<5; ++i ){
        for( int j=0; j<5; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    for( int i=0; i<5; ++i ){
        for( int j=0; j<5; ++j ){
            DFS( i, j, to_string(arr[i][j]) );
        }
    }
    printf("%d", (int)s.size());
    return 0;
}




