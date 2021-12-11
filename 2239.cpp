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
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define INF 1e9+7
#define MOD 1000000000
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

int arr[9][9];
bool done = false;
P findzero(){
    bool flag = false;
    int x=-1, y=-1;
    for( int i=0; i<9; ++i ){
        for( int j=0; j<9; ++j ){
            if( arr[i][j] == 0 ){
                x = i; y = j;
                flag = true;
                break;
            }
        }
        if( flag ) break;
    }
    return P(x,y);
}

bool canpick( int x, int y, int value ){
    for( int i=0; i<9; ++i ) if( arr[x][i] == value ) return false;
    for( int i=0; i<9; ++i ) if( arr[i][y] == value ) return false;
    int dx = (x/3)*3;
    int dy = (y/3)*3;
    if( arr[dx][dy] == value || arr[dx][dy+1] == value || arr[dx][dy+2] == value ) return false;
    if( arr[dx+1][dy] == value || arr[dx+1][dy+1] == value || arr[dx+1][dy+2] == value ) return false;
    if( arr[dx+2][dy] == value || arr[dx+2][dy+1] == value || arr[dx+2][dy+2] == value ) return false;
    return true;
}

void DFS(){
    P tmp = findzero();
    if( tmp.first == -1 && tmp.second == -1 ){
        for( int i=0; i<9; ++i ){
            for( int j=0; j<9; ++j ){
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
        done = true;
        return ;
    }
    for( int i=1; i<10; ++i ){
        if( canpick(tmp.first, tmp.second, i) ){
            arr[tmp.first][tmp.second] = i;
            DFS();
            if( done ) return ;
            arr[tmp.first][tmp.second] = 0;
        }
    }
    return ;
}

int main(){
    //fastio;
    memset( arr, 0, sizeof(arr) );
    for( int i=0; i<9; ++i ){
        for( int j=0; j<9; ++j ){
            scanf("%1d", &arr[i][j]);
        }
    }
    DFS();
    return 0;
}
