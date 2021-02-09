#include <iostream>
#include "EventMenu.h"
#include "BinTree.h"


void EventMenu::AllCommands() {
    std::cout << "What do we do? \n\n1: add event\n\n2: delete event\n\n3: show all event\n\n7: save event\n\n8: load event\n\n9: random events\n\n0: exit\n\n";
}


EventMenu::EventMenu() {
    AllCommands();
}

EventMenu::~EventMenu() {
    
}
void EventMenu::cmd(int c) {
    switch (c) {
    case 1:
        add_command();
        system("CLS");
        AllCommands();
        break;

    case 2:
        remove_command();
        system("CLS");
        AllCommands();
        break;

    case 3:
        show_command();
        system("CLS");
        AllCommands();
        break;
    case 7:
        save_command();
        system("CLS");
        AllCommands();
        break;
    case 8:
        load_command();
        system("CLS");
        AllCommands();
        break;
    case 9:
        random_command();
        system("CLS");
        AllCommands();
        break;
    default:
        return;
    }



}
void EventMenu::add_command() {
    Event* newEvent=new Event;
    Node.add_Node(newEvent, 1);

}

void EventMenu::remove_command() {
    int c;
    show_command();
    std::cout << "What event you want to delete? Enter number:" << std::endl;
    std::cin >> c;
    Node.del_Node(c);


}

void EventMenu::show_command() {
    Node.show_all_Tree();


}

void EventMenu::save_command() {
    std::string filename;
    std::cout << "Enter name of file to save: " << std::endl;
    std::cin >> filename;
    Node.SavetoFile(filename);


}

void EventMenu::load_command() {
    std::string filename;
    std::cout << "Enter name of file to load: " << std::endl;
    std::cin >> filename;
    Node.LoadfromFile(filename);


}

void EventMenu::random_command() {
    Node.Random_Tree();


}


int main() {
    EventMenu menu;
    int c = 10;
    while (c != 0) {
        std::cin >> c;
        menu.cmd(c);
       

    }

}