#include <iostream>

using namespace std;
//�������Ԫ�� 
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
// midΪ�м��������array[mid]������Ҫ���ҵ�Ԫ��ʱ������ѭ������mid��ֵ��KeyPos  
   while (low <= high) {
       int mid = low +((high - low) >> 1);
       if (searchKey == array[mid]) {
           keyPos = mid;
           break;
       }
       //���򣬵�������Ԫ�ش���array��mid��ʱ����˵��������Ԫ����array��mid���ҷ� ������low=mid+1֮�����ѭ�� 
       else if (searchKey > array[mid]) {
           low = mid + 1;
       }
       //��������Ԫ��С��array��mid��ʱ����˵��������Ԫ����array��mid���� ������high=mid-1֮�����ѭ��
       else {
           high = mid - 1;
       }
   }
   //����Ԫ���������е��±� 
   return keyPos;
}

int binarySearchRecurse(int searchKey, int array[], int low, int high) {

    int keyPos = -1;
    if (low <= high) {
         int mid = low +((high - low + 1) >> 1);
         //midΪ�м��������array[mid]������Ҫ���ҵ�Ԫ��ʱ����mid��ֵ��KeyPos   
        if (searchKey == array[mid]) {
            keyPos = mid;
        }
        //��������Ԫ�ش��ڻ����array[mid]ʱ�����õݹ��������������Ԫ�����Ӧ��midֵ����ֵ��KeyPos 
        else if (searchKey > array[mid]) {
            keyPos = binarySearchRecurse(searchKey, array, mid + 1, high);
        }
        else {
            keyPos = binarySearchRecurse(searchKey, array, low, mid - 1);

        }
    }
    return keyPos;
}
//����binarySearchRecurse����������Ԫ���������е��±� 
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
