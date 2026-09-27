#include <iostream>
#include <format>
#include <limits>
#include <cstdint>


void Problem03()
{
	// Declarations and Initialisation
	char callsign{ 'K' };
	int remainingTorpedos{ 6 };
	float remainingFuel{ 0.6237f };
	bool autopilot{ false };
	long long shipMass{ 4200000000 };

	std::cout << std::format("|{:>10}|{:>8}|\n", "Callsign", callsign);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Torpedoes", remainingTorpedos);
	std::cout << std::format("|{:>10}|{:>8.2f}|\n", "Fuel", remainingFuel * 100.0f);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Autopilot", autopilot);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Mass", shipMass);
}

void Problem04()
{
	std::cout << std::format("bool {} bytes, max {}\n", sizeof(bool), std::numeric_limits<bool>::max());
	std::cout << std::format("char {} bytes, max {}\n", sizeof(char), static_cast<int>(std::numeric_limits<char>::max()));
	std::cout << std::format("short {} bytes, max {}\n", sizeof(short), std::numeric_limits<short>::max());
	std::cout << std::format("int {} bytes, max {}\n", sizeof(int), std::numeric_limits<int>::max());
	std::cout << std::format("long long {} bytes, max {}\n", sizeof(long long), std::numeric_limits<long long>::max());
	std::cout << std::format("float {} bytes, max {}\n", sizeof(float), std::numeric_limits<float>::max());
	std::cout << std::format("uint8_t {} bytes, max {}\n", sizeof(std::uint8_t), std::numeric_limits<std::uint8_t>::max());
	std::cout << std::format("int32_t {} bytes, max {}\n", sizeof(std::int32_t), std::numeric_limits<std::int32_t>::max());
}

void Problem05()
{
	int currentShields{ 73 };
	int maximumShields{ 120 };

	float fraction = static_cast<float>(currentShields) / maximumShields;
	float percentage = fraction * 100.0f;
	std::cout << std::format("Shields at {:.1f}%\n", percentage);
}



void main()
{
	Problem05();
}