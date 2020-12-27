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
		cout << "Имя студента: " << Name << "\n";
	}

private:
	string Name;
};

int main() 
{
	SetConsoleCP(1251);				/*Ввод-Вывод русских симолов в консоль*/
	SetConsoleOutputCP(1251);

	/*Начальный список студентов*/
	Student st1;			
	Student st2;
	Student st3;
	Student st4;
	Student st5;
	st1.add("Андрей");
	st2.add("Михаил");
	st3.add("Виктория");
	st4.add("Афонасий");
	st5.add("Анна");
	
	int Size = 5; /*размер начального массива указателей на студенто*/
	
	shared_ptr<Student[]>Spisok(new Student[Size]{ st1, st2, st3, st4, st5 }); /*заполнил массив указателей студентами*/
	int n = 0;  /*Переменная для определения рамера второго массива выбранных по условию студентов*/

	for (int i = 0; i < Size; i++)		
	{
		if (Spisok[i].Get_name()[0] == 'А') /*Количество студентов соответствующих условию*/
			n++;
	}
	
	shared_ptr<Student[]>Spisok2(new Student[n]);		/*Создаем массив указателей на второй список размером n */
	n = 0;

	for (int i = 0; i < Size; i++)
	{		
		if (Spisok[i].Get_name()[0] == 'А')			/*Заполняем список 2 указателями на выбранных судентов*/
		{
			Spisok2[n] = Spisok[i];
			n++;			
		};
	}

	for (int i = 0; i < n; i++)					/*Вывод на экран Spisok2*/
		cout << Spisok2[i].Get_name() << "\n";	

	system("pause");
	return 0;
}