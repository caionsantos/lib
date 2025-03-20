#include <bits/stdc++.h>
#include "ponto.cpp"
#define endl '\n'
using namespace std;

int orientation(Point a, Point b, Point c){
    Point ab = b - a;
    Point bc = c - b;
    double v = ab.cross(bc);

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}