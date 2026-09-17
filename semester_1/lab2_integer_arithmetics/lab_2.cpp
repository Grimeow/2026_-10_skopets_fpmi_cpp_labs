#include <iostream>

int main() {
	using std::cout;
	using std::cin;

	int n;
	int sum = 0;

	cout << "Введите положительное число: ";

	if (!(cin >> n)) {
		cout << "Введено не число\n";
		return 1;
	}

	if (n <= 0) {
		cout << "Число не положительное\n";
		return 0;
	}

	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}

	}
	if (n == sum) {
		cout << "Число совершенно" << std::endl;
	}
	else {
		cout << "Число не совершенно" << std::endl;
	}

	return 0;
}