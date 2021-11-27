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
    
    char input[3000+1];
    
    memset( input, 0, sizeof(input) );
    scanf("%s", input);
    
    int cnt = 0;
    int len = strlen( input );
    string max_ans = "";
    string min_ans = "";
    for( int i=0; i<len; ++i ){
        if( input[i] == 'K' ){
            max_ans.push_back('5');
            if( cnt > 0 ){
                min_ans.push_back('1');
                for( int j=1; j<cnt; ++j ) min_ans.push_back('0');
            }
            for( int j=0; j<cnt; ++j ) max_ans.push_back('0');
            min_ans.push_back('5');
            cnt = 0;
        }else{
            cnt++;
        }
    }
    int max_len = max_ans.length();
    int min_len = min_ans.length();
    for( int i=0; i<len-max_len; ++i ) max_ans.push_back('1');
    if( len > min_len ){
        min_ans.push_back('1');
        min_len++;
        for( int i=0; i<len-min_len; ++i ) min_ans.push_back('0');
    }
    
    cout << max_ans << "\n";
    cout << min_ans;
    return 0;
}
