/* Курсова работа (проект) за виртуална информационна система продажба на монитори

// Програма KR_Monitoricpp 
// Автор на варианта на програма: Танжу Тюршанов Мехдиев Фак№ 19621684.

/* Програма за моделиране на виртуална информационна система за продажба на монитори.
   Програмата оперира с двоичен файл с пряк достъп и масив от структури с данни за продажба на монитори:
   сериен номер, марка, модел, цвят,цена, диагонала екрана, разделителна способност,вграден TV тунер, тип, статус, промоция.
   Чрез избор от основно меню се реализира:
		- Създаване и записване данни за продажба на монитори в двоичен файл с пряк достъп;
		- Допълване във файл информация за продажба на монитори ;
		- Извеждане на сортиране по сериен номер;
*/


#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

int const K = 100;  // максимален брой монитори.
const char NAME[] = "Prodajba_na_monitori.dat";  // Име на файла

// Деклариране на данни от тип структура с име Prodajba_na_monitori
struct Prodajba_na_monitori 
{
	int Seria_Number;
	char Marka[10];
	char Model[10];
	char Color[10];
	double Price;
	double Diagonal_screen;
	char Resolution[10];
	char Built_in_TV_Tuner[5];
	char Type[20];
	char Status[20];
	char Promociq[20];
};
Prodajba_na_monitori  *ps[K];

long getSizeOfFile();
void writeToFile(struct Prodajba_na_monitori val[]);
void showmonitori(Prodajba_na_monitori val);
void showAll(struct Prodajba_na_monitori val[]);
void addtoEnd();
void sale_monitor(struct Prodajba_na_monitori val[]);
void order(struct Prodajba_na_monitori *po,int K);
int main()
{
	// Текст в заглавната лента на прозореца на конзолата
	system("title Програма за моделиране на виртуална информационна система за продажба на монитори. ");
	system("chcp 1251"); // За текст на кирилица
	system("cls");

	struct Prodajba_na_monitori val[K];  // Дефиниране на масив от структури - данни за продажба на монитори
	int choice;    // За избор от меню
	do {
		do {   // Валидация на избора от меню, представено с псевдо графика на монитори
			system("cls");

			cout << "  1. Създаване на файл\n";
			cout << "  2. Визуализиране на всички монитори\n";
			cout << "  3. Добавяне на монитор\n";
		    cout << "  4. Продажба на монитори\n";
			cout << "  5. Сортиране по сериен номер\n";
			cout <<	"  6. Автор\n";
			cout << "  7. Изход\n" ;


            cout << "\n\t Въведете избора си от 1 до 7: ";
			cin >> choice;
			cout << endl << endl << endl;
		} while (choice < 1 || choice>7);
		switch (choice)    // Избор на съответна функция от менюто
		{
		case 1: writeToFile(val); 
			break;
		case 2: showAll(val); 
			break;
		case 3: addtoEnd(); 
			break;
		case 4: sale_monitor(val); 
			break;
		case 5:order(val,K);
			break;
		case 6: { system("cls");
			// "Авторски подпис" на екрана
			cout << "\n Програмата е създадена от Танжу Тюркшанов Мехдиев Фак №19621684 група 1а \n\n";
			system("pause"); 
			break; }
		case 7:exit(0); 
			break;
		default: cout << "Въвели сте некоректно. Опитайте пак \n"; system("pause"); 
			break;
		}
	} while (choice != 8);

	return 0;

}

// Функция за размер на файла (байтове)
long getSizeOfFile()
{
	system("cls");
	long size;   // Променлива за размер
	fstream fp;  // Файл с име fp
	fp.open(NAME, ios::in | ios::binary);  // Отваряне като входен двоичен файл
	if (!fp) {                              // Проверка за коректно отваряне
		cout << "Грешка при опит за отваряне на  файла " << endl;
	}
	fp.seekg(01, ios::end);  // Позициониране в текущия край на файла
	size = fp.tellg();
	fp.close();

	return size;
}

// Функция за записване на данни за продажба на монитори във файла
void writeToFile(struct Prodajba_na_monitori val[])
{
	fstream fp;
	int k;  // Променлива за брой монитори.
	do {     // Валидация на въвеждания брой монитори.
		cout << "Колко монитори искате да въведете (до 100) : ";
		cin >> k;
	} while (k < 0 || k >100);
	fp.open(NAME, ios::binary | ios::out);
	if (!fp)
	{
		cout << endl << "Грешка при отваряне на файл" << endl;
		exit(1);
	}
	for (int i = 0; i < k; i++)  // Цикъл за въвеждане на брой монитори.
	{
		cin.ignore(1000, '\n');
		system("cls");
		cout << endl << "Seria Number: ";
		cin>>val[i].Seria_Number;
		cin.ignore();

		cout << endl << "Marka: ";
		cin.getline(val[i].Marka, 10);

		cout << endl << "Model: ";
		cin.getline(val[i].Model, 10);

		cout << endl << "Color: ";
		cin.getline(val[i].Color, 10);

		cout << endl << "Price: ";
		cin>>val[i].Price;

		cout << endl << "Diagonal_screen: ";
		cin>>val[i].Diagonal_screen;

		cin.ignore();

		cout << endl << "Resolution: ";
		cin.getline(val[i].Resolution, 10);

		cout << endl << "Built-in TV tuner: ";
		cin.getline(val[i].Built_in_TV_Tuner, 5);

		cout << endl << "Type: ";
		cin.getline(val[i].Type, 20);

		cout << endl << "Status: ";
		cin.getline(val[i].Status, 20);

		cout << endl << "Promotion: ";
		cin.getline(val[i].Promociq, 20);


	}
	fp.write((char*)val, k * sizeof(Prodajba_na_monitori));  // Записване на данни за монитори във файла
	fp.close();
}

// Функция за извеждане информация за продажба на монитори.
void showmonitori(Prodajba_na_monitori val) 
{
	cout << endl << "Seria Number:" << val.Seria_Number;
	cout << endl << "Marka:" << val.Marka;
	cout << endl << "Model:" << val.Model;
	cout << endl << "Color:" << val.Color;
	cout << endl << "Price:" << val.Price;
	cout << endl << "Diagonal screen:" << val.Diagonal_screen;
	cout << endl << "Resolution:" << val.Resolution;
	cout << endl << "Built-in TV tuner:" << val.Built_in_TV_Tuner;
	cout << endl << "Type:" << val.Type;
	cout << endl << "Status:" << val.Status;
	cout << endl;

}

// Функция за показване на всички данни от файла за монитори
void showAll(struct Prodajba_na_monitori val[])
{
	Prodajba_na_monitori per;  // Зa един монитор
	fstream fp;
	long size_file;       // Размер на файла

	size_file = getSizeOfFile();

	fp.open(NAME, ios::in | ios::binary);
	if (!fp) {
		cout << "Грешка при опит за отваряне на  файла " << endl;
	}

	// Цикъл за извеждане на екрана на всички монитори
	for (int i = 0; i < size_file / sizeof(Prodajba_na_monitori); i++) {
		fp.read((char*)&per, sizeof(Prodajba_na_monitori));
		val[i] = per;
		showmonitori(val[i]);
	}

	fp.close();
	system("pause");
}

// Функция за  добавяне на монитор към края на файла
void addtoEnd()
{
	system("cls");
	Prodajba_na_monitori pp;  // Променлива от типа стуктура

	fstream fp;

	fp.open(NAME, ios::out | ios::app | ios::binary); // Отваряне на файла за добавяне на монитор
	if (!fp)
	{
		cout << endl << "Грешка при отваряне на файла" << endl;
		exit(1);
	}

	cin.ignore();

	cout << endl << "Seria Number: ";
		cin>>pp.Seria_Number;
		cin.ignore();

		cout << endl << "Marka: ";
		cin.getline(pp.Marka, 10);

		cout << endl << "Model: ";
		cin.getline(pp.Model, 10);

		cout << endl << "Color: ";
		cin.getline(pp.Color, 10);

		cout << endl << "Price: ";
		cin>>pp.Price;

		cout << endl << "Diagonal_screen: ";
		cin>>pp.Diagonal_screen;

		cin.ignore();

		cout << endl << "Resolution: ";
		cin.getline(pp.Resolution, 10);

		cout << endl << "Built-in TV tuner: ";
		cin.getline(pp.Built_in_TV_Tuner, 5);

		cout << endl << "Type: ";
		cin.getline(pp.Type, 20);

		cout << endl << "Status: ";
		cin.getline(pp.Status, 20);

		cout << endl << "Promotion: ";
		cin.getline(pp.Promociq, 20);
	fp.write((char*)&pp, sizeof(Prodajba_na_monitori)); // Записване (добавяне) на монитор във файла
	fp.close();
}

// Функция за продажба на монитои
void sale_monitor(struct Prodajba_na_monitori val[])
{
	system("cls");
	long size_file;
	char Marka1[10];// Търсене по марка и модел
	char Model1[10];
	int Seria_number;
	int Kaparo;
	fstream fp;
	Prodajba_na_monitori per;  // Променлива от типа стуктура 
	bool syvpadenie;      // Логическа променлива за съвпадение
	string again;

	size_file = getSizeOfFile();

	do {                   // Цикъл със запитване за ново търсене
		syvpadenie = false;

		fp.open(NAME, ios::in | ios::binary);
		if (!fp) {
			cout << "Грешка при опит за отваряне на  файла " << endl;
		}

		system("cls");
		cin.ignore();
		cout << "Въведете марката и модела на монитора " << endl;
		cout<<"Marka:";
		cin.getline(Marka1, 10);
		cout<<"Model:";
		cin.getline(Model1, 10);

		// Цикъл за прочитане на данните от файла
		for (int i = 0; i < size_file / sizeof(Prodajba_na_monitori); i++) 
		{
			fp.read((char*)&per, sizeof(Prodajba_na_monitori));
			val[i] = per;

			if (strcmp(val[i].Marka, Marka1) == 0) 
			{

				cout << "Има съвпадение" << endl;
				showmonitori(val[i]);
				syvpadenie = true;
				cout<<endl;
			}
		}
		if (!syvpadenie) {
			cout << "Няма такъв монитор. " << endl;
		}
		fp.close();
		cout << "Искате ли да направите ново търсене(Y/N) \n";
		cin >> again;
		cin.ignore();
		cout << "Въведете серийния номер на искания монитор" << endl;
		cin>>Seria_number;
			for (int i = 0; i < size_file / sizeof(Prodajba_na_monitori); i++) 
			{
			fp.read((char*)&per, sizeof(Prodajba_na_monitori));
			val[i] = per;

			if (val[i].Seria_Number==Seria_number) 
			{

				cout << "Има съвпадение" << endl;
				showmonitori(val[i]);
				syvpadenie = true;
			}
		}
			for (int i = 0; i < 1 ; i++) 
			{
			fp.read((char*)&per, sizeof(Prodajba_na_monitori));
			val[i] = per;
			cout<<endl;
			
			
			cout<<"Въведете капарото:";
				cin>>Kaparo;
				val[i].Price=val[i].Price-Kaparo;
			}
		
		fp.close();

		cout << "Искате ли да направите ново търсене(Y/N) \n";
		cin >> again;
		

	} while (again == "Y" || again == "y");
	system("pause");
}
void order(struct Prodajba_na_monitori *po,int K)
{
	Prodajba_na_monitori *p, *pend, work;
	int change, flag=1;
	change=0;
	while(flag!=0)
	{
		flag=0;
		change++;
		pend=po+K-change;
		for(p=po;p<pend;p++)
			if(p->Seria_Number>(p+1)->Seria_Number)
			{
				work=*p;
					*p=*(p+1);
					*(p+1)=work;
					flag=1;
			}
	}
}