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
