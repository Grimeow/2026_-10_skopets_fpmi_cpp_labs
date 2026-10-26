#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main() {
	std::string str;
	std::string delimiter;
	std::vector<std::string> container;
	
	std::cout << "Введите какие символы будут являться разделителем: ";
	getline(std::cin, delimiter);

	std::cout << "Введите предложение ";
	getline(std::cin, str);


	if (str.empty()) {
		std::cout << "Строка пустая";
		return 0;
	}
	size_t begin = 0;
	size_t end = str.find_first_of(delimiter);

	while (end != std::string::npos) {
		if (end != begin) {
			container.push_back((str.substr(begin, end - begin)));
		}
		begin = end + 1;
		end = str.find_first_of(delimiter, begin);
	}
	if (begin < str.size()) {
		container.push_back(str.substr(begin));
	}

	int answer;
	std::cout << "Как сортировать? По возрастанию = 1, по убыванию = 2" << std::endl;
	if (!(std::cin >> answer)) {
		std::cout << "Введено не число";
		return 0;
	}
	if (answer != 1 && answer != 2) {
		std::cout << "Нет такого варианта";
		return 0;
	}
	if (answer == 1) {
		std::sort(container.begin(), container.end(), [](std::string a, std::string b) {
			if (a.size() == b.size()) {
				return a < b;
			}
			return a.size() < b.size();
			});
		for (auto word : container) {
			std::cout << word << " ";
		}
	}
	if (answer == 2) {
		std::sort(container.begin(), container.end(), [](std::string a, std::string b) {
			if (a.size() == b.size()) {
				return a > b;
			}
			return a.size() > b.size();
			});
		for (auto word : container) {
			std::cout << word << " ";
		}
	}

	return 0;
}