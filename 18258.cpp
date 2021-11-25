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
#define INF 1000000000
#define MOD 1000000007
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

int main(void) {
   
    int N;
    queue<int> q;
    
    scanf("%d", &N);
    for( int i=0; i<N; ++i ){
        char input[20];
        memset( input, 0, sizeof(input) );
        scanf("%s", input);
        if( input[0] == 'p' && input[1] == 'u' && input[2] == 's' && input[3] == 'h' ){
            int tmp;
            scanf(" %d", &tmp);
            q.push( tmp );
        }else{
            if( input[0] == 'f' && input[1] == 'r' && input[2] == 'o' && input[3] == 'n' && input[4] == 't'){
                if( q.size() == 0 ){
                    printf("-1\n");
                }else{
                    printf("%d\n", q.front());   
                }
            }else if( input[0] == 'b' && input[1] == 'a' && input[2] == 'c' && input[3] == 'k' ){
                if( q.size() == 0 ){
                    printf("-1\n");
                }else{
                    printf("%d\n", q.back());
                }
            }else if( input[0] == 'p' && input[1] == 'o' && input[2] == 'p' ){
                if( q.size() == 0 ){
                    printf("-1\n");
                }else{
                    printf("%d\n", q.front());
                    q.pop();
                }
            }else if( input[0] == 's' && input[1] == 'i' && input[2] == 'z' && input[3] == 'e' ){
                printf("%ld\n", q.size());
            }else{
                if( q.size() == 0 ){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
            }
        }
    }
    
    return 0;
}
