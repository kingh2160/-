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
   
    int T;
    char input[1000000+1];
    
    scanf("%d", &T);
    for( int i=0; i<T; ++i ){
        list<char> target;
        memset( input, 0, sizeof(input) );
        
        scanf("%s", input);
        auto iter = target.end();
        int len = strlen(input);
        for( int j=0; j<len; ++j ){
            if( input[j] == '<' ){
                if( iter == target.begin() ) continue;
                iter--;
            }else if( input[j] == '>' ){
                if( iter == target.end() ) continue;
                iter++;
            }else if( input[j] == '-' ){
                if( iter == target.begin() ) continue;
                iter = target.erase( --iter );
            }else{
                target.insert( iter, input[j] );
            }
        }
        for( auto targeti=target.begin(); targeti != target.end(); ++targeti ) printf("%c", *targeti);
        printf("\n");    
    }
    return 0;
}
