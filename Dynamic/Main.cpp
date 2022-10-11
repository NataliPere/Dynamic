#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
void show_arr(T arr[], const int length) {

	std::cout <<"[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

//������ 1. ���������� ������������� �������
template <typename T>
void add_elements(T* &arr, const int length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{}; // {} ��������� ������ ������
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

//������ 2. ���������� ������������� �������
template <typename T>
void substract_elements(T* &arr, const int length, int num) {
	if (num <= 0)
		return;
	if (num > length) {
		delete[] arr;
		arr = new int[0];
		return;
	}
	T* tmp = new T[length - num];
	for (int i = 0; i < length - num; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//������������ ����������
	/*int* point = new int; //��������� ������ ������������ ������, �������� � 4 ����� � ������� ��������� new
	*point = 10;
	std::cout << "point = " << point << "\n";
	std::cout << "*point = " << * point << "\n";

	delete point; //�������� ������� ������, �� ������� ��������� ���������
	point = nullptr;
	if (point != nullptr)
		std::cout << *point << "\n";
	else
		std::cout << "��������� ���������.\n";


	point = new int; // ��������� ������ ������� ������
	*point = 15; // ��������� ��������� ��������
	std::cout << "point = " << point << "\n"; 
	std::cout << "*point = " << *point << "\n";
	
	delete point;*/

	//������������ ������

	/*std::cout << "������� ����� �������: ";
	std::cin >> n;
	if (n < 0)
		std::cout << "������. ����� �� ����� ���� �������������.\n";
	else {
		int* mass = new int[n]; //��������� ������������ ������ ��� �������� �������
		std::cout << "������������ ������: \n";
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			std::cout << mass[i] << ", ";
		}
		std::cout << "\b\b.\n";
		delete[] mass;

	}
	*/

	//������ 1. ���������� ������������� �������

	/*std::cout << "������ 1. \n������� ����� �������: ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	std::cout << "����������� ������: \n";
	fill_arr(arr1, size1, 1, 11);
	show_arr(arr1, size1);
	std::cout << "������� ���������� ����� ���������: ";
	std::cin >> n;
	add_elements(arr1, size1, n);
	size1 += n;
	std::cout << "�������� ������: \n";
	show_arr(arr1, size1);*/

	//������ 2. ���������� ������������� �������
	/*std::cout << "������ 2. \n������� ����� �������: ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	std::cout << "����������� ������: \n";
	fill_arr(arr2, size2, 1, 11);
	show_arr(arr2, size2);
	std::cout << "������� ���������� ���������, ������� ���������� ������: ";
	std::cin >> n;
	substract_elements(arr2, size2, n);
	size2 -= n;
	std::cout << "�������� ������: \n";
	show_arr(arr2, size2);*/
	
	//��������� ������������ ������
	//int* mx = new int[4][6]; // �� ��������
	int** mx = new int*[4]; //������� ������ ����������, ��� 4 - ���-�� �����
	for (int i = 0; i < 4; i++)
		mx[i] = new int[6]; // 6 - ���-�� �������
	 // �������� ���������� ������������� �������
	//delete[][] mx; // �� ��������

	for (int i = 0; i < 4; i++)
		delete[] mx[i]; //�������� ���� ����� �������
	delete[] mx; //�������� ������ ������� ����������

	
	return 0;
}