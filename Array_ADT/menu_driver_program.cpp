#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int Menu()
{
    int choice;
    cout << "Enter your choice: " << endl;
    cout << "1. Display" << endl;
    cout << "2. Append" << endl;
    cout << "3. Insert" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Search" << endl;
    cout << "6. Sum" << endl;
    cout << "7. Exit" << endl;
    cin >> choice;
    return choice;
}

//display
void Display(struct Array arr)
{
    cout << "Elements are: " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

//append
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

//insert
void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        //shift elements to right
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

//delete
int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        //shift elements to left
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

//swap
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            //swap with previous element
            Swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}
/*
here why we are passing the address of the elements inted of passing whole array:
1. Passing the address of the elements is more efficient than passing the whole array
2. Passing the address of the elements is more flexible than passing the whole array
*/

//sum
int Sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}



int main()
{
    int choice, x, index;
    //initialize array with user input
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    struct Array arr;
    arr.size = n;
    arr.length = 0;

    do
    {
        choice = Menu();
        switch (choice)
        {
        case 1:
            cout << "Display" << endl;
            Display(arr);
            break;
        case 2:
            cout << "Enter an element to append: ";
            cin >> x;
            Append(&arr, x);
            break;
        case 3:
            cout << "Enter an element to insert: ";
            cin >> x;
            cout << "Enter an index: ";
            cin >> index;
            Insert(&arr, index, x);
            break;
        case 4:
            cout << "Enter an index to delete: ";
            cin >> index;
            x = Delete(&arr, index);
            cout << "Deleted element is: " << x << endl;
            break;
        case 5:
            cout << "Enter an element to search: ";
            cin >> x;
            index = LinearSearch(&arr, x);
            cout << "Element found at index: " << index << endl;
            break;
        case 6:
            cout << "Sum" << endl;
            cout << "Sum is: " << Sum(arr) << endl;
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
    return 0;
}


/*
where using & and * in C++:
1. & is used to get the address of a variable
2. * is used to get the value at the address
3. * is also used to declare a pointer variable
4. * is used to pass the address of a variable to a function
5. * is used to access the value at the address in a function
6. -> is used to access the members of a structure through a pointer

example:
int x = 10;
int *p; // p is a pointer variable(3rd point)
p = &x; // p is pointing to the address of x(1st point) // out of p is address of variable x
cout << *p; // *p is the value at the address of x(2nd point) // out of *p is value of variable x
*/