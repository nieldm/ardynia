#include "entity.h"

void Entity::render(Renderer* renderer, uint8_t frame) {
    if (renderPtr != NULL) {
        renderPtr(this, renderer, frame);
    } else if (tiles != NULL && maskTiles != NULL) {
        renderer->drawExternalMask(x, y, tiles, maskTiles, 0, 0);
    } else {
        renderer->drawOverwrite(x, y, tiles, 0);
    }

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, w, h, BLACK);
#endif
}

EntityType Entity::update(Arduboy2* arduboy, uint8_t frame) {
    if (updatePtr != NULL) {
        return updatePtr(this, arduboy, frame);
    }

    return UNSET;
}

void Entity::onCollide(BaseEntity* other) {}

void Entity::onCollide(uint8_t tile) {}