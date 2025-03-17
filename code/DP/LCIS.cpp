#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, pos;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> aux;
    aux.push_back(v[0]);
    for(int i = 1; i < n; i++){
        pos = upper_bound(aux.begin(), aux.end(), v[i]) - aux.begin();
        if(pos >= aux.size()){
            if(v[i] != aux[pos - 1]){
                aux.push_back(v[i]);
            }
        } else{
            if(v[i] != aux[pos - 1]){
                aux[pos] = v[i];
            }
        }
    }
    cout << aux.size() << endl;

    return 0;
}