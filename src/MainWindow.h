/*
 * MainWindow.h
 *
 *  Created on: Sep 13, 2013
 *      Author: Tyler
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <SFML/Window.hpp>

#include "../Head.h"

class MainWindow : public sf::Window {
public:
	MainWindow();
	MainWindow(int width, int height, const char * title);
	virtual ~MainWindow();

	void create(int width, int height, const char * title);

	void run();
	void stop();

	using sf::Window::create;
private:
	bool running;
	int width, height;

	void initGL();

	void input();
//	void update();
	void render();
};

#endif /* MAINWINDOW_H_ */
