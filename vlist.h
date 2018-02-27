// vlist.h
// Rodolfo Lamug
// rlamug

#ifndef VLIST_H
#define VLIST_H

#include<iostream>
#include<string>
#include "video.h"

using namespace std;

class Vlist{

        public:
                Vlist();
                ~Vlist();
                Video* lookup(string title);
                int length();
                void print();
                bool insert(Video *video);
                bool remove(string target);


        private:
                // node declared
                class Node{

                        public:
                                Node(Video *video, Node *next){

                                        m_video = video; m_next = next;
                                }
                                Video *m_video;
                                Node *m_next;
                };
                Node *m_head;
};
#endif
