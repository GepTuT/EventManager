#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h> 

FILE *my_file;
int search_event_number=0, event_number = 0;
const int pc = 100; //for char to place
const int dc = 1000; //for char to desc
char filtr_place[pc] = "";
bool filtr_search = false;
int sort_type = 1; // 1 - sort to date; 2 - sort to imp

char* week_day(int day, int month, int year)
{	
	char* dnc;
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int dn = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
	switch (dn) {
	case 0: dnc = "SUN"; break;
	case 1: dnc = "MON"; break;
	case 2: dnc = "TUE"; break;
	case 3: dnc = "WED"; break;
	case 4: dnc = "THU"; break;
	case 5: dnc = "FRI"; break;
	case 6: dnc = "SAT"; break;
	}
	return dnc;
}

char* month_char(int month)
{
	char* mc;	
	switch (month) {
	case 1:  mc = "JAN"; break;
	case 2:  mc = "FEB"; break;
	case 3:  mc = "MAR"; break;
	case 4:  mc = "APR"; break;
	case 5:  mc = "MAY"; break;
	case 6:  mc = "JUN"; break;
	case 7:  mc = "JUL"; break;
	case 8:  mc = "AUG"; break;
	case 9:  mc = "SEP"; break;
	case 10: mc = "OKT"; break;
	case 11: mc = "NOV"; break;
	case 12: mc = "DEC"; break;
	}
	return mc;
}

struct event {
	int imp=0;
	int min = 0;
	int hour=0;
	int day;
	int month;
	int year;
	char* weekday;
	char desc[dc];
	char place[pc];
	struct event *Left;
	struct event *Right;	
};
struct event *MyTree = NULL;

void push(int sort, int day, int month, int year, int hour, int min, int imp, char desc[4001], char place[1000], event **t)
{
	// select a location in the tree
	if ((*t) == NULL) { //tree is false
		(*t) = (struct event*)malloc(sizeof(struct event));
		(*t)->day = day;
		(*t)->month = month;
		(*t)->year = year;
		(*t)->weekday = week_day(day, month, year);
		(*t)->hour = hour;
		(*t)->min = min;
		(*t)->imp = imp;
		for (int i = 0; i < pc; i++) {
			(*t)->place[i] = place[i];
		}
		for (int i = 0; i < dc; i++) {
			(*t)->desc[i] = desc[i];
		}		
		(*t)->Left = (*t)->Right = NULL; 
		return;
	}
	else
	{
		//tree is true
		if (sort == 1) { // 1 - sort to date			
			if (year > (*t)->year) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the year a is greater than the current ear, put it to the right
			else if (year < (*t)->year) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (month > (*t)->month) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the month a is greater than the current month, put it to the right
			else if (month < (*t)->month) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (day > (*t)->day) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument day a is greater than the current day, put it to the right
			else if (day < (*t)->day) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (hour > (*t)->hour) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument hour a is greater than the current hour, put it to the right
			else if (hour < (*t)->hour) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (min > (*t)->min) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument minute a is greater than the current minute, put it to the right
			else if (min < (*t)->min) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (imp > (*t)->imp) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument importance a is greater than the current importance, put it to the right
			else if (imp < (*t)->imp) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (strcmp(place, (*t)->place) > 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else if (strcmp(place, (*t)->place) < 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else if (strcmp(desc, (*t)->desc) > 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else if (strcmp(desc, (*t)->desc) < 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else printf("Event exists. Please other parameters.\n");
		}
		else if (sort == 2) { // 2 - sort to imp
			if (imp >(*t)->imp) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument importance a is greater than the current importance, put it to the right
			else if (imp < (*t)->imp) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (year >(*t)->year) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the year a is greater than the current ear, put it to the right
			else if (year < (*t)->year) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (month >(*t)->month) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the month a is greater than the current month, put it to the right
			else if (month < (*t)->month) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (day >(*t)->day) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument day a is greater than the current day, put it to the right
			else if (day < (*t)->day) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (hour >(*t)->hour) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument hour a is greater than the current hour, put it to the right
			else if (hour < (*t)->hour) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (min >(*t)->min) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right); //If the argument minute a is greater than the current minute, put it to the right
			else if (min < (*t)->min) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Left); //Otherwise, put it to the left
			else if (strcmp(place, (*t)->place) > 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else if (strcmp(place, (*t)->place) < 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else if (strcmp(desc, (*t)->desc) > 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else if (strcmp(desc, (*t)->desc) < 0) push(sort, day, month, year, hour, min, imp, desc, place, &(*t)->Right);
			else  printf("Event exists. Please other parameters.\n");
		}
	}
}

void Save_to_File(event *t) {
	if (t == NULL) { //if tree null to exit
		return;
	}
	else
	{
	fprintf(my_file, "%d\n%d\n%d\n%d\n%d\n%d\n%s\n%s\n", t->day, t->month, t->year, t->hour, t->min, t->imp, t->place, t->desc);
	if (t->Left != NULL) Save_to_File(t->Left);//Left 								 	
	if (t->Right != NULL) Save_to_File(t->Right); //Right
    }
}

bool SavetoFile(char* file_name, event *t) {
	my_file = fopen(file_name, "w");
	if (my_file == NULL) {
		return false;
	}
	Save_to_File(MyTree);
	fclose(my_file);
	return true;
}

int convert_to_int(char buf[dc + 2]) {
	char conv[4] = "";
	for (int k = 0; k <= sizeof(buf); k++) {
		if (buf[k] != '\n') conv[k] = buf[k];
		else { break; }
	}
	return  atoi(conv);
}

void Load_from_File(event *t) {
	int day = 0;
	int month = 0;
	int year = 0;
	int hour = 0;
	int min = 0;
	int imp = 0;
	char desc[dc];
	char place[pc];
	char buf[(dc + 1)] = "";
	int i = 0;
	int poz = 0;
	free(MyTree);
	MyTree = NULL;
	while (!feof(my_file))
	{
		buf[i] = fgetc(my_file);
		i++;
		if ((buf[i - 1] == '\n') && (poz == 0)) {
			i = 0; poz++;
			day = convert_to_int(buf);
			memset(buf, NULL, sizeof(buf));
		}
		if (buf[i - 1] == '\n' && poz == 1) {
			i = 0; poz++;
			month = convert_to_int(buf);
			memset(buf, NULL, sizeof(buf));
		}
		if (buf[i - 1] == '\n' && poz == 2) {
			i = 0; poz++;
			year = convert_to_int(buf);
			memset(buf, NULL, sizeof(buf));
		}
		if (buf[i - 1] == '\n' && poz == 3) {
			i = 0; poz++;
			hour = convert_to_int(buf);
			memset(buf, NULL, sizeof(buf));
		}
		if (buf[i - 1] == '\n' && poz == 4) {
			i = 0; poz++;
			min = convert_to_int(buf);
			memset(buf, NULL, sizeof(buf));
		}
		if (buf[i - 1] == '\n' && poz == 5) {
			i = 0; poz++;
			imp = convert_to_int(buf);
			memset(buf, NULL, sizeof(buf));
		}
		if (buf[i - 1] == '\n' && poz == 6) {
			i = 0; poz++;
			memset(place, NULL, sizeof(place));
			for (int k = 0; k < sizeof(buf); k++) {
				if (buf[k] == '\n') { break; }
				place[k] = buf[k];
			}
			memset(buf, 0, sizeof(buf));
		}
		if (buf[i - 1] == '\n' && poz == 7) {
			i = 0; poz++;
			memset(desc, NULL, sizeof(desc));
			for (int k = 0; k < sizeof(buf); k++) {
				if (buf[k] == '\n') { break; }
				desc[k] = buf[k];
			}
			memset(buf, NULL, sizeof(buf));
		}
		if (poz == 8) {
			poz = 0; i = 0;
			char* mc = month_char(month);
			//printf("Date %d %s %d | Weekday %s | Time %d:%d | importance %d\nPlace %s \nEvent %s \n\n", day, mc, year, week_day(day, month, year), hour, min, imp, place, desc);
			push(sort_type, day, month, year, hour, min, imp, desc, place, &MyTree);
		}
	}//end while
}

bool LoadfromFile(char* file_name, event *t) {
	my_file = fopen(file_name, "r");
	if (my_file == NULL) {
		return false;
	}
	Load_from_File(MyTree);
	fclose(my_file);
	return true;
}

void add_event(){
	int k = 1;
	int day=0;
	int month=0;
	int year=0;
	int hour=0;
	int min=0;
	int imp=0;
	char desc[dc];
	char place[pc];	
	printf("What is event date? Write like: dd.mm.yyyy.\n");
	while (k!=0) {
		scanf("%d.%d.%d", &(day), &(month), &(year));
		if ((day < 1 || day > 31) || (month < 1 || month > 12) || (year < 0 || year > 3000))
			printf("Wrong input. Enter the date correctly\n");
		else k = 0;
		
		//printf("%d:%d:%d\n", newevent->day, newevent->month, newevent->year);
	}
	printf("What hour and minute of the event? Write like hh:mm.\n");
	k = 1;
	while (k != 0) {
		scanf("%d:%d", &(hour), &(min));
		if ((hour < 0 || hour > 23) || (min < 0 || min > 59))
			printf("Wrong time. Enter time correctly\n");
		else k = 0;
	}
	printf("How this important? From 0 to 10\n");
	k = 1;
	while (k != 0) {
		scanf("%d", &(imp));
		if (imp < 0 || imp > 10)
			printf("Wrong importance. Enter importance correctly\n");
		else k = 0;
	}
	printf("What is event place?\n");
	gets_s(place, pc);
	gets_s(place, pc);
	printf("What is event?\n");
	gets_s(desc, dc);
	// save to tree
	push(sort_type, day, month, year, hour, min, imp, desc, place, &MyTree);	
}

bool delete_event( int event_num, event *t, event **temp1) {	
	if ((search_event_number == 0) && (t == NULL)) { //if tree null to exit
		return false;
	}
	if (t->Left != NULL) delete_event(event_num, t->Left, &(*temp1)->Left);//Left 								 
	search_event_number++;
	if (search_event_number == event_num) {
		char* mc = month_char(t->month);
		printf("Date %d %s %d | Weekday %s | Time %d:%d | importance %d\nPlace %s \nEvent %s \n\n", t->day, mc, t->year, t->weekday, t->hour, t->min, t->imp, t->place, t->desc);
		printf("This is event delete y/n ?\n");
		char a = NULL;
		int k = 1;
		scanf("%c", &(a));
		while (k != 0) {
			scanf("%c", &(a));
			if (a == 'y' || a == 'Y') {
				k = 0; 
				char* mc = month_char(t->month);
				//printf("Date %d %s %d | Weekday %s | Time %d:%d | importance %d\nPlace %s \nEvent %s \n\n", t->day, mc, t->year, t->weekday, t->hour, t->min, t->imp, t->place, t->desc);
				if (t->Right == NULL) { 
					*temp1 = t->Left; 
					return true; 
				}
				else {
					event *temp2 = t->Right;
					if (temp2->Left == NULL) { 
						temp2->Left = t->Left; 
						*temp1 = temp2;
						return true; 
					}
					else {
						event *temp3 = temp2->Left;
						while (temp3->Left != NULL)
						{
							temp2 = temp3;
							temp3 = temp2->Left;
						}
						temp2->Left = temp3->Right;
						temp3->Left = t->Left;
						temp3->Right = t->Right;
						*temp1 = temp3;
						return true;
					}				
				}
			} else
			if (a == 'n' || a == 'N') {
				k = 0; 
			    return false;
			}
			else printf("Wrong input. Enter y or n\n");
		}
	}
	if (t->Right != NULL) delete_event(event_num, t->Right, &(*temp1)->Right); //Right
}

void show_all_events(event *t, int sort, int u) {	
	if (t == NULL) { //if tree null to exit
		//printf("Events not exist \n"); 
		return; 
	}
	if (sort == 1 || sort == 9 || sort == 3) { // 1, 3 - sort increase; 9 - firter output
		if (t->Left != NULL) show_all_events(t->Left, sort, ++u);//Left 
		//print event to console
		char* mc = month_char(t->month);
		if (sort == 1 || sort == 3) {
			event_number++;
			//printf("Event number %d | node numder %d\n", event_number, u);
			if ((strcmp(filtr_place, t->place) == 0) || (strcmp(filtr_place, "") == 0)) {
				printf("Event number %d\n", event_number);
				printf("Date %d %s %d | Weekday %s | Time %d:%d | importance %d\nPlace %s \nEvent %s \n\n", t->day, mc, t->year, t->weekday, t->hour, t->min, t->imp, t->place, t->desc);
			}
		} else
			if (sort == 9) {
					event_number++;
					//printf("%d - ", event_number);
					printf("%s\n", t->place);
			}	
		u--;
		if (t->Right != NULL) show_all_events(t->Right, sort, ++u); //Right
	} //end sort increase
	else
		if (sort == 2 || sort == 4) { // 2, 4 - sort decrease
			if (t->Right != NULL) show_all_events(t->Right, sort, ++u);//Right	
			//print event to console
			char* mc = month_char(t->month);
			event_number++;
			if ((strcmp(filtr_place, t->place) == 0) || (strcmp(filtr_place, "") == 0)) {
				printf("Event number %d\n", event_number);
				printf("Date %d %s %d | Weekday %s | Time %d:%d | importance %d\nPlace %s \nEvent %s \n\n", t->day, mc, t->year, t->weekday, t->hour, t->min, t->imp, t->place, t->desc);
			}
			u--;
			if (t->Left != NULL) show_all_events(t->Left, sort, ++u); //Left
		} //end sort decrease
}

void pause_key(char* message_text)
{
	printf(message_text);
	while (!(_getch())) {
		//any key
	};
	system("CLS");
}

void search_place(event *t) {
	if ((search_event_number == 0) && (t == NULL)) { //if tree null to exit
		filtr_search = false;
		return;
	}
	if (t->Left != NULL) search_place( t->Left);//Left 								 	
	search_event_number++;
	if (strcmp(filtr_place, t->place) == 0) {
		filtr_search = true;
		return;
	}
	if (t->Right != NULL) search_place( t->Right); //Right
}

void case_sort_filtr() {
	int sort_num;
	bool st = true;	
	for (;;) {
		if (st) {
			st = false;
			if (strcmp(filtr_place, "") == 0) printf("Filtering by place All\n\n");
			else printf("Filtering by place %s\n\n", filtr_place);
			printf("Enter the sort type:\n\n1 - Increase date\n\n2 - Decrease date\n\n3 - Increase important\n\n4 - Decrease important\n\n9 - Filter place\n\n0 - Return to main menu\n\n");
	    }
		scanf("%d", &(sort_num));
		if ((sort_num > 0) && (sort_num < 5)) {
			system("CLS");
			event_number = 0;
			if (sort_num == 1 || sort_num == 2) {
				sort_type = 1;
				LoadfromFile("my_notebook.tmp", MyTree);
				show_all_events(MyTree, sort_num, 0);				
			}
			if (sort_num == 3 || sort_num == 4) {
				sort_type = 2;
				LoadfromFile("my_notebook.tmp", MyTree);
				show_all_events(MyTree, sort_num, 0);			
			}
			pause_key("...Please any key to show menu...");
			st = true;
		} 
		else
			if (sort_num == 9) {
				system("CLS");
				event_number = 0;
				show_all_events(MyTree, sort_num, 0);
				printf("\nEnter filtering by place. All - all place.\n");
				for (;;) {
					scanf("%s", &(filtr_place));
					search_event_number = 0;
					if (strcmp(filtr_place, "All") == 0) { 
						memset(filtr_place, NULL, sizeof(filtr_place));
						break; 
					}
					filtr_search = false;
					search_place(MyTree);
					if (filtr_search) {
						break;
					}
					else {
						printf("There is no such place %s.  Re-enter place\n", filtr_place);
					}
				}
				system("CLS");
				st = true;
				free(MyTree);
				MyTree = NULL;
			}
			else
				if (sort_num == 0) {
					memset(filtr_place, NULL, sizeof(filtr_place));
					system("CLS");
					return;
				}
				else printf("Wrong input. Enter correctly\n\n");
	}	
}

void random_event() {
	int k = 1;
	int rne=0;
	int day = 0;
	int month = 0;
	int year = 0;
	int hour = 0;
	int min = 0;
	int imp = 0;
	char desc[dc];
	char place[pc];
	char *d_array[] = { "Hello world","People is crazy","Go to the Museum","Buy a pencil","Perform work",
		                "Paint the wall","Congratulate on the birthday of the city","To discover their talents",
		                "Pass laboratory works","Meet friends" };
	char *p_array[] = { "Saint-Petersburg","Kronshtadt","Novgorod","Tver","Vologda",
		                "Valdai","Strelna","Petrodvorets","Pargolovo","Pushkin" };	
	printf("Enter the number of events 1-10000\n");
	while (k != 0) {
		scanf("%d", &(rne));
		if (rne < 1 || rne > 10000)
			printf("Wrong input. Enter the number correctly\n");
		else k = 0;
	}
	for (int i = 0; i < rne; i++) {
		hour = rand() % 24;
		min = rand() % 60;
		imp = rand() % 11;
		year = rand() % 5 + 2015;
		month = rand() % 12 + 1;
		if (month == 2) {
			day = rand() % 28 + 1;
	}	else {
			if (month == 4 || month == 6 || month == 9 || month == 11) {
				day = rand() % 30 + 1;
		}  else { 
				day = rand() % 31 + 1; 
			}
		}
	strcpy(desc, d_array[rand() % 10]);
	strcpy(place, p_array[rand() % 10]);
	push(sort_type, day, month, year, hour, min, imp, desc, place, &MyTree);
	}	
}


void main() {
	int choose = 0;
	srand(time(NULL));	
	while(1){
		printf("What do we do? \n\n1: - add event\n\n2: - delete event\n\n3: - show all event\n\n7: - save event\n\n8: - load event\n\n9: - random events\n\n0: - exit\n\n");
		scanf("%d", &choose);
		switch (choose) {

		case(1): {
			system("CLS");
			add_event();
			system("CLS");
			SavetoFile("my_notebook.tmp", MyTree);
			break;
		}
		case(2): {
			int k = 1;
			int ev_del = 0;
			search_event_number = 0;
			system("CLS");
			event_number = 0;
			show_all_events(MyTree, 1, 0); //sort to increase date
			printf("Enter the event number to delete 1-%d or other to exit\n",event_number);
			while (k != 0) {
				scanf("%d", &(ev_del));
				if (ev_del < 1 || ev_del > event_number)
				{
					system("CLS");
					break;
				}
				else k = 0;
			}
			if (delete_event(ev_del, MyTree, &MyTree)) pause_key("...Delete complete. Please enter any key to main menu...");
			else pause_key("...Delete cancel. Please any key to main menu...");
			SavetoFile("my_notebook.tmp", MyTree);
			break;
		}
		case(3): {
			system("CLS");
			case_sort_filtr();
			break;
		}
		case(7): {
			system("CLS");
			if (SavetoFile("my_notebook.txt", MyTree)) pause_key("...Save file to comlite. Please enter any key to main menu...");
			else pause_key("...Error to open file. Please enter any key to main menu...");
			break;
		}
		case(8): {
			system("CLS");
			if (LoadfromFile("my_notebook.txt", MyTree)) pause_key("...Load from file to comlite. Please enter any key to main menu...");
			else pause_key("...Error to open file. Please enter any key to main menu...");
			SavetoFile("my_notebook.tmp", MyTree);
			break;
		}
		case(9): {
			system("CLS");
			random_event();
			printf("Random event completion completed.\n\n");
			pause_key("...Please enter any key to main menu...");
			SavetoFile("my_notebook.tmp", MyTree);
			break;
		}
		case(0): {
			system("CLS");
			remove("my_notebook.tmp");
			return;
		}
		default:
			break;
		}
	}
	_getch();
}










