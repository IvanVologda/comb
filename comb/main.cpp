#include <iostream>
#include<windows.h>

void PermutationsWithoutRepetitions();
void PermutationsWithRepetitions();
void ArrangementsWithoutRepetitions();
void ArrangementsWithRepetitions();
void CombinationsWithoutRepetitions();
void CombinationsWithRepetitions();
unsigned long long Factorial(int n);
int EnterArg(char arg);

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	int choice = 0;
	while (true)
	{
		std::cout << "Решения задач по комбминаторики.\n\n";
		std::cout << "1. Перестановки без повторений\n";
		std::cout << "2. Перестановки с повторениями\n";
		std::cout << "3. Размещения без повторений\n";
		std::cout << "4. Размещения с повторениями\n";
		std::cout << "5. Сочетания без повторений\n";
		std::cout << "6. Сочетания с повторениями\n";
		std::cout << "0. Выход\n";
		std::cout << "Выберите действие: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			PermutationsWithoutRepetitions();
			system("pause");
			system("cls");
			break;
		case 2:
			PermutationsWithRepetitions();
			system("pause");
			system("cls");
			break;
		case 3:
			ArrangementsWithoutRepetitions();
			system("pause");
			system("cls");
			break;
		case 4:
			ArrangementsWithRepetitions();
			system("pause");
			system("cls");
			break;
		case 5:
			CombinationsWithoutRepetitions();
			system("pause");
			system("cls");
			break;
		case 6:
			CombinationsWithRepetitions();
			system("pause");
			system("cls");
			break;
		case 0:
			return 0;
		default:
			std::cout << "Неверный выбор. Попробуйте снова.\n";
		}
	}
	return 0;
}

unsigned long long Factorial(int n)
{
	unsigned long long factorial = 1;

	for (int i = 2; i <= n; i++)
	{
		factorial *= i;
	}

	return factorial;
}

void PermutationsWithoutRepetitions()
{
	int n = 0;
	unsigned long long answer = 0;
	std::cout << "ПЕРЕСТАВНОКИ БЕЗ ПОВТОРЕНИЙ\n\n";
	n = EnterArg('n');
	answer = Factorial(n);
	std::cout << "Ответ: " << answer;
}

void PermutationsWithRepetitions()
{
	int n = EnterArg('n');

	int groups = 0;
	std::cout << "Сколько групп одинаковых элементов: ";
	std::cin >> groups;

	unsigned long long denominator = 1;
	int sum = 0;

	for (int i = 0; i < groups; i++)
	{
		int count = 0;
		std::cout << "Сколько раз повторяется элемент " << i + 1 << ": ";
		std::cin >> count;

		sum += count;
		denominator *= Factorial(count);
	}

	if (sum > n)
	{
		std::cout << "Ошибка. Сумма повторений больше n!\n";
		return;
	}

	unsigned long long answer = Factorial(n) / denominator;
	std::cout << "Ответ: " << answer << "\n";
}

void ArrangementsWithoutRepetitions()
{
	int n = 0, k = 0;
	unsigned long long answer = 0;
	std::cout << "РАЗМЕЩЕНИЕ БЕЗ ПОВТОРЕНИЙ\n\n";
	n = EnterArg('n');

	do
	{
		k = EnterArg('k');
		if (k > n)
			std::cout << "Ошибка. k должно быть меньше n!";
	} while (k > n);

	answer = Factorial(n) / Factorial(n - k);
	std::cout << "Ответ: " << answer;
}

void ArrangementsWithRepetitions()
{
	int n = 0, k = 0;
	unsigned long long answer = 0;
	std::cout << "РАЗМЕЩЕНИЕ С ПОВТОРЕНИЯМИ\n\n";
	n = EnterArg('n');
	k = EnterArg('k');
	answer = std::pow(n, k);
	std::cout << "Ответ: " << answer;
}

void CombinationsWithoutRepetitions()
{
	int n = 0, k = 0;
	unsigned long long answer = 0;
	std::cout << "СОЧЕТАНИЯ БЕЗ ПОВТОРЕНИЙ\n\n";
	n = EnterArg('n');
	do
	{
		k = EnterArg('k');
		if (k > n)
			std::cout << "Ошибка. k должно быть меньше n!";
	} while (k > n);

	answer = Factorial(n) / (Factorial(k) * Factorial(n - k));
	std::cout << "Ответ: " << answer;
}

void CombinationsWithRepetitions()
{
	int n = 0, k = 0;
	unsigned long long answer = 0;
	std::cout << "СОЧЕТАНИЯ С ПОВТОРЕНИЯМИ\n\n";
	n = EnterArg('n');
	k = EnterArg('k');
	answer = Factorial(n + k - 1) / (Factorial(k) * Factorial(n - 1));
	std::cout << "Ответ: " << answer;

}

int EnterArg(char arg)
{
	int n = 0;

	do
	{
		std::cout << "Введите " << arg << ": ";
		std::cin >> n;
		if (n <= 0)
			std::cout << "Ошибка.Введите положительное число!";
	} while (n <= 0);

	return n;
}
