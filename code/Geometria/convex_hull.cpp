#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Point{
    //alterar tipos se preciso
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

int orientation(Point a, Point b, Point c){
    Point ab = b - a;
    Point bc = c - b;
    long long int v = ab.cross(bc);

    if(v < 0){
        return -1; //horario
    }
    if(v > 0){
        return 1; //antihorario
    }
    return 0;
}

bool cw(Point a, Point b, Point c, bool include_collinear){
    int o = orientation(a, b, c);
    return ((o < 0) || (include_collinear && (o == 0)));
}

bool ccw(Point a, Point b, Point c, bool include_collinear){
    int o = orientation(a, b, c);
    return ((o > 0) || (include_collinear && (o == 0)));
}

void convex_hull(vector<Point> &a, bool include_collinear=false){
    if(a.size() == 1){
        return;
    }
    sort(a.begin(), a.end());
    Point p1 = a[0];
    Point p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for(int i = 1; i < (int)a.size(); i++){
        if((i == a.size() - 1) || (cw(p1, a[i], p2, include_collinear))){
            while((up.size() >= 2) && !(cw(up[up.size() - 2], up[up.size() - 1], a[i], include_collinear))){
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if((i == a.size() - 1) || (ccw(p1, a[i], p2, include_collinear))){
            while((down.size() >= 2) && !(ccw(down[down.size() - 2], down[down.size() - 1], a[i], include_collinear))){
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }
    if(include_collinear && (up.size() == a.size())){
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for(int i = 0; i < (int)up.size(); i++){
        a.push_back(up[i]);
    }
    for(int i = down.size() - 2; i > 0; i--){
        a.push_back(down[i]);
    }
}

bool insidetriangle(Point a, Point b, Point c, Point point) {
    long long int s1 = abs((b-a).cross(c-b));
    long long int area1 = abs((point - a).cross(point - b));
    long long int area2 = abs((point - b).cross(point - c));
    long long int area3 = abs((point - c).cross(point - a));
    long long int s2 = area1 + area2 + area3;
    return s1 == s2;
}

bool isinside(vector<Point> &hull, Point p){
    int n = hull.size();
    if(n == 1){
        return (hull.front() == p);
    }
    int l = 1;
    int r = n - 1;
    int mid;
    while(abs(r - l) > 1){
        mid = (r+l)/2;
        Point tomid = hull[mid] - hull[0];
        Point topoint = p - hull[0];
        if(topoint.cross(tomid) < 0){
            //a esquerda
            r = mid;
        } else{
            l = mid;
        }
    }
    //Point vec = hull[r] - hull[l];
    //Point tovec = p - hull[l];
    //return (tovec.cross(vec) > 0);
    return insidetriangle(hull[0], hull[l], hull[r], p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
