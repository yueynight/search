#include<iostream>
using namespace std;
//����Ϊ�������� 
bool coutingSort(int array[], size_t arrLen) {
   //������鳤�ȣ����С��2��ֱ����� 
    if (arrLen < 2) {
        return true;
    }

   //���������Сֵ���趨��Χ 
    int max = array[0];
    int min = array[0];
  //�ҳ���Сֵ 
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        //�ҳ����ֵ 
        else if (max < array[i]) {
            max = array[i];
        }
    }
 
   //Ϊ���α����ռ�countingBuckets�����ڴ� 
    int *countingBuckets = new int[max - min + 1]();

 //��¼Ԫ�س��ִ��� 
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];
    }

//��������Ԫ�س��ִ�������Եõ��������ݵ�����λ�� 
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];
    }
 //Ϊ���α����ռ�tempArray�����ڴ� 
    int *tempArray = new int[arrLen]();
    //��ԭ����Ԫ�ذ�����countingBuckets���������Ӧλ�ô��� 
    for (int l = arrLen - 1; l >= 0; --l)
    {
        tempArray[--countingBuckets[array[l] - min]] = array[l];
    }
//��temp���鸴�Ƶ�array�� 
    for (size_t m = 0; m < arrLen; ++m)
    {
        array[m] = tempArray[m];
    }
//�ͷ��ڴ� 
    delete [] countingBuckets;
    delete [] tempArray;

    
    return true;
}
//�������array 
void printArray(int array[], int arrLen) {
	
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
//����Ϊ���ֲ��� 
int erfeng(int a[], int n,int key) {
   int low = 0;
   int high = n - 1;
   int keypos = -1;

   while (low <= high) {
       int mid = low +((high - low) >> 1);
       if (key == a[mid]) {
           keypos = mid;
           break;
       }
       else if (key > a[mid]) {
           low = mid + 1;
       }
       else {
           high = mid - 1;
       }
   }
   cout<<"������Ԫ���������е�λ��Ϊ��"<<keypos+1;
   return key;
}
int main(){
	int a[]={4,6,3,8,9,57,0,34,56,23};
	coutingSort(a,sizeof(a)/sizeof(int));
	printArray(a,sizeof(a)/sizeof(int));
	erfeng(a,sizeof(a)/sizeof(int),23);
	return 0;
}
