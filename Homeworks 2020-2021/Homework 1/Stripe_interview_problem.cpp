#include <bits/stdc++.h>
using namespace std;

int arr[1000000];

int getAnswer(int arrLen, int* arr)
{
    for(int i=0; i<arrLen; ++i)
    {
        if(arr[i] > 0 && arr[i] <= arrLen && arr[i] != i+1)
        {
            swap(arr[i], arr[arr[i]-1]);
            /// here the decrementation if i is needed because the value we swap arr[i] with may also need to change position. An example of this is the array [3, 4, -1, 1]
            --i;
        }
    }
    int ans = arrLen+1;
    for(int i=0; i<arrLen; ++i)
    {
        if(arr[i] != i+1)
        {
            ans = i+1;
            break;
        }
    }
    return ans;
}

int main()
{
    for(int f=0;f<10;++f)
    {
        char f1[20] = "input0x.txt";
        char f2[20] = "output1x.txt";
        f1[6] = '0' + f;
        f2[7] = '0' + f;
        freopen(f1, "r", stdin);
        freopen(f2, "w", stdout);

        int n;
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &arr[i]);

        }
        cout<<getAnswer(n, arr)<<endl;

    }
}

