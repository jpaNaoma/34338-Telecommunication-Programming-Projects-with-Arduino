/*Exercise 14.

14a. A member is a variable definde inside a structure. It represents one piece of data associated with that structure.

14.b Describe difference:
struct.member: accesses a member of a structure instance directly
*(struct.member): Uses paranthese to access a member of a structure. The parantheses ensure struct is evalutated first.
*struct.member: Dereferences a pointer to a structure to access its member. This assumes struct is a pointer to a structure. 
struct->member: Shortcut for accessing a member via a pointer to a structure.

*/
//14.c
struct Animal {
  char family[20];
  char species[20];
  bool isAlive;
  float weight;
  int yearOfCapture;
};

//14.e
void printAnimal(Animal a) {
  Serial.println("Animal Details:");
  Serial.print("Family: ");
  Serial.println(a.family);
  Serial.print("Species: ");
  Serial.println(a.species);
  Serial.print("Is Alive: ");
  Serial.println(a.isAlive ? "Yes" : "No");
  Serial.print("Weight: ");
  Serial.println(a.weight);
  Serial.print("Year of Capture: ");
  Serial.println(a.yearOfCapture);
  Serial.println();
}

void swapWeight(Animal *a, Animal *b) {
  float temp = a->weight;
  a->weight = b->weight;
  b->weight = temp;
}

void setup() {
  Serial.begin(115200);
  //14.d
  Animal hummingbird = {"bird", "birdie", true, 50.0, 2022};
  Animal tiger = {"tigermis", "tigermissen", false, 220.5, 2019};

  Serial.println("Before Swapping:");
  printAnimal(hummingbird);
  printAnimal(tiger);

  swapWeight(&hummingbird, &tiger);

  Serial.println("After Swapping:");
  printAnimal(hummingbird);
  printAnimal(tiger);
}

void loop() {
  
}

