#include <iostream>
#include <cctype>

using std::cout;
using std::cin;

namespace Exeptions
{
	const char uaExept[12] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
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
	bool operator == (char n) //������� ��������� ���� ��� ���������� ������� � ������ ������ ���������, �� 
	{						  //�� ������ ������ �������� true ���� �� ��� ����� �� false
		int inLeft = 0;
		int inRight = 0;

		for (int i = 0; i < 12; ++i)	//�������� �������� ���������� ������ �������� ���������� ��� ����������
		{
			if (Exeptions::uaExept[i] == letter)
			{
				inLeft = i + 1;
				break;
			}
		}

		for (int i = 0; i < 12; ++i)	//�������� �������� ���������� ������ �������� ���������� ���� ����������
		{
			if (Exeptions::engExept[i] == letter)
			{
				inLeft = i + 1;
				break;
			}
		}

		if (inLeft == 0)
		{
			return 0; //�������� ���� ������ ������� �� �������� �������� ����������
		}

		for (int i = 0; i < 12; ++i) //�������� ��������� ������� �� ����� ���������� ��� ���������
		{
			if (Exeptions::engExept[i] == n)
			{
				inRight = i + 1;
				break;
			}
		}

		for (int i = 0; i < 12; ++i) //�������� ��������� ������� �� ����� ���������� ��� ���������
		{
			if (Exeptions::uaExept[i] == n)
			{
				inRight = i + 1;
				break;
			}
		}

		if (--inLeft == --inRight)  //��������� �� ���������� ��������
		{
			return true;
		}
		else
		{

			return false;
		}
	}

	bool operator != (char n) //�������� ������� �� ��������� � ==, ���� ������� ����� ����� ����� false
	{
		int inLeft = 0;
		int inRight = 0;
		bool engOBJ = false;
		bool engIN = false;

		for (int i = 0; i < 12; ++i)	//�������� �������� ���������� ������ �������� ���������� ��� ����������
		{
			if (Exeptions::uaExept[i] == letter)
			{
				inLeft = i + 1;
				break;
			}
		}

		for (int i = 0; i < 12; ++i)	//�������� �������� ���������� ������ �������� ���������� ���� ����������
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
			else return false;       //�������� ���� ������ ������� �� �������� �������� ����������
		}

		for (int i = 0; i < 12; ++i) //�������� ��������� ������� �� ����� ���������� ��� ���������
		{
			if (Exeptions::engExept[i] == n)
			{
				inRight = i + 1;
				engIN = true;
				break;
			}
		}

		for (int i = 0; i < 12; ++i) //�������� ��������� ������� �� ����� ���������� ��� ���������
		{
			if (Exeptions::uaExept[i] == n)
			{
				inRight = i + 1;
				break;
			}
		}

		if (--inLeft != --inRight)  //��������� �� ���������� ��������
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

	SpecialSymbol symbol('�');
	char b = 'K';

	cout << (symbol == b) << std::endl;
	cout << (symbol != b) << std::endl;


	return 0;
}