#include <iostream>
using namespace std;

int main() {
    int arr[3][3][3];
    int target;
    
    cout << "Enter xs for 3x3x3 array:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Layer " << i << ":\n";
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "Enter x at [" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "\nEnter x to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (arr[i][j][k] == target) {
                    cout << "Found at Layer: " << i << ", Row: " << j << ", Column: " << k << endl;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "x not found in the array.\n";
    }

    return 0;
}
