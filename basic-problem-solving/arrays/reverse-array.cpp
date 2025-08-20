#include <iostream>
using namespace std;

int main(){
    // program initialisation
    int size = 10;
    int arr[size] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    int upperIndex = size - 1;
    int lowerIndex = 0;

    cout << "Original Array : "; 
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // program execution
    while(lowerIndex < upperIndex){
        int temp = arr[lowerIndex];
        int tempTwo = arr[upperIndex];
        arr[upperIndex] = temp;
        arr[lowerIndex] = tempTwo;
        lowerIndex++;
        upperIndex--;
    }

    // program result
    cout << "Reversed Array : "; 
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}