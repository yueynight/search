#include<iostream>
using namespace std;
//以下为计数排序 
bool coutingSort(int array[], size_t arrLen) {
   //检测数组长度，如果小于2则直接输出 
    if (arrLen < 2) {
        return true;
    }

   //定义最大最小值来设定范围 
    int max = array[0];
    int min = array[0];
  //找出最小值 
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        //找出最大值 
        else if (max < array[i]) {
            max = array[i];
        }
    }
 
   //为整形变量空间countingBuckets分配内存 
    int *countingBuckets = new int[max - min + 1]();

 //记录元素出现次数 
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];
    }

//将数组内元素出现次数相加以得到最终数据的排序位置 
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];
    }
 //为整形变量空间tempArray分配内存 
    int *tempArray = new int[arrLen]();
    //将原数组元素按照在countingBuckets中算出的相应位置存入 
    for (int l = arrLen - 1; l >= 0; --l)
    {
        tempArray[--countingBuckets[array[l] - min]] = array[l];
    }
//将temp数组复制到array中 
    for (size_t m = 0; m < arrLen; ++m)
    {
        array[m] = tempArray[m];
    }
//释放内存 
    delete [] countingBuckets;
    delete [] tempArray;

    
    return true;
}
//输出数组array 
void printArray(int array[], int arrLen) {
	
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
//利用递归思维进行二分查找 
int erfen(int a[],int key,int low,int high) {
    int keypos = -1;
    if (low <= high) {
         int mid = low +((high - low + 1) >> 1);
        if (key == a[mid]) {
            keypos = mid;
        }
        else if (key > a[mid]) {
            keypos = erfen( a, key, mid + 1, high);
        }
        else {
            keypos = erfen( a, key, low, mid - 1);

        }
    }
    return keypos;
}
int erfenuse(int key, int a[], int n) {
   int low = 0;
   int high = n - 1;
   int keypos = erfen(a, key, low, high);
      cout<<"所查找的元素在数组第"<<keypos+1<<"位";
   return keypos;
}
int main(){
	int a[]={3,5,7,9,13,45};
	coutingSort(a,sizeof(a)/sizeof(int));
	printArray(a,sizeof(a)/sizeof(int));
	erfenuse(7,a,sizeof(a)/sizeof(int));
return 0;
} 
