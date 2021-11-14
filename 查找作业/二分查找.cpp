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
//以下为二分查找 
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
   cout<<"所查找元素在数组中的位置为："<<keypos+1;
   return key;
}
int main(){
	int a[]={4,6,3,8,9,57,0,34,56,23};
	coutingSort(a,sizeof(a)/sizeof(int));
	printArray(a,sizeof(a)/sizeof(int));
	erfeng(a,sizeof(a)/sizeof(int),23);
	return 0;
}
