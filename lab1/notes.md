# Alex's Notes on This Lab

## Readability
I wanted to rewrite this lab to be a little more approachable. For this purpose, I rewrote the challenge 3 code as seen in this branch. I would also recommend starting with the sample code from the `IRremote` library so that students are not overwhelmed.

One problem is that the code that is given is illegible. I tried my best to rewrite it so that it was more readable, and would appreciate any advice or comments. One thing that I thought would be more engaging would be to have the different interpretations done in a `case/switch` call, where each case would call a different function. The students could then implement the functions.

## IRremote Library
Notes on the IRremote functions:
Function Name | Return | Special Use
:--- | --- | :---
`irrecv(PIN)` | void | constructor
`irrecv.decode(&results)` | int | returns 1 if there is a code available, stored in `.result`
`irrecv.resume()` | void | must be called after `.decode` to resume listening

## Problems and Solutions
The first problem with the original code is that it is hard to read. I've tried to solve this problem using a `switch` statement and adding `#define` statements too. I believe these are better style, since they are inserted by the C preprocessor without taking more memory (I think).
There is another problem where the IR remote gives multiple values for the same button. I haven't solved this yet, but I have a couple of ideas. However, it compromises readability in some capacity, though hopefully not much.