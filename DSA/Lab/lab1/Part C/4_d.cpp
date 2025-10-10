#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int arr[n] = {5, 12, 9, 21, 3, 18};
    
    int largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }

    cout << "Largest x: " << largest << endl;

    return 0;
}
