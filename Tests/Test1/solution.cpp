#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n;
    cin >> n;
    int arr[10000];
    int x;
    for(int i = 0 ; i < 10000;i++){
        arr[i] = 0;
    }
    for(int i = 0 ; i < n; i++){
        
        cin >> x;
        arr[x]++;
    }
    for(int i = 10000-1; i >=0 ;i--){
        for(int j = 0 ; j < arr[i];j++){
            cout << i <<" ";
        }
    }
    return 0;
}