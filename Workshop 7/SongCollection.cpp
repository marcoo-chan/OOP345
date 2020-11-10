// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/12/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <cstring>
#include "SongCollection.h"

using namespace std;

void printbar(std::ostream&); //from main function (create header bar)

namespace sdds
{
	std::string & SongCollection::trim(std::string & str)
	{
		while (str.length() > 0 && str[0] == ' ')
		{
			str.erase(0, 1);
		}

		while (str.length() > 0 && str[str.length() - 1] == ' ')
		{
			str.erase(str.length() - 1, 1);
		}

		return str;
	}

	void SongCollection::sort(const char * field)
	{
		std::sort(m_songs.begin(), m_songs.end(), [=](Song song1, Song song2)
		{
			if (!strcmp(field, "title"))
			{
				return song1.m_title < song2.m_title;
			}

			if (!strcmp(field, "album"))
			{
				return song1.m_album < song2.m_album;
			}

			return song1.m_songLength < song2.m_songLength;
		});
	}

	void SongCollection::cleanAlbum()
	{
		std::for_each(m_songs.begin(), m_songs.end(), [](Song& song)
		{
			if (song.m_album == "[None]")
			{
				song.m_album.clear();
			}
		});
	}

	bool SongCollection::inCollection(const char * artist) const
	{
		return any_of(m_songs.begin(), m_songs.end(), [artist](const Song& song) 
		{
			return song.m_artist == string(artist);
		});
	}

	std::list<Song> SongCollection::getSongsForArtist(const char * artist) const
	{
		std::list<Song> artistSongs;

		std::for_each(m_songs.begin(), m_songs.end(), [artist, &artistSongs](Song song)
		{
			if (song.m_artist == artist)
			{
				artistSongs.push_back(song);
			}
		});

		return artistSongs;
	}

	SongCollection::SongCollection(const char * fileName)
	{
		std::ifstream fileInput(fileName);
		std::string line;

		if (fileInput.fail() || !fileInput)
		{
			throw string("ERROR: Cannot open file [") + fileName + ("]. \n");
		}

		//fileInput.open(fileName); ???

		while (getline(fileInput, line, '\n'))
		{
			Song song;

			song.m_title = line.substr(0, 25);
			trim(song.m_title);

			song.m_artist = line.substr(25, 25);
			trim(song.m_artist);

			song.m_album = line.substr(50, 25);
			trim(song.m_album);

			song.m_year = line.substr(75, 5);
			trim(song.m_year);

			song.m_songLength = stoi(line.substr(80, 5));
			song.m_price = stod(line.substr(85, 5));
			m_songs.push_back(song);
		}
	}

	void SongCollection::display(std::ostream& out) const
	{
		for_each(m_songs.begin(), m_songs.end(), [&](const Song song)  //vector m_songs
		{
			out << song << endl;
		});

		printbar(out); //header bar
		out << "| " << setfill(' ') << setw(77) << "Total Listening Time: ";

		auto totalTime = [](unsigned int seconds) 
		{
			string m_songDuration;

			int mins = seconds / 60;
			int hours = mins / 60;
			seconds -= mins * 60;

			m_songDuration = std::to_string(hours);
			m_songDuration += ":";

			if (seconds < 10)
			{
				m_songDuration += string("0") + to_string((mins % 60)) + ":";

				if (seconds < 10)
				{
					m_songDuration += string("0") + to_string((seconds % 60));
				}

				else
				{
					m_songDuration += std::to_string((seconds % 60));
				}
			}

			else
			{
				m_songDuration += std::to_string((mins % 60)) + ":";

				if (seconds < 10)
				{
					m_songDuration += string("0") + to_string((seconds % 60));
				}

				else
				{
					m_songDuration += std::to_string((seconds % 60));
				}
			}

			return m_songDuration;
		};

		string sum = totalTime(accumulate(m_songs.begin(), m_songs.end(), 0, [=](int total, const Song& song)
		{
			return total + song.m_songLength;
		}));

		out << sum;

		out << " |" << std::endl;
	}

	ostream & operator<<(ostream & out, const Song & theSong)
	{
		auto songLength = [](unsigned int seconds)
		{
			string m_songDuration;
			int min = seconds / 60; //calculate minutes
			seconds -= min * 60; //calculate seconds

			if (seconds < 10)
			{
				m_songDuration = to_string(min) + ":" + "0" + to_string(seconds);
			}

			else
			{
				m_songDuration = to_string(min) + ":" + to_string(seconds);
			}

			return m_songDuration;
		};

		out << "| " << left << setw(20) << theSong.m_title;
		out << " | " << left << setw(15) << theSong.m_artist;
		out << " | " << left << setw(20) << theSong.m_album;
		out << " | " << right << setw(6) << theSong.m_year;
		out << " | " << songLength(theSong.m_songLength);
		out << " | " << setprecision(2) << fixed << theSong.m_price << " |";

		return out;
	}
}