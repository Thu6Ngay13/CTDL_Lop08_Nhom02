#include <iostream>
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
	int N = 4, M = 3, k = 5;
	Record A[N+1];
	Record B[M+1];
	
	A[0].Key = 60;
	A[1].Key = 45;
	A[2].Key = 80;
	A[3].Key = 60;
	A[4].Key = -1;
	
	B[0].Key = 30;
	B[1].Key = 60;
	B[2].Key = 75;
	B[3].Key = -1;
	
	oneWay_QuickSort(A, N);
	oneWay_QuickSort(B, M);
	
	int ans = 0;
	int i = 0, j = 0;
	while(i < N && j < M){
		if(abs(A[i].Key - B[j].Key) <= k)
			++ans, ++i, ++j;
		else if(A[i].Key - B[j].Key > k) 
			++j;
		else 
			++i;
	}
	cout << ans << endl;
		
	return 0;
}
