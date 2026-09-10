#include <iostream>

int main() {
	using std::cout;
	using std::cin;
	int num;
	int count_1 = 0;
	int count_2 = 0;

	cout << "Введите шестищначное натурально число: ";
	cin >> num;

	if (num >= 100000 and num <= 999999) {
		for (int i = 0; i < 3; i++) {
			int n = num % 10;
			count_1 += n;
			num /= 10;
		}
		for (int i = 0; i < 3; i++) {
			int n = num % 10;
			count_2 += n;
			num /= 10;
		}

		if (count_1 == count_2) {
			cout << "Ваше число счастливое";
		}
		else {
			cout << "Ваше число не счастливое";
		}
	}
	else {
		cout << "Ваше число не шестизначное";
	}

	return 0;
}
 