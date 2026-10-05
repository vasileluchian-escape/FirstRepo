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
