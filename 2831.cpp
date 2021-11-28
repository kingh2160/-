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

int main(void) {
    
    int N, tmp;
    priority_queue<int> man_minus;
    priority_queue<int> woman_minus;
    priority_queue<int, vector<int>, greater<int>> man_plus;
    priority_queue<int, vector<int>, greater<int>> woman_plus;
    
    scanf("%d", &N);
    for( int i=0; i<N; ++i ){
        scanf("%d", &tmp);
        if( tmp > 0 ) man_plus.push( tmp );
        else man_minus.push( tmp );
    }
    
    for( int i=0; i<N; ++i ){
        scanf("%d", &tmp);
        if( tmp > 0 ) woman_plus.push( tmp );
        else woman_minus.push( tmp );
    }
    
    int ans = 0;
    int target;
    while( !woman_minus.empty() && !man_plus.empty() ){
        target = ABS(woman_minus.top());
        woman_minus.pop();
        if( target > man_plus.top() ){
            ans++;
            man_plus.pop();
        }
    }
    while( !man_minus.empty() && !woman_plus.empty() ){
        target = ABS(man_minus.top());
        man_minus.pop();
        if( target > woman_plus.top() ){
            ans++;
            woman_plus.pop();
        }
    }
    printf("%d", ans);
    return 0;
}
