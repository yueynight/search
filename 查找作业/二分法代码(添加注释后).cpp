#include <iostream>

using namespace std;
//输出数组元素 
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int searchSortedArray(int searchKey, int array[], int arrLen) {
   int low = 0;
   int high = arrLen - 1;
   int keyPos = -1;
// mid为中间数，如果array[mid]等于所要查找的元素时，跳出循环并将mid赋值给KeyPos  
   while (low <= high) {
       int mid = low +((high - low) >> 1);
       if (searchKey == array[mid]) {
           keyPos = mid;
           break;
       }
       //否则，当所查找元素大于array【mid】时，将说明所查找元素在array【mid】右方 ，故令low=mid+1之后继续循环 
       else if (searchKey > array[mid]) {
           low = mid + 1;
       }
       //当所查找元素小于array【mid】时，将说明所查找元素在array【mid】左方 ，故令high=mid-1之后继续循环
       else {
           high = mid - 1;
       }
   }
   //返回元素在数组中的下标 
   return keyPos;
}

int binarySearchRecurse(int searchKey, int array[], int low, int high) {

    int keyPos = -1;
    if (low <= high) {
         int mid = low +((high - low + 1) >> 1);
         //mid为中间数，如果array[mid]等于所要查找的元素时，将mid赋值给KeyPos   
        if (searchKey == array[mid]) {
            keyPos = mid;
        }
        //当所查找元素大于或等于array[mid]时，利用递归来求得与所查找元素相对应的mid值并赋值给KeyPos 
        else if (searchKey > array[mid]) {
            keyPos = binarySearchRecurse(searchKey, array, mid + 1, high);
        }
        else {
            keyPos = binarySearchRecurse(searchKey, array, low, mid - 1);

        }
    }
    return keyPos;
}
//调用binarySearchRecurse函数来返回元素在数组中的下标 
int searchSortedArrayRecurse(int searchKey, int *array, int arrLen) {
   int low = 0;
   int high = arrLen - 1;
   int keyPos = binarySearchRecurse(searchKey, array, low, high);

   return keyPos;
}





int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);
    cout << "Array Pos of 2: "<< searchSortedArray(2, array0, arrayLen) << endl;
    cout << "Array Pos of 2: "<< searchSortedArrayRecurse(2, array0, arrayLen) << endl;

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);
   
    printArray(array1, arrayLen);
    cout << "Array Pos of 1: "<< searchSortedArray(1, array1, arrayLen) << endl;
    cout << "Array Pos of 1: "<< searchSortedArrayRecurse(1, array1, arrayLen) << endl;

    cout << "=========================================" << endl;

    int array2[] = {1, 2};
    arrayLen = sizeof(array2)/sizeof(int);
    printArray(array2, arrayLen);
    cout << "Array Pos of 2: "<< searchSortedArray(2, array2, arrayLen) << endl;
    cout << "Array Pos of 2: "<< searchSortedArrayRecurse(2, array2, arrayLen) << endl;

    cout << "=========================================" << endl;

    int array3[] = {1, 3, 5};
    arrayLen = sizeof(array3)/sizeof(int);
    printArray(array3, arrayLen);
    cout << "Array Pos of 5: "<< searchSortedArray(5, array3, arrayLen) << endl;
    cout << "Array Pos of 5: "<< searchSortedArrayRecurse(5, array3, arrayLen) << endl;

    cout << "=========================================" << endl;


    int array4[] = {7,8,9,12};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    cout << "Array Pos of 8: "<< searchSortedArray(8, array4, arrayLen) << endl;
    cout << "Array Pos of 8: "<< searchSortedArrayRecurse(8, array4, arrayLen) << endl;

    cout << "=========================================" << endl;

    int array5[] = {7,8,9,12};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array5, arrayLen);
    cout << "Array Pos of 6: "<< searchSortedArray(6, array5, arrayLen) << endl;
    cout << "Array Pos of 6: "<< searchSortedArrayRecurse(6, array5, arrayLen) << endl;

    cout << "=========================================" << endl;
}
