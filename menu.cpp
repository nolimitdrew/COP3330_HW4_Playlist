
/* Name: Andrew Stade
Date: 3/6/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include "playlist.h"

using namespace std;

void MainMenu() // Main menu function
{
    cout << "\n\t" << "\t*** PLAYLIST MENU ***\n" ;
    cout << "\tA" << "\tAdd a song to playlist\n" ;
    cout << "\tF" << "\tFind a song in the playlist\n" ;  
    cout << "\tD" << "\tDelete a song\n" ;
    cout << "\tS" << "\tShow the playlist\n" ;
    cout << "\tC" << "\tList songs from one Category\n" ;
    cout << "\tZ" << "\tTotal playlist size\n" ;
    cout << "\tO" << "\tSort playlist\n" ;
    cout << "\tM" << "\tShow this Menu\n" ;
    cout << "\tX" << "\teXit Program\n" ;
}

int main()
{
    Playlist p;
    char input;
    int numSongs = 0;
    
    cout << "*** Welcome to Playlist Manager ***\n" ;
    
    MainMenu();
    
    do
    {
        cout << "\n> ";
        cin >> input;
        
        
        if (input == 'A' || input == 'a')
        {
            char artistArr[21];
            char titleArr[31];
            char sty;
            char check1;
            double ssize;
            Style category;
            
            
            cout << "Enter title: ";
            cin.ignore();
            cin.getline(titleArr,31);
            cout << "Enter artist: ";
            cin.getline(artistArr,21);
            do
            {
            cout << "Enter Category - (P)op, (R)ock, (A)lternative, (C)ountry, (H)iphop, or Parod(Y): ";
            cin >> sty;
                if (sty == 'P' || sty == 'p')
                {
                    category = POP;
                }
                else if (sty == 'R' || sty == 'r')
                {
                    category = ROCK;
                }
                else if (sty == 'A' || sty == 'a')
                {
                    category = ALTERNATIVE;
                }
                else if (sty == 'C' || sty == 'c')
                {
                    category = COUNTRY;
                }
                else if (sty == 'H' || sty == 'h')
                {
                    category = HIPHOP;
                }
                else if (sty == 'Y' || sty == 'y')
                {
                    category = PARODY;
                }
                else
                {
                    cout << "\nInvalid Category entry. Please re-enter" << endl;
                }      
            check1 = sty;
            } while (check1 != 'P' && check1 != 'p' && check1 != 'R' && check1 != 'r' && check1 != 'A' && check1 != 'a' && check1 != 'C' && check1 != 'c' && check1 != 'H' && check1 != 'h' && check1 != 'Y' && check1 != 'y');         
            do
            {
                cout << "Enter size: ";
                cin >> ssize;
                if (ssize <= 0)
                {
                    cout << "Must enter a positive size. Please re-enter" << endl;
                }
                else
                {}
            } while (ssize <= 0);
            p.AddSong(titleArr, artistArr, category, ssize);
            numSongs = numSongs + 1;
        }
        else if (input == 'F' || input == 'f')
        {
            char Search[31];
            int result;
            int result2;
            
            cout << "Enter search string (title or artist): ";
            cin.ignore();
            cin.getline(Search,31);

            result = p.FindTitle(Search);
            if (result != -1)
            {
                cout << "\nSong Found:\n";
                p.Output(Search);
            }            
            else
            {
                result2 = p.FindArtist(Search);
                if (result2 != -1)
                {
                    cout << "\nSong Found:\n";
                    p.Output(Search);
                }    
                else
                {
                    cout << "\n\n";
                    cout << Search << ": Not Found\n";  
                }                
            }
        }
        else if (input == 'D' || input == 'd')
        {
            char Delete[31];
            int answer;
            
            cout << "Enter title to delete: ";
            cin.ignore();
            cin.getline(Delete,31);
            
            answer = p.FindTitle(Delete);
            if (answer != -1)
            {
                p.Delete(answer);
                
                numSongs = numSongs - 1;
                cout << "\nSong removed!" << endl;
            }
            else
            {
                cout << "\n";
                cout << Delete << " not found in the playlist" ;
                cout << "\n* No deletion performed *" ;
            }
        }
        else if (input == 'S' || input == 's') 
        {
            if (p.GetCurrentSize() > 0)
            {
                cout.setf(ios::left);
                cout.width(35);
                cout << fixed << showpoint<< setprecision (2);
                cout << "\n*Title*";
                cout.width(25);
                cout << "*Artist*";
                cout << "*Style*    ";
                cout << "*Size (MB)*\n\n";
                p.SDisplay();
                
                cout << "\nNumber of songs = " << numSongs;
                cout << "\nTotal playlist size = ";
                cout << fixed << showpoint<< setprecision (2);
                cout << p.GetMBSize();
                cout << " MB\n";
                
            }
            else 
            {
                cout << "\nNo songs currently in playlist\n";
                cout << "\nNumber of songs = 0";
                cout << "\nTotal playlist size = ";
                cout << fixed << showpoint<< setprecision (2);
                cout << p.GetMBSize();
                cout << " MB\n";
            }
        }
        else if (input == 'C' || input == 'c')
        {
            int temp;
            char choice;
            char check2;
            Style category;
            
            do
            {
            cout << "Enter Category - (P)op, (R)ock, (A)lternative, (C)ountry, (H)iphop, or Parod(Y): ";
            cin >> choice;
                if (choice == 'P' || choice == 'p')
                {
                    temp = 0;
                    p.CatSum(temp);
                }
                else if (choice == 'R' || choice == 'r')
                {
                    temp = 1;
                    p.CatSum(temp);
                }
                else if (choice == 'A' || choice == 'a')
                {
                    temp = 2;
                    p.CatSum(temp);
                }
                else if (choice == 'C' || choice == 'c')
                {
                    temp = 3;
                    p.CatSum(temp);
                }
                else if (choice == 'H' || choice == 'h')
                {
                    temp = 4;
                    p.CatSum(temp);
                }
                else if (choice == 'Y' || choice == 'y')
                {
                    temp = 5;
                    p.CatSum(temp);
                }
                else
                {
                cout << "\nInvalid Category entry. Please re-enter" << endl;
                }      
            check2 = choice;
            } while (check2 != 'P' && check2 != 'p' && check2 != 'R' && check2 != 'r' && check2 != 'A' && check2 != 'a' && check2 != 'C' && check2 != 'c' && check2 != 'H' && check2 != 'h' && check2 != 'Y' && check2 != 'y');       
        }
        else if (input == 'Z' || input == 'z')
        {
            cout << "\nTotal size of playlist = ";
            // Bob's example was an int for total size
            // but I just decided to make mine a double to be extra precise
            cout << p.GetMBSize() * 1000;
            cout << " kilobytes\n";
        }
        else if (input == 'O' || input == 'o')
        {
            
            cout << "Sort by (T)itle or (A)rtist? > ";
            p.Sort();
            
            cout << "Sort complete"; 
            
        }
        else if (input == 'M' || input == 'm') // Main Menu
        {
            MainMenu();
        }
        else if (input != 'X' && input != 'x') // Exit Program
        {
            cout << "Invalid menu choice. Try again.";
        }
        
    } while (input != 'X' && input != 'x');
        
    cout << "\nGoodbye!" << endl;
    
    return 0;
}