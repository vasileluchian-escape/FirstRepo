# WorkBook 1 Journal

## Problem 1 

Inside `Inventory.h` : H, F, B, C <br>

```cpp
#ifndef INVENTORY_H
#define INVENTORY_H
int SlotsUsed(int items);
#endif // INVENTORY_H
```

Inside `Inventory.cpp` : D <br>

```cpp
int SlotsUsed(int items)
{
	return items;
}
```

Inside `main.cpp` : E, A, G <br>

```cpp
#include <iostream>
#include "Inventory.h"

int main()
{
	std::cout << SlotsUsed(4) << "\n";
	return 0;
}
```

**I** - a copy of the body of `Inventory.cpp`. We can put it in main however <br>
we will get a Linker Error. We can declare as offten as we like but only define once. <br>

**J** - Base rule to not use anywhere, as it only works with Microsoft, while it would work, its best to avoid using.

**K** - We dont need to paste `Invetory.cpp` in every file that uses the definition. Sticking to just pasting the header <br>
and inside the header we do the include for `Invetory.cpp` that way we don't get Linker errors.

**L** - a second paste of the header declaration, while harmless, its unnecessary.


## Problem 2 

**1** *Compiler error* <br>

-Syntx error, Invetory.h is misspelled. <br>
-Can be found at the top of whateverfile has #include <br>

**2** *Compiler error* <br>

-Either syntax is wrong or missing "SlotsUsed". or the "#include" is for that header is missing. <br>
-Can be found wherever the error points to.

**3** *Linker error* <br>

-No definition for "SlotsUsed", or definition and declaration missmatch, or the cpp file is not in the project.<br>
-Can be found in the definition file "Inventory.cpp", else file is not inside the project.

**4** *Compiler* <br>

-Defined the same thing 2 times in the same file.<br>
-Can be found in the header that defines "Item".

**5** *Linker error* <br>

-The same thing being defined 2 times in 2 cpp files, or definiton left in the header file. <br>
-Can be found in any file the error names.

## Problem 3

```cpp
// Inside Inventory.h

#ifndef INVENTORY_H
#define INVENTORY_H

int SlotsUsed(int items);

int SlotsFree(int items); // Added line

#endif INVENTORY_H
```

```cpp
// Inside Inventory.cpp
int SlotsUsed(int items)
{
	return items;
}

// Everything underneath is added.
int SlotsFree(int items)
{
	return  10 - items;
}
```

```cpp
// Inside main.cpp
#include <iostream>
#include "Inventory.h" // Only header is needed.

int main() 
{
	std::cout << SlotsUsed(4) << "\n"; // This will now print 6
	return 0;
}
```

### Breakages : <br>

**Breakage 1** - ```cpp C3861: 'SlotsFree' : identifier not found``` <br>
-While the definition still exists, ```main.cpp``` never knew it existed, therefore we get a compiler error <br>

**Breakage 2** - ```cpp LNK2019P: unresolved external symbol``` <br>
-Everything compiles, ```main.cpp``` was promised the definition existed so, everything compiled just fine. <br>
-The Linker can't find what it needs to link 2 obj files, therefore it throws an error. <br>

**Breakage 3** <br>
-This one is compiles just fine, int can easly convert to float. <br>
-However I believe there will be a LNK error. The declaration expects an ```(int)``` not ```float)```, and so I think it might be similar to a missmatch error <br>

## Problem 4

**Inside ```main.cpp```**
```cpp
#include <iostream>
// ... Goes here

// From Item.h
struct Item
{
	int weight;
}

// From Inventory.h

#include "Item.h"
// ... From Item.h pastes here again

int TotalWeight(int itemCount);

int main()
{
 Item sword;
 sword.weight = 5;
 std::cout << sword.weight << "\n";
 return 0;
}
```

### The Error :
***Compiler Error*** - We have 2 pastes from Item.h with neither of them having guards, so the second paste isn't skipped, and gets pasted a second time, that triggers a compiler error. <br>

### The Fix : 

```cpp
// Inside Item.h we add a guard.

#ifndef ITEM_H
#definiton ITEM_H

struct Item 
{
	int weigh;
}

#endif ITEM_H
```

**Task 4** 
-As the code is right now, ```Inventorey.h``` does not need guards.  <br>
-Should we add some, yes because, as soon as we add another delcaraiton or struct, the code will break and throw an error. <br>

## Problem 5

### 1
**First Paste**
-From ```main.cpp``` that has its own ```#include Colours.h```, it will go through and create a lable for Colours.h as it does not currently have one and paste it in ```main.cpp```.
-After that, ```Palette.h``` gets read and pasted, and this is where we reach a second paste. <br>

**Second Paste**
-It will go thorugh and check if ```Colours.h``` already has a lable, and since it has guards, it will know it exist and skip this paste, and won't paste another copy of ```Colours.h```.

### 2
-The guard is there to prevent a second paste of a alrady declared lable. So only 1 paste occurs.

### 3
**Swapping the order of #includes** 
-This will change nothing, as we have a ```#Include Colours.h``` pasted in both ```main.cpp``` and ```Palette.h```, the only difference is that now, ```Palette.h``` will be the first paste 

### 4
**Without guards**
-If ```Colour.h``` had no guards, we would get a compiler error. ```Palette.h``` will be fine as it still has it's guards, but that does not protect ```Colours.h``` as well.
-The error will be a compiler error with something like ```Colour : struct type redefiniton```.

## Problem 6

**1.** - *Header*
-It's a declaration, other files will need it to call the function.

**2.** - *Soruce file*
-A definiton must only be one, inside a header, it will be pasted in every file it is included in.

**3.** - *Header*
-It's a declaration of the structure of ```Item.h```, so we need to know what it will look like.

**4.** - *Source file*
-Must only be included where it is needed, inside a header file it is useless.

**5.** - *Header*
-Anyone who includes a header, shouldn't have to guess what the header is for.

**6.** - *Header*
-The end of a declaration of a lable, so a cpp file would never need this.

**7.** - *Source file*
-If a file doesn't need it, than it shouln't be able to see it.

**8.** - *Source file*
-There is only 1 main.cpp file. This is where the program starts, and where the includes are called for.

# WorkBook 2 Journal 

### Problem 1

-Inside ```main.cpp```, the letters go : **C, G, H, A, F, J, D**. In order.
```cpp
constexpr int MaximumShields{ 120 };
constexpr int MaximumHull { 200 };
int cuurentShields{ 73 };
int currentHull{ 150 };

void Problem1()
{
	float hullPercent = static_cast<float>(currentHull) / MaximumHull * 100.0f;
	float shieldPercent = static_cast<float>(currentShilds) / MaximumShields * 100.0f;
	std::cout << std::format("Shields {:.1f}% Hull {:.1f}%\n", shieldPercent, hullPercent);
}
```

### Problem 2

**1.** <br>
-I get no warnings about shieldStrength. <br>
-All the otrher lines are throwining errors for missing ";".<br>

**2.** <br>
```cpp
void Problem02()
{
	int shieldStrength{};
	float enginePower{2.5};
	bool weaponsArmed{true};
	int hullPlating{45.8};
	char shipClass{'F'};
	std::cout << std::format("shields {}, engines {}, armed {}, plating {}, class{}\n", shieldStrength, enginePower, weaponsArmed, hullPlating, shipClass);
}

```

**3.** <br>
-After adding the braces, only ```int hullPlating{45.8};``` is throwing an error.<br>
-The error : ```Converion from 'double' to 'int' required a narrowing conversion```. <br>

**4.** <br>
-Changed from int to double, now it stores the correct value, correctly.
```cpp
double hullPlating{ 45.8 };
```

**5.** <br>
-This line is stored as a double, to make it a float we need to add an f at the ened <br>
```cpp
float enginePower{ 2.5f }; // Added the f at the end of 2.5, now its a float not a double.
```

**6.** <br>
-Changing to release didn't change the value 0 from shieldStrength.

### Problem 3

```cpp
void Problem03()
{
	// Declarations and Initialisation
	char callsign{ 'K' };
	int remainingTorpedos{ 6 };
	float remainingFuel{ 0.6237f };
	bool autopilot{ false };
	long long shipMass{4200000000};
	
	std::cout << std::format("|{:>10}|{:>8}|\n", "Callsign", callsign);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Torpedoes", remainingTorpedos);
	std::cout << std::format("|{:>10}|{:>8.2f}|\n", "Fuel", remainingFuel * 100.0f);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Autopilot", autopilot);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Mass", shipMass);
}
```

### Problem 4

**1.** ***Size Table***
```
Type 		 | Size | Largest it can hold	|
-------------|------|-----------------------|
bool	     | 1	| 1						|
char		 | 1	| 127					|
short		 | 2	| 32767  				|
int			 | 4	| 2147483647  			|
long long	 | 8	| 9223372036854775807 	|
float		 | 4	| 3.4028235e+38			|
std::uint8_t | 1	| 255					|
std::int32_t | 4	| 2147483647			|
```

**2.** ***Float Size*** <br>
-Float surprised me the most, its largest it can hold. <br>
-Float gives up exact place each digit it is near, while near 0, floats can distinguish values apart fairly precicly.<br>
-However the distance between the closest to the whole number and the one ones furthers, is lost. <br>
-We would need an extra command to compera floats, thats how inexcat they are.<br>

### Problem 5

**1.** *The Bug*<br>
-When printing it does show up woith "0.0%" <br>

**2.** *Why it happens* <br>
-When we devide, we devide 2 ints and conver to float, we should convert 1 int into a float, than devide. <br>

**3.** *The fix using cast* <br>
```cpp
float fraction = static_cast<float>(currentShields) / maximumShields;
```

**4.** *The fix without cast* <br>
```cpp
float percentage = currentShields * 100.0f / maximumShields;
```
-Doing this instead still works, the "100.0f" changes the equation to a float one by the end.<br>
-Doing this also deletes one unecessary line.<br>
-Between the 2 solutions, I think that the first one doens't massivly change much, so it would be quicker to implement. <br>
-The second one removes one line, and removes 1 no longer needed variable "fraction". <br>
-Personally I would stick with the first soltiuon, as I might want to use the fraction as a number before making it a percentage somehwere else in my code.<br>

### Problem 6

