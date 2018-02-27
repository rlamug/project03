// main.cpp
// Rodolfo Lamug
// rlamug

#include <iostream>
#include <string>
#include <istream>
#include <fstream>

// class Video and class Vlist
#include "video.h"
#include "vlist.h"

using namespace std;


int main()
{
        // variable declaration
        Vlist list;
        float length;
        int rating;
        string title, url, comment, option;

        //user inputs option and each option carries out function 
        while (getline(cin,option))
        {
                //insert function
                if ( option == "insert")
                {
                        getline(cin,title);
                        getline(cin,url);
                        getline(cin,comment);
                        cin>>length;
                        cin>>rating;
                        cin.ignore();
                        Video *new_video = new Video(title, url, comment, length, rating);
                        // error command if it is already in list. each respective command has an error if not valid
                        if (list.insert(new_video) == 0)
                        {
                                cerr << "Could not insert video <" <<title<< ">, already in list."<<endl;
                        }
                }
                //remove function
                else if ( option == "remove" )
                {
                        getline(cin, title);
                        if (list.remove(title) == 0)
                        {
                                cerr<<"Title <" <<title<< "> not in list, could not delete." << endl;
                        }
                }
                //lookup function
                else if ( option == "lookup")
                {
                        getline(cin, title);
                        Video *video = list.lookup(title);
                        if (video)
                        {
                                video->print();
                        }
                        else
                        {
                                cerr << "Title <" << title << "> not in list." << endl;
                        }
                        list.print();
                }
                //length function
                else if ( option == "length" )
                {
                        cout << list.length() << endl;
                }
                //print function
                else if ( option == "print" )
                {
                        list.print();
                }
                // If the command it not valid it will error out that it doesnt exist. 
                else
                {
                        cerr << "<" << option << "> is not a legal command, giving up." << endl;
                        return 1;
                }
        }

        return 0;
}
