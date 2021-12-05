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
typedef pair<double, int> P;
const int MAX_V = 50;

/**
int N, M, ans=0, cnt=0;
char arr[20][20];
bool visited[26];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=M ) return false;
	else return true;
}
**/

char input[36][3];
bool visited[6][6];

int main(){
    memset( input, 0, sizeof(input) );
    memset( visited, 0, sizeof(visited) );
    for( int i=0; i<36; ++i ) scanf("%s", input[i]);
    for( int i=0; i<36; ++i ) visited['6'-input[i][1]][input[i][0]-'A'] = true;
    for( int i=0; i<35; ++i ){
        int gap = ABS( input[i][0]-input[i+1][0] ) + ABS( input[i][1]-input[i+1][1] );
        if( gap != 3 ){
            printf("Invalid");
            return 0;
        }else{
            if( input[i][0] == input[i+1][0] || input[i][1] == input[i+1][1] ){
                printf("Invalid");
                return 0;
            }
        }
    }
    int gap = ABS( input[0][0]-input[35][0] ) + ABS( input[0][1]-input[35][1] );
    if( gap != 3 ){
        printf("Invalid");
        return 0;
    }else{
        if( input[0][0] == input[35][0] || input[0][1] == input[35][1] ){
            printf("Invalid");
            return 0;
        }
    }
    for( int i=0; i<6; ++i ){
        for( int j=0; j<6; ++j ){
            if( !visited[i][j] ){
                printf("Invalid");
                return 0;
            }
        }
    }
    printf("Valid");
	return 0;
}










