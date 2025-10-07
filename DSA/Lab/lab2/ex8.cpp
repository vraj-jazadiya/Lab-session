#include <iostream>
using namespace std;

int main() {
    int arr[2][2][2];
    int sum = 0;

    cout << "Enter xs for 2x2x2 array:\n";
    for (int i = 0; i < 2; i++) {
        cout << "Layer " << i << ":\n";
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cout << "Enter x at [" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
                sum += arr[i][j][k];
            }
        }
    }

    cout << "Sum of all X's = " << sum << endl;

    return 0;
}
