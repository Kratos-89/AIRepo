#include <stdio.h>

void pourWater(int fromCap, int toCap, int target) {
    int from = fromCap, to = 0, step = 1;
    printf("Step %d: Fill Jug1 (%d, %d)\n", step++, from, to);

    while (from != target && to != target) {
        int pour = (toCap - to < from) ? (toCap - to) : from;
        from -= pour;
        to += pour;
        printf("Step %d: Pour Jug1 -> Jug2 (%d, %d)\n", step++, from, to);

        if (from == target || to == target) break;

        if (!from) {
            from = fromCap;
            printf("Step %d: Refill Jug1 (%d, %d)\n", step++, from, to);
        }

        if (to == toCap) {
            to = 0;
            printf("Step %d: Empty Jug2 (%d, %d)\n", step++, from, to);
        }
    }

    printf("Target achieved: (%d, %d)\n", from, to);
}

int main() {
    int jug1 = 4, jug2 = 3, target = 2;
    printf("Solving Water Jug Problem for Jug1 = %dL, Jug2 = %dL, Target = %dL\n\n", jug1, jug2, target);
    pourWater(jug1, jug2, target);
    return 0;
}