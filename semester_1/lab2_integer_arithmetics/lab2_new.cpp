#include <iostream>

int TryRead(int& n);
int func(int n);

int main() {
	int n;
	int sum = 0;

	std::cout << "Введите положительное число: ";


	if (TryRead(n) != 2) {
		return 0;
	}

	sum = func(n);

	
	if (n == sum) {
		std::cout << "Число совершенно" << std::endl;
	}
	else {
		std::cout << "Число не совершенно" << std::endl;
	}

	return 0;
}


int TryRead(int& n) {

	if (!(std::cin >> n)) {
		std::cout << "Введено не число\n";
		return 1;
	}

	if (n <= 0) {
		std::cout << "Число не положительное\n";
		return 0;
	}

	return 2;
}


int func(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}

	}
	return (sum);
}