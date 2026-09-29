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

```cpp

constexpr int totalEnemies{ 40 };
constexpr int scorePerEnemy{ 150 };
constexpr int maxWaves{ 5 };
constexpr int scorePerWave{ 1000 };
constexpr int maxSeconds{ 90 };
constexpr int scorePerSecond{ 25 };

constexpr int rankAPass{ 5000 };

constexpr int maxScore { (totalEnemies * scorePerEnemy) + (maxWaves * scorePerWave) + (maxSeconds * scorePerSecond) };


void Problem06()
{
	int enemiesDestroyed{ 14 };
	int wavesSurvived{ 3 };
	int secondsRemaining{ 47 };
	int score = (enemiesDestroyed * scorePerEnemy) + (wavesSurvived * scorePerWave) + (secondsRemaining * scorePerSecond);
	
	std::cout << stf::format("You Scored {} out of {}\n", score, maxScore);
	
	if (score > rankAPass)
	{
		std::cout << "Rank A\n";
	}
	else
	{
		std::cout << "Rank B\n";
	}
}
```

### Problem 7

```cpp
auto shipClass{ 'K' };
auto hullPoints{ 250 };
auto shieldRegenRate{ 2 };
auto isDocked{ false };
auto fuelBurn{ 3 / 4 };
auto crewCount{ 12u };
auto turnRadius{ 45.0f };
auto missileYield{ 1.5 };

char shipClass{ 'K' };
int hullPoints{ 250 };
float shieldRegenRate{ 2.0f };
bool isDocked{ false };
float fuelBurn{ 3.0f / 4.0f };
int crewCount{ 12 };
float turnRadius{ 45.0f };
double missileYield{ 1.5 };
```

-If I would write this code, I would replace each one with the intented type, as it would be easier to read and understand much faster, what variable is meant to be what. <br>
-The first bug happens at ```auto shieldRegenRate{ 2 };```, this will be interpreted as an int when in reality it should be a float, calutalions will all be wrong and truncated, if kept as auto. <br>
-Second bug is at ```auto fuelBurn{ 3 / 4 };```, this bug is not really caused by auto, but rather hidden, as again it will truncate and hid the real answer under 0, as it will assume it is an int.<br>

# WorkBook 3 Journal 

### Problem 1

**Letters Used :**  *B, E, D, I, F, C, K*

**Letters avoided :** *A, G, H*

***A*** - Has no cast to float, the divion would just produce a 0, instead of what we actaully need. <br>
***G*** - House rule is to not use unsigned int unless there is a good reason, this is only basic math so no reason to use unsigned. <br>
***H*** - It won't compile, and will throw an error, as it won't do what we expect it to becauase ""<<"" is stronger than ">". <br>

```cpp
constexpr int MaximumArmour{ 50 };

void Problem1()
{
	int rawDamage{ 7 };
	int currentArmour{ 40 };

	float reduction = static_cast<float>(currentArmour) / MaximumArmour;
	std::cout << std::format("Reduction: {:.2f}\n", reduction);
	float finalDamage = rawDamage * (1.0f - reduction);
 	std::cout << std::format("Damage taken: {:.2f}\n", finalDamage);
}
```

### Problem 2

**Equation 1 | Type : int** <br> 9 / 2 = 4  <br><br>
**Equation 2 | Type : int** <br> 9 % 2 = 5 <br><br>
**Equation 3 | Type : double** <br> 9.0 / 2 = 4.5 <br><br>
**Equation 4 | Type : double** <br> 9 / 2.0 = 4.5 <br><br>
**Equation 5 | Type : int** <br> -9 / 2 = -4 <br><br>
**Equation 6 | Type : int** <br> -9 % 2 = -1 <br><br>
**Equation 7 | Type : int** <br> 9 / 2 * 2 = 8 <br><br>
**Equation 8 | Type : int** <br> 9 * 2 / 2 = 9 <br><br>
**Equation 9 | Type : int** <br> 2 + 3 * 4 - 8 / 2 = 11 <br><br>
**Equation 10 | Type : bool** <br> 7 > 3 = True <br><br>
**Equation 11 | Type : bool** <br> 1 + 2 > 3 = False <br><br>
**Equation 12 | Type : bool** <br> 0.1 + 0.2 == 0.3 = False <br>

1. Equations 7 and 8 : <br>
- Basic math, as both operators have the same level of equality, it goed from left to right. <br>

2. Equations using intiger division alwqays lose data. <br>
- Division truncates towards 0, so 9 / 2 = 4, not 4.5 and not 5. 

### Problem 3

1. Remaining : 
- 4294967294 <br>

2. Why this big number ?
- Remaining is an unsigned value, meaning it can't express negative values.
- Unsigned stretches from 0 to 4294967294, so it printed its max range.

3. The Fix :
```cpp
void Problem03()
{
	// All unsigned ints get removed.
	int stock{ 3u };
	int purchased{ 5u };
	int remaining = stock - purchased;
	std::cout << std::format("Stock: {}\n", stock);
	std::cout << std::format("Purchased: {}\n", purchased);
	std::cout << std::format("Remaining: {}\n", remaining);
}
```

4. Why does comparison still go through just fine?
- Its comparing 3 agains 5, while unasinged, they are still ints so the comparison is just fine to go through.
- Unsigned values are not a danger to comparing between them, or looking at them, but its bad to use them in mathematics.

### Problem 4

```cpp
constexpr int WeaponCount{ 4 };

void Problem4()
{
	int currentWeapon{ 3 };

	int nextWeapon = (currentWeapon + 1) % WeaponCount; // 3 + 1 % 4 = 4 % 4 = 0. This wrapps back just fine.

	int previousWeapon = (current weapon + WeaponCounbt - 1) % WeaponCount; //Weapon count isnt needed until we hit 0, as that will put un in negative numbers, which we do not have assigned, thats why WeaponCount is used in the additon.

	std::cout << std::format("from {}: next {}, previous {} \n", currentWeapon, nextWeapon, previousWeapon)f
}
```

### Problem 5

**1. Pass. Division will run first before comparison** <br>
**2. << is stronger than <, so it won't print what is expected. This line will not compile** <br>
**3. Written Wrong. The first condition will go through than second, which is what we don't want.** <br>
**4. Written Wrong, braces won't help either, needs a float cast.** <br>
**5. Pass. The "!" will run first before "&&"**<br>


```cpp
void Problem05()
{
	int health{ 30 };
	int maxHealth{ 100 };
	bool hasPotion{ true };
	bool isPoisoned{ false };
	bool inCombat{ true };

	// 1. Intended: "is health below a quarter of maximum?"
	bool isCritical = health < maxHealth / 4;

	// 2. Intended: "print whether health is below 50"
	std::cout << "Low health: " << health < 50 << "\n";

	// 3. Intended: "has a potion, and is either poisoned or in combat"
	bool shouldDrink = hasPotion && isPoisoned || inCombat;

	// 4. Intended: "health as a percentage"
	float percentage = health / maxHealth * 100.0f;

	// 5. Intended: "not poisoned, and in combat"
	bool fightingClean = !isPoisoned && inCombat;

}
```

**Written Correctly**<br>
**Making the expression easier to read as well**

```cpp
void Problem05()
{
	int health{ 30 };
	int maxHealth{ 100 };
	bool hasPotion{ true };
	bool isPoisoned{ false };
	bool inCombat{ true };

	// 1. Intended: "is health below a quarter of maximum?"
	bool isCritical = (health < (maxHealth / 4)); // Looks cleaner.

	// 2. Intended: "print whether health is below 50"
	std::cout << "Low health: " << (health < 50) << "\n"; 
	// Wrap (health < 50) in braces to indicate importance

	// 3. Intended: "has a potion, and is either poisoned or in combat"
	bool shouldDrink = (hasPotion && (isPoisoned || inCombat)); 
	// Wrap (isPoisoned || inCombat) first to do this comparison first before hasPotion &&.

	// 4. Intended: "health as a percentage"
	float percentage = (static_cast<float>(health) / maxHealth) * 100.0f; 
	// Making at least 1 int into a float so the operation passes.

	// 5. Intended: "not poisoned, and in combat"
	bool fightingClean = ((!isPoisoned) && inCombat); // Looks cleaner.

}
```

# WorkBook 4 Journal 

### Problem 1

**Letters Used :** *A, C, E, F, G, H, I, J*

**Letters Avoided :** *B, D, K*<br>

**Reason for avoidence :** <br> 
*B* = ```if (health = 0)``` - Compiles just fine, however sets "health" to 0. instead of comparison, it initialises, giving us a wrong answer, and a wrong variable. <br>
*D* = ```else if (enemyCount)``` - House Rule, write the comparison out when comparing agains numbers, while compiles fine, it will always compare to 0, which could be wrong if we want to compare agains something else. <br>
*K* = ```else if (health < 25) std::cout << ...```- Compiles and runs just fine, however will break as soon as we add more than one lines to the statement.

```cpp
void Problem1()
{
	int health{ 30 };
	int enemyCount{ 3 };

	if (health <= 0)
	{
		std::cout << "Status: dead\n";
	}
	else if (health < 25)
	{
		std::cout << "Status: critical\n";
	}
	else if (enemyCount > 2)
	{
		std::cout << "Status: outnumbered\n";
	}
	else
	{
		std::cout << "Status: ready\n";
	}
}
```

**Task 5 :** The console will now print "Status: critical". This is because, as soon as one of the if statements counts true, the code stops there and doesn't check anything underneath that.

### Problem 2

**Predict the outcome**
```
B: arrows
C: staff
D: mana again
E: mana is 10
F: plenty of arrows
G: ready
I: partly equipped
```

**A doesn't print as mana is 0.**
```cpp
    if (mana)
    {
        std::cout << "A: mana\n";
    }
```
**B prints as currecntly arrows is more than 0. While it passes, the expression should be written out correctly.**
```cpp
    if (arrows)
    {
        std::cout << "B: arrows\n";
    }
```
**C prints, as hasStaff is indeed set to true.**
```cpp
    if (hasStaff == true)
    {
        std::cout << "C: staff\n";
    }
```
**D prints, as mana is now initialised to 10, this is wrong as its supposed to be a comparison. This should not have been written if it was correct.**
```cpp
    if (mana = 10)
    {
        std::cout << "D: mana again\n";
    }
	std::cout << std::format("E: mana is {}\n", mana); //this line confirms that mana is now a different value
```
**E prints, as we do have more than 3 arrows so thats fine, however G also prints, beacause we didn't use braces to specify what we should print for this if statement so antyhing under "std::cout << "F: plenty of arrows\n";" will jhust print as there is braces to indicate where the code should stop.**
```cpp
    if (arrows > 3)
        std::cout << "F: plenty of arrows\n";
        std::cout << "G: ready\n";
```
**H won't print, mana is 10, so that part is all good, but arrows is only 3 so this comparison fails.**
```cpp
    if (mana > 5 && arrows > 10)
    {
        std::cout << "H: fully equipped\n";
    }
```
**I prints, as mana auto passes since its set to 10. However this shouln't have printed.**
```cpp
    else if (mana > 5 || arrows > 10)
    {
        std::cout << "I: partly equipped\n";
    }
```

***Writing the most important 3 bugs correctly***
```cpp
    if (mana == 10) // changerd = to ==
    {
        std::cout << "D: mana again\n";
    }


	if (arrows > 3)
	{
		std::cout << "F: plenty of arrows\n"; // added braces around F.
	}
    std::cout << "G: ready\n";


	//Both mana and arrows are now written correctly.
    if (mana > 0) 
    {
        std::cout << "A: mana\n";
    }
    if (arrows > 0)
    {
        std::cout << "B: arrows\n";
    }
```

### Problem 3

```cpp
void GuardCastSpell(bool knowsSpell, int mana, int manaCost, bool isSilenced)
{
	if (!knowsSpell)
	{
		std::cout << "You don't know the spell.\n";
		return;
	}
	if(isSilenced)
	{
		std::cout << "You are silenced, and cannot speak.\n";
		return;
	}
	if (mana < manaCost)
	{
		std::cout << "You don't have enough mana.\n";
		return;
	}

	std::cout << "The Spell is cast!\n";
}
```

**Task 4 : To improve from using nested if statements to gurads, the code looks a lot cleaner, also if one of the 3 if statements fail, than the code stops running, if everything passes it just casts the spell.**

### Problem 4

```cpp
enum class DamageType{ Physical = 0, Fire = 1, Ice =2, Poison = 3};
enum class ArmourType{ None, Leather, Chain, Plate};

int ApplyResistance(int damage, DamageType type, ArmourType armour)
{
    switch (armour)
    {
    case ArmourType::None:
        return damage;

    case ArmourType::Leather:
        if (type == DamageType::Poison)
        {
            return damage / 2;
        }
        else
        {
            return damage;
        }

    case ArmourType::Chain:
        if (type == DamageType::Physical)
        {
            return damage / 2;
        }
        if (type == DamageType::Ice)
        {
            return damage * 2;
        }

    case ArmourType::Plate:
        if (type == DamageType::Physical)
        {
            return damage / 2;
        }
        if (type == DamageType::Fire || type == DamageType::Ice)
        {
            return damage * 2;
        }
    }
    return damage;
}

const char* NameOf(DamageType type)
{
    switch (type)
    {
    case DamageType::Physical:
        return "physical";

    case DamageType::Fire:
        return "fire";

    case DamageType::Ice:
        return "ice";

    case DamageType::Poison:
        return "poison";
    }
    return "unknown";
}

void Problem4()
{
    int fireAndPlate = ApplyResistance(20, DamageType::Fire, ArmourType::Plate);
    int physicalAndChain = ApplyResistance(20, DamageType::Physical, ArmourType::Chain);

    std::cout << std::format("Dealting 20 {} damage type against Plate Aromour becomes {}\n", NameOf(DamageType::Fire), fireAndPlate);
    std::cout << std::format("Dealting 20 {} damage type agains Chain Armour becomes {}\n", NameOf(DamageType::Physical), physicalAndChain);
}
```

### Problem 5

**This code Produces 4 faults :**
```cpp
enum class Command { MoveNorth, MoveSouth, Attack, Wait, Quit };

void HandleCommand(Command command)
{
    switch (command)
    {
    case Command::MoveNorth:
        std::cout << "   You move north.\n";

    case Command::MoveSouth:
        std::cout << "   You move south.\n";
        break;

    case Command::Attack:
        std::cout << "   You attack!\n";
        break;

    case Command::Wait:
        std::cout << "   You wait.\n";
        break;
    }
}

void Problem05()
{
    HandleCommand(Command::MoveNorth);
    HandleCommand(Command::Attack);
    HandleCommand(Command::Quit);
}
```

***Fault 1 :*** <br>
```case Command::MoveNorth:``` has no ```break;```, this will case the output to leack to the next case.

***Fault 2 :*** <br>
"Quit" has no case in the switch case, which is casuing it to just not do anything, hence the code compiles but nothing actaully happens when we call quit.

***Fault 3 :*** <br>
"quit" not having a case, creates a second faulty, where we could instead do a default, tho a switch on a enum class don't need a default. A switch that matches nothing, simply does nothing in silence, when we have a default, it will just pick the default.

**The Fix :**

```cpp
enum class Command { MoveNorth, MoveSouth, Attack, Wait, Quit };

void HandleCommand(Command command)
{
    switch (command)
    {
    case Command::MoveNorth:
        std::cout << "   You move north.\n";
		break;

    case Command::MoveSouth:
        std::cout << "   You move south.\n";
        break;

    case Command::Attack:
        std::cout << "   You attack!\n";
        break;

    case Command::Wait:
        std::cout << "   You wait.\n";
        break;

	case Command::Quit:
        std::cout << "   See you later.\n";
        break;
    }
}

void Problem05()
{
    HandleCommand(Command::MoveNorth);
    HandleCommand(Command::Attack);
    HandleCommand(Command::Quit);
}
```