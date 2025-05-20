#include <stdio.h>
int main()
{
  int lM = 3, lC = 3; // Left side missionaries and cannibals
  int rM = 0, rC = 0; // Right side missionaries and cannibals
  int uM, uC;
  // User input for left to right travel
  int userM, userC; // User input for right to left travel
  int k = 0;
  // Number of total moves
  printf("\n\tGame Start\n");
  printf("Now the task is to move all of them to right side of the river\n");
  printf("Rules:\n1. The boat can carry at most two people\n");
  printf("2. If cannibals outnumber missionaries on either side, missionaries will be eaten\n");
  printf("3. The boat cannot cross the river with no people\n");
  printf("\nM M M C C C | --- | \n");
  while (1)
  {
    // Left to Right Travel
    while (1)
    {
      printf("Left side -> Right side river travel\n");
      printf("Enter number of Missionaries travel => ");
      scanf("%d", &uM);
      printf("Enter number of Cannibals travel => ");
      scanf("%d", &uC);
      if (uM == 0 && uC == 0)
      {
        printf("Empty travel not possible\nRe-enter:\n");
      }
      else if ((uM + uC) <= 2 && (lM - uM) >= 0 && (lC - uC) >= 0)
      {
        break;
      }
      else
      {
        printf("Wrong input, re-enter:\n");
      }
    }
    lM -= uM;
    lC -= uC;
    rM += uM;
    rC += uC;
    k++;
    printf("\n");
    for (int i = 0; i < lM; i++)
      printf("M ");
    for (int i = 0; i < lC; i++)
      printf("C ");
    printf("| --> | ");
    for (int i = 0; i < rM; i++)
      printf("M ");
    for (int i = 0; i < rC; i++)
      printf("C ");
    printf("\n");
    // Check for loss condition - if cannibals outnumber missionaries on either side
    // (and there are missionaries present)
    if ((lM > 0 && lC > lM) || (rM > 0 && rC > rM))
    {
      printf("Cannibals eat missionaries:\nYou lost the game\n");
      break;
    }
    // Check for win condition - all missionaries and cannibals on right side
    if (rM == 3 && rC == 3)
    {
      printf("You won the game : \n\tCongrats\n");
      printf("Total attempts: %d\n", k);
      break;
    }
    // Right to Left Travel
    while (1)
    {
      printf("Right side -> Left side river travel\n");
      printf("Enter number of Missionaries travel => ");
      scanf("%d", &userM);
      printf("Enter number of Cannibals travel => ");
      scanf("%d", &userC);
      if (userM == 0 && userC == 0)
      {
        printf("Empty travel not possible\nRe-enter:\n");
      }
      else if ((userM + userC) <= 2 && (rM - userM) >= 0 && (rC - userC) >= 0)
      {
        break;
      }
      else
      {
        printf("Wrong input, re-enter:\n");
      }
    }
    lM += userM;
    lC += userC;
    rM -= userM;
    rC -= userC;
    k++;
    printf("\n");
    for (int i = 0; i < lM; i++)
      printf("M ");
    for (int i = 0; i < lC; i++)
      printf("C ");
    printf("| <-- | ");
    for (int i = 0; i < rM; i++)
      printf("M ");
    for (int i = 0; i < rC; i++)
      printf("C ");
    printf("\n");
    // Check for loss condition again
    if ((lM > 0 && lC > lM) || (rM > 0 && rC > rM))
    {
      printf("Cannibals eat missionaries:\nYou lost the game\n");
      break;
    }
  }
  return 0;
}