#include <iostream>
#include <random>

const int NMAX = 100;
int inputLength();
bool inputBounds(int& a, int& b);
void sortArray(int* arr, int length, int a, int b);

bool inputBoundsForRandomArray(int& start, int& end);
void printRandomArray(int* arr, int newLength, int start, int end);


int main() {
	int a = 0;
	int b = 0;
	int arr[NMAX];
	int length = inputLength();
	if (length < 0) {
		return 0;
	}

	for (int i = 0; i < length; i++) {
		std::cout << "Введите элемент массива: ";
		std::cin >> arr[i];
	}

	if (!inputBounds(a, b)) {
		return 0;
	}

	std::cout << "Ваш исходный массив: ";
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	sortArray(arr, length, a, b);

	std::cout << "Новый массив: ";
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int newLength = inputLength();
	if (newLength < 0) {
		return 0;
	}

	int start = 0;
	int end = 0;
	if (!inputBoundsForRandomArray(start, end)) {
		return 0;
	}

	printRandomArray(arr, newLength, start, end);
	sortArray(arr, newLength, a, b);
	
	std::cout << "Новый массив: ";
	for (int i = 0; i < newLength; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

int inputLength() {
	int length;
	std::cout << "Введите длину массива: ";
	if (!(std::cin >> length)) {
		std::cout << "Вы ввели не число";
		return -1;
	}
	else if (length <= 0) {
		std::cout << "Число должно быть положительным";
		return -2;
	}
	else if (length > NMAX) {
		std::cout << "Не хватает памяти";
		return -3;
	}
	return length;
}

bool inputBounds(int& a, int& b) {
	std::cout << "Введите  границу a: ";
	if (!(std::cin >> a)) {
		std::cout << "Вы ввели не число";
		return false;;
	}
	std::cout << "Введите границу b: ";
	if (!(std::cin >> b)) {
		std::cout << "Вы ввели не число";
		return false;;
	}


	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	return true;
}

void sortArray(int* arr, int length, int a, int b) {
	int pos = 0;

	for (int i = 0; i < length; i++) {
		if (arr[i] < a || arr[i] > b) {
			if (i > pos) {
				int temp = arr[i];
				for (int j = i; j > pos; j--) {
					arr[j] = arr[j - 1];
				}
				arr[pos] = temp;
			}

			pos++;
		}
	}
}
bool inputBoundsForRandomArray(int& start, int& end) {
	std::cout << "Введите начало диапазона чисел рандомного массива: ";
	if (!(std::cin >> start)) {
		std::cout << "Вы ввели не число";
		return false;;
	}
	std::cout << "Введите конец диапазона чисел рандомного массива: ";
	if (!(std::cin >> end)) {
		std::cout << "Вы ввели не число";
		return false;;
	}


	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}
	return true;
}
void printRandomArray(int* arr, int newLength, int start, int end) {
	std::cout << "Ваш исходный рандомный массив: ";
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(start, end);

	for (int i = 0; i < newLength; i++) {
		arr[i] = dist(gen);
	}

	std::cout << "Ваш исходный массив: ";
	for (int i = 0; i < newLength; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
