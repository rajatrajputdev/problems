#include <iostream>
using namespace std;

int main(){
    // program initialisation
    int target;
    int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    cout << "Enter the element you want to find : ";
    cin >> target;

    // program execution
    int size = sizeof(arr) / sizeof(arr[0]);
    int indexOfTarget = -1;
    bool found = false;
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            indexOfTarget = i;
            found = true;
        }
    }

    // program completion verification
    if(found){
        cout << "Target found at index " << indexOfTarget << "." << endl;
        return target;
    }
    cout << "Target not found in array." << endl;
    return 0;
}