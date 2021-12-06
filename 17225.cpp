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
    priority_queue<P, vector<P>, greater<P>>Blue;
    priority_queue<P, vector<P>, greater<P>>Red;
    int A, B, N, T, M;
    char ch;
    int btime, rtime;
    scanf("%d %d %d", &A, &B, &N);
    btime = 0;
    rtime = 0;
    for( int i=0; i<N; ++i ){
        scanf("%d %c %d", &T, &ch, &M);
        if( ch == 'B' ){
            btime = max( btime, T );
            while( M-- ){
                Blue.push({btime, btime+A});
                btime += A;
            }
        }else{
            rtime = max( rtime, T );
            while( M-- ){
                Red.push({rtime, rtime+B});
                rtime += B;
            }
        }
    }
    int bnum = (int)Blue.size();
    int rnum = (int)Red.size();
    vector<int> bluev;
    vector<int> redv;
    int idx = 1;
    while( !Blue.empty() || !Red.empty() ){
        if( Blue.empty() ){
            redv.push_back( idx++ );
            Red.pop();
        }else if( Red.empty() ){
            bluev.push_back( idx++ );
            Blue.pop();
        }else{
            if( Blue.top().first <= Red.top().first ){
                bluev.push_back( idx++ );
                Blue.pop();
            }else{
                redv.push_back( idx++ );
                Red.pop();
            }
        }
    }
    printf("%d\n", bnum);
    for( int i=0; i<bnum; ++i ) printf("%d ", bluev[i]);
    printf("\n%d\n", rnum);
    for( int i=0; i<rnum; ++i ) printf("%d ", redv[i]);
    return 0;
}
