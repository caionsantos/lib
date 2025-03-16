#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<long long int> tabuas(n);
    stack<long long int> monotesq;
    stack<long long int> monotdir;
    vector<long long int> mindir(n);
    vector<long long int> minesq(n);

    for(int i = 0; i < n; i++){
        while((monotesq.size() > 0) and (tabuas[i] < tabuas[monotesq.top()])){
            monotesq.pop();
        }

        if(monotesq.size() > 0){
            minesq[i] = monotesq.top();
        } else{
            minesq[i] = -1;
        }
        monotesq.push(i);
    }
    //GUARDA MENOR MAIS PRÓXIMO À ESQUERDA

    for(int i = 1; i <= n; i++){
        while((monotdir.size() > 0) and (tabuas[n - i] <= tabuas[monotdir.top()])){
            monotdir.pop();
        }

        if(monotdir.size() > 0){
            mindir[n - i] = monotdir.top();
        } else{
            mindir[n - i] = n;
        }
        monotdir.push((n - i));
    }
    //VERSÃO INVERTIDA

    long long int ar;
    long long int maxarea = 0;
    for(int i = 0; i < n; i++){
        ar = (mindir[i] - minesq[i] - 1) * tabuas[i];
        maxarea = max(ar, maxarea);
    }
    cout << maxarea << endl;


    return 0;
}