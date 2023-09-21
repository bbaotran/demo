#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Nhap(int m, vector<vector<int>>& mt);
int TimK(int m, vector<vector<int>> mt);
bool KiemTra(int m, vector<vector<int>> mt);

int main()
{
	int m;
	cin >> m;
	vector<vector<int>> mt(m, vector<int>(m));
	Nhap(m, mt);
	if (KiemTra(m, mt))
	{
		cout << "0";
		return 0;
	}
	cout << TimK(m, mt);
};

void Nhap(int m, vector<vector<int>>& mt)
{
	for (int i = 0;i < m;i++)
		for (int j = 0;j < m;j++) cin >> mt[i][j];
}

//Tim he so-period Arnold's cat map
int TimK(int m, vector<vector<int>> mt)
{
	vector<vector<int>> temp(m, vector<int>(m)), tmp(m, vector<int>(m));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) temp[i][j] = mt[i][j];
	int k = 1;
	for (k = 1;k < m * m;k++)
	{
		for (int i = 0;i < m;i++)
			for (int j = 0;j < m;j++)
			{
				int x = (2 * i + j) % m;
				int y = (i + j) % m;
				tmp[x][y] = temp[i][j];
			};
		if (mt == tmp) return k;
		temp = tmp;
	}
	return k;
}
bool KiemTra(int m, vector<vector<int>> mt)
{
	int dem=0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) if (mt[0][0] == mt[i][j]) dem++;
	if (dem == m * m) return 1;
	return 0;
}

