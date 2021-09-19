#include <iostream>
#include <vector>
using namespace std;

void main() {
	setlocale(LC_ALL, "ru");

	int n, m;
	cout << "������� n � m:";
	cin >> n >> m; m++; 

	vector<vector<double>> matrix(n, vector<double>(m));
	cout << "������� ��������� ������������ ������� ��������� � ��������� ����\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];

	//������ ���
	for (int i = 0; i < n; i++) {
		double a = matrix[i][i]; 
		for (int j = 0; j < m; j++)
			matrix[i][j] /= a; 

		for (int k = i + 1; k < n; k++)
		{
			double b = matrix[k][i]; 
			for (int j = i; j < m; j++)
				matrix[k][j] -= matrix[i][j] * b;
		}
	}

	//�������� ���
	for (int i = n - 1; i >= 0; i--)
		for (int k = i - 1; k >= 0; k--)
		{
			double c = matrix[k][i]; 
			for (int j = 0; j < m; j++)
				matrix[k][j] -= matrix[i][j] * c;
		}

	cout << "�������� �������:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << ' ';
		cout << '\n';
	}
}



