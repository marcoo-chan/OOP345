// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/12/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <string>
#include <list>
#include <iostream>

using namespace std;

namespace sdds
{
	struct Song
	{
		string m_artist;
		string m_title;
		string m_album;
		string m_year;
		double m_price;
		size_t m_songLength;
	};

	class SongCollection
	{
		vector<Song> m_songs;

	public:
		SongCollection(const char* file);
		void display(std::ostream& out) const;
		std::string& trim(std::string& str);
		void sort(const char * field);
		void cleanAlbum();
		bool inCollection(const char * artist) const;
		std::list<Song> getSongsForArtist(const char * artist) const;
	};

	ostream& operator<<(ostream& out, const Song& theSong);
}

#endif