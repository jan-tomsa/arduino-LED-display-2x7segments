Purpose
=======
This is a simple demo as a proof of concept of using displaying output
with 2 digit LED display.

Components
----------
* Display DA56-11GWA
* 2x 74HC164 Shift Register
* 140 ohm resistor
* Arduino Leonardo (but should work with any)

Function
--------
Cycles from 0 to 99.
Displays numbers by sending bits serially via pin 12 (Bit_out)
to two 74HC164 shift registers.

Segments for the digits are encoded in the array _segments_.
Space represents 0 (segment OFF).
Any other character represents 1 (segment ON).
Segment to which the value is relevant is determined by character's position
but for the sake of clarity the names of segments are used.
The mapping of character's position to LED segements is following: "fba.cgde"

I.e: the first character determines the state of segment _f_,
second character maps to segment _b_ and so on.

E.g.:
String "f a cgd " makes segments for number 5:
```
   ###a###
 ##       __
 #f       _b
 ##       __
   ###g###
 __       ##
 _e       #c
 __       ##
   ###d###   __(dot)\\
```

Schemactics
-----------
(To be added later)
