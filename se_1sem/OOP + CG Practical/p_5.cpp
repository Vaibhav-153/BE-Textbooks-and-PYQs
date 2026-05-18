#include <iostream>
using namespace std;

template <class T>
void sel(T A[], int n) {
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted array:";
    for (i = 0; i < n; i++) {
        cout << " " << A[i];
    }
}

int main() {
    int n;
    cout << "\nEnter total no of int elements:";
    cin >> n;

    int A[n];
    cout << "\nEnter int elements:";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sel(A, n);

    float B[n];
    cout << "\nEnter total no of float elements:";
    cin >> n;

    cout << "\nEnter float elements:";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    sel(B, n);

    return 0;
}
