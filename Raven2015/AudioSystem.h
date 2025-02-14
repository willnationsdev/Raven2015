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
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Music.hpp"
#include <map>
#include <vector>

namespace Raven {

    /*
     * An AudioSystem that receives AudioEvents and updates game systems with
     * audio-related information.
     *
     * -------------
     * Instructions:
     * -------------
     * When users wish to use an audio resource, a LOAD operation must be called
     * from an AudioEvent. Depending on the size of the audio file, you may wish to
     * use a SoundEvent (for under a minute) or MusicEvent (for longer files).
     *
     * Typical operations include PLAY, PAUSE, & STOP. When finished, use the
     * UNLOAD operation to free the space for other resources.
     *
     * Because audio resources are mapped using Entity-filename pairs, users
     * should designate an Entity "owner" for each named audio resource. Attempting
     * to load the same audio file to the same Entity will result in the buffer or
     * stream becoming replaced with another copy of itself, interrupting the
     * previous audio resource regardless of what state it was in.
     *
     */
    class AudioSystem : public ex::System<AudioSystem>,
        public ex::Receiver<AudioSystem> {

    public:
        /*
         *
         */
        explicit AudioSystem() {

        }

        /*
         * Setup necessary static information
         */
        void configure(entityx::EventManager &event_manager) {
            event_manager.subscribe<AudioEvent>(*this);
        }

        /*
         * Continues processing on any existing audio files as necessary
         */
        void update(ex::EntityManager &es, ex::EventManager &events,
            ex::TimeDelta dt) override;

        // Receives and processes AudioEvents
        void receive(const AudioEvent &event);
    };
}