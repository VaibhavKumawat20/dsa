// // C++ code to find duplicates in an array
// // using hashmap

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> findDuplicates(vector<int> &arr) {

//     // Step 1: Create an empty unordered map to store
//     // element frequencies
//     int n = arr.size();
//     unordered_map<int, int> freqMap;
//     vector<int> result;

//     // Step 2: Iterate through the array and count
//     // element frequencies
//     for (int i = 0; i < n; i++) {
//         freqMap[arr[i]]++;
//     }

//     // Step 3: Iterate through the hashmap to find duplicates
//     for (auto &entry : freqMap) {
//         if (entry.second > 1) {
//             result.push_back(entry.first);
//         }
//     }

//     // Step 4: If no duplicates found, add -1 to the result
//     if (result.empty()) {
//         result.push_back(-1);
//     }

//     // Step 6: Return the result vector containing
//     // duplicate elements or -1
//     return result;
// }

// int main() {
//     vector<int> arr = {1, 6, 5, 2, 3, 3, 2};

//     vector<int> duplicates = findDuplicates(arr);

//     for (int element : duplicates) {
//         cout << element << " ";
//     }

//     return 0;
// }

//          OR

// C++ code to find duplicates in an array
// using auxilary array

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &arr) {

    int n = arr.size();
    vector<int> freqArr(n);
    vector<int> result;

    // Step 2: Iterate through the array and count
    // element frequencies
    for (int i = 0; i < n; i++) {
        freqArr[arr[i]]++;
    }

    // Step 3: Iterate through all the possible elements to check
    // duplicates
    for (int i = 0; i < n; i++) {
        if (freqArr[i] > 1) {
            result.push_back(i);
        }
    }

    // Step 4: If no duplicates found, add -1 to the result
    if (result.empty()) {
        result.push_back(-1);
    }

    // Step 6: Return the result vector containing
    // duplicate elements or -1
    return result;
}

int main() {
    vector<int> arr = {1, 6, 5, 2, 3, 3, 2};

    vector<int> duplicates = findDuplicates(arr);

    for (int element : duplicates) {
        cout << element << " ";
    }

    return 0;
}