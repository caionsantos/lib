#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int len, elemento;
    long long maxsum, prevsum;
    int arr[len];
    prevsum = arr[0];
    maxsum = arr[0];
    //maior soma em subarray
    for (int j = 1; j < len; j++){
        if((prevsum + arr[j]) < arr[j]){
            prevsum = arr[j];
        } else{
            prevsum += arr[j];
        }

        if (prevsum > maxsum){
            maxsum = prevsum;
        }
    }
    cout << maxsum << endl;

    return 0;
}