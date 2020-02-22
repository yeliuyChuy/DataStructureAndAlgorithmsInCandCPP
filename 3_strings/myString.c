#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void Swap(char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int GetLength(char *string) {
  for (int i = 0; string[i] != '\0'; i++) {
  }
  printf("Length of this string is %d\n", i);
  return i;
}

void ChangeCase(char *string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] >= 65 && string[i] <= 90) {
      string[i] += 32;
    } else if (string[i] >= 97 && string[i] <= 122) {
      string[i] -= 32;
    }
  }
  return;
}

bool Valid(char *string) // check if a string is valid or not
{
  for (int i = 0; string[i] != '\0'; i++) {
    if (!(string[i] >= 65 && string[i] <= 90) &&
        !(string[i] >= 97 && string[i] <= 122) &&
        !(string[i] >= 48 && string[i] <= 57)) {
      return false;
    }
  }
  return true;
}

void Reverse(char *string) {
  char temp;
  for (int i = 0; string[i] != '\0'; i++)
    i = i - 1; // the char before '\0'
  for (int j = 0; j < i; j++, i--) {
    temp = string[j];
    string[j] = string[i];
    string[i] = temp;
  }
  return;
}
