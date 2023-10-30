#include <iostream>
#include <cctype>

using std::cout;
using std::cin;

namespace Exeptions
{
	const char uaExept[12] = { 'О', 'А', 'І', 'Е', 'Н', 'С', 'В', 'К', 'Р', 'Х', 'Т', 'М' };
	const char engExept[12] = { 'O', 'A', 'I', 'E', 'H', 'C', 'B', 'K', 'P', 'X', 'T', 'M' };
}


class SpecialSymbol
{
private:
	char letter;

public:
	SpecialSymbol(char a) :
		letter(a) {}

	void setLetter()
	{
		cout << "Enter new letter" << std::endl;
		cin >> letter;
	}
	char getLetter()
	{
		return letter;
	}
	bool operator == (char n) //Функция проверяет если два одинаковых символа с разных языков одинаковы, то 
	{						  //то функия вернет значение true если же они разны то false
		int inLeft = 0;
		int inRight = 0;

		for (int i = 0; i < 12; ++i)	//Проверка является переменная объета символом исключения укр расскладки
		{
			if (Exeptions::uaExept[i] == letter)
			{
				inLeft = i + 1;
				break;
			}
		}

		for (int i = 0; i < 12; ++i)	//Проверка является переменная объета символом исключения англ расскладки
		{
			if (Exeptions::engExept[i] == letter)
			{
				inLeft = i + 1;
				break;
			}
		}

		if (inLeft == 0)
		{
			return 0; //Поправка если символ объекта не является символом исключения
		}

		for (int i = 0; i < 12; ++i) //Проверка входящего символа на сивол исключения анг раскладки
		{
			if (Exeptions::engExept[i] == n)
			{
				inRight = i + 1;
				break;
			}
		}

		for (int i = 0; i < 12; ++i) //Проверка входящего символа на сивол исключения укр раскладки
		{
			if (Exeptions::uaExept[i] == n)
			{
				inRight = i + 1;
				break;
			}
		}

		if (--inLeft == --inRight)  //Проверака на совпадение символов
		{
			return true;
		}
		else
		{

			return false;
		}
	}

	bool operator != (char n) //Обратная функция по отношению к ==, если символы равны вывод будет false
	{
		int inLeft = 0;
		int inRight = 0;
		bool engOBJ = false;
		bool engIN = false;

		for (int i = 0; i < 12; ++i)	//Проверка является переменная объета символом исключения укр расскладки
		{
			if (Exeptions::uaExept[i] == letter)
			{
				inLeft = i + 1;
				break;
			}
		}

		for (int i = 0; i < 12; ++i)	//Проверка является переменная объета символом исключения англ расскладки
		{
			if (Exeptions::engExept[i] == letter)
			{
				inLeft = i + 1;
				engOBJ = true;
				break;
			}
		}

		if (inLeft == 0)
		{
			if (letter != n) return true;
			else return false;       //Поправка если символ объекта не является символом исключения
		}

		for (int i = 0; i < 12; ++i) //Проверка входящего символа на сивол исключения анг раскладки
		{
			if (Exeptions::engExept[i] == n)
			{
				inRight = i + 1;
				engIN = true;
				break;
			}
		}

		for (int i = 0; i < 12; ++i) //Проверка входящего символа на сивол исключения укр раскладки
		{
			if (Exeptions::uaExept[i] == n)
			{
				inRight = i + 1;
				break;
			}
		}

		if (--inLeft != --inRight)  //Проверака на совпадение символов
		{
			return true;
		}
		else
		{
			return false;
		}

	}
};

int main()
{
	system("chcp 1251");
	std::cout << std::boolalpha;

	SpecialSymbol symbol('К');
	char b = 'K';

	cout << (symbol == b) << std::endl;
	cout << (symbol != b) << std::endl;


	return 0;
}