#include <iostream>
using namespace std;

class binTreeArr {
    int tree[100];
    int size;

public:
    binTreeArr() {
        size = 0;
        for (int i = 0; i < 100; i++) {
            tree[i] = -1;
        }
    }

    void insert(int value) {
        if (size < 100) {
            tree[size] = value;
            size++;
        } else {
            cout << "tree is full\n";
        }
    }

    void displayArray() {
        for (int i = 0; i < size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    bool isComplete() {
        for (int i = 0; i < size; i++) {
            if (tree[i] == -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    binTreeArr bt;
    int n, value;

    cout << "size: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "pos: " << i << ": ";
        cin >> value;
        bt.insert(value);
    }

    bt.displayArray();

    if (bt.isComplete()) {
        cout << "Complete" << endl;
    } else {
        cout << "NOT a Complete" << endl;
    }

    return 0;
}
