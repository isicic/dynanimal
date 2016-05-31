#include <stdio.h>
#include <malloc.h>

typedef char const* (*PTRFUN)();

//Animal(s) Don't let me be misunderstood!
typedef struct{
	PTRFUN *table;
	char* name;
} Animal;

void animalPrintGreeting(Animal* zivina){
    printf("%s pozdravlja: %s \n", zivina->name, zivina->table[0]());
}
void animalPrintMenu(Animal* zivina){
    printf("%s voli %s \n", zivina -> name, zivina -> table[1]());
}


void AnimalInit(Animal* zivina, char* name){
    zivina -> table = NULL;
    zivina -> name = name;
}

// DOG
char const* dogGreet(void){
  return "vau!";
}
char const* dogMenu(void){
  return "kuhanu govedinu";
}

PTRFUN DogFTable[2] = {
	(PTRFUN)dogGreet,
	(PTRFUN)dogMenu
};

Animal* createDog(char* name){
    Animal* dog = (Animal*)malloc(sizeof(Animal));
	AnimalInit(dog, name);
	dog->table = DogFTable;
	return dog;
}

// CAT
char const* catGreet(void){
  return "mijau!";
}
char const* catMenu(void){
  return "konzerviranu tunjevinu";
}

PTRFUN CatFTable[2] = {
	(PTRFUN)catGreet,
	(PTRFUN)catMenu
};

Animal* createCat(char* name){
    Animal* cat = (Animal*)malloc(sizeof(Animal));
	AnimalInit(cat, name);
	cat->table = CatFTable;
	return cat;
}

// testAnimals
void testAnimals(void){
  struct Animal* p1=createDog("Hamlet");
  struct Animal* p2=createCat("Ofelija");
  struct Animal* p3=createDog("Polonije");

  animalPrintGreeting(p1);
  animalPrintGreeting(p2);
  animalPrintGreeting(p3);

  animalPrintMenu(p1);
  animalPrintMenu(p2);
  animalPrintMenu(p3);

  free(p1); free(p2); free(p3);
}

// main
int main (void){
    testAnimals();
    system("pause");
    return 0;
}
