/* Classname:   Gaming Platform Frameworks
 * Project:     Raven
 * Version:     1.0
 * 
 * Copyright:   The contents of this document are the property of its creators.
 *              Reproduction or usage of it without permission is prohibited.
 *
 * Owners:      Will Nations
 *              Hailee Ammons
 *              Kevin Wang
 */
#pragma once

#include "entityx\System.h"
#include "EventLibrary.h"

namespace Raven {

    class CollisionSystem : public ex::System<CollisionSystem>,
        public ex::Receiver<CollisionSystem> {

    public:
        /*
         *
         */
        explicit CollisionSystem() {

        }

        /*
         * Setup necessary static information
         */
        void configure(entityx::EventManager &event_manager) {
            event_manager.subscribe<CollisionEvent>(*this);
        }

        /*
         * Iterate through all objects with Colliders and emit CollisionEvents.
         */
        void update(ex::EntityManager &es, ex::EventManager &events,
            ex::TimeDelta dt) override;

        // Picks up CollisionEvents
        void receive(const CollisionEvent &event);

        /*
         * Tests whether two entities' colliders register a collision.
         */
        std::shared_ptr<sf::Vector2f> CollisionSystem::testCollision(ex::Entity leftEntity,
            ex::Entity rightEntity);

    private:
        std::map<ex::Entity, std::set<ex::Entity>> collisionMap;
    };

}
