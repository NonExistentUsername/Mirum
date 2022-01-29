#include "textures/menu_texture_manager.hpp"

const std::unordered_map<MENU_TEXTURE, std::string> MenuTextureManager::_menu_textures = []() {
    std::unordered_map<MENU_TEXTURE, std::string> result;
    result[MENU_TEXTURE::GREEN_BIG_BUTTON] = "textures/button.png";
    return result;
}();

MenuTextureManager::MenuTextureManager(): 
    TextureManager<MENU_TEXTURE>(_menu_textures) {}