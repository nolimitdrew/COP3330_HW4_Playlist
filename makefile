menu_executable: menu.o playlist.o song.o
	g++ -o menu menu.o playlist.o song.o
	chmod 755 menu

menu.o: menu.cpp playlist.h song.h
	g++ -c menu.cpp
    
playlist.o: playlist.cpp playlist.h song.h
	g++ -c playlist.cpp    
    
song.o: song.cpp song.h
	g++ -c song.cpp

clean:
	rm -f *.o