#include <iostream>

int main() {
    using std::cout;
    using std::cin;
    int n, num;
    int f_1 = 1, f_0 = 0;
    cout << "Введите число: ";
    cin >> n;

    if (n <= 0) {
        cout << "Число должно быть положительным";
        return 0;
    }
    if (n >= 1) {
        cout << "0";
    }
    if (n >= 2) {
        cout << " 1";
    }

    for (int i = 0; i < n - 2; i++) {
        num = f_0 + f_1;
        cout << " " << num;
        f_0 = f_1;
        f_1 = num;
    }


    return 0;
}