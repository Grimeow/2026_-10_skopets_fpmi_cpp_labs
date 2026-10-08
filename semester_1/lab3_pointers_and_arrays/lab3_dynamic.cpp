#include <iostream>
#include <random>

int const MAX_SIZE = 1000;

int getValidLength();
bool inputArray(int* arr, int length);
int inputT();
void process(int* arr, int length, int t);
void printArrray(int* arr, int length);


bool inputBounds(int& a, int& b);
void processForRandomArray(int* arr, int newLength, int t);
void randomArray(int* arr, int newLength, int a, int b);
void printRandomArray(int* arr, int newLlength);


int main()
{

	int length = getValidLength();
	if (length < 0) {
		return 0;
	}

	int* arr = new int[length];

	if (!inputArray(arr, length)) {
		delete[] arr;
		return 0;
	}

	int t = inputT();
	if (t < 0) {
		delete[] arr;
		return 0;
	}

	std::cout << "Ваш исходный массив: ";
	printArrray(arr, length);

	process(arr, length, t);

	std::cout << "Ваш новый массив: ";
	printArrray(arr, length);

	delete[] arr;

	int newLength = getValidLength();
	if (newLength < 0) {
		return 0;
	}
	arr = new int[newLength];

	int a, b;
	if (!inputBounds(a, b)) {
		delete[] arr;
		return 0;
	}

	randomArray(arr, newLength, a, b);

	std::cout << "Ваш исходный рандомный массив: ";
	printRandomArray(arr, newLength);

	processForRandomArray(arr, newLength, t);

	std::cout << "Ваш новый рандомный массив: ";
	printRandomArray(arr, newLength);
	
	delete[] arr;

	return 0;
}


int getValidLength() {
	int length;
	std::cout << "Введите количество элементов массива: ";

	if (!(std::cin >> length)) {
		std::cout << "Вы ввели не число";
		return -1;
	}
	else if (length <= 0) {
		std::cout << "Число должно быть положительным";
		return -2;;
	}
	else if (length > MAX_SIZE) {
		std::cout << "Не хватает памяти";
		return -3;;
	}
	return length;
}

int inputT() {
	int t;
	std::cout << "введите Т: ";
	if (!(std::cin >> t)) {
		std::cout << "Вы ввели не число";
		return -1;
	}
	return abs(t);
}

bool inputArray(int* arr, int length) {

	for (int i = 0; i < length; i++) {
		std::cout << "Введите элемент массива: ";

		if (!(std::cin >> arr[i])) {
			std::cout << "Вы ввели не число";
			return false;;
		}
	}
	return true;
}

void process(int* arr, int length, int t) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (abs(arr[i]) != t) {
			arr[count] = arr[i];
			count++;
		}
	}
	for (int i = count; i < length; i++) {
		arr[i] = 0;
	}
}

void printArrray(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

bool inputBounds(int& a, int& b) {
	std::cout << "Введите границу массива a: ";
	if (!(std::cin >> a)) {
		std::cout << "Вы ввели не число";
		return false;;
	}
	std::cout << "Введите границу массива b: ";
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

void randomArray(int* arr, int newLength, int a, int b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);

	for (int i = 0; i < newLength; i++) {
		arr[i] = dist(gen);
	}
}

void processForRandomArray(int* arr, int newLength, int t) {
	int count = 0;
	for (int i = 0; i < newLength; i++) {
		if (abs(arr[i]) != t) {
			arr[count] = arr[i];
			count++;
		}
	}
	for (int i = count; i < newLength; i++) {
		arr[i] = 0;
	}
}

void printRandomArray(int* arr, int newLength) {
	for (int i = 0; i < newLength; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
