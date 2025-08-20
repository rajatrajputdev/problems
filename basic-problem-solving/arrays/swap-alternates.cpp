#include <iostream>
using namespace std;

int main(){
    // program initialisation
    int size = 10;
    int arr[size] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    int loopEndVariable = 0;
    
    if(size % 2 == 0){
        loopEndVariable = size;
    }
    else{
        loopEndVariable = size - 1;
    }

    cout << "Original Array : "; 
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // program execution
    for(int i = 0; i < loopEndVariable; i = i + 2){
        int temp = arr[i];
        int tempTwo = arr[i + 1];
        arr[i] = tempTwo;
        arr[i+1] = temp;
    }

    // program result
    cout << "Swapped Array : "; 
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}