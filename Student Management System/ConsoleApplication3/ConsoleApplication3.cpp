
#include "pch.h"
#include<iostream>
 
#include <fstream>
#include<string>
#include<Windows.h>
#include <thread>
#include<mmsystem.h>
#include<iomanip>

using namespace std;
struct course
{
	string id;
	string course_name;
	string instructor;
	string n_s;

}course[20];
struct studentinf
{
	string id;
	string studentename;
	string age;
	string address;
}student[20];
struct enrolled
{
	string id;
	string grade;
	string course_id;
}enrolled[20];

int size1, size2, size3;

void load_enrollments()
{
	ifstream enroll("Enrollments.txt");
	for (int i = 0; enroll.peek() != -1; i++)
	{

		getline(enroll, enrolled[i].course_id, ',');
		getline(enroll, enrolled[i].id, ',');
		getline(enroll, enrolled[i].grade);
		size1 = i;


	}
}

void load_datacourse()
{
	ifstream cou("courses.txt");
	for (int i = 0; cou.peek() != -1; i++)
	{

		getline(cou, course[i].id, ',');
		getline(cou, course[i].course_name, ',');
		getline(cou, course[i].instructor, ',');
		getline(cou, course[i].n_s);

		size2 = i;


	}

	cou.close();
}

void load_datastudent()
{
	ifstream stu("students.txt");
	for (int i = 0; stu.peek() != -1; i++)
	{

		getline(stu, student[i].id, ',');
		getline(stu, student[i].studentename, ',');
		getline(stu, student[i].age, ',');
		getline(stu, student[i].address);

		size3 = i;

	}

	stu.close();
}

void display_courses()
{
	cout << "\t Course id \t Course name \t Instructor \t\t Number of student \n";
	load_datacourse();
	for (int i = 0; i <= size2; i++)
	{
		cout << "\t" << course[i].id << "\t\t" << course[i].course_name << "\t\t" << course[i].instructor << "                  " << course[i].n_s << endl;

	}


}

void append_course()
{
	int o;
	load_datacourse();
	for (int i = size2 + 1; i < 20; i++)
	{
		cout << "Enter course id \t";
		cin >> course[i].id;
		cout << "Enter course name \t";
		cin >> course[i].course_name;
		cout << "Enter instructor \t";
		cin >> course[i].instructor;
		cout << "Enter number of student \t";
		cin >> course[i].n_s;
		cout << "1 : END \t 2 : Append Again \n";
		cin >> o;
		if (o == 1)
		{
			break;
		}
		else if (o == 2)
		{
			continue;

		}
		else
		{
			cout << "Enter right number \n";
		}

	}




}
void append_student()
{
	int x;


	load_datastudent();
	for (int i = size3 + 1; i < 20; i++)
	{
		cout << "Enter student id \t";
		cin >> student[i].id;
		cout << "Enter student name \t";
		cin >> student[i].studentename;
		cout << "Enter age of student \t";
		cin >> student[i].age;
		cout << "Enter student address \t";
		cin >> student[i].address;

		cout << "Enter ' 1 ' to END OR \t' 2 'to Append Again \n";
		cin >> x;
		if (x == 1)
		{
			break;
		}
		else if (x == 2)
		{
			continue;

		}
		else
		{
			cout << "Enter right number \n";
		}

	}
}
void append_studentcourse()
{
	load_datacourse();
	cout << "\t Course id \t Course name \t Instructor \t Number of student \n";
	for (int i = 0; i <= size2; i++)
	{

		cout << "\t" << course[i].id << "\t\t" << course[i].course_name << "\t\t" << course[i].instructor << "               " << course[i].n_s << endl;

	}

	int y;
	load_enrollments();
	for (int i = size1 + 1; i < 20; i++)
	{
		cout << "\n Enter course id \t";
		cin >> enrolled[i].course_id;
		cout << "Enter student id \t";
		cin >> enrolled[i].id;
		cout << "Enter grade \t";
		cin >> enrolled[i].grade;
		cout << "Enter 1 to end 2 to append again \t";
		cin >> y;
		if (y == 1)
		{
			break;
		}
		else if (y == 2)
		{
			continue;
		}
		else
		{
			cout << "Enter right number \n";
		}

	}

}
void delete_course()
{

	string a;

	cout << "Enter id to delete \t";
	cin >> a;


	cout << "\t course id \t course name \t Instructor \t Number of student \n";
	load_datacourse();
	for (int i = 0; i < 20; i++)
	{
		if (course[i].id.find(a) != string::npos)
		{
			int v = i;
			cout << "\t" << course[i].id << "\t\t" << course[i].course_name << "\t\t" << course[i].instructor << "\t" <<
				course[i].n_s << endl;

			for (int i = v; i < 20; i++)
			{
				course[i] = course[i + 1];
			}



			cout << "Done \n";
		}

	}


}


void edit()
{
	
	cout << "Do you want edit student(1) or course(2) \t";
	int w;
	cin >> w;
	int b;
	if (w == 1)
	{
		string a, q, r, w, y;



		load_datastudent();
		cout << "Enter id to search \t";
		cin >> a;
		cout << "\t Student id \t Student name \t Student Age \t Student address \n";
		for (int i = 0; i < 20; i++)
		{

			if (student[i].id.find(a) != string::npos)
			{
				cout << "\t" << student[i].id << "\t\t" << student[i].studentename << "\t" << student[i].age << "\t\t" <<
					student[i].address << endl;




				cout << " to edit in id (1) name (2) age (3) address (4) \n";
				cin >> b;
				switch (b)
				{
				case 1:
					cout << "Enter new id \t";
					cin >> q;
					student[i].id = q;
					break;
				case 2:
					cout << "Enter new name \t";
					cin >> r;
					student[i].studentename = r;
					break;
				case 3:
					cout << "Enter new age \t";
					cin >> w;
					student[i].age = w;
					break;
				case 4:
					cout << "Enter new address \t";
					cin >> y;
					student[i].address = y;
					break;

				default:
					cout << "Enter right number \n";
					break;
				}

				break;
			}
		}

	}
	else if (w = 2)
	{
		int cont;
		string z, x, c, v, n, p;
		cout << "Enter id to search \t";
		cin >> p;
		cout << "\t course id \t course name \t Instructor \t Number of student \n";
		load_datacourse();
		for (int i = 0; i <= size1; i++)
		{
			if (course[i].id.find(p) != string::npos)
			{
				cout << "\t" << course[i].id << "\t\t" << course[i].course_name << "\t\t" << course[i].instructor << "\t" <<
					course[i].n_s << endl;

				cout << "Do you want to edit in course id (1) course name (2) Instructor (3) Number of student (4) \n";
				cin >> cont;
				switch (cont)
				{
				case 1:
					cout << "Enter new id \t";
					cin >> z;
					course[i].id = z;
					break;
				case 2:
					cout << "Enter new course name \t";
					cin >> x;
					course[i].course_name = x;
					break;
				case 3:
					cout << "Enter new instructor \t";
					cin >> c;
					course[i].instructor = c;
					break;
				case 4:
					cout << "Enter new number of student \t";
					cin >> v;
					course[i].n_s = v;
					break;

				default:
					cout << "Enter right number \n";
					break;
				}

				break;
			}

		}
	}

}
void display_students()
{
	cout << " \t Student id \t Student name \t Student age \t Student address \n";
	load_datastudent();
	for (int i = 0; i < size3; i++)
	{
		cout << "\t" << student[i].id << "\t\t" << student[i].studentename << "\t" << student[i].age << "\t\t" << student[i].address << endl;
	}


}
void search_course()
{

	string x;
	cout << "Enter id to search \t";
	cin >> x;
	load_datacourse();
	load_enrollments();
	load_datastudent();



	for (int i = 0; i < 20; i++)
	{

		if (course[i].id.find(x) != string::npos)
		{
			cout << "\t Course id \t Course name \t Instructor \t\t Number of student \n";
			cout << "\t" << course[i].id << "\t\t" << course[i].course_name << "\t\t" << course[i].instructor << "                   " << course[i].n_s << endl;
		}

	}
	cout << "----------------------------------------------------------------- \n";
	cout << "\n   Grade  \t";
	int n = 0;

	string arr[100];
	for (int j = 0; j < 20; j++)
	{
		if (enrolled[j].course_id.find(x) != string::npos)
		{

			cout << "\t" << enrolled[j].grade;
			arr[n] = enrolled[j].id;
			n++;

		}

	}

	string s;
	n = 0;
	cout << "\n Srudent name ";
	for (int q = 0; q < size3; q++)
	{
		for (int k = 0; k <= size3; k++)
		{
			s = arr[n];

			if (student[k].id == s)
			{
				cout << "\t" << student[k].studentename;
				n++;
			}

		}
	}







	cout << "\n";



}
void display_enrollmens()
{
	cout << "\t Course id \t Student id \t Grade \n";
	load_enrollments();
	for (int i = 0; i <= size1; i++)
	{
		cout << "\t" << enrolled[i].course_id << "\t\t" << enrolled[i].id << "\t\t" << enrolled[i].grade << endl;

	}


}
void delete_student()
{

	string l;

	cout << "Enter student id \t";
	cin >> l;
	cout << "\t Student id \t Student name \t Student Age \t Student address \n";
	load_datastudent();

	for (int i = 0; i < 20; i++)
	{
		if (student[i].id.find(l) != string::npos)
		{
			int g = i;
			cout << "\t" << student[i].id << "\t\t" << student[i].studentename << "\t" << student[i].age << "\t\t" <<
				student[i].address << endl;
			for (int i = g; i < 20; i++)
			{
				student[i] = student[i + 1];
			}


		}



	}


	cout << "Done \n";
}

void search_student()
{
	string arr[100];
	string k;
	int r = 0, a;
	cout << "Enter student id \t";
	cin >> k;
	load_enrollments();
	for (int i = 0; i < 20; i++)
	{
		if (enrolled[i].id.find(k) != string::npos)
		{
			cout << "\t" << enrolled[i].course_id << endl;
			arr[r] = enrolled[i].course_id;
			r++;
			a = r;
		}

	}
	r = 0;
	load_datacourse();
	for (int q = 0; q < size2; q++)
	{
		for (int w = 0; w <= size2; w++)
		{
			string e = arr[r];
			if (course[w].id == e)
			{
				cout << course[w].course_name << endl;
				r++;
			}


		}
	}



}

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << setw(78) << "-----------------------------------------" << endl;

	cout << setw(78) << "Course Management System \n";

	cout << setw(78) << "-----------------------------------------" << endl;
	bool flage = true;
	while (flage) {

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


		load_datacourse();
		load_datastudent();
		load_enrollments();

		int a, b, c, g;
		cout << setw(60) << "DEAR USER" << endl;
		cout << setw(75) << ">>---------------------------------<<" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << setw(70) << "1 : Manager \t 2 : Student \n";
		cin >> a;
		if (a == 1)
		{

			cout << "\t 1 : Append student \t 2 : Append course \t 3 : Append New Student to a Specific course \t 4 : Edit \t 5 : Delete student \t 6 : Delete course \t 7 : Search course \t 8 : Search student \t 9 : Display\n";
			cin >> b;
			switch (b)
			{

			case 1:
				system("cls");
				append_student();
				size3++;
				break;

			case 2:
				system("cls");
				append_course();
				size2++;
				break;

			case 3:
				system("cls");
				append_studentcourse();
				size1++;
				break;

			case 4:
				system("cls");

				edit();
				break;

			case 5:
				system("cls");
				delete_student();
				size3--;
				break;
			case 6:
				system("cls");
				delete_course();
				size2--;
				break;
			case 7:
				system("cls");
				search_course();
				break;
			case 8:
				system("cls");
				search_student();
				break;
			case 9:
				system("cls");

				cout << "1 : Display course \t 2 : Display student \t 3 : Dislay Enrollments \n";
				cin >> g;
				if (g == 1)
				{
					display_courses();
				}
				else if (g == 2)
				{
					display_students();
				}
				else if (g == 3)
				{
					display_enrollmens();
				}
				else
				{
					cout << "Enter right number \n";
				}

				break;
			default:
				cout << "Enter right number !!! \n";
			}

		}
		else if (a == 2)
		{

			cout << "1 : Display \t 2 : Search course \t 3 : Search student \n";
			cin >> c;
			switch (c)
			{
			case 1:
				cout << " 1 : Display course \t 2 : Display student \t 3 :  Dislay Enrollments \n";
				cin >> g;
				if (g == 1)
				{
					display_courses();
				}
				else if (g == 2)
				{
					display_students();
				}
				else if (g == 3)
				{
					display_enrollmens();
				}
				else
				{
					cout << "Enter right number \n";
				}
				break;
			case 2:
				search_course();
				break;
			case 3:
				search_student();
				break;

			default:
				cout << "Enter right number !!! \n";
			}
		}
		else
		{
			cout << "Enter right number !!! \n";
		}





		ofstream cou("courses.txt");
		ofstream stu("students.txt");
		ofstream enroll("Enrollments.txt");

		for (int i = 0; i <= size2; i++)
		{
			cou << course[i].id << "," << course[i].course_name << "," << course[i].instructor << "," << course[i].n_s << endl;
		}
		for (int g = 0; g <= size3; g++)
		{
			stu << student[g].id << "," << student[g].studentename << "," << student[g].age << "," << student[g].address << endl;
		}

		for (int n = 0; n <= size1; n++)
		{
			enroll << enrolled[n].course_id << "," << enrolled[n].id << "," << enrolled[n].grade << endl;
		}


		cout << " if you want to countine press 'y ' \n";
		char y;
		cin >> y;
		if (y == 'y' || y == 'Y') {
			system("cls");
			continue;
		}
		else {
			break;
		}


	}



	return 0;
}