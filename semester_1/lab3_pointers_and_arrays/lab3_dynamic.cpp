#include <iostream>
#include <random>

int const MAX_SIZE = 1000;

int getValidLength();
bool inputArray(int* arr, int length);
bool isPalindrome(int num);
void findTheLongestPalindromeChain(int* arr, int length, int& maxLen, int& bestStartIndex);
void printTheLongestPalindrome(int* arr, int maxLen, int bestStartIndex);

bool inputBounds(int& a, int& b);
void printRandomArray(int* arr, int length);
void randomArray(int* arr, int length, int a, int b);


int main()
{

	int length = getValidLength();
	if (length < 0) {
		return 0;
	}
	int* arr = new int[length];

	int maxLen = 0;
	int bestStartIndex = -1;

	if (!inputArray(arr, length)) {
		delete[] arr;
		return 0;
	}
	findTheLongestPalindromeChain(arr, length, maxLen, bestStartIndex);
	printTheLongestPalindrome(arr, maxLen, bestStartIndex);

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
	printRandomArray(arr, newLength);
	findTheLongestPalindromeChain(arr, newLength, maxLen, bestStartIndex);
	printTheLongestPalindrome(arr, maxLen, bestStartIndex);

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

bool isPalindrome(int num) {
	if (num < 0) {
		return false;
	}
	int original = num;
	long reversed = 0;
	while (num > 0) {
		int ostatok = num % 10;
		reversed = ostatok + reversed * 10;
		num /= 10;
	}
	return original == reversed;
}

void findTheLongestPalindromeChain(int* arr, int length, int& maxLen, int& bestStartIndex) {
	maxLen = 0;
	bestStartIndex = -1;

	int startIndex = 0;
	int currentLen = 0;


	for (int i = 0; i < length; i++) {
		if (isPalindrome(arr[i])) {
			if (currentLen == 0) {
				startIndex = i;
			}
			currentLen++;
		}
		else {
			if (currentLen > maxLen) {
				maxLen = currentLen;
				bestStartIndex = startIndex;
			}
			currentLen = 0;
		}
	}
	if (currentLen > maxLen) {
		maxLen = currentLen;
		bestStartIndex = startIndex;
	}
}

void printTheLongestPalindrome(int* arr, int maxLen, int bestStartIndex) {
	if (bestStartIndex != -1) {
		std::cout << "Самая длинная цепочка палиндромов равна " << maxLen << std::endl;
		for (int i = bestStartIndex; i < bestStartIndex + maxLen; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "В массиве нет ни одного палиндрома\n";
	}

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
void printRandomArray(int* arr, int newLength) {
	for (int i = 0; i < newLength; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void randomArray(int* arr, int newLength, int a, int b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);

	for (int i = 0; i < newLength; i++) {
		arr[i] = dist(gen);
	}
}
