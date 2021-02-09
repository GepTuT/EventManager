#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Event.h"

class BinTree :	Event {
	class Node;
public:
	BinTree(){
		root = NULL;
	}

	bool isEmpty(Node* root) {
		return(root == NULL);
	}

	

	void add_Node(Event* NewEvent, int m_sort) {
		add_event(NewEvent, m_sort);
		SavetoFile("my_notebook.tmp");
	}

	void del_Node(int event_num)
	{
		remove(event_num, root,&root);
		SavetoFile("my_notebook.tmp");
	}
	
	void show_all_Tree() {
		case_sort_filtr();
	}

	bool SavetoFile(std::string file_name) {
		my_file = fopen(file_name.c_str(), "w");
		if (my_file == NULL) {
			return false;
		}
		Save_to_File(root);
		fclose(my_file);
		return true;
	}

	bool LoadfromFile(std::string file_name) {
		my_file = fopen(file_name.c_str(), "r");
		if (my_file == NULL) {
			return false;
		}
		Load_from_File(root);
		SavetoFile("my_notebook.tmp");
		fclose(my_file);
		return true;
	}

	void Random_Tree() {
		random_event();
		SavetoFile("my_notebook.tmp");
	}
	
private:


	void add_event(Event* newEvent,int m_sort) {
		int k = 1;
		std::string Description;
		std::string Place;
		int day, month, year,imp,hour,min;
		std::cout<<"What is event date?\n";
		while (k != 0) {
			std::cout << "Day\n";
			std::cin >> day;
			std::cout << "Month\n";
			std::cin >> month;
			std::cout << "Year\n";
			std::cin >> year;
			if ((day < 1 || day > 31) || (month < 1 || month > 12) || (year < 0 || year > 3000))
				std::cout<<"Wrong input. Enter the date correctly\n";
			else {
				k = 0;
				newEvent->SetDay(day);
				newEvent->SetMonth(month);
				newEvent->SetYear(year);
			}
			//printf("%d:%d:%d\n", newevent->day, newevent->month, newevent->year);
		}
		std::cout << "What hour and minute of the event?\n";
		k = 1;
		while (k != 0) {
			std::cout << "Hour\n";
			std::cin >> hour;
			std::cout << "Minutes\n";
			std::cin >> min;
			if ((hour < 0 || hour > 23) || (min < 0 || min > 59))
				std::cout << "Wrong time. Enter time correctly\n";
			else {
				k = 0;
				newEvent->SetHour(hour);
				newEvent->SetMin(min);
			}
		}
		std::cout << "How this important? From 0 to 10\n";
		k = 1;
		while (k != 0) {
			std::cin>>imp;
			if (imp < 0 || imp > 10)
				std::cout << "Wrong importance. Enter importance correctly\n";
			else {
				k = 0;
				newEvent->SetImportant(imp);
			}
			
		}
		std::cout << "What is event place?\n";
		std::cin >> Place;
		newEvent->SetPlace(Place);
		std::cout << "What is event?\n";
		std::cin.ignore();
		getline(std::cin,Description);
		
		newEvent->SetDescription(Description);
		// save to tree
		
		root = insert(newEvent, sort_type, this->root);
	}


	Node* insert(Event* NewEvent, int m_sort, Node *rootNode) {
		if (isEmpty(rootNode)) {
			rootNode = new Node;
			rootNode->Event = NewEvent;
			rootNode->Left = NULL;
			rootNode->Right = NULL;
			//*this = rootNode;
		}
		else {
			if (m_sort == 1) {//sort to date
				if (rootNode->Event->GetYear() > NewEvent->GetYear())
					rootNode->Right=insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetYear() < NewEvent->GetYear())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetMonth() > NewEvent->GetMonth())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetMonth() < NewEvent->GetMonth())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetDay() > NewEvent->GetDay())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetDay() < NewEvent->GetDay())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetHour() > NewEvent->GetHour())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetHour() < NewEvent->GetHour())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetMin() > NewEvent->GetMin())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetMin() < NewEvent->GetMin())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetImportant() > NewEvent->GetImportant())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetImportant() < NewEvent->GetImportant())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);
				else std::cout << "Event exists. Please other parameters." << std::endl;
			}
			if (m_sort == 2) {//sort to date
				if (rootNode->Event->GetImportant() > NewEvent->GetImportant())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetImportant() < NewEvent->GetImportant())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);
				
				else if (rootNode->Event->GetYear() > NewEvent->GetYear())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetYear() < NewEvent->GetYear())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetMonth() > NewEvent->GetMonth())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetMonth() < NewEvent->GetMonth())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetDay() > NewEvent->GetDay())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetDay() < NewEvent->GetDay())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetHour() > NewEvent->GetHour())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetHour() < NewEvent->GetHour())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				else if (rootNode->Event->GetMin() > NewEvent->GetMin())
					rootNode->Right = insert(NewEvent, m_sort, rootNode->Right);
				else if (rootNode->Event->GetMin() < NewEvent->GetMin())
					rootNode->Left = insert(NewEvent, m_sort, rootNode->Left);

				
				else std::cout << "Event exists. Please other parameters." << std::endl;
			}


		}
		return rootNode;
	}

	

	Node* remove(int event_num, Node* rootNode, Node** TmpNode) {
		char ev;
		
		if (event_to_search == 0 && isEmpty(rootNode))
			return false;
		if (!isEmpty(rootNode->Left)) remove(event_num, rootNode->Left,&(*TmpNode)->Left);
		event_to_search++;
		if (event_to_search == event_num) {
			std::cout << "Date: " << rootNode->Event->GetDay() << " " << rootNode->Event->GetMonth_Char(rootNode->Event->GetMonth()) << " " << rootNode->Event->GetYear() << "| Weekday: " << rootNode->Event->GetWeek_Day(rootNode->Event->GetDay(), rootNode->Event->GetMonth(), rootNode->Event->GetYear());
			std::cout << "| Time: " << rootNode->Event->GetHour() << " " << rootNode->Event->GetMin() << "| Importance: " << rootNode->Event->GetImportant() << std::endl << "Place: " << rootNode->Event->GetPlace() << std::endl << "Description: " << rootNode->Event->GetDescription() << std::endl << std::endl; std::cout << "This event to delete? y/n"<<std::endl;
			int num = 1;
			while (num != 0) {
				std::cin >> ev;
				if (ev == 'y' || ev == 'Y') {
					num = 0;
					if (isEmpty(rootNode->Right)) {
						*TmpNode = rootNode->Left;
						return rootNode;
					}
					else {
						Node* tempNode = rootNode->Right;
						if (isEmpty(tempNode->Left)) {
							tempNode->Left = rootNode->Left;
							*TmpNode = tempNode;
							return rootNode;
						}
						else {
							Node* tempNode2 = tempNode->Left;
							while (!(isEmpty(tempNode2->Left)))
							{
								tempNode = tempNode2;
								tempNode2 = tempNode->Left;
							}
							tempNode->Left = tempNode2->Right;
							tempNode2->Left = rootNode->Left;
							tempNode2->Right = rootNode->Right;
							*TmpNode = tempNode2;
							return rootNode;

						}
					}


					return rootNode;
				}
				else if (ev == 'n' || ev == 'N') {
					num = 0;
					return false;

				}
				else std::cout << "Wrong input. Enter y or n" << std::endl;

			}
		}
		if (!isEmpty(rootNode->Right)) remove(event_num, rootNode->Right, & (*TmpNode)->Right);
	}

	void show_all_events(Node* rootNode, int sort, int u) {
		if (isEmpty(rootNode)) { //if tree null to exit
			//printf("Events not exist \n"); 
			return;
		}
		if (sort == 1 || sort == 9 || sort == 3) { // 1, 3 - sort increase; 9 - firter output
			if (!isEmpty(rootNode->Left)) show_all_events(rootNode->Left, sort, ++u);//Left 
			//print event to console
			if (sort == 1 || sort == 3) {
				event_number++;
				//printf("Event number %d | node numder %d\n", event_number, u);
				if (filtr_place == rootNode->Event->GetPlace() || filtr_place == "") {
					std::cout<<"Event number "<< event_number<<std::endl;
					std::cout << "Date: " << rootNode->Event->GetDay() << " " << rootNode->Event->GetMonth_Char(rootNode->Event->GetMonth()) << " " << rootNode->Event->GetYear() << "| Weekday: " << rootNode->Event->GetWeek_Day(rootNode->Event->GetDay(), rootNode->Event->GetMonth(), rootNode->Event->GetYear());
					std::cout << " | Time: " << rootNode->Event->GetHour() << ":" << rootNode->Event->GetMin() << " | Importance: " << rootNode->Event->GetImportant() << std::endl << "Place: " << rootNode->Event->GetPlace() << std::endl << "Description: " << rootNode->Event->GetDescription() << std::endl << std::endl;
				}
			}
			else
				if (sort == 9) {
					event_number++;
					std::cout<< rootNode->Event->GetPlace()<<std::endl;
				}
			u--;
			if (!isEmpty(rootNode->Right)) show_all_events(rootNode->Right, sort, ++u); //Right
		} //end sort increase
		else
			if (sort == 2 || sort == 4) { // 2, 4 - sort decrease
				if (!isEmpty(rootNode->Right)) show_all_events(rootNode->Right, sort, ++u);//Left 
			//print event to console
				event_number++;
				if (filtr_place == rootNode->Event->GetPlace() || filtr_place == "") {
					std::cout << "Event number " << event_number << std::endl;
					std::cout << "Date: " << rootNode->Event->GetDay() << " " << rootNode->Event->GetMonth_Char(rootNode->Event->GetMonth()) << " " << rootNode->Event->GetYear() << "| Weekday: " << rootNode->Event->GetWeek_Day(rootNode->Event->GetDay(), rootNode->Event->GetMonth(), rootNode->Event->GetYear());
					std::cout << "| Time: " << rootNode->Event->GetHour() << " " << rootNode->Event->GetMin() << "| Importance: " << rootNode->Event->GetImportant() <<std::endl<< "Place: " << rootNode->Event->GetPlace() <<std::endl<< "Description: " << rootNode->Event->GetDescription() << std::endl << std::endl;
				}
				u--;
				if (!isEmpty(rootNode->Left)) show_all_events(rootNode->Left, sort, ++u); //Left
			} //end sort decrease
	}

	void pause_key(char* message_text)
	{
		std::cout<<message_text;
		while (!(_getch())) {
			//any key
		};
		system("CLS");
	}


	void search_place(Node* rootNode) {
		if ((event_to_search == 0) && (isEmpty(rootNode))) { //if tree null to exit
			filtr_search = false;
			return;
		}
		if (!isEmpty(rootNode->Left)) search_place(rootNode->Left);//Left 								 	
		event_to_search++;
		if (filtr_place== rootNode->Event->GetPlace()) {
			filtr_search = true;
			return;
		}
		if (!isEmpty(rootNode->Right)) search_place(rootNode->Right); //Right
	}

	void case_sort_filtr() {
		system("CLS");
		int sort_num;
		bool st = true;
		for (;;) {
			if (st) {
				st = false;
				if (filtr_place== "") std::cout<<"Filtering by place All"<<std::endl<<std::endl;
				else std::cout << "Filtering by place "<<filtr_place << std::endl << std::endl;
				std::cout<<"Enter the sort type:\n\n1 - Increase date\n\n2 - Decrease date\n\n3 - Increase important\n\n4 - Decrease important\n\n9 - Filter place\n\n0 - Return to main menu\n\n"<<std::endl;
			}
			std::cin>>sort_num;
			if ((sort_num > 0) && (sort_num < 5)) {
				system("CLS");
				event_number = 0;
				if (sort_num == 1 || sort_num == 2) {
					sort_type = 1;
					LoadfromFile("my_notebook.tmp");
					show_all_events(root, sort_num, 0);
				}
				if (sort_num == 3 || sort_num == 4) {
					sort_type = 2;
					LoadfromFile("my_notebook.tmp");
					show_all_events(root, sort_num, 0);
				}
				pause_key("...Please enter any key to show menu...");
				st = true;
			}
			else
				if (sort_num == 9) {
					system("CLS");
					event_number = 0;
					show_all_events(root, sort_num, 0);
					std::cout<<std::endl<<"Enter filtering by place. All - all place."<<std::endl;
					for (;;) {
						std::cin>>filtr_place;
						event_to_search = 0;
						if (filtr_place=="All") {
							filtr_place="";
							break;
						}
						filtr_search = false;
						search_place(root);
						if (filtr_search) {
							break;
						}
						else {
							std::cout << "There is no such place "<<filtr_place<<".  Re-enter place\n";
						}
					}
					system("CLS");
					st = true;
					delete root;
					root = NULL;
				}
				else
					if (sort_num == 0) {
						filtr_place="";
						system("CLS");
						return;
					}
					else std::cout<<"Wrong input. Enter correctly\n\n";
		}
	}

	void random_event() {
		srand(time(NULL));
		int k = 1;
		int rne = 0;
		//Node* node=new Node;
		
		char* d_array[] = { "Hello world","People is crazy","Go to the Museum","Buy a pencil","Perform work",
							"Paint the wall","Congratulate on the birthday of the city","To discover their talents",
							"Pass laboratory works","Meet friends" };
		char* p_array[] = { "Saint-Petersburg","Kronshtadt","Novgorod","Tver","Vologda",
							"Valdai","Strelna","Petrodvorets","Pargolovo","Pushkin" };
		std::cout<<"Enter the number of events 1-10000"<<std::endl;
		while (k != 0) {
			std::cin>>rne;
			if (rne < 1 || rne > 10000)
				std::cout<<"Wrong input. Enter the number correctly"<<std::endl;
			else k = 0;
		}
		for (int i = 0; i < rne; i++) {
			Event* newEvent = new Event;
			newEvent->SetHour(rand() % 24) ;
			newEvent->SetMin(rand() % 60) ;
			newEvent->SetImportant(rand() % 11) ;
			newEvent->SetYear(rand() % 5 + 2015) ;
			newEvent->SetMonth(rand() % 12 + 1) ;
			if (newEvent->GetMonth()==2) {
				newEvent->SetDay(rand() % 28 + 1) ;
			}
			else {
				if (newEvent->GetMonth() == 4 || newEvent->GetMonth() == 6 || newEvent->GetMonth() == 9 || newEvent->GetMonth() == 11) {
					newEvent->SetDay(rand() % 30 + 1);
				}
				else {
					newEvent->SetDay(rand() % 31 + 1);
				}
			}
			newEvent->SetDescription(d_array[rand() % 10]);
			newEvent->SetPlace(p_array[rand() % 10]);
			root=insert(newEvent,sort_type,root);
			
		}
	}

	void Save_to_File(Node* t) {
		if (t == NULL) { //if tree null to exit
			return;
		}
		else
		{
			fprintf(my_file, "%d\n%d\n%d\n%d\n", t->Event->GetDay(), t->Event->GetMonth() , t->Event->GetYear() , t->Event->GetHour());
			fprintf(my_file, "%d\n%d\n%s\n%s\n", t->Event->GetMin(), t->Event->GetImportant(), t->Event->GetPlace().c_str(), t->Event->GetDescription().c_str());
			if (t->Left != NULL) Save_to_File(t->Left);//Left 								 	
			if (t->Right != NULL) Save_to_File(t->Right); //Right
		}
	}

	

	int convert_to_int(std::string buf) {
		char conv[4] = "";
		for (int k = 0; k <= sizeof(buf); k++) {
			if (buf[k] != '\n') conv[k] = buf[k];
			else { break; }
		}
		return  atoi(conv);
	}

	void Load_from_File(Node* t) {
		
		char buf[1000] = "";
		char desc[1000]="";
		char place[100]="";
		int i = 0;
		int poz = 0;
		delete root;
		root = NULL;
		Event* newEvent = new Event;
			while (!feof(my_file))
			{
				
				
					buf[i] = fgetc(my_file);
					i++;
					if ((buf[i - 1] == '\n') && (poz == 0)) {
						i = 0; poz++;
						newEvent->SetDay(convert_to_int(buf));
						memset(buf, NULL, sizeof(buf));
					}
					if (buf[i - 1] == '\n' && poz == 1) {
						i = 0; poz++;
						newEvent->SetMonth(convert_to_int(buf));
						memset(buf, NULL, sizeof(buf));
					}
					if (buf[i - 1] == '\n' && poz == 2) {
						i = 0; poz++;
						newEvent->SetYear(convert_to_int(buf));
						memset(buf, NULL, sizeof(buf));
					}
					if (buf[i - 1] == '\n' && poz == 3) {
						i = 0; poz++;
						newEvent->SetHour(convert_to_int(buf));
						memset(buf, NULL, sizeof(buf));
					}
					if (buf[i - 1] == '\n' && poz == 4) {
						i = 0; poz++;
						newEvent->SetMin(convert_to_int(buf));
						memset(buf, NULL, sizeof(buf));
					}
					if (buf[i - 1] == '\n' && poz == 5) {
						i = 0; poz++;
						newEvent->SetImportant(convert_to_int(buf));
						memset(buf, NULL, sizeof(buf));
					}
					if (buf[i - 1] == '\n' && poz == 6) {
						i = 0; poz++;
						memset(place, NULL, sizeof(place));
						for (int k = 0; k < sizeof(buf); k++) {
							if (buf[k] == '\n') { break; }
							place[k] = buf[k];
						}
						newEvent->SetPlace(place);
						memset(buf, NULL, sizeof(buf));
					}
					if (buf[i - 1] == '\n' && poz == 7) {
						i = 0; poz++;
						memset(desc, NULL, sizeof(desc));
						for (int k = 0; k < sizeof(buf); k++) {
							if (buf[k] == '\n') { break; }
							desc[k] = buf[k];
						}
						newEvent->SetDescription(desc);
						memset(buf, NULL, sizeof(buf));
					}
					if (poz == 8) {
						poz = 0; i = 0;
						Event* newEvent2 = new Event;
						newEvent2->SetDay(newEvent->GetDay());
						newEvent2->SetMonth(newEvent->GetMonth());
						newEvent2->SetYear(newEvent->GetYear());
						newEvent2->SetImportant(newEvent->GetImportant());
						newEvent2->SetHour(newEvent->GetHour());
						newEvent2->SetMin(newEvent->GetMin());
						newEvent2->SetPlace(newEvent->GetPlace());
						newEvent2->SetDescription(newEvent->GetDescription());
						root = insert(newEvent2, sort_type, root);

					}
				
			}//end while
		
	}

	

	class Node {
	public:
		Node* Left=NULL; 
		Node* Right=NULL;
		Event* Event;
	};
	Node *root;
	std::string filtr_place="";
	bool filtr_search = false;
	int sort_type = 1; // 1 - sort to date; 2 - sort to imp
	int event_to_search = 0;
	int	event_number = 0;
	FILE* my_file;
};