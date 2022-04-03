#include <iostream>
#include "sources/Notebook.hpp"

using namespace ariel;
using namespace std;
int main() {

    Notebook my_notebook;

    ///////////////// start write ////////////////
    cout << "write: \n" << endl;

    try {
        my_notebook.write(-20,4,5,Direction::Horizontal, "Hello World");
    } catch (exception e) {
        cout<<"invalid position,page can't be negative"<< endl;
    }
    try {
        my_notebook.write(0,-4,5,Direction::Horizontal, "Hello World");
    } catch (exception e) {
        cout<<"invalid position, row can't be negative"<< endl;
    }
    try {
        my_notebook.write(0,4,-5,Direction::Horizontal, "Hello World");
    } catch (exception e) {
        cout<<"invalid position, column can't be negative"<< endl;
    }
    try {
        my_notebook.write(0,4,97,Direction::Horizontal, "Hello World");
    } catch (exception e) {
        cout<<"invalid position, can't write in column bigger then 100"<< endl;
    }
    try {
        my_notebook.write(0,4,200,Direction::Vertical, "Hello World");
    } catch (exception e) {
        cout<<"invalid position, can't write in column bigger then 100"<< endl;
    }


    my_notebook.write(0,3,3,Direction::Horizontal, "Hello World");
    my_notebook.show(0);
    my_notebook.write(0,15,3,Direction::Horizontal, "This is my note");

    try {
        my_notebook.write(0,15,15,Direction::Horizontal, "Wellcome");
    } catch (exception e) {
        cout<<"can't write into spot that has already benn writen"<< endl;
    }

    try {
        my_notebook.write(0,3,9,Direction::Vertical, "Wellcome");
    } catch (exception e) {
        cout<<"can't write into spot that has already benn writen"<< endl;
    }

    my_notebook.write(0,4,9,Direction::Vertical, "ellcome");
    my_notebook.write(0,4,17,Direction::Vertical, "My name is");
    my_notebook.write(0,4,18,Direction::Vertical, "My name is Gil");
    //////////////// end write /////////////////

    cout << "\n\nshow page 0: \n" << endl;
    my_notebook.show(0);

    //////////////// starr erase ///////////////
    cout << "\n\nerase: \n" << endl;

    try {
        my_notebook.erase(-20,4,5,Direction::Horizontal, 3);
    } catch (exception e) {
        cout<<"invalid position,page can't be negative"<< endl;
    }
    try {
        my_notebook.erase(0,-4,5,Direction::Horizontal, 5);
    } catch (exception e) {
        cout<<"invalid position, row can't be negative"<< endl;
    }
    try {
        my_notebook.erase(0,4,-5,Direction::Horizontal, 6);
    } catch (exception e) {
        cout<<"invalid position, column can't be negative"<< endl;
    }
    try {
        my_notebook.erase(0,4,97,Direction::Horizontal, 6);
    } catch (exception e) {
        cout<<"invalid position, can't erase in column bigger then 100"<< endl;
    }
    try {
        my_notebook.erase(0,4,200,Direction::Vertical, 2);
    } catch (exception e) {
        cout<<"invalid position, can't erase in column bigger then 100"<< endl;
    }

    my_notebook.erase(0,4,17,Direction::Vertical, 10);
    my_notebook.erase(0,13,6,Direction::Horizontal, 5);

    try {
        my_notebook.write(0,4,17,Direction::Vertical,"something");
    } catch (exception e) {
        cout<<"can't write into spot that has already benn erased"<< endl;
    }

    //////////////// end erase ///////////////

    //////////////// start reading ///////////////
    cout << "\n\nreading: \n"<< endl;

    try {
        my_notebook.read(-20,4,5,Direction::Horizontal, 3);
    } catch (exception e) {
        cout<<"invalid position,page can't be negative"<< endl;
    }
    try {
        my_notebook.read(0,-4,5,Direction::Horizontal, 5);
    } catch (exception e) {
        cout<<"invalid position, row can't be negative"<< endl;
    }
    try {
        my_notebook.read(0,4,-5,Direction::Horizontal, 6);
    } catch (exception e) {
        cout<<"invalid position, column can't be negative"<< endl;
    }
    try {
        my_notebook.read(0,4,97,Direction::Horizontal, 6);
    } catch (exception e) {
        cout<<"invalid position, can't read in column bigger then 100"<< endl;
    }
    try {
        my_notebook.read(0,4,200,Direction::Vertical, 2);
    } catch (exception e) {
        cout<<"invalid position, can't read in column bigger then 100\n"<< endl;
    }

    string my_reading= my_notebook.read(0,3,3,Direction::Horizontal,11);
    cout<< my_reading<< endl;

    //reading also with a spot thet has been erased
    my_reading= my_notebook.read(0,3,9,Direction::Vertical,11);
    cout<< my_reading<< endl;

    // reading from a page that non exits
    my_reading= my_notebook.read(2,3,3,Direction::Horizontal,11);
    cout<< my_reading<< endl;

    //reading random row;
    my_reading= my_notebook.read(0,9,13,Direction::Horizontal,7);
    cout<< my_reading<< endl;
    //////////////// end reading ///////////////

    cout << "\n\nshow page 0: \n" << endl;
    my_notebook.show(0);




}
