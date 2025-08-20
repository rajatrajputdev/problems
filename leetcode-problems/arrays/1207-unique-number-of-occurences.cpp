// following solution has 0 ms latency, beats 100%

#include <iostream>
#include <vector>
using namespace std;

bool visited(vector<int> &nums, int target){
    for(int i : nums){
        if(i == target){
            return true;
        }
    }
    return false;
}
bool uniqueOccurrences(vector<int> &nums){
    vector<int> tempVector;
    vector<int> counts;
    int size = nums.size();
    int count = 0;
    for(int i = 0; i < size; i++){
        bool isElementVisited = visited(tempVector, nums[i]);
        if(isElementVisited == false){
            int currentCount = 0;
            tempVector.push_back(nums[i]);
            for(int j = 0; j < size; j++){
                if(nums[j] == nums[i]){
                    currentCount = currentCount + 1;
                }
            }
            if(visited(counts, currentCount)){
                return false;
            }
            counts.push_back(currentCount);
        }
        
    }
    return true;
}

int main(){
    // program initialisation
    vector<int> arr = {1, 1, 2};

    // program execution
    bool element = uniqueOccurrences(arr);

    // program result
    cout << element << endl;
    return 0;
}