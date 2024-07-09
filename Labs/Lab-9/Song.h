#ifndef SONG_H
#define SONG_H
#include"String.h"
class Song
{
public:
	int songID;
	String title;
	String artist;
	String album;
	int durationInSeconds;
	Song();
	Song(int id, String t, String a, String al, int d);
};
#endif