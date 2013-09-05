#include "DrawableImage.hpp"
#include "ugdk/graphic/texture.h"

namespace amb {
	DrawableImage::DrawableImage(const std::string& fileName) : texture_(Texture::CreateFromFile(fileName)), drawable_(texture_), deletesTexture_(true) {}

	DrawableImage::DrawableImage(const std::string& fileName, const Vector2D& size) : texture_(Texture::CreateFromFile(fileName)), drawable_(texture_, size), deletesTexture_(true) {}

	DrawableImage::DrawableImage(Texture* texture) : texture_(texture), drawable_(texture_), deletesTexture_(false) {}

	DrawableImage::DrawableImage(Texture* texture, const Vector2D& size) : texture_(texture), drawable_(texture_, size), deletesTexture_(false) {}

	DrawableImage::~DrawableImage() {
		if(deletesTexture_)
			delete texture_;
	}

	DrawableImage& DrawableImage::operator =(const DrawableImage& other) {
		texture_ = other.texture_;
		drawable_ = other.drawable_;
		deletesTexture_ = true;
	}
} //namespace amb