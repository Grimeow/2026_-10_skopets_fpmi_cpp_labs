#include <iostream>

int main() {
	using std::cout;
	using std::cin;

	int a, b, d;

	cout << "Введите начало отрезка a: ";
	cin >> a;
	cout << "Введите конец отрезка b: ";
	cin >> b;
	cout << "Введите разность прогрессии d: ";
	cin >> d;


	if (a > b) {
		int origin_a = a;
		a = b;
		b = origin_a;
	}

	if (d > 0) {
		int a_0 = a;
		while (a_0 <= b) {
			if (a_0 % 3 == 0) {
				cout << a_0 << " ";
			}
			a_0 += d;
		}
	}
	else if (d < 0) {
		int a_0 = b;
		while (a_0 >= a) {
			if (a_0 % 3 == 0) {
				cout << a_0 << " ";
			}
			a_0 += d;
		}
	}
	else if (d == 0) {
		if (a % 3 == 0) {
			cout << a;
		}
	}
	cout << std::endl;
	return 0;

}