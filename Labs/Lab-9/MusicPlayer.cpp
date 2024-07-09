#include"MusicPlayer.h"
MusicPlayer::MusicPlayer()
{
	currentSongNode = nullptr;
}
void MusicPlayer::addSongToPlaylist(const Song& song)
{
	playlist.addToTail(song);
	if (currentSongNode == nullptr)
	{
		currentSongNode = playlist.head;
	}
}
void MusicPlayer::removeSongFromPlaylist(int id)
{
	if (playlist.head == nullptr)
		return;
	DNode<Song>* temp = playlist.head;
	while (temp != nullptr && temp->data.songID != id)
	{
		temp = temp->next;
	}
	if (temp->data.songID == id)
	{
		if (currentSongNode == temp)
			moveForward();
		if (temp == playlist.head)
		{
			temp->next->prev = nullptr;
			playlist.head = playlist.head->next;
			delete temp;
		}
		else if (temp == playlist.tail)
		{
			temp->prev->next = nullptr;
			playlist.tail = playlist.tail->prev;
			delete temp;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
}
void MusicPlayer::playPlaylist()
{
	if (playlist.head == nullptr)
		return;
	DNode<Song>* curr = currentSongNode;
	while (curr != nullptr)
	{
		cout << curr->data.songID << endl;
		curr = curr->next;
	}
}
void MusicPlayer::moveForward()
{
	if (playlist.head == nullptr)
		return;
	if (currentSongNode->next == nullptr)
	{
		currentSongNode = playlist.head;
	}
	else
	{
		currentSongNode = currentSongNode->next;
	}
}
void MusicPlayer::moveBackward()
{
	if (playlist.head == nullptr)
		return;
	if (currentSongNode->prev == nullptr)
	{
		currentSongNode = playlist.tail;
	}
	else
	{
		currentSongNode = currentSongNode->prev;
	}
}
void MusicPlayer::displayPlaylist()
{
	if (playlist.head == nullptr)
		return;
	DNode<Song>* temp = playlist.head;
	while (temp != nullptr)
	{
		cout << temp->data.songID << " ";
		temp = temp->next;
	}
}
void MusicPlayer::displayCurrentSong()
{
	if (playlist.head == nullptr)
		return;
	cout << currentSongNode->data.songID;
}
void MusicPlayer::shufflePlaylist()
{
	DNode<Song>* temp = playlist.head;
	DNode<Song>* d = nullptr;
	while (temp != nullptr && temp->next != nullptr)
	{
		if (playlist.head == temp)
			playlist.head = playlist.head->next;
		if (d != nullptr)
			d->next = temp->next;
		d = temp;
		temp = temp->next;
		d->next = temp->next;
		temp->next = d;
		temp = temp->next->next;
	}
}
DNode<Song>* MusicPlayer::mergePlaylists(DLList<Song>& playlist2)
{
	DNode<Song>* temp1 = playlist.head;
	DNode<Song>* temp2 = playlist2.head;
	DLList<Song> merged;
	while (temp1 != nullptr && temp2 != nullptr)
	{
		if (temp1->data.songID > temp2->data.songID)
		{
			merged.addToTail(temp2->data);
			temp2 = temp2->next;
		}
		else if (temp1->data.songID < temp2->data.songID)
		{
			merged.addToTail(temp1->data);
			temp1 = temp1->next;
		}
		else
		{
			merged.addToTail(temp1->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	while (temp1 != nullptr)
	{
		merged.addToTail(temp1->data);
		temp1 = temp1->next;
	}
	while (temp2 != nullptr)
	{
		merged.addToTail(temp2->data);
		temp2 = temp2->next;
	}
	return merged.head;
}
void MusicPlayer::deleteNthSongFromEnd(int n)
{
	if (n == 0)
		return;
	DNode<Song>* temp = playlist.tail;
	while (n > 1)
	{
		temp = temp->prev;
		n--;
	}
	if (temp == playlist.head)
	{
		if (currentSongNode == temp)
			moveForward();
		temp->next->prev = nullptr;
		playlist.head = playlist.head->next;
		delete temp;
	}
	else if (temp == playlist.tail)
	{
		if (currentSongNode == temp)
			moveBackward();
		temp->prev->next = nullptr;
		playlist.tail = playlist.tail->prev;
		delete temp;
	}
	else if (temp != nullptr)
	{
		if (currentSongNode == temp)
			moveBackward();
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
}