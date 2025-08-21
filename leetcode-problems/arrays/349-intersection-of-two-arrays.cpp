// following solution has 0 ms latency, beats 100%

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums3;
    for(int i : nums1){
    for(int j = 0; j < nums2.size(); j++){
            if(i == nums2[j]){
                if(count(nums3.begin(), nums3.end(), i) < 1){
                    nums3.push_back(i);
                }
            }
        }
    }
    return nums3;
}

int main(){
    // program initialisation
    vector<int> arr1 = {1, 1, 2,3,4,5};
    vector<int> arr2 = {1, 1, 2};

    // program execution
    vector<int> result = intersection(arr1, arr2);

    // program result
    cout << "Intersection Elements in Array : ";
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}