#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
public:
    // constructor
    Array() {
        size = 10;
        A = new int[size];
        length = 0;
    }
    // parameterized constructor
    Array(int sz) {
        size = sz;
        A = new int[size];
        length = 0;
    }
    // destructor
    ~Array() {
        delete[] A;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int BinarySearch(int key);
    int get(int index);
    void set(int index, int x);
    int max();
    int min();
    int sum();
    float avg();
    void reverse();
    void shift();
    void rotate();
    bool isSorted();
    void insertInSorted(int x);
};

// here Array:: is the scope resolution operator which is used to define a member function outside the class.
void Array::Display() {
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::Append(int x) {
    if (length < size) {
        // here length will first be used and then incremented
        A[length++] = x;
    }
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--) {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index) {
    int x = 0;
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    return 0;
}

int Array::BinarySearch(int key) {
    int l = 0, h = length - 1, mid;
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid]) {
            return mid;
        } else if (key < A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int Array::get(int index) {
    if (index >= 0 && index < length) {
        return A[index];
    }
    return -1;
}

void Array::set(int index, int x) {
    if (index >= 0 && index < length) {
        A[index] = x;
    }
}

int Array::max() {
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

int Array::min() {
    int min = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

int Array::sum() {
    int s = 0;
    for (int i = 0; i < length; i++) {
        s += A[i];
    }
    return s;
}

float Array::avg() {
    return (float)sum() / length;
}

void Array::reverse() {
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        swap(&A[i], &A[j]);
    }
}

void Array::shift() {
    for (int i = 0; i < length - 1; i++) {
        A[i] = A[i + 1];
    }
    A[length - 1] = 0;
}

void Array::rotate() {
    int x = A[0];
    for (int i = 0; i < length - 1; i++) {
        A[i] = A[i + 1];
    }
    A[length - 1] = x;
}

bool Array::isSorted() {
    for (int i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

void Array::insertInSorted(int x) {
    int i = length - 1;
    if (length == size) {
        return;
    }
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

int menu() {
    int choice;
    cout << "1. Append" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Binary Search" << endl;
    cout << "5. Get" << endl;
    cout << "6. Set" << endl;
    cout << "7. Max" << endl;
    cout << "8. Min" << endl;
    cout << "9. Sum" << endl;
    cout << "10. Avg" << endl;
    cout << "11. Reverse" << endl;
    cout << "12. Shift" << endl;
    cout << "13. Rotate" << endl;
    cout << "14. Is Sorted" << endl;
    cout << "15. Insert In Sorted" << endl;
    cout << "16. Display" << endl;
    cout << "17. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    return choice;
}

int main() {
    // custom size from user input
    int sz;
    cout << "Enter the size of the array: ";
    cin >> sz;
    Array arr(sz);
    // show menu
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1: {
                int x;
                cout << "Enter the element to append: ";
                cin >> x;
                arr.Append(x);
                break;
            }
            case 2: {
                int index, x;
                cout << "Enter the index and element to insert: ";
                cin >> index >> x;
                arr.Insert(index, x);
                break;
            }
            case 3: {
                int index;
                cout << "Enter the index to delete: ";
                cin >> index;
                cout << "Deleted element: " << arr.Delete(index) << endl;
                break;
            }
            case 4: {
                int key;
                cout << "Enter the key to search: ";
                cin >> key;
                cout << "Element found at index: " << arr.BinarySearch(key) << endl;
                break;
            }
            case 5: {
                int index;
                cout << "Enter the index to get: ";
                cin >> index;
                cout << "Element at index: " << arr.get(index) << endl;
                break;
            }
            case 6: {
                int index, x;
                cout << "Enter the index and element to set: ";
                cin >> index >> x;
                arr.set(index, x);
                break;
            }
            case 7: {
                cout << "Max element: " << arr.max() << endl;
                break;
            }
            case 8: {
                cout << "Min element: " << arr.min() << endl;
                break;
            }
            case 9: {
                cout << "Sum of elements: " << arr.sum() << endl;
                break;
            }
            case 10: {
                cout << "Average of elements: " << arr.avg() << endl;
                break;
            }
            case 11: {
                arr.reverse();
                break;
            }
            case 12: {
                arr.shift();
                break;
            }
            case 13: {
                arr.rotate();
                break;
            }
            case 14: {
                cout << "Is sorted: " << arr.isSorted() << endl;
                break;
            }
            case 15: {
                int x;
                cout << "Enter the element to insert in sorted: ";
                cin >> x;
                arr.insertInSorted(x);
                break;
            }
            case 16: {
                arr.Display();
                break;
            }
            case 17: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    } while (choice != 17);
    
    return 0;
}