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

void GO(){
    string str, tmp;
    deque<string> dq;
    int N, rcnt=0;
    cin >> str >> N;
    cin.ignore();
    getline(cin, tmp, '[');
    for( int i=0; i<N-1; ++i ){
        getline(cin, tmp, ',');
        dq.push_back( tmp );
    }
    getline(cin, tmp, ']');
    dq.push_back( tmp );
    for( int i=0; i<(int)str.size(); ++i ){
        if( str[i] == 'R' ){
            rcnt++;
        }else{
            if( dq.empty() || N == 0 ){
                cout << "error" << "\n";
                return ;
            }else{
                if( rcnt%2 == 0 ) dq.pop_front();
                else dq.pop_back();
            }
        }
    }
    
    if( dq.empty() || N == 0 ) cout << "[]" << "\n";
    else{
        cout << "[";
        while( !dq.empty() ){
            if( (int)dq.size() == 1 ) break;
            if( rcnt%2 == 0 ){
                cout << dq.front() << ",";
                dq.pop_front();
            }else{
                cout << dq.back() << ",";
                dq.pop_back();
            }
        }
        cout << dq.back() << "]\n";
    }
}

int main(){
    fastio;
    int TC;
    cin >> TC;
    while( TC-- ) GO();
    return 0;
}
