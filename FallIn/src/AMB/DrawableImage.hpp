#ifndef DRAWABLEIMAGE_HPP
#define	DRAWABLEIMAGE_HPP
#include <ugdk/math/vector2D.h>
#include <ugdk/math/integer2D.h>
#include <ugdk/action/entity.h>
#include <ugdk/graphic/geometry.h>
#include <ugdk/graphic/drawable.h>
#include <ugdk/graphic/drawable/texturedrectangle.h>
#include <ugdk/graphic/texture.h>
#include <string>
const int _tileSize = 64;
namespace {
	using ugdk::graphic::Texture;
	using ugdk::math::Vector2D;
	using ugdk::math::Integer2D;
	using ugdk::graphic::Geometry;
}

namespace amb {

	class DrawableImage : public ugdk::action::Entity, public ugdk::graphic::Drawable {
	public:
		DrawableImage(const std::string&);
		DrawableImage(const std::string&, const Vector2D&);
		DrawableImage(Texture*);
		DrawableImage(Texture*, const Vector2D&);
		DrawableImage(const DrawableImage&);
		~DrawableImage();

		DrawableImage& operator =(const DrawableImage&);

		void Update(double) {}

		void Draw(const Geometry& geo, const ugdk::graphic::VisualEffect& eff) const { drawable_.Draw(geo * Geometry(position_ * _tileSize), eff); };
		const Vector2D& size() const { return drawable_.size(); };

		Texture *getTexture(void) const { return texture_; };
		bool getDeletesTexture(void) const { return deletesTexture_; } 
		void setDeletesTexture(bool del) { deletesTexture_ = del; }
		Integer2D position_; //tile relative
	private:
		Texture *texture_;
		ugdk::graphic::TexturedRectangle drawable_;
		bool deletesTexture_;
	};
} //namespace amb

#endif	/* DRAWABLEIMAGE_HPP */
