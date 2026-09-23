# WorkBook Journal

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
