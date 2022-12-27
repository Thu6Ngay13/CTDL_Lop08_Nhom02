#include <iostream>
using namespace std;

struct Record{
	int SucManhCuaRong;
	int SucManhTangThem;
};

void oneWay_QuickSort(Record R[], int N){
	int I, J;
	Record P;
	
	for(int L = 0; L < N; ++L){
		while(R[L].SucManhCuaRong > 0){
			I = L;
			J = L;
			P = R[L]; 
			
			while(R[J].SucManhCuaRong > 0){
				++J;
				while(P.SucManhCuaRong <= R[J].SucManhCuaRong) J++;
				if(R[J].SucManhCuaRong > 0){
					R[I] = R[J]; I++;
					R[J] = R[I];
				}
			}
			
			P.SucManhCuaRong = -P.SucManhCuaRong;
			R[I] = P;
		}
		R[L].SucManhCuaRong = -R[L].SucManhCuaRong;
	}
}

int main(){
	long long s = 2;
	int N = 2;
	bool CoThemTieuDietRong = true;
	Record R[N+1];
	
	R[0].SucManhCuaRong = 1;
	R[0].SucManhTangThem = 99;
	
	R[1].SucManhCuaRong = 100;
	R[1].SucManhTangThem = 0;
	
	R[2].SucManhCuaRong = -1;
	R[2].SucManhTangThem = -1;
	
	oneWay_QuickSort(R, N);
	
	for(int i = 0; i < N && CoThemTieuDietRong; i++)
		if(s > R[i].SucManhCuaRong) s += R[i].SucManhTangThem;
		else CoThemTieuDietRong = false;
		
	if(CoThemTieuDietRong) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
