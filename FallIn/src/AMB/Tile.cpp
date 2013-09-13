#include "Tile.hpp"

namespace amb {
	Tile::Tile() : body_(NULL) {}
	Tile::Tile(int x, int y) : index_(x, y), body_(NULL) {}
}

