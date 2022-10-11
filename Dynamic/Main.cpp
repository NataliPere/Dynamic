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

//Задача 1. Увеличение динамического массива
template <typename T>
void add_elements(T* &arr, const int length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{}; // {} заполнили массив нулями
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

//Задача 2. Уменьшение динамического массива
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

	//Динамические переменные
	/*int* point = new int; //выделение уастка динамической памяти, размеров в 4 байта с помощью оператора new
	*point = 10;
	std::cout << "point = " << point << "\n";
	std::cout << "*point = " << * point << "\n";

	delete point; //очищение области памяти, на которую направлен указатель
	point = nullptr;
	if (point != nullptr)
		std::cout << *point << "\n";
	else
		std::cout << "Указатель нейтрален.\n";


	point = new int; // выделение нового участка памяти
	*point = 15; // указателю присвоено значение
	std::cout << "point = " << point << "\n"; 
	std::cout << "*point = " << *point << "\n";
	
	delete point;*/

	//Динамический массив

	/*std::cout << "Введите длину массива: ";
	std::cin >> n;
	if (n < 0)
		std::cout << "Ошибка. Длина не может быть отрицательной.\n";
	else {
		int* mass = new int[n]; //Выделение динамической памяти для хранения массива
		std::cout << "Динамический массив: \n";
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			std::cout << mass[i] << ", ";
		}
		std::cout << "\b\b.\n";
		delete[] mass;

	}
	*/

	//Задача 1. Увеличение динамического массива

	/*std::cout << "Задача 1. \nВведите длину массива: ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	std::cout << "Изначальный массив: \n";
	fill_arr(arr1, size1, 1, 11);
	show_arr(arr1, size1);
	std::cout << "Введите количество новых элементов: ";
	std::cin >> n;
	add_elements(arr1, size1, n);
	size1 += n;
	std::cout << "Итоговый массив: \n";
	show_arr(arr1, size1);*/

	//Задача 2. Уменьшение динамического массива
	/*std::cout << "Задача 2. \nВведите длину массива: ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	std::cout << "Изначальный массив: \n";
	fill_arr(arr2, size2, 1, 11);
	show_arr(arr2, size2);
	std::cout << "Введите количество элементов, которое необходимо убрать: ";
	std::cin >> n;
	substract_elements(arr2, size2, n);
	size2 -= n;
	std::cout << "Итоговый массив: \n";
	show_arr(arr2, size2);*/
	
	//Двумерный динамический массив
	//int* mx = new int[4][6]; // не работает
	int** mx = new int*[4]; //создаем массив указателей, где 4 - кол-во рядов
	for (int i = 0; i < 4; i++)
		mx[i] = new int[6]; // 6 - кол-во колонок
	 // Очищение двумерного динамического массива
	//delete[][] mx; // не работает

	for (int i = 0; i < 4; i++)
		delete[] mx[i]; //удаление всех рядов массива
	delete[] mx; //удаление самого массива указателей

	
	return 0;
}