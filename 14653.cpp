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
    bool visited[10000][26];
    vector<pair<int, char>> v;
    int N, K, Q;
    int tmp;
    char ch;
    memset( visited, 0, sizeof(visited) );
    scanf("%d %d %d", &N, &K, &Q);
    for( int i=0; i<K; ++i ){
        scanf("%d %c", &tmp, &ch);
        v.push_back({tmp,ch});
    }
    if( v[Q-1].first == 0 ){
        printf("-1");
        return 0;
    }
    for( int i=0; i<K; ++i ){
        if( v[i].first >= v[Q-1].first ) visited[Q-1][v[i].second-'A'] = true;
    }
    visited[Q-1][0] = true;
    for( int i=0; i<N; ++i ){
        if( !visited[Q-1][i] ) printf("%c ", 'A'+i);
    }
    return 0;
}
