#pragma once
#include "Config.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	sf::RenderWindow window_; // main SFML window
	sf::Font jersey_font_;// font used by message

	bool exit_game_; // control exiting game

	void process_events();
	void process_keys(const sf::Event& event);

	void check_keyboard_state();

	void update(sf::Time delta_time);
	void render();
};