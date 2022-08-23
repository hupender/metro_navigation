#include <iostream>
#include "ui_manager.cpp"
#include "file_manager.cpp"
int main(){
    File_manager FM;
    Ui_manager UI;
    UI.operation(FM.get_input_from_file());
}