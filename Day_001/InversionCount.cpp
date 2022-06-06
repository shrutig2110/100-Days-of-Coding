#include<iostream>

using namespace std;

int merge(int *arr, int s, int e) {
    
    int mid = (s+e)/2;
    //size of new arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;
    
    //to store divided array
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }
    
    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    int swap=0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
            //counting inversions
            swap+=len1-index1;
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }
    
    delete []first;
    delete []second;
    return swap;

}

int mergeSort(int *arr, int s, int e) {
    //base case
    if(s >= e) {
        return 0;
    }
    int ans=0;
    int mid = (s+e)/2;

    //left part sort karna h 
    ans +=mergeSort(arr, s, mid);
    
    //right part sort karna h 
   ans += mergeSort(arr, mid+1, e);

    //merge
    ans += merge(arr, s, e);
    return ans;

}

int main() {

    int arr[4] = {3,7,0,1};
    int n = 4;
    int ans = mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;
    cout<<"Inversions: "<<ans<<endl;
    return 0;
}
