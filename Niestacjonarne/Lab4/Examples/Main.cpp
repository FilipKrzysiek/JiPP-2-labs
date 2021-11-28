

#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

int main() {
	int flgRead = 1;

	cout << "Podaj 1 aby wczytac plik, podaj 0, aby zapisac" << endl;

	cin >> flgRead;

	if(flgRead == 0)
	{
		//Zapisywanie Danych do pliku
		Student students[] = { {"Jan", "Kowalski"}, {"Halina", "Ciep�a"}, {"Chrobry", "Zimny"}, {"Genowefa", "Kowalski"}, {"Chiacynt", "Kowalski"} };

		//Usupe�nianie student�w losowymi danymi
		for (int i = 0; i < 5; ++i) {
			students[i].changeTabValue(0, i * i - 3);
			students[i].changeTabValue(1, i *( i - 3));
			students[i].changeTabValue(2, i *( i - 3 + i));
			students[i].changeTabValue(3, i /( i - 3 + i));
			students[i].changeTabValue(4, i /(3));

			students[i].addGrade((i * i * 3) % 50);
			students[i].addGrade((i * 2 * i * 3) % 50);
			students[i].addGrade((i * 3 * i * 3) % 50);
		}

		cout << "Student oryginal" << endl;

		for (auto &stud : students)
			stud.printAllData();

	
		ofstream output("myStudents.dat", ios::out | ios::binary);

		//Zamieniamy tablic� student�w na ci�g char�w
		char* ptr = reinterpret_cast<char*>(students);

		for (int i = 0; i < sizeof(students); ++i) {
			output.put(ptr[i]);
		}
		output.close();

		size_t all = 0;
		for (auto& stud : students)
			all += stud.getSize();

		//cout << endl << "----------------------" << endl;
	} else
	{
		cout << "Podaj rozmiar klasy:" << endl;
		size_t size;
		cin >> size;
		//Wczytywanie pliku
		Student students2[5];

		ifstream input("myStudents.dat", ios::out | ios::binary);

		//Zamieniamy tablic� student�w na ci�g char�w
		char* ptr = reinterpret_cast<char*>(students2);

		for (int i = 0; i < size; ++i) {
			input.get(ptr[i]);
		}
		input.close();

		for (auto& stud : students2) {
			stud.printAllData();
		}
	}


	return 0;
}
