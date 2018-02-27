// video.h
// Rodolfo Lamug
// rlamug

#include <iostream>
#include <string>

#ifndef VIDEO_H
#define VIDEO_H

using namespace std;

class Video
{

        public:
                Video (string title, string url, string comment, float length, int rating);
                void print();
                bool longer(Video *other);
                bool stars(Video *other);
                bool alphabet(Video *other);
                string title();

        private:
                string m_title, m_url, m_comment;
                float m_length;
                int m_rating;
};
#endif
