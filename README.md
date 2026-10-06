# NFe Access Key Verifier – ITP / UFRN

This repository contains a C program developed for an assignment in **Introduction to Programming Techniques** (*Introdução às Técnicas de Programação – ITP*), part of the Bachelor's degree in Information Technology (**BTI**) at the Federal University of Rio Grande do Norte (**UFRN**).

The program validates 44-digit Electronic Invoice (NFe) access keys, verifying their Check Digit (DV - *Dígito Verificador*) using the Modulo 11 algorithm, and counts valid keys issued in Rio Grande do Norte (UF code `24`).

---

## Overview

1. Reads $N$ access keys formatted as 11 space-separated 4-digit groups.
2. Extracts all 44 numerical digits, ignoring layout formatting.
3. Calculates the expected Check Digit (DV) from the first 43 digits:
   * Assigns weights from 2 to 9 sequentially from right to left (restarting at 2 after 9).
   * Computes remainder $r = \text{sum} \pmod{11}$.
   * Sets DV to `0` if $r \le 1$, or $11 - r$ otherwise.
4. Compares the calculated DV with the actual 44th digit.
5. Tracks valid keys originating from Rio Grande do Norte (starting with state prefix `24`).

---

## Input & Output Format

### Input
* The first line contains an integer $N$ ($1 \le N \le 100$).
* The next $N$ lines each contain an access key made of 11 groups of 4 digits separated by spaces.

### Output
* For each key (1-based index $i$):
  * `Chave i: VALIDA` if the check digit matches.
  * `Chave i: INVALIDA (DV correto: d)` if it does not match.
* Final summary line: `Validas do RN: k`.

---

## Compilation & Execution

To compile and run the program using `gcc`:

```bash
# Compile
gcc -O2 main.c -o nfe_verifier

# Run
./nfe_verifier
