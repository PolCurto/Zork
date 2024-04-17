# Simple Zork-like Game 

## Table of contents
1. [Introduction](#introduction)
2. [General explanation](#general-explanation)
3. [How to play](#how-to-play)
4. [Guide to complete the game](#guide-to-complete-the-game)
5. [Extras](#extras)
6. [Credits](#credits)
7. [License](#license)

## Introduction
This is a simple text-based game like Zork made entirely in C++. It has seven rooms the player can move through, items to be picked up and dropped, stats that can be modified by equipping or using the items you find, and NPCs that move around and can be interacted with.

## General explanation
The game consists in seven rooms, which are connected in the following way:

                  Poison lake--------Dark woods-------King's chamber
                                          |                  |
                                          |                  |
                                          |                  |
                                      Entrance--------Castle main room-------Castle's catacombs
                                          |
                                          |
                                          |
                                     Guest's room
All the connections are available both ways, with no locked doors. 

The player starts in the Entrance room, and has the following stats: 
* Hp
* Attack damage
* Defense
* Agility
* Attack speed
* Equipment slots

In these rooms there are items in the ground, which can be picked up. There are two types of items:
* __Equipment__:  Equipment can be equipped, and raise certain stats of the player while their are equipped. However the player has limited equipment slots.

* __Consumables__: Consumables can be used, and they modify certain player stats for the rest of the game. After used, they disappear. Some consumables are used to increase the equipment slots.

Items can store other items inside themselves. Items can be picked up from the room or from another item the player already has. 
These items can also be dropped, to the room or inside another item the player already has. 

In the game there are also three NPCs. This NPCs move around by themselves every random time span. You can interact with the NPCs that are in the same room as you in two ways:
* __Talking__: The player can talk to the NPCs. They will first greet the player, and they say different phrases every time they are talked to, until all the phrases are said and the cycle is repeated.

* __Fighting__: The player can attack NPCs, which will trigger a combat between them. They will perform attacks in a rate depending on their attack speed, and they will deal each other an amount of damage depending on each one's attack damage and defense. Attacks can also be dodged, being more probable the higher the agility of a creature is. When the hp of one of both reaches zero, the creature dies and the combat ends. If the NPC dies, it drops to the room all the items it had, and stops performing any actions.

While your are in combat, neither you or the NPC can move. You can still pick, drop and use items to modify your stats while in combat. You can also talk to the NPC, but it will give you a different answer.
You can't attack a different NPC until the combat ends.

The game ends if the player quits the game, if it dies or if it consumes the item called *Star*.

## How to play
This is the list of all commands you can introduce to the game and what they do:

* __Move__: Introduce "move (direction)" to move to the room located in that direction, if there is one. Directions are "up", "right", "down" and "left".

* __Describe__: Introduce "describe" to see a brief description of the character and its current stats. Introduce "describe room" to see a description of the room you are currently in, and introduce "describe all" to see a description of the room and the other entities in it: items, exits and other NPCs.

* __Inventory__: Introduce "inventory" to see which items you have in your inventory.

* __Equipment__: Introduce "equipment" to see which items you have equipped.

* __Pick Items__: Introduce "pick (itemName)" to pick an item that is in the same room as you. Introduce "pick (itemName) from (sourceName)" to pick an item from another item. The source item must be in your inventory.

* __Drop Items__: Introduce "drop (itemName)" to drop an item and leave it in the current room. Introduce "drop (itemName) to (destinationName)" to place an item inside another item that is also in your inventory. Dropping an equipped item unequips it automatically.

* __Equip__: Introduce "equip (itemName)" to equip an item that is currently in your inventory. It does not remove it from your inventory.

* __Unequip__: Introduce "unequip (itemName)" to remove an item from you equipment slots. It does not remove it from your inventory.

* __Use__: Introduce "use (itemName)" to use an item from you inventory. Doing this will remove the item.

* __Talk__: Introduce "talk to (npcName)" to talk to an NPC located in the same room as you.

* __Attack__: Introduce "attack (npcName)" to attack an NPC located in the same room as you. This will trigger the beginning of a combat, and will not end until one of both dies.


## Guide to complete the game
The game is completed when you use the item *Star*, which is dropped by one of the NPCs. You can reach this through different ways, but here I will explain a solid one in case you may be struggling with it.

First of all, the best you can do is go through all the rooms and pick the items you find. The NPCs are neutral so they won't bother you while you explore, and fighting them without equipping anything will result in a fast death.

There are different types of equipment, some give small boosts while others boost some stats more heavily in exchange of decreasing others. Concretely, you should pick the *Bag* from the **Guest's room** and use it to increase you equipment slots by one, and also pick the *Potion* from the **King's chamber** and use it to receive a permanent stats boost.
Once you have equipped yourself with the chosen items, it would be time to go after the NPCs and get their drops.

The NPCs are the following ones:
* __Gideon__: Gideon starts in the Dark woods. He is the weakest NPC. Deals a huge amount of damage, but attacks very slowly and has little life and defense. He also drops a consumable that increases a bit all your stats and adds an equipment slot.

* __Malenia__: Malenia starts in the Castle's main room. She is in the middle way between Gideon and Jesse. She tanks some hits and attacks really quickly, dealing way more DPS than Gideon but less damage in each separated hit. She drops her weapon, which highly increases your attack speed and also boosts you agility. With this you should be ready to take on Jesse.

* __Jesse__: Jesse starts in the Catacombs. He is the hardest NPC of the game. He tanks the most, deals the most damage and has the higher agility, although he attacks a little slower than Malenia. Fighting him from the start will result in an instant death, so better equip yourself all you can before fighting against him. He drops the *Star*.

Pick up the *Star* after defeating **Jesse** and use it to finish the game.

## Extras
At first I had a little struggle to get the user input while keeping the code running so the NPCs can move around. The result works, but has some flaws, being the most important one that you can't properly delete what you have written. This way you have to write you commands without making any mistake so the game understands you, but apart from this everything else works as expected.

Also, the zip folder with the build posted in the "Release" section may contain some unnecessary files because I was not sure which ones were strictly necessary and which ones could be removed.

## Credits
Authors: Pol Curto

[Link to GitHub repository](https://github.com/PolCurto/Zork.git)

## License
    MIT License

    Copyright (c) 2024 Pol Curto

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
