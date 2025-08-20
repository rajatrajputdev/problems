// following solution has 0 ms latency, beats 100%

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums){
    int unique = -1;
    int upperIndexLimit = nums.size() - 1;
    if (upperIndexLimit + 1 == 1)return nums[0];
    
    for (int i = 0; i < upperIndexLimit + 1; i = i + 2){
        if (i == upperIndexLimit + 1){
            unique = nums[i];
            break;
        }
        if (nums[i] != nums[i + 1]){
            unique = nums[i];
            break;
        }
    }
    
    return unique;
}

int main(){
    // program initialisation
    vector<int> arr = {1, 1, 2};

    // program execution
    int element = singleNonDuplicate(arr);

    // program result
    cout << "Unique Element in Sorted Array : " << element << endl;
    return 0;
}