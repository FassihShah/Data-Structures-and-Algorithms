#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
#include"Song.h"
#include"DLList.h"
class MusicPlayer
{
	DLList<Song> playlist;
	DNode<Song>* currentSongNode;
public:
	MusicPlayer();
	void addSongToPlaylist(const Song& song);
	void removeSongFromPlaylist(int id);
	void playPlaylist();
	void moveForward();
	void moveBackward();
	void displayPlaylist();
	void displayCurrentSong();
	void shufflePlaylist();
	DNode<Song>* mergePlaylists(DLList<Song>& playlist2);
	void deleteNthSongFromEnd(int);
};

#endif