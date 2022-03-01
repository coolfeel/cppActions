#include <iostream>
#include <fstream>
#include <cstdio>


using namespace std;


class Student
{
	char name[20];
	char grade[5];
	char address[25];
	char course[20];
	char section[5];
	char birthday[9];
	int admin;
	
	void displayInformation();

	public:
		void inputInformation();
		void readInformation();
		void writeInformation();
		void searchInformation();
		void deleteInformation();
		void updateInformation();
}stu;




int main()
{
	int choice;
	char end = 'n';

	do
	{
		cout << "Student Information:\n";
		cout << "********************************************\n";
		cout << "*  1. View student details\n";
		cout << "*  2. Add new student details\n";
		cout << "*  3. Search a student record\n";
		cout << "*  4. Delete a student record\n";
		cout << "*  5. Update a student record\n";
		cout << "********************************************\n";
		cout << "Enter your choice:\n";

		cin >> choice;

		switch (choice)
		{
			case 1:
				stu.readInformation();
				break;
			case 2:
				stu.writeInformation();
				break;
			case 3:
				stu.searchInformation();
				break;
			case 4:
				stu.deleteInformation();
				break;
			case 5:
				stu.updateInformation();
				break;

			default:
			{
				cout << "error" << endl;
			}
			break;
		}


	} while (end == 'y');






	return 0;
}


void Student::displayInformation()
{
	cout << "！！！！StudentInformation！！！！:" << endl;
	cout << "name:" << name << endl;
	cout << "grade:" << grade << endl;;
	cout << "address:" << address << endl;
	cout << "course:" << course << endl;
	cout << "section:" << section <<endl;
	cout << "birthday:" << birthday << endl;
	cout << "admission number:" << admin << endl;
}



void Student::inputInformation()
{
	puts("enter name:");
	cin >> name;

	puts("enter grade:");
	cin >> grade;

	puts("enter address:");
	cin >> address;

	puts("enter course:");
	cin >> course;

	puts("enter section:");
	cin >> section;

	puts("enter birthday:");
	cin >> birthday;
	
	puts("enter admission number:");
	cin >> admin;
}




void Student::readInformation()
{
	ifstream ifile;
	ifile.open("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\test.txt");
	ifile.seekg(0, ios::beg);
	ifile.read((char*)&stu, sizeof(stu));
	
	while (ifile)
	{
		displayInformation();
		ifile.read((char*)&stu, sizeof(stu));
	}
	ifile.close();


}


void Student::writeInformation()
{
	ofstream ofile;
	ofile.open("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\test.txt", ios::app);
	inputInformation();
	ofile.write((char*)&stu, sizeof(stu));
	ofile.close();
}



void Student::searchInformation()
{
	char search_name[20];
	ifstream ifile;
	ifile.open("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\test.txt");

	cout << "Enter name of student which has to be searched" << endl;
	cin >> search_name;

	ifile.seekg(0, ios::beg);
	ifile.read((char*)&stu, sizeof(stu));

	while (ifile)
	{
		if (strcmp(search_name, name) == 0)
		{
			displayInformation();
		}	
		ifile.read((char*)&stu, sizeof(stu));
	}
	ifile.close();
}

void Student::deleteInformation()
{
	char delete_name[20];
	ifstream ifile;
	ifile.open("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\test.txt", ios::app);
	
	ofstream ofile;
	ofile.open("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\new.txt", ios::app);
	
	cout << "Enter the name of the student whose records you want to delete" << endl;
	cin >> delete_name;
	
	ifile.seekg(0, ios::beg);
	ifile.read((char*)&stu, sizeof(stu));

	while (ifile)
	{
		if (strcmp(delete_name, name))
		{
			ofile.write((char*)&stu, sizeof(stu));
		}	
		ifile.read((char*)&stu, sizeof(stu));
	}
	ifile.close();
	ofile.close();
	remove("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\test.txt");
	rename("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\new.txt", "F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\test.txt");
}


void Student::updateInformation()
{
	char update_name[20];
	int mode;

	cout << "\nEnter name of student whose record you want to modify\n" << endl;
	cin >> update_name;

	fstream f;
	f.open("F:\\study\\Projects\\cppProjects\\cppActions\\StuManageSystem\\SMS\\Debug\\test.txt", ios::in | ios::out);
	f.seekg(0, ios::beg);
	f.read((char*)&stu, sizeof(stu));

	int a = f.tellg();
	while (!f.eof())
	{
		if (!strcmp(update_name, name))
		{
			puts("\nPress 1 to change name\nPress 2 to change grade\nPress 3 to change address\nPress 4 to change course\n Press 5 to change section\nPress 6 to change birthday\nPress 7 to change admin\n");
			cin >> mode;

			switch (mode)
			{
				case 1:
					cin >> name;
					break;
				case 2:
					cin >> grade;
					break;
				case 3:
					cin >> address;
					break;
				case 4:
					cin >> course;
					break;
				case 5:
					cin >> section;
					break;
				case 6:
					cin >> birthday;
					break;
				case 7:
					cin >> admin;
					break;
				default:
				{
					cout << "error" << endl;
				}
				break;
			}
			f.seekg(a - sizeof(stu), ios::beg);
			f.write((char*)&stu, sizeof(stu));
		}
		f.read((char*)&stu, sizeof(stu));
		a = f.tellg();
	}
	f.close();
}