
/* Name: Andrew Stade
Date: 3/6/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "song.h"
#include "playlist.h"

using namespace std;


Playlist::Playlist()
{
    currentSize = 0;
    maxSize = 5;
    ssize = 0;
    songArr = new Song[maxSize];
}

Playlist::~Playlist()
{
    delete [] songArr;
}
    
void Playlist::AddSong(const char* t, const char* a, Style s, double si)
{
    if (currentSize == maxSize)
    {
       Grow();
       cout << "Array being resized to " << maxSize << " allocated slots";
    }
    Song s1;
    AddSize(si);
    s1.Set(t,a,s,si);
    songArr[currentSize++] = s1; 
}

void Playlist::AddSize(double si)
{
    si = si / 1000;
    ssize = ssize + si; 
}

void Playlist::SubSize(double si)
{
    si = si / 1000;
    ssize = ssize - si; 
}

int Playlist::FindTitle(char* searchT)
{
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(songArr[i].GetTitle(), searchT) == 0)
        {
            return i; 
        } 
    }
    return -1;
}

int Playlist::FindArtist(char* searchA)
{
    for (int i = 0; i < currentSize; i++) 
    {
        if (strcmp(songArr[i].GetArtist(), searchA) == 0)
        {
             return i;
        }
    }   
    return -1;
}

void Playlist::Output(char* search) const
{
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(songArr[i].GetTitle(), search) == 0)
        {
            cout << songArr[i];
        }  
        else if (strcmp(songArr[i].GetArtist(), search) == 0)
        {
            cout << songArr[i];            
        }
    }
}

void Playlist::Delete(int s)
{
    double temp;

    for (int i = s; i < currentSize; i++)
    {
        temp = songArr[s].GetSize();
    }
    SubSize(temp);
    for (int i = s+1; i < currentSize; i++)
    {
       songArr[i-1] = songArr[i];
    }
    currentSize--;
}

double Playlist::GetMBSize() const
{
    return ssize;
}

void Playlist::Sort()
{
    // Not this time :(
}

void Playlist::CatSum(int c)
{
    double csize = 0.00;
    int counter = 0;
    
    cout << "\n";
    for (int i = 0; i < currentSize; i++)
    {
        if (songArr[i].GetCategory() == c)
        {
           counter++;
           csize = csize + songArr[i].GetSize();
           cout << songArr[i];
        }
    }
    csize = csize / 1000;
    cout << "\nTotal songs in this category = " << counter;
    cout << fixed << showpoint<< setprecision (2);
    cout << "\nTotal file size = " << csize << " MB\n";
}

void Playlist::SDisplay()
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << songArr[i];
    }
}

int Playlist::GetCurrentSize() const
{
    return currentSize;
}

void Playlist::Grow()
// Increase the array; if needed
{
    maxSize = currentSize + 5;
    Song* newList = new Song[maxSize];
    
    for (int i = 0; i < currentSize; i++)
        newList[i] = songArr[i];
    
    
    delete [] songArr;
    songArr = newList;
}