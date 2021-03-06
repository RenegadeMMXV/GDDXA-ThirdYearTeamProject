/**
*	@author			Ciaran Bent [K00221230]
*					Owen O'Dea	[K00218956]
*					Rory Ryan	[K00218864]
*	@creationDate	2019/01/15	YYYY/MM/DD
*	@description
*/

#include "Button.h"

/**
*	@description	- Default Contructor
*/
GUI::Button::Button() {

}

/**
*	@description	- Paramaterised Constructor
*/
GUI::Button::Button(std::string s, sf::Font& font, sf::Vector2f position, sf::Uint32 style) {
	//set position
	this->m_position = position;

	//set initial state
	this->m_btnstate = GUI::ButtonState::normal;
	this->m_sinceLastClick = sf::Time::Zero;

	//set button style
	this->m_style = style;

	switch (this->m_style) {
	case GUI::ButtonStyle::none:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(255, 255, 255, 100);
		this->m_bgHover = sf::Color(200, 200, 200, 100);
		this->m_bgClicked = sf::Color(150, 150, 150);
		break;

	case GUI::ButtonStyle::save:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(0, 255, 0, 100);
		this->m_bgHover = sf::Color(0, 200, 0, 100);
		this->m_bgClicked = sf::Color(0, 150, 0);
		break;

	case GUI::ButtonStyle::cancel:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(255, 0, 0, 100);
		this->m_bgHover = sf::Color(200, 0, 0, 100);
		this->m_bgClicked = sf::Color(150, 0, 0);
		break;

	case GUI::ButtonStyle::clean:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(0, 255, 255, 100);
		this->m_bgHover = sf::Color(0, 200, 200, 100);
		this->m_bgClicked = sf::Color(0, 150, 150);
		break;

	default:
		break;
	}

	//set up text
	this->m_text.setString(s);
	this->m_text.setFont(font);
	this->m_text.setOrigin(this->m_text.getGlobalBounds().width / 2, this->m_text.getGlobalBounds().height / 2);
	this->m_text.setFillColor(this->m_textNormal);

	//set some defauts
	this->m_borderRadius = 5.f;
	this->m_borderThickness = 0.f;
	this->m_size = sf::Vector2f(this->m_text.getGlobalBounds().width * 1.5f, this->m_text.getGlobalBounds().height * 1.5f);

	this->m_button = sf::RectangleShape(this->m_size);
	this->m_button.setOrigin(this->m_button.getGlobalBounds().width / 2, this->m_button.getGlobalBounds().height / 2);
	this->m_button.setPosition(this->m_position);

	sf::Vector2f textPosition = sf::Vector2f(this->m_button.getPosition().x, this->m_button.getPosition().y - this->m_text.getGlobalBounds().height / 2);

	this->m_text.setPosition(textPosition);

	this->m_shadow.setFont(font);
	this->m_shadow = this->m_text;
	this->m_shadow.setOrigin(this->m_shadow.getGlobalBounds().width / 2, this->m_shadow.getGlobalBounds().height / 2);
	this->m_shadow.setPosition(textPosition.x + 3.f, textPosition.y + 3.f);
}


/**
*	@description	- Destructor
*/
GUI::Button::~Button() {
	//Destructor
}


/**
*	@description	- Set the Size of the button
*/
void GUI::Button::setSize(unsigned int size) {
	this->m_fontSize = size;
	this->m_text.setCharacterSize(this->m_fontSize);
	this->m_text.setOrigin(this->m_text.getGlobalBounds().width / 2, this->m_text.getGlobalBounds().height / 2);
	this->m_shadow.setCharacterSize(this->m_fontSize);
	this->m_shadow.setOrigin(this->m_shadow.getGlobalBounds().width / 2, this->m_shadow.getGlobalBounds().height / 2);
	this->m_size = sf::Vector2f(this->m_text.getGlobalBounds().width * 1.5f, (this->m_text.getGlobalBounds().height + this->m_text.getGlobalBounds().height) * 1.5f);
	this->m_button = sf::RectangleShape(this->m_size);
}


/**
*	@description	- Set the text to be displayed on the button
*/
void GUI::Button::setText(std::string s) {
	this->m_text.setString(s);
	this->m_shadow = this->m_text;
}


/**
*	@description	- Set a Pre-Assigned ButtonStyle to the button
*/
void GUI::Button::setStyle(sf::Uint32 style) {
	//set button style
	this->m_style = style;

	switch (this->m_style) {
	case GUI::ButtonStyle::none:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(255, 255, 255, 100);
		this->m_bgHover = sf::Color(200, 200, 200, 100);
		this->m_bgClicked = sf::Color(150, 150, 150);
		break;

	case GUI::ButtonStyle::save:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(0, 255, 0, 100);
		this->m_bgHover = sf::Color(0, 200, 0, 100);
		this->m_bgClicked = sf::Color(0, 150, 0);
		break;

	case GUI::ButtonStyle::cancel:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(255, 0, 0, 100);
		this->m_bgHover = sf::Color(200, 0, 0, 100);
		this->m_bgClicked = sf::Color(150, 0, 0);
		break;

	case GUI::ButtonStyle::clean:
		this->m_textNormal = sf::Color(255, 255, 255);
		this->m_textHover = sf::Color(255, 255, 255);
		this->m_textClicked = sf::Color(255, 255, 255);
		this->m_bgNormal = sf::Color(0, 255, 255, 100);
		this->m_bgHover = sf::Color(0, 200, 200, 100);
		this->m_bgClicked = sf::Color(0, 150, 150);
		break;

	default:
		break;
	}
}


/**
*	@description	- Set the font of the text to be displayed on the button
*/
void GUI::Button::setFont(sf::Font& font) {
	this->m_text.setFont(font);
	this->m_shadow.setFont(font);
}


/**
*	@description	- Update the button
*/
void GUI::Button::update(sf::Event& e, sf::Time t, sf::RenderWindow& window) {
	//perform updates for settings from user
	sf::Vector2f textPosition;
	switch (this->m_style) {
	case GUI::ButtonStyle::none:
		this->m_size = sf::Vector2f(this->m_text.getGlobalBounds().width * 1.5f, this->m_text.getGlobalBounds().height * 1.75f);
		this->m_button = sf::RectangleShape(this->m_size);
		this->m_button.setOrigin(this->m_button.getGlobalBounds().width / 2, this->m_button.getGlobalBounds().height / 2);
		this->m_button.setPosition(this->m_position);
		this->m_text.setOrigin(this->m_text.getGlobalBounds().width / 2, this->m_text.getGlobalBounds().height / 2);
		textPosition = sf::Vector2f(this->m_button.getPosition().x, this->m_button.getPosition().y - this->m_text.getGlobalBounds().height / 2);
		this->m_text.setPosition(textPosition);
		this->m_text.setFillColor(this->m_textNormal);
		this->m_shadow.setOrigin(this->m_shadow.getGlobalBounds().width / 2, this->m_shadow.getGlobalBounds().height / 2);
		this->m_shadow.setPosition(textPosition.x + 3.f, textPosition.y + 3.f);
		this->m_shadow.setFillColor(sf::Color(0, 0, 0));
		break;

	case GUI::ButtonStyle::save:
		this->m_size = sf::Vector2f(this->m_text.getGlobalBounds().width * 1.5f, this->m_text.getGlobalBounds().height * 1.75f);
		this->m_button = sf::RectangleShape(this->m_size);
		this->m_button.setOrigin(this->m_button.getGlobalBounds().width / 2, this->m_button.getGlobalBounds().height / 2);
		this->m_button.setPosition(this->m_position);
		this->m_text.setOrigin(this->m_text.getGlobalBounds().width / 2, this->m_text.getGlobalBounds().height / 2);
		textPosition = sf::Vector2f(this->m_button.getPosition().x, this->m_button.getPosition().y - this->m_text.getGlobalBounds().height / 2);
		this->m_text.setPosition(textPosition);
		this->m_text.setFillColor(this->m_textNormal);
		this->m_shadow.setOrigin(this->m_shadow.getGlobalBounds().width / 2, this->m_shadow.getGlobalBounds().height / 2);
		this->m_shadow.setPosition(textPosition.x + 3.f, textPosition.y + 3.f);
		this->m_shadow.setFillColor(sf::Color(0, 0, 0));
		break;

	case GUI::ButtonStyle::cancel:
		this->m_size = sf::Vector2f(this->m_text.getGlobalBounds().width * 1.5f, this->m_text.getGlobalBounds().height * 1.75f);
		this->m_button = sf::RectangleShape(this->m_size);
		this->m_button.setOrigin(this->m_button.getGlobalBounds().width / 2, this->m_button.getGlobalBounds().height / 2);
		this->m_button.setPosition(this->m_position);
		this->m_text.setOrigin(this->m_text.getGlobalBounds().width / 2, this->m_text.getGlobalBounds().height / 2);
		textPosition = sf::Vector2f(this->m_button.getPosition().x, this->m_button.getPosition().y - this->m_text.getGlobalBounds().height / 2);
		this->m_text.setPosition(textPosition);
		this->m_text.setFillColor(this->m_textNormal);
		this->m_shadow.setOrigin(this->m_shadow.getGlobalBounds().width / 2, this->m_shadow.getGlobalBounds().height / 2);
		this->m_shadow.setPosition(textPosition.x + 3.f, textPosition.y + 3.f);
		this->m_shadow.setFillColor(sf::Color(0, 0, 0));
		break;

	case GUI::ButtonStyle::clean:
		this->m_size = sf::Vector2f(this->m_text.getGlobalBounds().width * 1.5f, this->m_text.getGlobalBounds().height * 1.75f);
		this->m_button = sf::RectangleShape(this->m_size);
		this->m_button.setOrigin(this->m_button.getGlobalBounds().width / 2, this->m_button.getGlobalBounds().height / 2);
		this->m_button.setPosition(this->m_position);
		this->m_text.setOrigin(this->m_text.getGlobalBounds().width / 2, this->m_text.getGlobalBounds().height / 2);
		textPosition = sf::Vector2f(this->m_button.getPosition().x, this->m_button.getPosition().y - this->m_text.getGlobalBounds().height / 2);
		this->m_text.setPosition(textPosition);
		this->m_text.setFillColor(this->m_textNormal);
		this->m_shadow.setOrigin(this->m_shadow.getGlobalBounds().width / 2, this->m_shadow.getGlobalBounds().height / 2);
		this->m_shadow.setPosition(textPosition.x + 3.f, textPosition.y + 3.f);
		this->m_shadow.setFillColor(sf::Color(0, 0, 0));
		break;

	default:
		break;
	}

	// Get the current mouse position in the active window
	sf::Vector2i m_mousePosition = sf::Mouse::getPosition(window);

	// Is the mouse hovering over the Button?
	bool mouseInButton = m_mousePosition.x >= this->m_button.getPosition().x - this->m_button.getGlobalBounds().width / 2
		&& m_mousePosition.x <= this->m_button.getPosition().x + this->m_button.getGlobalBounds().width / 2
		&& m_mousePosition.y >= this->m_button.getPosition().y - this->m_button.getGlobalBounds().height / 2
		&& m_mousePosition.y <= this->m_button.getPosition().y + this->m_button.getGlobalBounds().height / 2;

	if (e.type == sf::Event::MouseMoved) {
		if (mouseInButton) {
			this->m_btnstate = GUI::ButtonState::hovered;
		}
		else {
			this->m_btnstate = GUI::ButtonState::normal;
		}
	}

	if (e.type == sf::Event::MouseButtonPressed) {
		if ((t.asMilliseconds() - this->m_sinceLastClick.asMilliseconds()) > 500.0f) {
			switch (e.mouseButton.button) {
			case sf::Mouse::Left:
				if (mouseInButton) {
					this->m_btnstate = GUI::ButtonState::clicked;
					this->m_sinceLastClick = t;
				}
				else {
					this->m_btnstate = GUI::ButtonState::normal;
				}
				break;
			}
		}
	}

	if (e.type == sf::Event::MouseButtonReleased) {
		switch (e.mouseButton.button) {
		case sf::Mouse::Left:
			if (mouseInButton) {
				this->m_btnstate = GUI::ButtonState::hovered;
			}
			else{
				this->m_btnstate = GUI::ButtonState::normal;
			}
			break;
		}
	}

	switch (this->m_btnstate) {
	case GUI::ButtonState::normal:
		this->m_button.setFillColor(this->m_bgNormal);
		this->m_text.setFillColor(this->m_textNormal);
		break;

	case GUI::ButtonState::hovered:
		this->m_button.setFillColor(this->m_bgHover);
		this->m_text.setFillColor(this->m_textHover);
		break;

	case GUI::ButtonState::clicked:
		this->m_button.setFillColor(this->m_bgClicked);
		this->m_text.setFillColor(this->m_textClicked);
		break;
	}
}

/**
*	@description	- Draw the button.  Overloads default draw() inherited from sf::Drawable
*/
void GUI::Button::draw(sf::RenderTarget& targetWindow, sf::RenderStates states) const {
	switch (this->m_style) {
	case GUI::ButtonStyle::none:
		targetWindow.draw(this->m_button, states);
		targetWindow.draw(this->m_shadow, states);
		targetWindow.draw(this->m_text, states);
		break;

	case GUI::ButtonStyle::save:
		targetWindow.draw(this->m_button, states);
		targetWindow.draw(this->m_shadow, states);
		targetWindow.draw(this->m_text, states);
		break;

	case GUI::ButtonStyle::cancel:
		targetWindow.draw(this->m_button, states);
		targetWindow.draw(this->m_shadow, states);
		targetWindow.draw(this->m_text, states);
		break;

	case GUI::ButtonStyle::clean:
		targetWindow.draw(this->m_button, states);
		targetWindow.draw(this->m_shadow, states);
		targetWindow.draw(this->m_text, states);
		break;

	default:
		break;
	}
}