// vlist.cpp
// Rodolfo Lamug
// rlamug

#include<iostream>
#include<string>

//two header files
#include"vlist.h"
#include"video.h"

using namespace std;

//constructor
Vlist::Vlist()
{
        m_head = NULL;
}

//destructor
Vlist::~Vlist()
{
        Node *ptr = m_head;
        while (ptr != NULL)
        {
                Node *temp;
                temp = ptr;
                ptr = ptr->m_next;
                delete temp;
        }
}
//lookup function: checks the list for the title. 
Video* Vlist::lookup (string title)
{
        //checks if list is empty first. If it's not it proceeds
        if (!m_head)
                return NULL;

        for ( Node *tmp = m_head; tmp != NULL; tmp = tmp->m_next )
        {
                if( title == tmp->m_video->title() )
                {
                        return tmp->m_video;
                }
        }
        return NULL;
}
//legnth function: goes through list until the end is reached and then returns length
int Vlist::length()
{
        int length = 0;

        for (Node *ptr = m_head; ptr != NULL; ptr=ptr->m_next)
        {
                length++;
        }
        return length;
}
//print function: prints the list
void Vlist::print()
{
        Node *ptr = m_head;
        while(ptr != NULL)
        {
                ptr->m_video->print();
                ptr = ptr->m_next;
        }
}
//insert function: it will first add a new node if empty, then it will create the rest.
bool Vlist::insert(Video *video)
{
        //checks if head node is empty and adds node
        if (m_head == NULL)
        {
                m_head = new Node(video, m_head);
                return true;
        }
        //checks for duplicates
        if ( m_head->m_video->title() == video->title() )
        {
                return false;
        }
        //adds node if header is empty
        if( m_head->m_video->title() > video->title() )
        {
                m_head = new Node(video, m_head);
                return true;
        }
        else
        {
                Node *ptr = m_head;
                while (( ptr->m_next != NULL) && (ptr->m_next->m_video->title() <= video->title()))
                {
                        if( ptr->m_next->m_video->title() == video->title() )
                        {
                                return false;
                        }
                        ptr = ptr->m_next;
                }
                ptr->m_next = new Node(video, ptr->m_next);
                return true;
        }
}
// remove function: finds the given node and deletes it from the list
bool Vlist::remove(string target)
{
        if (m_head==NULL)
        {
                return false;
        }
        if ( m_head->m_video->title() == target )
        {
                Node *tmp = m_head;
                m_head = m_head->m_next;
                delete tmp;
                return true;
        }
        Node *ptr = m_head;
        while (ptr->m_next != NULL && ptr->m_next->m_video->title() != target)
        {
                ptr = ptr->m_next;
        }
        if (ptr->m_next == NULL)
                return false;
        Node *tmp = ptr->m_next;
        ptr->m_next = ptr->m_next->m_next;
        delete tmp;
        return true;
}
