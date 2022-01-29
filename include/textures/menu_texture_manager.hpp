#pragma once

#include "texture_manager.hpp"

enum MENU_TEXTURE {
    GREEN_BIG_BUTTON,
};

class MenuTextureManager : public TextureManager<MENU_TEXTURE> {
private:
    static const std::unordered_map<MENU_TEXTURE, std::string> _menu_textures;
public:
    MenuTextureManager();
};