#include <iostream>

int main() {
    using std::cout;
    using std::cin;
    int num;
    cout << "Введите четырехзначное число: ";
    cin >> num;

    int original = num;
    int new_num = 0;

    if ((num >= 1000) and (num <= 9999)) {
        for (int i = 0; i < 4; i++) {
            int n = num % 10;
            new_num = n + new_num * 10;
            num= num / 10;
        }

        if (new_num == original) {
            cout << "Ваще число - палиндром";
        }
        else {
            cout << "Ваше число не палиндром";
        }
    }
    else {
        cout << "Ваще число не четырехзначное";
    }

    return 0;
}