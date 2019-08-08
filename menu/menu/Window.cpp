#include "Window.hpp"
#include "SharedContext.hpp"

Window::Window(SharedContext * ctx) : ctx(ctx) {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    renderWindow.create(sf::VideoMode(desktopMode.width, desktopMode.height), "DIY Arcade Menu", sf::Style::Fullscreen);
}

Window::~Window() {
    renderWindow.close();
}

void Window::pollEvents() {
    sf::Event event;
    while(renderWindow.pollEvent(event)) {
        ctx->eventManager->handlePolledEvent(event);
    }
}

sf::RenderWindow * Window::getRenderWindow() {
    return &renderWindow;
}

void Window::clear() {
    renderWindow.clear(sf::Color(50, 50, 50));
}

void Window::display() {
    renderWindow.display();
}