/**
 *
 *
 *
 */

#include <string>

#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"
#include "ToyStory.h"

int main() {
	Buzz buzz("Buzzi");
	Woody woody("Wood");

	ToyStory::tellMeAStory("story.txt", buzz, &Toy::speak, woody, &Toy::speak);
	return (0);
}
