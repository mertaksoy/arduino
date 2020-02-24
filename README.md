# Dual 7 Segment Display with Arduino
Dual 7 Segment auto counter

***Circuit:***
````
// Dual seven-segment LED Display
// Common Anode digit 1 pin 10
// Common Anode digit 2 pin 5

//       CA1 G  F  A  B
//        |  |  |  |  |      -> pins and segments they control
//   ---------    ---------
//   |   A   |    |   A   |
//  F|       |B  F|       |B
//   |---G---|    |---G---|
//  E|       |C  E|       |C
//   |   D   |    |   D   |
//   ---------    ---------
//        |  |  |  |  |      -> pins and segments they control
//        D  DP E  C CA2         

// Segments that make each number when lit:
// 0 => -FEDCBA
// 1 => ----BC-
// 2 => G-ED-BA
// 3 => G--DCBA
// 4 => GF--CB-
// 5 => GF-DC-A
// 6 => GFEDC-A
// 7 => ----CBA
// 8 => GFEDCBA
// 9 => GF-DCBA
````

*Please note that example was developed in 2010*
