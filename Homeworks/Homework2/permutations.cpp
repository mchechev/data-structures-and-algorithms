#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 'z' + 1;

bool check(char * a, char * b, int length) {
    int alphabet[ALPHABET_SIZE] { 0 };
    for (int i = 0; i < length; i++) {
        alphabet[a[i]]++;
    }
    for (int i = 0; i < length; i++) {
        alphabet[b[i]]--;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (alphabet[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int length = 0;
    cin >> length;
    char * a = new char[length + 1];
    char * b = new char[length + 1];

    cin >> a;
    cin >> b;

    if (check(a , b, length)) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    delete[] a;
    delete[] b;
}