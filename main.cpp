#include<iostream>
#include<stdio.h>
#include<math.h>
#include"func.h"
#include"time_f.h"
using namespace std;

int main(void){
	int m; 
	//double *arr;
	cout << "введите количество потоков" << endl;
	cin >> k;
	cout << "по формуле(0), из файла(1) " /*<< fix()*/ << endl;
	cin >> m;
	cout << "введите размер матрицы"<</* love() <<*/ endl;
	cin >> n;
	/*test();*/
	arr = new double[2*n*n];
	first = new double[n*n];
	ord = new int[n];
	t = new pthread_t[k];
	if (m == 0){
		for (int i = 0; i < n; i++){
			ord[i] = i;
			/*for (int j = 0; j < n; j++){
				arr[i*2*n+j] = 1 / (1 + (double)i + (double)j);
				first[i*n+j] = 1 / (1 + (double)i + (double)j);
				if (j == i) { arr[i*2*n + j + n] = 1; arr[i*2*n+j] += 1; first[i*n+j]+=1;}
				else { arr[i*2*n + j + n] = 0;}
			}*/
			for (int j = 0; j < n; j++){
				arr[i*2*n+j] = (double)(min(i,j)+1)/(max(i,j)+1);
				first[i*n+j] = arr[i*2*n+j];
				if (j == i) { arr[i*2*n + j + n] = 1; }
				else { arr[i*2*n + j + n] = 0;}
			}
		}
	}
	if (m == 1){ 
		//freopen("a.txt", "r", stdin);
		//cin >> n;
		//double arr[2*n*n];
		for (int i = 0; i < n; i++){
			ord[i] = i;
			for (int j = 0; j < n; j++){
				cin >> arr[i*2*n+j];
				first[i*n+j] = arr[i*2*n+j];
			}
		} 
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (j == i) { arr[i*2*n + j + n] = 1;}
				else arr[i*2*n + j + n] = 0;
			}
		}	
	}
	long int t_full;
  	t_full = get_full_time ();
	//show(n, arr);
	func1(n,arr);
	//for(int i = 0; i < n; i++){
	//	for(int j = n; j <2*n; j++){
	//		cout << arr[2*n*ord[i] + j] << " " ;
	//	}
	//	cout << endl;
	//}
	cout<<"UpTreangle "<<(double)(get_full_time ()-t_full)/100<<"sec"<<endl;
	nevyazka();


return 0;
}
