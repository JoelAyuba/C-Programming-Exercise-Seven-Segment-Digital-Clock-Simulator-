# C-Programming-Exercise-Seven-Segment-Digital-Clock-Simulator-

# Academic Integrity Note: This code was developed as an individual assignment for the University of Birmingham (School of Engineering). It relies strictly on techniques discussed in lectures, labs, and the official study guide.

## Overview
This repository contains the C source code for **Exercise B** of the Computing for Engineers Assessed Lab 1. The program simulates the behavior of a digital clock constructed from four seven-segment LED displays. It reads a 24-hour clock time from the user, validates it, and dynamically calculates the specific electronic segments that must be activated to display the digits `1`, `2`, and `3`.

## Features & Requirements
* **Continuous Execution:** The program loops continuously, prompting the user for a time until the explicit termination code `9990` is entered.
* **Rigorous Validation:** It parses the 4-digit character input, ensuring it only contains digits and represents a mathematically valid 24-hour clock time (HH:MM). Illegal formats print a multi-line error.
* **Algorithmic Extraction:** The program uses a descending `for` loop to extract digits linearly from the 1000s column down to the 1s column.
* **Targeted Activation:** Only the digits `1`, `2`, and `3` produce segment connections. Any other digits (including `0`) are explicitly printed as "ignored".
* **Dynamic Segment Mapping:** The base segments for the rightmost digit are dynamically shifted by an offset of `+10` for each successive column moving to the left, modeling a real-world continuous circuit. 

## Technical Details

### Digit Extraction Formula
To mathematically isolate a specific digit from the full integer time string, the program relies on the following formula:

$digit = \frac{c \bmod (10h)}{h}$

Where:
* $c$ is the parsed 24-hour clock time.
* $\bmod$ is the modulus operator in C (`%`).
* $h$ is the positional weight being targeted (1000, 100, 10, or 1).

### Base Circuit Segments (1s Column)
| Digit | Segments to Light Up |
| :--- | :--- |
| **1** | 2, 5 |
| **2** | 1, 2, 3, 6, 7 |
| **3** | 1, 2, 3, 5, 6 |

*The 10s, 100s, and 1000s columns automatically apply a +10, +20, and +30 positional offset to these base segments, respectively.*

## Example Output

```text
Enter 24-hour clock time: 2469
Error
illegal time
Enter 24-hour clock time: 0978
Error
illegal time
Enter 24-hour clock time: 1122
The digits you need to connect are:
Digit 1 needs 32 35
Digit 1 needs 22 25
Digit 2 needs 11 12 13 16 17
Digit 2 needs 1 2 3 6 7
Enter 24-hour clock time: 1234
The digits you need to connect are:
Digit 1 needs 32 35
Digit 2 needs 21 22 23 26 27
Digit 3 needs 11 12 13 15 16
Digit 4 ignored
Enter 24-hour clock time: 9990
End of the program


