#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

//trocar os long longs por outro tipo desejado, ou:
//template<typename T>
struct Point{
    long long int x, y;
    Point(long long int x, long long int y){
        this->x = x;
        this->y = y;
    }
    Point operator+(Point o){ return Point(x + o.x, y + o.y); }
    Point operator-(Point o){ return Point(x - o.x, y - o.y); }
    Point operator*(long long int k){ return Point(k*x, k*y); }
    double len(){ return hypot(x, y); }
    long long int cross(Point o){ return ((x * o.y) - (y*o.x)); }
    bool operator<(Point o){ return(tie(x, y) < tie(o.x, o.y)); }
    bool operator==(Point o){ return (tie(x, y) == tie(o.x, o.y)); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long int x1, x2, x3, y1, y2, y3;
    for(int k = 0; k < t; k++){
        Point p1 = Point(x2 - x1, y2 - y1);
        Point p2 = Point(x3 - x1, y3 - y1);
        //produto vetorial
        long long int check = p2.cross(p1);
        if(check == 0){
            cout << "TOUCH" << endl;
        } else if(check > 0){
            cout << "RIGHT" << endl;
        } else{
            cout << "LEFT" << endl;
        }
    }

    return 0;
}