#include<iostream>
using namespace std;
int order(int a[],int n,int key){
	int i=0;
	for(i;i<=n-1;i++){
		if(key==a[i]){
			break;
		}
		}
		//ѭ����������i��С��0~n-1��Χ��˵��Ԫ���������ڣ����i=n,��Ԫ�ز��������� 
		if(i<=n-1)
		{
			cout<<"������Ԫ��λ��Ϊ"<<i+1; 
			return i+1;
			
			}		
			else
			{cout<<"���ҵ����ֲ���������";
			return -1;}
			}
			int main(){
				int a[]={2,3,4,10,8,34,20};
				order(a,sizeof(a)/sizeof(int),5);
				return 0;
			}
		
