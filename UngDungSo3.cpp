#include <iostream>
#include <iomanip>
using namespace std;

struct Record{
	int Key;
};

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
					R[J] = R[I]; continue;
				}
			}
			
			P.Key = -P.Key;
			R[I] = P;
		}
		R[L].Key = -R[L].Key;
	}
}

int main(){
	int N = 7, l = 15;
	Record R[N+1];
	
	R[0].Key = 15;
	R[1].Key = 5;
	R[2].Key = 3;
	R[3].Key = 7;
	R[4].Key = 9;
	R[5].Key = 14;
	R[6].Key = 1;
	R[7].Key = -1;
	
	oneWay_QuickSort(R, N);
	
	double d = max(R[0].Key-0, l-R[N-1].Key);
	for(int i = 0; i < N-1; ++i)
		d = max(d, (double)(R[i+1].Key-R[i].Key)/2);

	cout << fixed << setprecision(10) << d << endl;
	return 0;
}
