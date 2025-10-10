#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int arr[n] = {5, 12, 9, 21, 3, 18};

    int smallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    cout << "Smallest x: " << smallest << endl;

    return 0;
}
