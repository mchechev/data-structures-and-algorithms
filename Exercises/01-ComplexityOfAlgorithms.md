# Сложност на алгоритми

## Cheat sheet
![](https://i.stack.imgur.com/5eFMU.png)

## 1

```c++
bool isEven(int number) {
    return number % 2 ? false : true;
}
```

## 2

```c++
int getElement(int arr[], int index) {
    return arr[index];
}
```

## 3

```c++
int maxElement(vector<int> numbers) {
    int max = numbers[0];
    for(auto i = numbers.begin(); i != numbers.end(); i++) {
        if(*i > max){
            max = *i;
        }
    }
    return max;
}
```

## 4

```c++
int findDuplicateNotSmartOne(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(v[i] == v[j] && i != j) {
                return v[i];
            }
        }
    }
    return -1;
}
```

## 5

```c++
vector<int> findXYZ(int numberToSumTo, int maxCycles) {
    vector<int> result;
    for(int x = 0; x < maxCycles; x++) {
        for(int y = 0; y < maxCycles; y++) {
            for(int z = 0; z < maxCycles; z++) {
                if(x + y + z == numberToSumTo) {
                    result.push_back(x);
                    result.push_back(y);
                    result.push_back(z);
                }
            }
        }
    }
    return result;
}
```

## 6

```c++
void logit(int n) {
    for(int i = n; i > 0; i = i/2) {
        cout<<i;
    }
}
```

## 7

```c++
void logItSlow(int n) {
    for(int i = n; i > 0; i--) {
        for(int j = n; j > 0; j = j/2) {
            cout << i << " " << j;
        }
    }
}
```

## 8

```c++
void powerSet(string str, int index = -1, string curr = "") {
    int n = str.length();
    if (index == n)
        return;
    
    cout << curr << "\n";  
    for (int i = index + 1; i < n; i++) {
        curr += str[i];
        powerSet(str, i, curr);
        curr.erase(curr.size() - 1);
    }
    return;
}
```

## 9

```c++
void permute(string a, int l, int r) { 
    if (l == r)
    {
        cout<<a<<endl;
    }
    else
    {
        for (int i = l; i <= r; i++) 
        {   
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        } 
    } 
}
```

## 10

```c++
void foo(int n) {
    for (int i = 1; i < n; i *= 2) {
        for (int k = 0; k < n; k++) {
            cout << i;
            cout << k;
        }
    }
}
```

## 11

```c++
int fact(n) {
    if (n <= 1) {
        return 1;
    }
    return n * fact(n - 1);
}
```

## 12

```c++
int fibonacci(n) {
    if (n <= 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

## 13

```c++
int sum(int n) {
    int s = 0;
    for (int i = 1; i < n; i++) {
        s += i;
    }
    return s;
}

int sumSqr(int n) {
    int s = 0;
    for (int i = 1; i < n; i++) {
        s += sum(i);
    }
    return s;
}
```

## 14

```c++
int bar(int k) {
    while (k > 0) {
        k = k >> 1;
    }
}
```


## Answers

1. O(1)
2. O(1)
3. O(numbers.size())
4. O(v.size() ^ 2)
5. O(maxCycles ^ 3)
6. O(log(n))
7. O(n * log(n))
8. O(2 ^ str.size())
9. O(a.size()!)
10. O(n*log(n))
11. O(n)
12. O(2^n)
13. O(n^2)
14. O(log(k))
