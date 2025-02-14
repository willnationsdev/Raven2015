# Raven2015
a 2D, C++ game engine developed jointly by Will Nations, Hailee Ammons, and Kevin Wang 

# Developers
##Summary

Raven builds primarily upon two base libraries: The Simple and Fast Multimedia Library (SFML) and EntityX, an entity-component system. For detailed instructions on how to use the systems within Raven, please consult those libraries. In essence...

Principles:  
1. All objects in the game are Entities, containers with an id number.  
2. Entities contain Component objects that house DATA ONLY. No methods are permitted on entities.  
3. A set of System classes update continuously, gathering all entities matching a particular pattern and operating on them in some manner. The entirety of the logic for one's game must be stored within the System classes.  
4. Systems can communicate between one another using Event objects.  

Current Component list:
- Transform - provides 2D position data
- Rigidbody - provides physics related movement data (velocity / acceleration, etc.)
- BoxCollider - provides physics related boundaries for collision detection
- SoundMaker - provides the ability to load & play small sound files.
- MusicMaker - provides the ability to open & stream large sound files.
- Renderer - provides the ability to render elements relative to the Transform of the Entity.
- Pawn - allows the object to respond to input.
- Villain - a "tagging" component to recognize "enemies" in a game.
- Tracer - An AI component that moves the Entity closer to the nearest Pawn over time.
- Pacer - An AI component that moves the Entity along an axis in a ping-pong fashion.

Current System list:
- MovementSystem - updates the positions of all objects according to their current Rigidbody stats.
- CollisionSystem - cycles through all objects and detects collisions. Emits collision events as appropriate.
- AudioSystem - Responds to Music and Sound events to perform operations on audio resource files.
- InputSystem - Listens for user input and triggers events based on "actions" which are mapped to inputs.
- RenderingSystem - Cycles through all Entities with Renderers and draws objects associated with them.
- GUISystem - Displays the engine's editor windows and interface.
- TimerSystem (not currently operational) - Allows the user to trigger a function after a set period of time.
- XMLSystem (partly operational) - "Saves" content by serializing and deserializing entity components and state information.

Current Event list:
- CollisionEvent - responds to a collision between two entities
- SoundEvent - performs an operation on a small audio file.
- MusicEvent - performs an operation on a large audio file.

## Current Issues

The Engine's default content currently has a sample project that showcased some small features at our latest demonstration. Needs to be updated to have these removed.

## Bugs & Workarounds

The collision system is missing a proper implementation at the moment. The game therefore begins lagging very quickly as you add more entities with colliders.

## Installation

This installation guide will assume a build for Visual Studio 2015, built for a Windows x64 platform. As a team, we wished to develop for VS, and the only edition of the VC++ compiler that would work with the EntityX library was that of VS2015. Both of the main libraries used for this game engine are usable for Windows, Mac OSX, and Linux platforms, but as we only have explicit experience in installing for Windows' Visual Studio, that is the only one we will be creating a direct guide for. If you wish to develop on a different platform or use a different IDE, I suggest you visit the documentation for the two libraries listed below.

1. Ensure that Visual Studio 2015 is installed on your computer. Any edition of the actual IDE will be fine.

2. Create your Visual Studio 2015 project. Make sure that it is listed as a C++ Win32 Application.

3. Clone the git repository using the integrated git plugin for Visual Studio 2015.

4. Right click your project title, then go to Properties. At the top, make sure "All Configurations" is selected, then go to Configuration Properties -> VC++ Directories. Under "Include Directories", go to the "SFML" folder in the cloned repository (not the longer VisualStudio2015 build version) and ensure that the "include" folder is selected. Hit Select Folder. Then hit Apply. After that, under "Library Directories", go to the same location and select the "lib" folder and hit Apply.

5. Build the project and attempt to run it. It -should- compile and link just fine if you've fixed any pathing issues in the previous step.

#Players

Feel free to experiment with moving around a blue dot using the WASD or up/down/left/right arrow keys.
