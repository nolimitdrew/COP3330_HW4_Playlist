
/* Name: Andrew Stade
Date: 3/6/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "song.h"

using namespace std; 

ostream& operator<<(ostream& os, const Song& s)
{
    double mb = s.size;
    mb = mb / 1000;
    
    cout.setf(ios::left);
    cout.width(35);
    os << fixed << showpoint<< setprecision(1);
    os << s.title;
    cout.width(25);
    os << s.artist;
    if (s.category == POP)
    {
        os << "Pop";
    }
    else if (s.category == ROCK)
    {
        os << "Rock";
    }
    else if (s.category == ALTERNATIVE)
    {
        os << "Alt";
    }
    else if (s.category == COUNTRY)
    {
        os << "Ctry";
    }
    else if (s.category == HIPHOP)
    {
        os << "HH";
    }
    else if (s.category == PARODY)
    {
        os << "Par";
    }
    
    if (s.size >= 10000.0 && s.size < 99999.9)
    {
        os << fixed << showpoint<< setprecision(1);
        os << "\t           " << mb << endl;
    }
    else if (s.size >= 100000.0 && s.size < 999999.9)
    {
        os << fixed << showpoint<< setprecision(1);
        os << "\t          " << mb << endl;
    }
    else if (s.size >= 1000000.0)
    {
        os << fixed << showpoint<< setprecision(1);
        os << "\t         " << mb << endl;
    }
    else
    {
        os << fixed << showpoint<< setprecision(1);
        os << "\t            " << mb << endl;
    }
    
    return os;
}

Song::Song()
// default constructor, sets up blank song object
{
    enum Style{P,R,A,C,H,Y};
    
    strcpy(title, " ");
    strcpy(artist, " ");
    category == 'F';
    size = 0;
}

void Song::Set(const char* t, const char* a, Style st, int sz)
// the Set function should allow incoming data to be received through
{   
    strcpy(title, t);
    strcpy(artist, a);
    category = st;
    size = sz;
}

const char* Song::GetTitle() const
// returns the title stored in the object
{
    return title;
}

const char* Song::GetArtist() const
// returns the artist
{
    return artist;
}

int Song::GetSize() const
// returns the file size in kilobytes
{
    return size;
}

Style Song::GetCategory() const
{
    return category;
}