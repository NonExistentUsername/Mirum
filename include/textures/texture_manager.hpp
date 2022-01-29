#pragma once

#include <unordered_map>
#include <string>
#include "itexture_manager.hpp"
#include "itexture_loader.hpp"
#include "lazy_texture_loader.hpp"
#include "texture.hpp"
#include "animated_texture.hpp"

template<class IDType>
class TextureManager : public ITextureManager<IDType> {
private:
    std::unordered_map<IDType, ITextureLoader*> id_to_loader;

    void generate_id_to_loader(const std::unordered_map<IDType, std::string>& id_to_path) {
        for(const auto& x : id_to_path)
            id_to_loader[x.first] = new LazyTextureLoader(new SimpleTextureLoader(std::move(x.second)));
    }
public:
    TextureManager(const std::unordered_map<IDType, std::string>& id_to_path) {
        generate_id_to_loader(id_to_path);
    }

    ITexture* get(IDType id) override {
        return new Texture(id_to_loader[id]->load());
    }

    IAnimatedTexture* get(IDType id, int frames_cnt) override {
        return new AnimatedTexture(id_to_loader[id]->load());
    }

    ~TextureManager() {
        for(auto& x : id_to_loader)
            delete x.second;
    }
};