#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) return 0;

    int rn_valid_count = 0;

    for (int i = 1; i <= n; i++) {
        char key_digits[44];
        int count = 0;

        while (count < 44) {
            char ch = getchar();
            if (ch >= '0' && ch <= '9') {
                key_digits[count] = ch;
                count++;
            }
        }

        int sum = 0;
        int weight = 2;

        for (int j = 42; j >= 0; j--) {
            int digit = key_digits[j] - '0';
            sum += digit * weight;
            weight++;
            if (weight > 9) {
                weight = 2;
            }
        }

        int remainder = sum % 11;
        int calculated_dv;

        if (remainder == 0 || remainder == 1) {
            calculated_dv = 0;
        } else {
            calculated_dv = 11 - remainder;
        }

        int actual_dv = key_digits[43] - '0';

        if (actual_dv == calculated_dv) {
            printf("Key %d: VALID\n", i);

            if (key_digits[0] == '2' && key_digits[1] == '4') {
                rn_valid_count++;
            }
        } else {
            printf("Key %d: INVALID (DV correct: %d)\n", i, calculated_dv);
        }
    }

    printf("Valid Keys from RN: %d\n", rn_valid_count);

    return 0;
}
