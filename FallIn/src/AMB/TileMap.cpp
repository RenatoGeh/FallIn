#include "TileMap.hpp"

#include "../AMB.hpp"
#include "DrawableImage.hpp"

namespace {
	using ugdk::graphic::Geometry;
}

namespace amb {
	TileMap::TileMap(int width, int height) : size_(width, height), tiles_(new Tile*[width]) {
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
}

