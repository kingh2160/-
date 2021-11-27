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
    
    int N;
    cin >> N;
    
    while( N-- ){
        int len;
        cin >> len;
        string s1="", s2="";
        cin >> s1 >> s2;
        
        int s1_cnt=0, s2_cnt=0, diff=0;
        for( int i=0; i<len; ++i ){
            if( s1[i] == 'W' ) s1_cnt++;
            if( s2[i] == 'W' ) s2_cnt++;
            if( s1[i] != s2[i] ) diff++;
        }
        int delta = ABS( (s1_cnt-s2_cnt) );
        int ans = delta + (diff-delta)/2;
        printf("%d\n", ans);
    }
    return 0;
}
