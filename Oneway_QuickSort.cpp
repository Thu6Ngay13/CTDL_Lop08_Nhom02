#include <iostream>
using namespace std;

struct Record{
	int Key;
};

void init_Array(Record R[], int &N){
	N = 10;
	
	R[0].Key = 2;
	R[1].Key = 3;
	R[2].Key = 7;
	R[3].Key = 8;
	R[4].Key = 10;
	R[5].Key = 5;
	R[6].Key = 4;
	R[7].Key = 1;
	R[8].Key = 9;
	R[9].Key = 8;
	
	R[10].Key = -1;
}

void oneWay_QuickSort(Record R[], int N){
	int I, J;
	Record P;
	
	for(int L = 0; L < N; ++L){
		while(R[L].Key > 0){
			I = L;
			J = L;
			P = R[L]; 
			
			while(R[J].Key > 0){
				++J;
				while(P.Key <= R[J].Key) J++;
				if(R[J].Key > 0){
					R[I] = R[J]; I++;
					R[J] = R[I];
				}
			}
			
			P.Key = -P.Key;
			R[I] = P;
		}
		R[L].Key = -R[L].Key;
	}
}

int main(){
	int N;
	Record R[111];
	
	init_Array(R, N);
	oneWay_QuickSort(R, N);
	
	for(int i = 0; i < N; ++i) 
		cout << R[i].Key << " ";
		
	return 0;
}
