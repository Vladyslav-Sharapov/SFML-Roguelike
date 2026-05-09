#include "Game.h"
#include <iostream>
#include <optional>

Game::Game() :
	window_{ sf::VideoMode{ sf::Vector2u{config::window_width, config::window_height}, 32U }, config::window_title },
	exit_game_{ false } //when true game will exit
{
	// setupers
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time time_since_last_update = sf::Time::Zero;

	constexpr sf::Time time_per_frame = sf::seconds(1.0f / static_cast<float>(config::frame_rate));
	while (window_.isOpen())
	{
		process_events(); // as many as possible
		time_since_last_update += clock.restart();
		while (time_since_last_update > time_per_frame)
		{
			time_since_last_update -= time_per_frame;
			process_events(); // at least 60 fps
			update(time_per_frame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::process_events()
{
	while (const std::optional new_event = window_.pollEvent())
	{
		if (new_event->is<sf::Event::Closed>()) // close window message 
		{
			exit_game_ = true;
		}

		if (new_event->is<sf::Event::KeyPressed>()) //user pressed a key
		{
			process_keys(*new_event);
		}
	}
}

void Game::process_keys(const sf::Event& event)
{
	if (const auto* key_pressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (sf::Keyboard::Key::Escape == key_pressed->code)
		{
			exit_game_ = true;
		}
	}
}

void Game::check_keyboard_state()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		exit_game_ = true;
	}
}



void Game::update(sf::Time delta_time)
{
	check_keyboard_state();
	if (exit_game_)
	{
		window_.close();
	}
}

void Game::render()
{
	window_.clear(sf::Color::Black);

	window_.display();
}
