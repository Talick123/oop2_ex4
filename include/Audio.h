#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class Audio {
public:
	Audio(sf::SoundBuffer* soundBuffer);
	~Audio();

	void playMusic(int volume = 10, bool loop = false);
	void stopPlayMusic();
private:
	void initMusic(sf::SoundBuffer* soundBuffer);
	sf::Sound m_sound;
};