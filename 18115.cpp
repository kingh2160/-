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
typedef pair<int, int> P;
const int MAX_V = 50;

int main(void) {
   
    int N;
    int tmp;
    deque<int> d;
    vector<int> v;
    
    scanf("%d", &N);
    for( int i=0; i<N; ++i ){
        scanf("%d", &tmp);
        v.push_back( tmp );
    }
    
    int cnt = 1;
    vector<int>::iterator iter;
    reverse( v.begin(), v.end() );
    for( iter = v.begin(); iter != v.end(); iter++ ){
        if( *iter == 1 ){
            d.push_front( cnt++ );
        }else if( *iter == 3 ){
            d.push_back( cnt++ );
        }else{
            if( d.empty() ){
                d.push_back( cnt++ );
            }else{
                if( d.empty() ){
                    d.push_front( cnt++ );
                }else{
                    int first = d.front();
                    d.pop_front();
                    d.push_front( cnt++ );
                    d.push_front( first );
                }
            }
        }
    }
    deque<int>::iterator iter1;
    for(iter1 = d.begin(); iter1 != d.end(); iter1++){
        printf("%d ", *iter1);
    }
    return 0;
}
