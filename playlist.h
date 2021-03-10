
/* Name: Andrew Stade
Date: 3/6/2019
Section: 2 */

#include "song.h"

class Playlist
{
public:
    Playlist();
    ~Playlist();
    
    void AddSong(const char* t, const char* a, Style s, double si);
    int FindTitle(char* findT);
    int FindArtist(char* searchA);
    void Output(char* search) const;
    void Delete(int s);
    double GetMBSize() const;
    void AddSize(double si);
    void SubSize(double si);
    void Sort();
    void CatSum(int s);
    void SDisplay();
    int GetCurrentSize() const;

private:
    int maxSize;
    int currentSize;
    double ssize;
    Song* songArr;
    void Grow();
};