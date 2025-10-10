#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30; 
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element " << key << " found at pos " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element " << key << " not found" << endl;

    return 0;
}
