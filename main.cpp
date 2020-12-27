#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>

using namespace std;

class Student
{
public:
	Student()
	{
	};
	void add(string name)
	{
		Name = name;
	}
	~Student() 
	{
	};

	string Get_name()
	{
		return Name;
	}

	void Print()
	{
		cout << "��� ��������: " << Name << "\n";
	}

private:
	string Name;
};

int main() 
{
	SetConsoleCP(1251);				/*����-����� ������� ������� � �������*/
	SetConsoleOutputCP(1251);

	/*��������� ������ ���������*/
	Student st1;			
	Student st2;
	Student st3;
	Student st4;
	Student st5;
	st1.add("������");
	st2.add("������");
	st3.add("��������");
	st4.add("��������");
	st5.add("����");
	
	int Size = 5; /*������ ���������� ������� ���������� �� ��������*/
	
	shared_ptr<Student[]>Spisok(new Student[Size]{ st1, st2, st3, st4, st5 }); /*�������� ������ ���������� ����������*/
	int n = 0;  /*���������� ��� ����������� ������ ������� ������� ��������� �� ������� ���������*/

	for (int i = 0; i < Size; i++)		
	{
		if (Spisok[i].Get_name()[0] == '�') /*���������� ��������� ��������������� �������*/
			n++;
	}
	
	shared_ptr<Student[]>Spisok2(new Student[n]);		/*������� ������ ���������� �� ������ ������ �������� n */
	n = 0;

	for (int i = 0; i < Size; i++)
	{		
		if (Spisok[i].Get_name()[0] == '�')			/*��������� ������ 2 ����������� �� ��������� ��������*/
		{
			Spisok2[n] = Spisok[i];
			n++;			
		};
	}

	for (int i = 0; i < n; i++)					/*����� �� ����� Spisok2*/
		cout << Spisok2[i].Get_name() << "\n";	

	system("pause");
	return 0;
}