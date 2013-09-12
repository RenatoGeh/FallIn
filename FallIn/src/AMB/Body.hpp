#ifndef BODY_HPP
#define	BODY_HPP
#include <ugdk/action/entity.h>
#include <ugdk/graphic/drawable.h>

#include "Vector2D.hpp"

namespace amb {
    const int _TileSize = 64;
    
    class Body : public ugdk::action::Entity, public ugdk::graphic::Drawable {
    public:
      typedef Point2D<int> TilePosition;
		
      virtual ~Body() {}
      
      virtual void Update(double dt) = 0;
		void update(double dt) { Update(dt); }
		void draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const { Draw(geo, eff); }
		
		virtual void onDelete() {}

      TilePosition& getTile() { return tile_; }
      const TilePosition& getTile() const { return tile_; }
      void translate(const TilePosition& diff) { tile_ += diff; }
      void translate(int tx, int ty) { tile_.add(tx, ty); }
      void setTile(const TilePosition& tile) { tile_ = tile; }
      void setTile(int x, int y) { tile_.set(x, y); }
    protected:
      Body() {} 
      TilePosition tile_;
    };
}

#endif	/* BODY_HPP */

