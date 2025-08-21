// following solution has 0 ms latency, beats 100%

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
    bool containsDuplicate(vector<int> &nums){
        if(nums.size() == 1){
            return false;
        }
        
        if(nums.size() == 2){
            if(nums[0] == nums[1]){
                return true;
            }
            return false;
        }
        
        stable_sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }

int main(){
    // program initialisation
    vector<int> arr = {67,1,2,3,46,56,67,4};

    // program execution
    bool element = containsDuplicate(arr);
    // program result
    cout << element <<endl;
    return 0;
}