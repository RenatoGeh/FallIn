#include "TileMap.hpp"
#include "DrawableImage.hpp"

namespace {
	using ugdk::graphic::Geometry;
}

namespace amb {
	TileMap::TileMap(int width, int height) : size_(width, height), realSize_(width*_TileSize, height*_TileSize), tiles_(new Tile*[width]) {
		for(int i = 0; i < width; i++) {
			tiles_[i] = new Tile[height];
			for(int j = 0; j < height; j++)
				tiles_[i][j].setIndex(i, j);
		}
	}
	
	TileMap::~TileMap() {
		for(int i = 0; i < size_.x; i++)
			delete[] tiles_[i];
		delete[] tiles_;
	}
	
	
	void TileMap::Draw(const Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {
		//placeholder just for testing, of course
		static DrawableImage di("resources/Lydia.png");
		for(int i = 0; i < size_.x; i++)
			for(int j = 0; j < size_.y; j++)
				di.Draw(geo * Geometry(ugdk::math::Vector2D(i, j) *= _TileSize), eff);
	}
}

