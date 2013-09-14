/*
 * MainWindow.cpp
 *
 *  Created on: Sep 13, 2013
 *      Author: Tyler
 */

#include "MainWindow.h"

#include <gl/gl.h>
#include <gl/glu.h>

#include <iostream>

MainWindow::MainWindow() {
	width = height = 0;
	running = false;
}

MainWindow::MainWindow(int width, int height, const char* title) {
	create(width, height, title);
}

MainWindow::~MainWindow() {
}

void MainWindow::create(int w, int h, const char* title) {
	width = w;
	height = h;
	create(sf::VideoMode(width, height, 32), title);
}

void MainWindow::initGL() {
	glClearColor(0, 0, 0.2f, 1);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat) width / (GLfloat) height, 1.0f, 200.0f);

	glMatrixMode(GL_MODELVIEW);
}

void MainWindow::run() {
	if (running) {
		return;
	}

	running = true;
	while (running) {
		input();
		render();
	}
}

void MainWindow::stop() {
	if (running) {
		running = false;
	}
}

void MainWindow::input() {
	sf::Event event;
	while (pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			stop();
		} else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				stop();
			}
		}
	}
}

void MainWindow::render() {
}
