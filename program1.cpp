#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void modifyArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> copyArr;
    copy(arr.begin(), arr.end(), back_inserter(copyArr));
    int i = 0, j = n - 1, index = 0;
    while(index < n) {
        arr[index++] = copyArr[j--];
        arr[index++] = copyArr[i++];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    modifyArray(arr);
    printArray(arr);
    return 0;
}