#include <iostream>
using namespace std;

struct Record{
	int NgayBatDau;
	int NgayKetThuc;
};


void oneWay_QuickSort(Record R[], int N){
	int I, J;
	Record P;
	
	for(int L = 0; L < N; ++L){
		while(R[L].NgayKetThuc > 0){
			I = L;
			J = L;
			P = R[L]; 
			
			while(R[J].NgayKetThuc > 0){
				++J;
				while(P.NgayKetThuc <= R[J].NgayKetThuc) J++;
				if(R[J].NgayKetThuc > 0){
					R[I] = R[J]; I++;
					R[J] = R[I];
				}
			}
			
			P.NgayKetThuc = -P.NgayKetThuc;
			R[I] = P;
		}
		R[L].NgayKetThuc = -R[L].NgayKetThuc;
	}
}


int main(){
	int N = 4;
	Record R[N+1];
	
	R[0].NgayBatDau = 5;
	R[0].NgayKetThuc = 6;
	
	R[1].NgayBatDau = 1;
	R[1].NgayKetThuc = 2;
	
	R[2].NgayBatDau = 7;
	R[2].NgayKetThuc = 8;
	
	R[3].NgayBatDau = 3;
	R[3].NgayKetThuc = 4;
	
	R[4].NgayBatDau = -1;
	R[4].NgayKetThuc = -1;
	
	oneWay_QuickSort(R, N);
	
	int ans = 1;
	int tmp = R[0].NgayKetThuc;
	for(int i = 1; i < N; ++i)
		if(R[i].NgayBatDau > tmp){
			ans++;
			tmp = R[i].NgayKetThuc;
		}
	cout << ans << endl;
}
