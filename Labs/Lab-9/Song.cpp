#include"Song.h"
Song::Song()
{
	songID = 0;
	durationInSeconds = 0;
}
Song::Song(int i, String t, String a, String al, int d) :title(t), artist(a), album(al)
{
	songID = i;
	durationInSeconds = d;
}