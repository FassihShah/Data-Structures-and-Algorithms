#include<iostream>
#include"MusicPlayer.h"
using namespace std;
int main()
{
	Song s1(1, "Math", "Ali", "Song", 4);
	Song s2(4, "Math", "Ali", "Song", 4);
	Song s3(6, "Math", "Ali", "Song", 4);
	Song s4(8, "Math", "Ali", "Song", 4);
	Song s5(2, "Math", "Ali", "Song", 4);
	Song s6(5, "Math", "Ali", "Song", 4);
	Song s7(7, "Math", "Ali", "Song", 4);
	Song s8(9, "Math", "Ali", "Song", 4);
	DLList<Song> playlist;
	playlist.addToTail(s5);
	playlist.addToTail(s6);
	playlist.addToTail(s7);
	playlist.addToTail(s8);
	MusicPlayer m;
	m.addSongToPlaylist(s1);
	m.addSongToPlaylist(s2);
	m.addSongToPlaylist(s3);
	m.addSongToPlaylist(s4);
	//m.addSongToPlaylist(s5);
	DNode<Song>* temp = m.mergePlaylists(playlist);
	while (temp != nullptr)
	{
		cout << temp->data.songID << " ";
		temp = temp->next;
	}
	cout << endl;
	//m.shufflePlaylist();
	//m.deleteNthSongFromEnd(2);
	//m.displayCurrentSong();
	m.displayPlaylist();
	return 0;
}