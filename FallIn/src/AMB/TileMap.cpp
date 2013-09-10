#include "TileMap.hpp"
#include "DrawableImage.hpp"

namespace amb {
	TileMap::TileMap(int width, int height) : size_(width, height), realSize_(width*_tileSize, height*_tileSize), tiles_(new Tile*[width]) {
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
	
	
	void TileMap::Draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {
		//placeholder just for testing, of course
		static DrawableImage di("resources/Lydia.png");
		di.Draw(geo, eff);
	}
}

