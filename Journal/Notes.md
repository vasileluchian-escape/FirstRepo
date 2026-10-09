# Week 3 - Moday 05 / 10 / 26 Notes

##Part 1

### Vectors

```cpp
std::vector<Track> playlist{};
// Its ok to have empty vectors.

playlist.pushBack(Track{"SongName", 150});
// Adds a song to the vector list

playlist.back(); // Can print the very last item
playlist.front(); // Can print the very first item

v[99] // Undefinied, it will run whatever it has
v.at(99) // Will throw an error.
// They will both work as soon as you make a mistake, one will catch it, one will not.

v[] // Can be used, as long as you know you are inbounds.
v.at() // Use when unsure if you are within bounds.

for (std::size_t i{ vectorName.size() -1}; i >= 0; --i) 
// This will never end looping as the vector is empty.

// They both initialise a vector, but they both do different things
std::vector<int> sizes{1000, 0}; // This makes a list, in this case a list of 2
std::vector<int> sizes(1000, 0); // This will make a vector with 1000 entries and all will be set to 0.

vector.Name.assign( 4, 100 ); // Does the same thing, 4 entries with 100 each.
vectorName.clear(); // Cleares everything in the vector.

for (const Track& t : playlist ) // loops over and only looks at each item 
for (Track& t : playlist ) // looks and might change each item in the vector 
for (Track t : playlist ) // only looks at a copy of playlist, almost always a mistake to write.
```

## Part 2

### Randomness

```cpp
std::mtd19937 engine{ 42 };
// std::mtd19937 is the library used for creating random numbers
// engine is the name of the variable and 42 is the seed, which generates the random numbers
// passing in the same seed would generate the same set of random numbers. This is called pseudo-random.
// We can create a function to generate a random seed for geneating random numbers for the dungeon.
```

Problam 2 of WorBook 12 : 
A - 2 engines, same seed produces : same result
B - 2 engines, 2 seeds : different results
C - an engines copied, than both drawn : same First result.
D - 1 engine, 2 draws in a row : different result
E - a big Distribution, then a small distribution : different results

## Part 3

### std::string, std::string_view, and std::format

Creating a map and environment in text.
A string is another container like vector.
```cpp
std::string bar(n, '#'); // Iitialising a string, using round paranthesis, no brackets.
std::string bar{12, 55}; // This will translate to charaters.

std::string path{ " path/path.dot" }; // Path to string

std::string first("goblin");
std::string second("Goblin");
// We can also compare strings, in capital letters have a lower bit binary assigned, whereas lowercase have a higher value
// In this case "Goblin" < "goblin" is "true". if we compare "Goblin" == "goblin" is "false".

std::cout << std::format("{0} has {1}. Yes, {0}.\n", name, health);
// Inside format now we have {0} and {1}, this allows us to assign an index to what we want to put in there.
// {0} = name, {1} = health, now we can reuse 0 multiple times in the same line without having to re input.

std::cout << std::format("{:<12}, {:>6}\n");
// {:<12} means 12 characters to the left, and {:>6} means 6 characters to the right.

std::string input{"132"};
std::stoi(input); // stoi converts a string to an int. 
// stoi stops at the first character it cannot use. aka "123abc", when it gets to a it stops convering. this would throw an error.

```
# Week 3 - Friday 09 / 10 / 26 Notes

## Part 1

**Quiz**
1. 1+2+3+4+5+6 = 21 / 6 = 3.5 - Expected value
2. Expected Redraw around every ~ 1.00000002 in ~50 million
3. The min and max Room size is what limits BspRecursionDepth.
4. Every time a room is cut, its devided into 2 regions, each region shares no tiles, hence no need to check.
5. 2 dice of 6 give 7 more often, this is becaue there is a higher chance that 2 numbers that equal 7 will roll, versus a draw which is a flat equal chance between 2-12.
6. Recursive - a fucntion that calls itself over and over.

### Destructors and RAII

**Destructors**
Braces create a scope, anything "local" gets destryed. Local vairables are created in the order we put in the file, and when leaving a scope, they get destroyed from the last created to first.

```cpp
{
    Announcer a{ "A" }; // Created starting from A
    Announcer b{ "B" };
    Announcer c{ "C" }; // Finish creating at C
} // Get destroyed here from C to A.
```

**RAII**
This is to deal with Resource allocation, default constructors, no deconstructors, no copy consturctors, no assigning opearation constructor. <bR>

## Part 2 

### Streams, Files, Errors

Things can go wrong outside of our control. This part is about how to manage the unexpected.

```cpp
std::cout << // This is a stream
variableName.() // The things that go in the stream, in this case it will be printed on the console.
```

```std::ofstream``` - the way we create, open a file
```std::ifstream``` - writing to an opened file.
```out <<``` - The way we write to the opened file
```cpp
std::ofstream out( "demo.txt");
std::ifstream ();
out << "something" << '\n';
```

