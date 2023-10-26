/*Notes on Memory*/
// & is reference operator or address operator
// * is dereference operator or pointer
// they are inverses of each other
//a byte is the smallest unit of memory stored in RAM anything smaller that is stored will take up a whole byte
//each bite has a memory address
/*ex
    int x = 100;
    cout << &x;
    */
//gives you location of memory address
//top storage of ram is OS specific info
/*              HOW MUCH STORAGE DOES INT DATA TYPE TAKE UP?
    int data takes up 4
    double is 8
*/
//the address is not always fixed, can change after every compilation
/*  ex.
1. Alias variable
        a variable that follows another variable (int y = x)
        int x =100;
        int &ref = x;
        now if x is changed to a different number, ref will become that number
        they now share the same address (shown as a hexidecimal 0x)
2. Passing by reference to the functions
        SWAP FUNCTION
        swap(int a, int b) 
        int main() {
            int x, y;
            swap (x,y)
        }
            now x becomes a and y becomes b, a and b get destroyed after (if they are same data type)
        
        PASSING BY REFERENCE
        swap(int&a, int&b) 
        int main() {
            int x, y;
            swap (x,y)
        }
        makes a copy of original data with new information
        large amounts of data are recomended to pass by reference
        if you want to preserve the original data, pass by reference is not recomended 
*/
#include <iostream>
using namespace std;

// int main() {
//     int x = 'A';
//     int y = 'B';
//     cout << &x << " : " << x << endl;
//     cout << &y << " : " << y << endl;
//     return 0;
// }

// int main() {
//     int x = 97;
//     int &R = x; //name doesnt matter
//     R = 100;
//     cout << R << endl;
//     x = 991;
//     cout << R << endl; //reference varible will change 
//     cout << &R << endl;
//     cout << &x << endl; //same memory address
//     return 0;
// }

// template <typename T>
// void Swap (T &x, T &y) {
//     T z =x;
//     x = y;
//     y = z;
// };

// int main() {
//     float pi = 3.14;
//     float e = 2.71
//     Swap (pi,e);
//     cout << "pi: " << pi << endl;

//     string a1 = "Hello!";
//     string a2 = "Welcome"!;

//     return 0;
// }
//POINTER NOTES
/* int x = 12
cout << &x;
int *p
*p=12; <------pointers cannot be assigned
also called "derefference"

int x= 10; int y = 12; int z= 15;
p = x <-------pointer cannot be assigned. do this instead:
p = &x;
p = &y;
now p will act as x and y
*/

int main() {
    int *q;
    int x = 10;
    int y = 12;

//    q = x; // cannot be asssigned!! Instead do this:
    q = &x;
    cout << q << endl;

    q = &y;
    cout << q << endl;

    //to see memory instead of data:
    q = &x;
    cout << *q << endl;

    q = &y;
    cout << *q << endl;
    return 0;
}
