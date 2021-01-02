# Anne Pro Lighting Effects

The lighting effects described here come from ObinsKit, the official software to
configure the Anne Pro line of keyboards by Obins Lab. Lighting effects here may
or may not be available as part of AnnePro2-Shine.

## Colors

The color palette provided in ObinsKit is a max saturated HSV color wheel. The
default colors provided are used in the default color palette for most lighting
effects.

| Color           | Hex     | Color           | Hex     |
|-----------------|---------|-----------------|---------|
| red             | #FF0000 | blue            | #0000FF |
| orange          | #FF8000 | violet          | #8000FF |
| yellow          | #FFFF00 | fuchsia         | #FF00FF |
| lime green      | #80FF00 | magenta         | #FF0080 |
| green           | #00FF00 | black           | #000000 |
| seafoam green   | #00FF80 | white           | #FFFFFF |
| cyan            | #00FFFF | yellow-orange   | #FF9800 |
| cornflower blue | #0080FF | teal            | #00B7C3 |

## Static Effect(s)

Static effects do not change colors at any given time. They are constant colors.
Generic static effects light up the entire board as one color. Custom color
mappings are possible, but for this repository, will not be available unless the
user defines a custom color mapping.

## Animated Effects

Animated effects change color overtime. Animated effects include gradual waves,
breathing (lighting up and down of the entire keyboard), and novelties such as
fire or fireworks.

### Breathing effect

The breathing effect inovlves the keyboard continuously lighting up and down
while it transitions through the color palette.

* **Animated color effect:** entire keyboard lights up and down
* **Animated transition effect:** dim the keyboard before next color
* **Animation color time:** 2 seconds - 1 second to gradually light up and
  another to gradually dim down

### Gradual Breathing effect

Similar to the breathing effect, but transitions interpolate between colors
rather than dim.

* **Animated color effect:** entire keyboard lights up and down
* **Animated transition effect:** interpolate between the colros
* **Animated color time:** 1 second from color A to color B

### Rainbow (Palette)

Each color of the palette takes an entire column and the colors flow toward the
right. Colors are interpolated appropriately for the animation (i.e. colors do
not directly switch to the next color).

* **Animated color effect:** keyboard columns represent the palette and flows
  right
* **Animated transition time:** colors appear on the next row every half second

### Starry Sky

Random keys light up on an initially unlit keyboard. At any time, there seems to
be no more than a quarter of the keys being lit up.

* **Animated color effect:** random keys light up
* **Animated key transition time:** a key lights up and dims for an approximate
  total of 5 seconds

### Comet

Random rows will light up with a "comet" darting from the left to right. The
colors are in the order of the color palette. Never is there multiple rows
lighting up simultaneously. The fastest a new row lights up is when the previous
comet's head completely transitions off the keyboard (i.e. gets to the right
side of the keyboard).

* **Animated color effect:** random rows light up from left to right
* **Animated color time:** 1 second to dart completely across and 1 second to
  completely dim the row

### Colorful

Similar to Starry sky but the entire keyboard is lit up. The keyboard begins
by gradually lighting up a randomly colored board.

* **Animated color effect:** random keys light up
* **Animated key transition time:** a key lights up and dims for an approximate
  total of 5 seconds

### Wave

An entire keyboard lights up in one color. Then a dark column flows to the left
and is succeeded with the next color in the color palette.

* **Animated color effect:**
* **Animated color time:** 5 seconds for entire color. dark column is 3 columns
  wide and takes 3 seconds for the left most column to get to the other side

### Black Hole

Colors go from the edge toward the center as it is sucked into the black hole.

* **Animated color effect:** Colors are in rings that flow toward the center
  (key H)
* **Animated color width:** Each color takes 1 key unit
* **Animated color time:** Approximately 4 seconds for color to appear at edge 
  and reach the center of the board

### Vertical Rainbow (Vertical Palette)

Colors move toward the top of the keyboard. The color in the palette take up an
entire row.

* **Animated color effect:** colors take entire row and flow upward
* **Animated color width:** 1 row per color
* **Animated color time:** approximately 3 seconds to completely go from bottom
  row to top row

### Fountain

Reverse of a black hole.

### Flame

A procedurally generated flame animation.

### Firework

Random keys light up, bloom, and dim out in a spiral manner. The colors of the
bloom are random colors from the color palette.

## Trigger (Reactive) Effects

Trigger effects are animated effects that listen to keypress events to determine
how an animation should proceed.

### Breathing per key

Keyboard is dark, but pressed keys light up in the order of the color palette.
The keys immediately light up and gradually dim out within 1 second. None of the
colors linger when other keys are pressed.

### Poptang

Keybard is dark, but pressed keys light up the column and row in the order of
the color palette. The light gradually spread across the row and column.
Although the colors fade within 1 second of lighting up, if another key press
event occurs, the colors linger for the last gradual spread to occur.

Behavior of spread should be noted. If two keys are pressed quickly one after
another, then one of the spreads may overtake another spread. For example, if
both f and j are pressed simultaneously, does the spread from f or the spread
from j take over?

The spread takes about 1 second to go from left to right and another second to
dim.

### Breathing

Breating causes the colors to transition similar to the gradual breathing effect
animation. During a transition, additional key presses do not cause the
breathing effect to cycle further than one color. Only once the transition has 
finished does a key press trigger a transition to the next color. Transitions
seem to take 2 seoncds.

### Rainbow

Rainbow seems to be exactly the same as the rainbow animation. Trigger doesn't
seem to affect it.

### Ripple

Ripple is similar to the fountain effect but with a trigger event listener.

### Pulse

Pulse is simmilar to the comet effect with a trigger. However, the animation
seems to take half the time.

### Star Fall

Star fall is similar to the Breathing per key effect, but the dimming is joined
with a "starfall" where lights from levels above will trickle down. The stars
only fall once a lower row has completely fallen. Colors stay for 3 seconds
before falling. Falling takes 1.5 seconds to completely fall from top to bottom.