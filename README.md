Name: Nils Van de Velde

Studentnumber: 20240345

## 📋 Project Evaluation Checklist

### 1. Core Game Requirements (40 Points)

- [x] **Startup screen & Scoreboard**
    - *Implementation:* Startup screen is implemented in de MenuState, where the play button is created in the
      constructor and the scores are loaded via a json file. After that the render function creates a static title,
      playTexts and inputText so that they are only created once. The render function draws the text to the screen and
      calls renderScoreboard() which creates a sorted vector of the scores (pair<string, int>) and draws the top 5 with
      40 pixels height difference between every score.
- [x] **Maze & Collision Correctness**
    - *Implementation:* Mazes are implemented via txt files and are read in the World constructor. World checks for
      collisions every tick but it doesn't check for collisions with walls. The movement code (found in tick()) of
      pacman and the ghost prevent them (mostly) from running against walls. World gives them a wallValidator function (
      via std::function) so that they are aware of where the walls are. Using this system I don't need to check for
      intersecting rectangles with walls.
- [x] **Smooth Continuous Movement**
    - *Implementation:* The movement of Pacman is handled by the tick function, where its speed is dynamically adapted
      based on direction and deltaTime. A wallValidator ensures that Pacman cannot move into walls, and queued
      directions are processed to enable seamless turns. The alignToCenter helper function keeps Pacman centered within
      grid cells, while a correction speed prevents abrupt stops when movement constraints are met. This implementation
      achieves smooth and continuous movement across varying directions while avoiding jittery behavior during
      transitions between tiles.
- [x] **Ghost AI**
    - *Modes Implemented:* Fear, Eaten, Chasing, Waiting.
    - *Logic:* Ghosts use BFS and manhattan distance to determine which direction they should go to, depending on the
      movement type. You have 2 Cutting type ghosts, which look 4 tiles ahead of pacman and then uses BFS to determine
      the best direction to go to, if this fails we use Manhattan distance as a fallback. The remaining 2 ghosts are the
      Fixed and Chasing ghosts. The Chasing ghost uses the same system as the Cutting ones, without the lookahead and
      the Fixed ghost chooses a random index from a vector of candidates. The chasing mode/boolean is only used for the
      delay of the ghosts. The eaten mode/boolean is used to change their target in BFS/Manhattan to their spawn location and
      to update their sprite. Fear mode will be discussed later.
- [x] **Coin & Fruit Score Modifiers**
    - *Implementation:* When a collision with a Collectable and Pacman is detected, score is notified via a
      CollectEvent, which tells the score how many points it should add. The score also calculates a bonus with the
      following formula using base as the points from the collectable: min(base / (timeSinceCollection + 0.1f), base).
      We add 0.1 to avoid division by 0, even though it shouldn't take place in a normal game. The bonus is capped at
      base, so you can maximally reach a 100% bonus. Coins are worth 10 points, fruit is 100 points and ghosts are 200.
      Since the bonus is calculated using the points of the current collected collectable, it is better to eat a lot of
      coins right before collecting fruit or ghosts.
- [x] **Fear Mode & Ghost Reversal**
    - *Implementation:* Just like wall detection a ghostFearer function is given to the pacmanCollisionHandler, so that
      when pacman collects a fruit, the handler can set the ghosts to fear mode without knowledge of the ghosts
      themselves. When the ghosts are in fear mode they all use Manhattan distance to run away from pacman using the
      boolean maximize. We call the same function but tell it to maximize the distance via this maximize boolean.
- [x] **Level Clearing & Scaling Difficulty**
    - *Implementation:* A level is cleared when all collectables are collected. This is detected in World simply by
      checking if the collectables vector is empty. Every tick we check if a collectable is marked as expired (the
      marking of expired happens on collision with pacman), and if it is expired we remove from the vector and decouple
      it's observers, so that the observers don't try to observe a non-existing object. When a level is cleared we
      increment the level counter in LevelState and make a new world and give it the new level. I have a system in place
      so that you can use different maps, but I don't use it myself. The ghosts have level as a member and use it to
      calculate fear duration: 5 - 0.5 * (level - 1) and speed: 0.3 + 0.05 * (level - 1). You start at level 1 and there
      is technically no limit to which level you can reach, except of course integer limit. This combined with the smart
      movement of the ghosts make higher levels really difficult (at the time of writing this I haven't reached level 2
      yet). After every level completion you get a quick win screen via VictoryState, which shows which level you
      cleared.
- [x] **Life System & Game Over**
    - *Implementation:* You have 3 lives and when you hit a ghost, you lose one and then pacman and ghost positions are
      reset directly after the death animation. During the death animation only pacman, score and lives are rendered and
      ticked. Lives reset to 3 after every level. After you lose all 3, detected by world via pacmanCollisionHandler,
      you go to the DefeatState where you can return to menu and your score is saved to the json.

### 2. Software Design & Code Architecture (40 Points)

- [x] **Clear MVC Separation**
    - *Implementation:* In src you have the EntityViews which have all sprite data and get other data from EntityModels
      via Events and the notify function. The notification of events often happen in the tick functions of EntityModels,
      World or a collision handler. Thus, EntityView is the view, EntityModel is the Model and World (which calls the
      tick functions) and PacmanCollisionHandler are the controllers.
- [x] **Design Patterns Implemented**
    - **MVC:** Explained above.
    - **Observer:** Observers use the update function to handle their own logic based on events. For example: PacmanView
      updates it's sprite according to a TickEvent which tells it where to display pacman and which way he's facing.
    - **Abstract Factory:** Abstract Factory consists of createEntity functions which are then implemented in its
      subclass EntityFactory.
    - **Singleton:** I used the singleton pattern for Random and Stopwatch. I had discussed with classmates about making
      Camera a singleton, but since my Camera doesn't have any member variables, it only contains static functions. The
      way I implemented the Singleton pattern was by deleting the constructors and using a unique_ptr as the instance.
      When you call getInstance a reference to the object is returned.
    - **State Pattern:** I have a StateManager which contains a stack of States via unique_ptr's and only the manager is
      able to call the update functions for input and rendering.
- [x] **Logic as Standalone Library**
    - *Implementation:* My logic and library and representation (which I simply call src) have separate CMakeLists so
      that logic and src are compiled separately. Then I have a main CMakeList which links them together.
- [x] **Camera & Normalized Coordinates**
    - *Implementation:* Camera consists of 3 static functions: showScore (displays score), showLives (displays lives)
      and project, which projects and entity to the screen by transforming the normalized coordinates to pixel
      coordinates. I do this by first calculating cell dimensions (Coords keep normalized width and height of the
      entity), we then calculate the center of the screen and an offset which we use to calculate the pixel x and y
      coordinates as follows: center_x + (coords.x * offset_x). To kind of translate this formula, the coordinates of a
      entity are always its center coordinates, so to project them to the screen we start at the center of the screen
      and calculate how much to the right/left and up/down we have to go to find its relative pixel coordinates.
- [x] **Polymorphism & Extensibility**
    - *Implementation:*

### 3. Documentation & Deliverables (20 Points)

- [ ] **Project Defence Video**
    - [Gameplay Demo (3 min)](https://youtu.be/V1pQ9D90kqM)
    - [Technical Explanation (7 min)](https://youtu.be/V1pQ9D90kqM)

- [x] **Written Documentation**
    - [x] 2-Page Report & Design Rationale
    - [x] Doxygen/API Documentation (Comments in code)

### 4. Bonus Features (Up to 10 Points)

- [ ] **Extra Gameplay / Visuals**
- [ ] **Sounds / Music**
- [x] **Smarter AI (BFS / ~~A~~ * )**
- [ ] **Procedural Maps**
- [ ] **Multithreading**
- [x] **Extra Design Patterns**
    - *Details:* Visitor pattern for Collision
