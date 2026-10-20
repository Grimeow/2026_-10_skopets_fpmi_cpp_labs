#include <iostream>
#include <random>
const int MAX = 10;
int inputN();
bool inputMatrix(int matrix[][MAX], int& n);
void outputMatrix(int matrix[][MAX], int& n);
int replace(int matrix[][MAX], int& n);

bool inputBounds(int& a, int& b);
void inputRandomMatrix(int matrix[][MAX], int& newN, int& a, int& b);

int main() {
	int matrix[MAX][MAX];
	int n = inputN();
	if (n == 0) return 0;
	if (!(inputMatrix(matrix, n))) return 0;
	
	std::cout << "Ваш исходный массив: " << std::endl;
	outputMatrix(matrix, n);

	int count = replace(matrix, n);

	std::cout << "Ваш новый массив: " << std::endl;
	outputMatrix(matrix, n);

	std::cout << "Количество измененных элементов: " << count << std::endl;


	int newN = inputN();
	if (newN == 0) return 0;

	int a, b;
	if (!(inputBounds(a, b))) {
		return 0;
	}

	inputRandomMatrix(matrix, newN, a, b);
	std::cout << "Ваш исходный рандомный массив: " << std::endl;
	outputMatrix(matrix, newN);


	int newCount = replace(matrix, newN);

	std::cout << "Ваш новый массив: " << std::endl;
	outputMatrix(matrix, newN);

	std::cout << "Количество измененных элементов: " << newCount << std::endl;

	return 0;
}

int inputN() {
	int n;
	std::cout << "Введите размер квадратной матрицы: ";
	if (!(std::cin >> n)) {
		std::cout << "Введено не число";
		return 0;
	}
	if (n == 0) {
		std::cout << "Размер не может быть равен нулю";
		return 0;
	}
	if (n > MAX) {
		std::cout << "Не хватает памяти";
		return 0;
	}
	return std::abs(n);
}
bool inputMatrix(int matrix[][MAX], int& n) {
	std::cout << "Введите элементы матрицы:";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!(std::cin >> matrix[i][j])) {
				std::cout << "Введено не число";
				return false;
			}
		}
	}
	return true;
}

void outputMatrix(int matrix[][MAX], int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

int replace(int matrix[][MAX], int& n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (matrix[i][j] != matrix[j][i]) {
				matrix[j][i] = matrix[i][j];
				count++;
			}
		}
	}
	return count;
}

bool inputBounds(int& a, int& b) {
	std::cout << "Введите границу интервала a, которому должны принаддежать элементы массива: ";
	if (!(std::cin >> a)) {
		std::cout << "Введено не число";
		return false;
	}
	std::cout << "Введите границу интервала b, которому должны принаддежать элементы массива: ";
	if (!(std::cin >> b)) {
		std::cout << "Введено не число";
		return false;
	}

	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	return true;
}
void inputRandomMatrix(int matrix[][MAX], int& newN, int& a, int& b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);
	for (int i = 0; i < newN; i++) {
		for (int j = 0; j < newN; j++) {
			matrix[i][j] = dist(gen);
		}
	}
}
