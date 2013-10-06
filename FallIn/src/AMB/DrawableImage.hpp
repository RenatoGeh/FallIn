#ifndef DRAWABLEIMAGE_HPP
#define	DRAWABLEIMAGE_HPP

#include <ugdk/math/vector2D.h>
#include <ugdk/graphic/geometry.h>
#include <ugdk/graphic/drawable.h>
#include <ugdk/graphic/drawable/functions.h>
#include <ugdk/graphic/texture.h>

#include "../AMB.hpp"
#include "Vector2D.hpp"

namespace amb {
	class DrawableImage {
	public:
		DrawableImage(const std::string&);
		DrawableImage(const std::string&, const ugdk::math::Vector2D&);
		DrawableImage(const DrawableImage&);
		~DrawableImage();

		DrawableImage& operator = (const DrawableImage&);

		void draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const { ugdk::graphic::DrawSquare(geo * size_, eff, texture_); }
		
		Vector2D<int> size() const { return Vector2D<int>(texture_->width(), texture_->height()); }
		
		ugdk::graphic::Texture *texture() const { return texture_; };
		
	private:
		DrawableImage(ugdk::graphic::Texture*);
		DrawableImage(ugdk::graphic::Texture*, const ugdk::math::Vector2D&);
	private:
		ugdk::graphic::Texture *texture_;
		ugdk::graphic::Geometry size_;
	};
} //namespace amb

#endif	/* DRAWABLEIMAGE_HPP */

