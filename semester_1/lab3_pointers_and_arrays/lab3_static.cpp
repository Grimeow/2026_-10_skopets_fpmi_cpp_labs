#include <iostream>
#include <random>

int const MAX_SIZE = 1000;

int getValidLength();
bool inputArray(int* arr, int length);
bool isPalindrome(int* arr, int left, int right);
void findTheLongestPalindromeChain(int* arr, int length, int& maxLen, int& bestStartIndex);
void printTheLongestPalindrome(int* arr, int maxLen, int bestStartIndex);

bool inputBounds(int &a, int &b);
void printRandomArray(int* arr, int length);
void randomArray(int* arr, int length, int a, int b,std::mt19937 &gen);

int main()
{
	int arr[MAX_SIZE];

	int length = getValidLength();
	if (length <= 0) {
		return 0;
	}
	int maxLen = 0;
	int bestStartIndex = 0;

	if (!inputArray(arr, length)) {
		return 0;
	}
	findTheLongestPalindromeChain(arr, length, maxLen, bestStartIndex);
	printTheLongestPalindrome(arr, maxLen, bestStartIndex);

	int newLength = getValidLength();
	if (newLength <= 0) {
		return 0;
	}

	int a, b;
	if (!inputBounds(a, b)) {
		return 0;
	}

	std::mt19937 gen(1234567890);
	randomArray(arr, newLength, a, b, gen);
	printRandomArray(arr, newLength);
	findTheLongestPalindromeChain(arr, newLength, maxLen, bestStartIndex);
	printTheLongestPalindrome(arr, maxLen, bestStartIndex);

	return 0;
}


int getValidLength() {
	int length;
	std::cout << "Введите количество элементов массива: ";

	if (!(std::cin >> length)) {
		std::cout << "Вы ввели не число" << std::endl;
		return -1;
	}
	 else if (length <= 0) {
		std::cout << "Число должно быть положительным" << std::endl;
		return -2;
	}
	 else if (length > MAX_SIZE){
		std::cout << "Не хватает памяти" << std::endl;
		return -3;
	}
	return length;
}

bool inputArray(int* arr, int length) {

	for (int i = 0; i < length; i++) {
		std::cout << "Введите элемент массива: ";
		
		if (!(std::cin >> arr[i])) {
			std::cout << "Вы ввели не число" << std::endl;
			return false;
		}
	}
	return true;
}

bool isPalindrome(int* arr, int left, int right) {
	while (left < right) {
		if (arr[left] != arr[right]) {
			return false;
		}
		left++;
		right--;
	}
	return true;
}

void findTheLongestPalindromeChain(int* arr, int length, int& maxLen, int& bestStartIndex) {
	maxLen = 0;
	bestStartIndex = 0;

	for (int left = 0; left < length; left++) {
		for (int right = left; right < length; right++) {
			if (isPalindrome(arr, left, right)) {
				int currentLen = right - left + 1;
				if (currentLen > maxLen) {
					maxLen = currentLen;
					bestStartIndex = left;
				}
			}
		
		}
	}
}

void printTheLongestPalindrome(int* arr, int maxLen, int bestStartIndex) {
	std::cout << "Самая длинная цепочка палиндромов равна " << maxLen << std::endl;
	for (int i = bestStartIndex; i < bestStartIndex + maxLen; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

bool inputBounds(int& a, int& b) {
	std::cout << "Введите границу массива a: ";
	if (!(std::cin >> a)) {
		std::cout << "Вы ввели не число" << std::endl;
		return false;
	}
	std::cout << "Введите границу массива b: ";
		if (!(std::cin >> b)) {
			std::cout << "Вы ввели не число" << std::endl;
			return false;
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

void randomArray(int* arr, int newLength, int a, int b, std::mt19937 &gen) {
	std::uniform_int_distribution<> dist(a, b);

	for (int i = 0; i < newLength; i++) {
		arr[i] = dist(gen);
	}
}
