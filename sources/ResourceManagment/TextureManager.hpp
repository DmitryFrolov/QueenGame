#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <boost/filesystem.hpp>
#include "ResourceManager.hpp"

class TextureManager : public ResourceManager<sf::Texture>
{
private:
	std::string defaultPathToFiles; 

private:
	TextureManager();	
	void loadAllItemsFromDirectory(const std::string pathToFiles) override;		
	
public:
	static TextureManager const& getInstance();
	
	TextureManager(TextureManager const&) = delete;
	TextureManager& operator=(TextureManager const&) = delete;
};

#endif //TEXTURE_MANGER_HPP