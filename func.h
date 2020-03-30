#include<math.h>
#include<iostream>
#include<string>
#include<pthread.h>
//#include"str.h"
using namespace std;

struct someArgs_t {
    int col; //stolbez
    int num; //nomer niti
    //int max;
};

int n, k;
double *arr, *first;
int *ord;
pthread_t *t;
someArgs_t *args;


void show(int n, double *arr);
int maxx(int n, double *arr, int i);
void func1(int n, double *arr);
void *run (void*args);
void nevyazka();


void func1(int n, double *arr){
	//pthread_t *t = new pthread_t[k];
	args = new someArgs_t[k];
	//int *m = new int[k];
	for (int i = 0; i < n; i++){
		int max;
		max = maxx(n, arr, i);
		int tmp = ord[i];
		ord[i] = ord[max];
		ord[max] = tmp;
		//j = i;
		double m = arr[2*n*ord[i] + i];

		for (int j = i; j < 2*n; j++){
			arr[2*n*ord[i] + j] = arr[2*n*ord[i] + j]/m;
		}
		for (int s = 0; s < k; s++) {  
			args[s].col = i;
			args[s].num = s;
			//args[s].max = max;
		}		

		for (int s = 0; s < k; s++) {  
			pthread_create(&t[s], 0, &run,(void *) &args[s]);
		}
		for (int s = 0; s < k; s++){
    			pthread_join(t[s], 0);
  		}
	}
return;
}


void show(int n, double *arr){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2*n; j++){
			cout << arr[i*2*n+j] << " " ;
		}
		cout << endl;
	}
return;
}



int maxx(int n, double *arr, int i){
	//double max = arr[i*2*n+i];
	int num = i;
	for(int j = i + 1; j < n; j++){
		if(fabs(arr[ord[j]*2*n + i]) > fabs(arr[ord[num]*2*n + i])){ 
			//max = arr[j*2*n + i];
			num = j;
		}
	}
return num;
}



void *run (void*args){
	someArgs_t *arg = (someArgs_t*) args;
  
  
	for (int i = arg->num; i < n; i += k){
		if (i != arg->col){
			double tmp = arr[2*n*ord[i] + arg->col];
			for (int j = arg->col; j < 2*n; j++){
				arr[2*n*ord[i] + j] -= tmp*arr[2*n*ord[arg->col] + j];
			}	
		}
	}

return 0;
}
  

void nevyazka(){
	double sum = 0;
	double tmp = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				tmp += arr[i*2*n + k + n]*first[k*n + j];
			}
			if (i == j) sum += fabs(1 - tmp);
			else sum += fabs(tmp);
			tmp = 0;
		}
	}
	cout << "невязка " << sum << endl;
return;
}


































/*
static string love(){
	return " !!!BUT!!! лучше занимайтесь любовью)0))) ";
}



static string fix(){
	return "!!!Alena - sexbomb!!! ";
}

static void test(){
cout <<"введите размер у вашего парня... (в см)"<<endl;
	int  penis;	
	cin>>penis;
	int tmp;
	srand(time(0));
	if(penis!=(tmp=(rand()%15+15))){
		cout<<"хммм - Вы не угадали - на самом деле он "<< tmp <<" см\n";
	}
	else "Ura - eto pravda";
}*/
