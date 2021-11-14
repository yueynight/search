#include<iostream>
using namespace std;
int order(int a[],int n,int key){
	int i=0;
	for(i;i<=n-1;i++){
		if(key==a[i]){
			break;
		}
		}
		//循环结束后，若i大小在0~n-1范围内说明元素在数组内，如果i=n,则元素不在数组内 
		if(i<=n-1)
		{
			cout<<"所查找元素位置为"<<i+1; 
			return i+1;
			
			}		
			else
			{cout<<"查找的数字不在数组中";
			return -1;}
			}
			int main(){
				int a[]={2,3,4,10,8,34,20};
				order(a,sizeof(a)/sizeof(int),5);
				return 0;
			}
		
