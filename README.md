# Geespotter---MineSweeper-Game

Harry Wang - 1A ECE at University of Waterloo

Geese are part of Waterloo life! Everyone knows to not get too close to a goose, in particular a mother goose
with her goslings. In this project you will develop “GeeseSpotter”, a simple, text-based, single-player game.
The player is first asked for the desired dimensions of the 2-dimensional playing board and then for the
number of geese that should hide on the playing board. The playing board is made up of individual fields. A
field can be occupied by a goose or not. Geese are messy, and the (up to) eight neighboring fields of a field
that contains a goose contain goose droppings. An observant Waterloovian can tell how many geese are in
neighboring fields by observing the amount of goose droppings.

The University is asking us to determine all fields that contain a goose, without disturbing a goose. To make
this easier, a field can be marked as containing a goose. A marked field is a reminder that a field might
contain a goose. Only hidden fields can be marked and only marked fields can be unmarked. As the fields are
initially hidden, there is no guarantee that a marked field contains a goose.

The player is presented with the current status of the playing board, where the content of all fields is initially
unknown. The player is given the option to either reveal a field or to mark or unmark a field as likely occupied
by a goose, by asking the player whether to reveal or mark/unmark a field and the two coordinates of the
field.

If the player selects to reveal a field, there are two possible outcomes: (1) the field contains a goose, and the
player upsets the mighty goose. The game is lost immediately. (2) the field does not contain a goose; the field
is revealed. If the field and none of its neighbors contain a goose, the neighboring fields are also revealed,
and the player learns how many geese are in the neighbors of each of the neighboring fields. This value can
range from 0 to 8.

If the player selects to mark or unmark a field, the status of the field is changed from unknown to marked or
from marked to unknown, depending on the current status of the field. Only unknown fields can be revealed
or marked and only marked fields can be unmarked and thereby changed to an unknown field again.

The current status of the board is printed after every change to the fields. The player is free at any turn to
choose to restart with a new game or to quit.
