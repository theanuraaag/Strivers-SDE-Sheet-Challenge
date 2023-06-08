#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {

    if (n == 1) return arr[0];
    int count = 1;

    sort(arr, arr + n);

    for (int i = 1; i <= n; i++){
        if (arr[i - 1] == arr[i]){
            count++;
        }

    else{
            if (count > n / 2){
                return arr[i - 1];
            }
            count = 1;
        }
    }

    return -1;

}