#pragma once

class ITexture;
class IAnimatedTexture;

template<class IDType>
class ITextureManager {
public:
    virtual ITexture* get(IDType id) = 0;
    virtual IAnimatedTexture* get(IDType id, int frames_cnt) = 0;
};