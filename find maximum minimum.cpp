#include <iostream>
#include <vector>

using namespace std;

int finder(vector<int> arr, int n, int value){
    if(value == 0){
        int min = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }
       return min;
    } else if(value == 1){
        int max = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
         return max;
    } else {
        cout<<"Invalid input"<<endl;
    }
    return -1;
}

int main() {
    
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    // simple check to compare two numbers
    if(a > b){
        cout << a << " is greater than " << b << endl;
    } else if(a < b){
        cout << b << " is greater than " << a << endl;
    } else {
        cout<<"Both numbers are equal."<<endl;
    }

    vector<int> arr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cout << "Enter element " << (i+1) << ": ";
        cin >> num;
        arr.push_back(num);
    }
    
    int value;
    cout << "Enter 0 to find minimum or 1 to find maximum: ";
    cin >> value;

    int find = finder(arr, n, value);

    if(find != -1){
        if(value == 0){
            cout<<"Minimum value is: "<<find<<endl;
        } else if(value == 1){
            cout<<"Maximum value is: "<<find<<endl;
        }
    }
    return 0;
}