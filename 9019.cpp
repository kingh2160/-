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
#define MOD 10000
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, string> P;
const int MAX_V = 50;

int A, B;
bool visited[10000+1];

void BFS(){
    queue<P> q;
    q.push({A, ""});
    visited[A] = true;
    while( !q.empty() ){
        int x = q.front().first;
        string y = q.front().second;
        q.pop();
        if( x == B ){
            cout << y << '\n';
            return ;
        }
        int tmp;
        tmp = (x*2)%10000;
        if( !visited[tmp] ){
            visited[tmp] = true;
            q.push({tmp,y+'D'});
        }
        tmp = x == 0 ? 9999 : x-1;
        if( !visited[tmp] ){
            visited[tmp] = true;
            q.push({tmp,y+'S'});
        }
        tmp = (x%1000)*10+(x/1000);
        if( !visited[tmp] ){
            visited[tmp] = true;
            q.push({tmp,y+'L'});
        }
        tmp = (x%10)*1000+(x/10);
        if( !visited[tmp] ){
            visited[tmp] = true;
            q.push({tmp,y+'R'});
        }
    }
}

int main(){
    fastio;
    int TC;
    cin >> TC;
    while( TC-- ){
        cin >> A >> B;
        memset( visited, 0, sizeof(visited) );
        BFS();
    }
    return 0;
}
