#include "StartScene.hpp"

StartScene::StartScene(const sf::Vector2u& _windowSize,
                       tgui::Gui *_gui,
                       SceneManager* _smgr)
{
    background = new sf::Sprite(*(TextureLoader::Instance().getItem("blue_background")));

    gui = _gui;
    
    playBtn = tgui::Button::create();
    playBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                         (_windowSize.y / 2) - ( playBtn->getSize().y / 2) - 80);
    playBtn->setText("Play");
    playBtn->connect("pressed",[_smgr](){ _smgr->replaceCurrentScene(Scenes::play); });
    gui->add(playBtn);

    settingsBtn = tgui::Button::create();
    settingsBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                             (_windowSize.y / 2) - ( playBtn->getSize().y / 2));
    settingsBtn->setText("Settings");
    settingsBtn->connect("pressed", [_smgr](){ _smgr->replaceCurrentScene(Scenes::settings) ;});
    gui->add(settingsBtn);

    exitBtn = tgui::Button::create();
    exitBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                         (_windowSize.y / 2) - ( playBtn->getSize().y / 2) + 80);
    exitBtn->setText("Exit");
    exitBtn->connect("pressed", [=](){ exit(0); });
    gui->add(exitBtn);
}

StartScene::~StartScene()
{
    gui->removeAllWidgets();
}

void StartScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
}
