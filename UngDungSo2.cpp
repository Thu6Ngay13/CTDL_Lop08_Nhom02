#include <iostream>
using namespace std;

struct Record{
	int ThoiDiemCheckIn;
	int ThoiGianCheckInXong;
};


void oneWay_QuickSort(Record R[], int N){
	int I, J;
	Record P;
	
	for(int L = 0; L < N; ++L){
		while(R[L].ThoiDiemCheckIn > 0){
			I = L;
			J = L;
			P = R[L]; 
			
			while(R[J].ThoiDiemCheckIn > 0){
				++J;
				while(P.ThoiDiemCheckIn <= R[J].ThoiDiemCheckIn) J++;
				if(R[J].ThoiDiemCheckIn > 0){
					R[I] = R[J]; I++;
					R[J] = R[I];
				}
			}
			
			P.ThoiDiemCheckIn = -P.ThoiDiemCheckIn;
			R[I] = P;
		}
		R[L].ThoiDiemCheckIn = -R[L].ThoiDiemCheckIn;
	}
}

int main(){
	int N = 3;
	Record R[N+1];
	
	R[0].ThoiDiemCheckIn = 2;
	R[0].ThoiGianCheckInXong = 1;
	
	R[1].ThoiDiemCheckIn = 8;
	R[1].ThoiGianCheckInXong = 3;
	
	R[2].ThoiDiemCheckIn = 5;
	R[2].ThoiGianCheckInXong = 7;
	
	R[3].ThoiDiemCheckIn = -1;
	R[3].ThoiGianCheckInXong = -1;
	
	oneWay_QuickSort(R, N);

	int EndTime = R[0].ThoiDiemCheckIn + R[0].ThoiGianCheckInXong;
	for(int i = 1; i < N; ++i){
		if(R[i].ThoiDiemCheckIn > EndTime)
			EndTime = R[i].ThoiDiemCheckIn + R[i].ThoiGianCheckInXong;
		else
			EndTime += R[i].ThoiGianCheckInXong;
	}
	cout << EndTime%24 << endl;
}
