/*Exercise 13

16.a A pointer stores the memory address of another variable. If you read the memory where a pointer is stored, you would find the address of the variable
it points to.

16.b The pointer initially points to the first element of the array (a[0]). With each iteration the pointer is incremented (pointer++) causing it to point
to the next element in the array. After five iterations the pointer goes out of bounds and it points to a memory location that is not a part of the array.

16.d The pointer is initialized to point to the first element of the array a[0]. Then it prints the memory of the element the pointer currently points to.
It prints the value stored at that memory address. Moves the pointer to the next element of the array. Waits 3 seconds. 

*/

//16.c
int var = 10;
int *pointer = &var; // pointer points to the address of var

//16.e
int x = 5; 
int y = 10; 

void swap(int *pointer_a, int *pointer_b) {
    int temp = *pointer_a;   // Store the value of *pointer_a in a temporary variable
    *pointer_a = *pointer_b; // Assign the value of *pointer_b to *pointer_a
    *pointer_b = temp;       // Assign the stored value (temp) to *pointer_b
}

void setup() {
  Serial.begin(115200);

  //16.c
  *pointer = 20;       // changing the value of var via the pointer
  Serial.println("16.c: Pointer Manipulation ");
  Serial.print("New value of var is: ");
  Serial.println(var); // Output will be 20

  // Print before swapping
  Serial.println("16.e: Swapping variables ");
  Serial.print("Before swap: x = ");
  Serial.print(x);
  Serial.print(", y = ");
  Serial.println(y);

  // Call the swap function
  swap(&x, &y);

  // Print after swapping
  Serial.print("After swap: x = ");
  Serial.print(x);
  Serial.print(", y = ");
  Serial.println(y);
}

void loop() {
  
}
