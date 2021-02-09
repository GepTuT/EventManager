#pragma once
#include <iostream>
#include "BinTree.h"

class EventMenu {

public:
    EventMenu();
    ~EventMenu();
    void cmd(int c);
    void add_command();
    void remove_command();
    void show_command();
    void save_command();
    void load_command();
    void random_command();
private:
    void AllCommands();
    BinTree Node;

};


