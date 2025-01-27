#include <iostream>

using namespace std;

bool isPresent(int arr[][4], int traget, int i , int j){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(arr[i][j] == traget){
                return 1;
            }
        }
    }
    return 0;
}

void printSum(int arr[][4],  int i , int j ){
    for(int i = 0; i < 3; i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            sum += arr[i][j];        
        }
        cout<<sum<<endl;
    }
}

int main() {
    
    
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}; // take row wise
    


    // //row wise input
    // for (int i = 0; i < 3; i++){
    //     for (int j = 0; j < 4; j++){
    //         cin>>arr[i][j];
    //     }
    // }

   
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int target;
    cout<< "Enter the target: "<<endl;
    cin>> target;
    cout <<"Element present: "<<isPresent(arr, target, 3,4)<<endl;

    printSum(arr, 3,4);
    return 0;
}
