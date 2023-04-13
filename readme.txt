# SomeRPG
Welcome to SomeRPG!

## Goals of the game
Go into various rooms of a dungeon and become the strongest hero of the world! In the end, fight with the great menace that is awaiting someone to challenge it.

## Character
The main characteristics of a character is:
- Name
- Level
- Class
- Weapon
- Skills
- Resources (HP, MP, SP)
- Critical Chance
- Critical Damage
- Defense
- Equipment

## Map
Will be rendered a char map every round to the player check where can go. Exemple (WIP):

Floor 1
|------------------------|
|        | F2 |          |
|--|                 I   |
| D1      P              |
|--|            @        |
|      @         - D2 -  |
|                |    |  |
|------------------------|

Subtitles:
- DX: Door number x
- P: Player symbol
- @: Enemy
- FX: Floor number x
- I: item (WIP)

## Gameplay
There are 2 states of gameplay. The first one will be the roaming, which player can use the arrow keys to walk in the map. At every input, the map will be rendered again (enemies will be static, for now). When player touches some enemy, will enter in a fighting state, and a new interface will be rendered.

### Roaming
Map will be rendered.

### Fighting (Player)
A simple menu with some options will be rendered. Example:
|======================= BATTLE =====================|
| Turn 2 (Player)                                    |
|     Hero         (90  HP, 100 MP, 50 SP)           |
|     Enemy        (100 HP, 100 MP, 50 SP)           |
|                                                    |
| Log: Enemy used slash! Player lost 10 HP           |
|                                                    |
| Actions:                                           |
| 1 - Attack                                         |
| 2 - Inventory                                      |
| 3 - Run                                            |
|====================================================|

#### Attack
|====================== ATTACK ======================|
| Turn 2 (Player)                                    |
|     Hero         (90  HP, 100 MP, 50  SP)          |
|     Enemy        (100 HP, 100 MP, 100 SP)          |
|                                                    |
| Log: Enemy used slash! Player lost 10 HP           |
|                                                    |
| Actions (use up or down to select):                |
| (*) - Fireball (-10 MP)                            |
| ( ) - Smash (-5 SP)                                |
| ( ) - Return                                       |
|====================================================|

### Inventory
|==================== INVENTORY =====================|
| Turn 2 (Player)                                    |
|     Lvl 09 Hero         (90  HP, 100 MP, 50  SP)   |
|     Lvl 08 Enemy        (100 HP, 100 MP, 100 SP)   |
|                                                    |
| Log: Enemy used slash! Player lost 10 HP           |
|                                                    |
| Actions (use up or down to select):                |
| (*) - Mana Potion (+10 MP)                         |
| ( ) - Health Potion (+5 HP)                        |
| ( ) - Return                                       |
|====================================================|

### Fighting (Enemy) (WIP)
|======================= BATTLE =====================|
| Turn 2 (Enemy)                                     |
|     Hero         (90  HP, 100 MP, 50 SP)           |
|     Enemy        (80  HP, 100 MP, 50 SP)           |
|                                                    |
| Log: Hero used fireball! Enemy lost 20 HP          |
|                                                    |
| Enemy is preparing to act...                       |
|====================================================|