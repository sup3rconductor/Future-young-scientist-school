#include <iostream>
#include <random>
#include <chrono>

//Генератор псевдослучайных чисел - вихрь Мерсенна. Для генерации использется текущее время и более точный метод
//high_resolution_clock

int main()
{
	//Инициализация вихря Мерсенна
	std::mt19937 mt{ static_cast <std::mt19937> (std::chrono::high_resolution_clock::now().time_since_epoch().count()) };

	//Инициализация равномерного генератора псевдослучайных чисел в диапазоне от 1 до 99999
	std::uniform_int_distribution<> gamma{ 1, 99999 }; //расширил диапазон для большей точности генерируемых чисел

	//Цикл, генерирующий 20 псевдослучайных чисел
	for (int i = 0; i < 20; i++)
	{
		std::cout << double(gamma(mt)) / 100000. << '\t';
	}
	return 0;
}
