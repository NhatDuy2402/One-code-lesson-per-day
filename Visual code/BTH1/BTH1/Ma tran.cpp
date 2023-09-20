// khai báo một ma trận bằng cách nhập, ngẫu nhiên, xuất ma trận 
#include <iostream>
#include <iomanip> // để sử dụng setw()
#include <ctime> // để sử dụng rand(time(0)
#include <cstdlib>
using namespace std;
#define max 50

// hàm nhập ma trận (người dùng nhập)
void input(int a[max][max], int &r, int &c) {
	cout << "Nhap so dong va so cot cua ma tran: ";
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cout << "Nhap " << c << " phan tu hang thu " << i + 1 << ": ";
		for (int j = 0; j < c; j++)
			cin >> setw(3) >> a[i][j];
	}
}

// hàm nhập ma trận (ngẫu nhiên)
void NgauNhien(int a[max][max], int& r, int& c) {
	srand(time(0));
	cout << "Nhap so dong va so cot cua ma tran: ";
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			// nhap ngau nhien tu 1 den 20
			// (max - min + 1) _ min 
			a[i][j] = rand() % 20 + 1;
	}
}

// hàm xuất ma trận đã lưu trữ
void output(int a[max][max], int r, int c) {
	cout << "mang da luu: \n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}

}

// hàm tính tổng các giá trị trị cảu mảng 
int sum(int a[max][max], int r, int c) {
	int sum = 0;
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++)
			sum += a[i][i];
	return sum;
}

// hàm tìm giá trị nhỏ nhất của mảng
int find_Min(int a[max][max], int r, int c) {
	int min_N = INT_MAX;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (min_N > a[i][j])
				min_N = a[i][j];
		}
	}
	return min_N;
}

// hàm tìm giá trị lớn nhất của mảng
int find_Max(int a[max][max], int r, int c) {
	int max_N = INT_MIN;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (max_N < a[i][j])
				max_N = a[i][j];
		}
	}
	return max_N;
}

// hàm tìm giá trị nhỏ nhất nằm tại vị trí nào
void find_vt_Min(int a[max][max], int r, int c) {
	int min_N = INT_MAX;
	int x, y;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (min_N > a[i][j]) {
				min_N = a[i][j];
				 x = i;
				 y = j;
			}
				
		}
	}
	cout << "gia tri nho nhat: " << min_N << " tai dong " << x+ 1 << " cot " << y+1 << endl;
}

// hàm tìm giá trị lớn nhất nằm ở vị trí nào
void find_vt_Max(int a[max][max], int r, int c) {
	int max_N = INT_MIN;
	int x, y;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (max_N < a[i][j]) {
				max_N = a[i][j];
				x = i;
				y = j;
			}
				
		}
	}
	cout << "gia tri lon nhat: " << max_N << " tai dong " << x + 1 << " cot " << y + 1 << endl;

}

// hàm tính tổng hàng bất kì
int sum_Row(int a[max][max], int r, int c, int x) {
	int sum = 0;
	for (int j = 0; j < c; j++)
		sum += a[x-1][j];
	return sum;
}

// hàm tính tổng cột bất kì
int sum_Col(int a[max][max], int r, int c, int x) {
	int sum = 0; 
	for (int i = 0; i < r; i++)
		sum += a[i][x-1];
	return sum;
}

int main() {
	int a[max][max];
	int r, c;
	//input(a, r, c);
	NgauNhien(a, r, c);
	output(a, r, c);

	cout << "Tong Cac Gia Tri Cua Mang: " << sum(a, r, c) << endl;
	cout << "gia tri nho nhat cua mang la: " << find_Min(a, r, c) << endl;
	cout << "gia tri lon nhat cua mang la: " << find_Max(a, r, c) << endl;
	find_vt_Min(a, r, c);
	find_vt_Max(a, r, c);

	int sum_r, sum_c;

	cout << "nhap hang muon tinh: ";
	cin >> sum_r;
	cout <<"tong hang: "<< sum_Row(a, r, c, sum_r);
	cout << "\nnhap cot muon tinh: ";
	cin >> sum_c;
	cout <<"tong cot: "<<sum_Col(a, r, c, sum_c);


	return 0;
}