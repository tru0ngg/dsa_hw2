#include <iostream>
using namespace std;

void TripSort(int size, int arr[]){
        for (int i = 0; i < size - 1; i++){
                for (int j = 0; j < size - 2; j++){
                        if (arr[j] > arr[j+2]){
                                int temp = arr[j];
                                arr[j] = arr[j + 2];
                                arr[j + 2] = temp;
                        }
                }
        }
}


int main(){
        int size;
        cin >> size;
        int* arr = new int[size];
        for (int i = 0; i < size; i++){
                cin >> arr[i];
        }
        TripSort(size, arr);
        int prev_val = arr[0];
        for (int i = 1; i < size; i++){
                int current_val = arr[i];
                if (prev_val > current_val){
                        cout << "TripSort will not work" << endl;
                        return 0;
                }
                prev_val = current_val;
        }

        cout << "TripSort will work" << endl;
        delete [] arr;

        return 0;
}
