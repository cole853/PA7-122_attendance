/*
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/

#include "Menu.h"

//constructor
Menu::Menu()
{
	records.open("Records.csv");
	absenceFile.open("Master.txt");
	report1.open("Report1.txt");
	report2.open("Report2.txt");
	masterList = new List<Node<Data>>;
}

//destructor
Menu::~Menu()
{
	records.close();
	absenceFile.close();
	report1.close();
	report2.close();
	delete masterList;
}

void Menu::runApp()
{
	int choice = 0;

	do
	{
		if (records.is_open() && absenceFile.is_open())
		{
			choice = displayMenu();
			system("cls");

			if (choice == 1)
			{
				importCourseList();
			}
			else if (choice == 2)
			{
				loadMasterList();
			}
			else if (choice == 3)
			{
				storeMasterList();
			}
			else if (choice == 4)
			{
				markAbsences();
			}
			else if (choice == 5)
			{
				cout << "Edit absences is not complete" << endl << endl;
			}
			else if (choice == 6)
			{
				generateReport();
			}
			else if (choice == 7)
			{
				cout << "Goodbye..." << endl << endl;
			}

			if (choice != 7)
			{
				system("pause");
			}
		}
		else
		{
			cout << "One of the files did not open properly." << endl << endl;
			choice = 7;
		}

	} while (choice != 7);
}

int Menu::displayMenu()
{
	int choice = 0;

	do
	{
		system("cls");
		cout << "1.\tImport course list" << endl
			<< "2.\tLoad master list" << endl
			<< "3.\tStore master list" << endl
			<< "4.\tMark absences" << endl
			<< "5.\tEdit absences" << endl
			<< "6.\tGenerate report" << endl
			<< "7.\tExit" << endl << endl
			<< "Please enter the number corresponding to your choice: ";

		cin >> choice;
	} while (choice < 1 || choice > 7);

	return choice;
}


void Menu::importCourseList()
{
	char dummy[100];
	records.getline(dummy, 100);
	int count = 0;


	while (records.good())
	{
		Node<Data>* newNode = new Node<Data>;
		Data* newData = new Data;
		records >> newData;

		cout << newData;

		newNode->setData(newData);

		masterList->insertNode(newNode);
		count++;
	}

	cout << count << " Records have been successfully imported." << endl << endl;
}

void Menu::loadMasterList()
{
	if (!masterList->isEmpty())
	{
		Node<Data>* current = nullptr;
		Node<Data>* find = nullptr;

		while (absenceFile.good())
		{

			current = masterList->getHead();

			while (current->getNext() != find)
			{
				current = current->getNext();
			}

			find = current;

			absenceFile >> current->getData();
			cout << current->getData();
		}

		cout << "Master list has been loaded successfully!" << endl << endl;

	}
	else
	{
		cout << "Course list must be imported before loading master list." << endl << endl;
	}
}

void Menu::storeMasterList()
{
	if (!masterList->isEmpty())
	{
		if (!masterList->getHead()->getData()->getAbsencesDates()->isEmpty())
		{
			absenceFile.close();
			absenceFile.open("Master.txt");

			Node<Data>* current = nullptr;
			Node<Data>* find = nullptr; 
			bool stop = false;
			int count = 0;

			while (!stop)
			{

				current = masterList->getHead();

				while (current->getNext() != find)
				{
					current = current->getNext();
				}

				find = current;

				absenceFile << current->getData();
				++count;

				if (find == masterList->getHead())
				{
					stop = true;
				}
			}

			cout << count << " Records have been successfully stored." << endl << endl;
		}
		else
		{
			cout << "Master list must be loaded before storing it." << endl << endl;
		}
	}
	else
	{
		cout << "Course list must be imported before storing master list." << endl << endl;
	}

}

void Menu::markAbsences()
{
	if (!masterList->isEmpty())
	{
		if (!masterList->getHead()->getData()->getAbsencesDates()->isEmpty())
		{
			Node<Data>* current = masterList->getHead();
			int response = 0;

			while (current != nullptr)
			{
				do
				{
					system("cls");
					cout << "Was " << current->getData()->getName() << " absent today?" << endl
						<< "Enter 1 for yes or 2 for no." << endl;
					cin >> response;

				} while (response > 2 || response < 1);

				if (response == 1)
				{
					// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c

					time_t t = time(0);   // get time now
					struct tm* now = localtime(&t);

					/*cout << (now->tm_year + 1900) << '-'
						<< (now->tm_mon + 1) << '-'
						<< now->tm_mday
						<< endl;*/

					//end of code from stackoverflow

					string date = to_string(now->tm_mon + 1) + "/" + to_string(now->tm_mday) + "/" + to_string(now->tm_year + 1900);

					int temp = current->getData()->getAbsencesDates()->getSize();
					current->getData()->getAbsencesDates()->setSize(temp - 1);
					int tempA = current->getData()->getAbsencesNumber();
					current->getData()->setAbsencesNumber(tempA);
					current->getData()->addAbsenceDate(date);
				}

				current = current->getNext();
			}
		}
		else
		{
			cout << "Master list must be loaded before marking absences." << endl << endl;
		}
	}
	else
	{
		cout << "Course list must be imported before marking absences." << endl << endl;
	}
}

void Menu::generateReport()
{
	if (!masterList->isEmpty())
	{
		if (!masterList->getHead()->getData()->getAbsencesDates()->isEmpty())
		{
			int choice = 0;

			do
			{
				system("cls");

				cout << "1.\tGenerate report for all students" << endl
					<< "2.\tGenerate a report for students with absences above a chosen number" << endl << endl
					<< "Enter the number corresponding to your choice: ";
				cin >> choice;

			} while (choice > 2 || choice < 1);

			Node<Data>* current = masterList->getHead();

			if (choice == 1)
			{
				while (current != nullptr)
				{

					report1 << "Name: " << current->getData()->getName() << endl
						<< "Absences: " << current->getData()->getAbsencesNumber() << endl
						<< "Last absence: " << current->getData()->getAbsencesDates()->peek() << endl << endl;

					current = current->getNext();
				}

				system("cls");
				cout << "A report for all students was made in Report1.txt" << endl;
			}
			else if (choice == 2)
			{
				int choice2 = 0;
				do
				{
					system("cls");

					cout << "Enter a number to find students with equal or higher absences." << endl;
					cin >> choice2;

				} while (choice2 > 100 || choice2 < 0);

				while (current != nullptr)
				{
					if (current->getData()->getAbsencesNumber() >= choice2)
					{
						report2 << current->getData()->getName() << endl;
					}

					current = current->getNext();
				}
				system("cls");
				cout << "A report for students with equal or higher absences was made in Report2.txt" << endl;
			}
		}
		else
		{
			cout << "Master list must be loaded before generating a report." << endl << endl;
		}
	}
	else
	{
		cout << "Course list must be imported before generating a report." << endl << endl;
	}
}