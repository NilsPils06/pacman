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
    - *Implementation:*
- [x] **Ghost AI**
    - *Modes Implemented:* Fear, Eaten, Chasing, Collectable.
    - *Logic:* Ghosts use BFS and manhattan distance to determine which direction they should go to, depending on the
      movement type. You have 2 Cutting type ghosts, which look 4 tiles ahead of pacman and then uses BFS to determine
      the best direction to go to, if this fails we use Manhattan distance as a fallback. The remaining 2 ghosts are the
      Fixed and Chasing ghosts. The Chasing ghost uses the same system as the Cutting ones, without the lookahead and
      the Fixed ghost chooses a random index from a vector of candidates. The chasing mode/boolean is only used for the
      delay of the ghosts. The collectable mode/boolean is used to prevent infinite score additions when colliding with
      eaten ghosts. The eaten mode/boolean is used to change their target in BFS/Manhattan to their spawn location and
      to update their sprite. Fear mode will be discussed later.
- [x] **Coin & Fruit Score Modifiers**
    - *Implementation:*
- [x] **Fear Mode & Ghost Reversal**
    - *Implementation:*
- [x] **Level Clearing & Scaling Difficulty**
    - *Implementation:*
- [x] **Life System & Game Over**
    - *Implementation:* ---

### 2. Software Design & Code Architecture (40 Points)

- [x] **Clear MVC Separation**
    - *Implementation:*
- [x] **Design Patterns Implemented**
    - **MVC:** Used as the core architecture.
    - **Observer:** - **Abstract Factory:** - **Singleton:** - **State Pattern:**
- [x] **Logic as Standalone Library**
    - *Implementation:*
- [x] **Camera & Normalized Coordinates**
    - *Implementation:*
- [x] **Polymorphism & Extensibility**
    - *Implementation:* ---

### 3. Documentation & Deliverables (20 Points)

- [ ] **Project Defence Video**
    - [Gameplay Demo (3 min)](LINK_HERE)
    - [Technical Explanation (7 min)](LINK_HERE)

- [ ] **Written Documentation**
    - [ ] 2-Page Report & Design Rationale
    - [ ] Doxygen/API Documentation (Comments in code)

---

### 4. Bonus Features (Up to 10 Points)

- [ ] **Extra Gameplay / Visuals**
    - *Details:*
- [ ] **Sounds / Music**
    - *Details:*
- [x] **Smarter AI (BFS / ~~A~~ * )**
    - *Details:*
- [ ] **Procedural Maps**
    - *Details:*
- [ ] **Multithreading**
    - *Details:*
- [x] **Extra Design Patterns**
    - *Details:* Visitor pattern for Collision