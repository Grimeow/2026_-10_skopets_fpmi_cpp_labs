#include <iostream>

int main() {
	using std::cout;
	using std::cin;

	int n;
	cout << "Введите количество чисел: ";
	cin >> n;
	cout << "Сумма первых нечетных чисел: " << n * n;

	return 0;
}