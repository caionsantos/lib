#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void subsetsum(int n, vector<int> &all, vector<long long int> &atual){
    if(n == all.size()){
        //verificação
        return;
    }

    subsetsum(n + 1, all, atual);
    atual.push_back(all[n]);
    subsetsum(n + 1, all, atual);
    atual.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //subset sum com bitmask
    int n, arr[100];
    long long int sum;
    vector<long long int> vec;
    for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) { 
                sum += arr[j]; 
            }
		}
		vec.push_back(sum);
        sum = 0;

	}
    

    return 0;
}