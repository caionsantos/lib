#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long int digsum(long long int num){
    string s = to_string(num);
    long long int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += s[i] - '0';
    }
    return sum;
}

int digsum2(int n) {
    while(n>=10) {
            int temp = 0;
            while (n > 0) {
                temp += n % 10;
                n /= 10;
            }
            n = temp;
        }
    return n;
}