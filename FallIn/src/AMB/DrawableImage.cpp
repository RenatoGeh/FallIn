#include "DrawableImage.hpp"
#include "ugdk/graphic/drawable/textbox.h"

#include <map>

#include <ugdk/graphic/texture.h>

namespace {
	struct TextureReferenceCount {
		int count;
		const std::string textureName;
	};
	
	std::map<std::string, ugdk::graphic::Texture*> memorizationMap;
	std::map<ugdk::graphic::Texture*, TextureReferenceCount> referenceCount;
	
	ugdk::graphic::Texture *getTexture(const std::string& name) {
		auto it = memorizationMap.lower_bound(name);
		if(it != memorizationMap.end() && !(memorizationMap.key_comp()(name, it->first))) {
			referenceCount[it->second].count++; //add a reference
			return it->second;
		} else {
			ugdk::graphic::Texture *t = ugdk::graphic::Texture::CreateFromFile(name);
			memorizationMap.insert(it, std::pair<const std::string, ugdk::graphic::Texture*>(name, t));
			referenceCount.insert(std::pair<ugdk::graphic::Texture*, TextureReferenceCount>(t, {1, name})); //initializes it with one reference
			return t;
		}
	}
	
	inline ugdk::graphic::Texture *addReference(ugdk::graphic::Texture *t) {
		referenceCount[t].count++;
		return t;
	}
	
	void removeTextureReference(ugdk::graphic::Texture *t) {
		auto it = referenceCount.find(t);
		if(--(it->second.count) == 0) {
			memorizationMap.erase(it->second.textureName);
			referenceCount.erase(it);
			delete t;
		}
	}
	
	const ugdk::math::Vector2D _VecZero(0,0);
}

namespace amb {
	DrawableImage::DrawableImage(const std::string& fileName) : DrawableImage(getTexture(fileName)) {}

	DrawableImage::DrawableImage(const std::string& fileName, const ugdk::math::Vector2D& size) : DrawableImage(getTexture(fileName), size) {}

	DrawableImage::DrawableImage(ugdk::graphic::Texture* texture) : DrawableImage(texture, ugdk::math::Vector2D(texture->width(), texture->height())) {}

	DrawableImage::DrawableImage(ugdk::graphic::Texture* texture, const ugdk::math::Vector2D& size) : texture_(texture), size_(_VecZero, size) {}

   DrawableImage::DrawableImage(const DrawableImage& other) : texture_(addReference(other.texture_)) { size_.Compose(other.size_); }
        
	DrawableImage::~DrawableImage() { removeTextureReference(texture_); }

	DrawableImage& DrawableImage::operator = (const DrawableImage& other) {
		if(texture_ != other.texture_) {
			removeTextureReference(texture_);
			texture_ = addReference(other.texture_);
		}
		size_ = other.size_;
	}
}