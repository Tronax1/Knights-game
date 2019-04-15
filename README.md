# Knights-game
2 players move a night around a board
## Rules
- Human player will always go first
- Knight moves in an L shape
- Knight can only move to a tile once
- Player with unavailable moves loses
## Approach
  The Knight’s move game was modeled using a game tree where the algorithm calculates all the
legal moves available, sets a heuristic cost for each, and plays the best possible move. The code
has some very important functions that implement this functionality.

  The first important step in creating the project was legal moves since a Knight moves in a
particular pattern. The legal ‘L’ shape move can be made by moving two spaces horizontally and
one vertically or two vertically and one horizontally. To ensure this, an adjacency matrix was
made to indicate which squares the Knight could move to from it’s current position. The
Vertices.txt file contains the adjacency, which is then used to create the matrix when creating
the game board. An adjacent matrix was used over the list in implementation because it would
be easier to add and remove edges while playing the game. Using the adjacency matrix also
made it possible to have the Knight start at any position in the beginning instead of having it
start in one specific space and evaluate its decision based on a decision tree.
