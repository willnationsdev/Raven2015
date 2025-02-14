#pragma once
#include "Common.h"
#include "Game.h"
#include "ComponentLibrary.h"
#include "EventLibrary.h"

namespace Raven {

    struct EntityLibrary {

        // Turns the first entity into a replica of the second entity before returning the first entity.
        // Simply combines the use of clearEntity and copyComponents with the full set of template parameters.
        static ex::Entity copyEntity(ex::Entity toReturn, ex::Entity toCopy);

        // Clears the last component from an entity. Base case for the parameter pack version to work recursively
        template <typename C>
        static void clearEntity(ex::Entity e, C* c);

        // Clears all components from the given entity
        // Usage:
        // /* Entity e1 with Data, Transform, and Rigidbody */
        // clearEntity<Data, Transform, Rigibody>(e1); // OR
        // clearEntity<Data, Transform, Rigibody, BoxCollider, etc.>(e1);
        template <typename C, typename... Components>
        static void clearEntity(ex::Entity e, C* c, Components*... components);

        // Having troubles with clearEntity. LNK2019 (no implementation for...) when using only Data, Transform, Rigidbody.
        // Resorting to a direct function for that functionality to speed things along.
        static void clearCoreComponents(ex::Entity e);

        // Copies the last component from one entity to another. Base case for the parameter pack version to work recursively
        template <typename C>
        static ex::Entity copyEntityComponents(ex::Entity toReturn, ex::Entity toCopy, C* c);

        // Copies all possible components from the given toCopy entity into the toReturn entity
        // By the end, the following 4 conditions will be true:
        // 1. If toReturn has a component that toCopy has, toReturn's version will be replaced with a copy of toCopy's
        // 2. If toReturn does not have a component that toCopy has, it will not have a copy of toCopy's
        // 3. Any components that toReturn has that toCopy doesn't will remain untouched
        // 4. Component pointer members will have deep copies made
        // Usage:
        // /* Entity e1 with some set of components, Entity e2 with some different set of components */
        // copyComponents<Data, Transform, etc.>(e1, e2, *e2.component<Data>().get(), *e2.component<Transform>().get(), etc.); // OR
        // copyComponents<COMPONENT_TYPE_LIST>(e1, e2, COMPONENTS_OF_ENTITY(toCopy); // captures all possible components
        template <typename C, typename... Components>
        static ex::Entity copyEntityComponents(ex::Entity toReturn, ex::Entity toCopy, C* c, Components*... components);

        // Given a particular enumerated component type, the corresponding component handle will be acquired. Base case.
        template <typename C>
        static ex::ComponentHandle<C> getComponentByType(ex::Entity entity, ComponentType type, C* c) {
            return (C::getType() == type) ? entity.component<C>() : return nullptr;
        }

        // Given a particular enumerated component type, the corresponding component handle will be acquired. Recursive case.
        template <typename C, typename... Components>
        static ex::ComponentHandle<C> getComponentByType(ex::Entity entity, ComponentType type, C* c, Components*... components) {
            return (C::getType() == type) ? entity.component<C>() : getComponentByType<Components...>(components);
        }

        // Given a particular component name, the corresponding component handle will be acquired. Base case.
        template <typename C>
        static ex::ComponentHandle<C> getComponentByName(ex::Entity entity, std::string name, C* c) {
            return (C::getElementName() == name) ? entity.component<C>() : return nullptr;
        }

        // Given a particular component name, the corresponding component handle will be acquired. Recursive case.
        template <typename C, typename... Components>
        static ex::ComponentHandle<C> getComponentByName(ex::Entity entity, std::string name, C* c, Components*... components) {
            return (C::getElementName() == name) ? entity.component<C>() : getComponentByType<Components...>(components);
        }

        struct Create {

            static ex::Entity Entity(std::string entityName = "Default Entity", bool enumerateName = true) {
                ex::Entity e = cmn::game->entities.create();
                ex::ComponentHandle<Data> data = e.assign<Data>(entityName, "NULL", false, false);
                e.assign<Transform>();
                e.assign<Rigidbody>();
                if (enumerateName) {
                    data->name += " " + std::to_string(counter++);
                }
                return e;
            }

            // FUNCTION WILL BECOME OBSOLETE WITH THE IMPLEMENTATION OF PREFABS
            static ex::Entity Player(std::string playerName = "Default Player") {
                ex::Entity e = Entity(playerName);
                e.component<Data>()->persistent = true;
                e.assign<Pawn>();
                e.assign<BoxCollider>();
                e.assign<Renderer>();
                // Assign a RenderableSprite to the Player character here
            }

        private:
            static unsigned int counter;

        };
    };
}