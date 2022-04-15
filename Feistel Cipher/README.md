                                  ******** IN PROGRESS ********

#### Project Desciption:

Write a program that inputs from the keyboard a decimal number k, such that 0 ≤ k < 2
24 (KEY), and then
requests a plaintext sentence to be encrypted using an algorithm implemented by you. Plaintexts may contain
any characters (except spaces). Your algorithm must be based on the Feistel cipher (similar to DES). The
algorithm must run 4 rounds of encryption. The sub-keys should be generated from the original key by using the
16 rightmost bits of the key. The use of the key in the second round and beyond should be preceded by a four
bits left circular rotation of the 16 bits used in the previous round. The F function should consist of a
permutation reversing the byte configuration of its input (example with 16 bits:
b<sub>15</sub>b<sub>14</sub>b<sub>13</sub>b<sub>12</sub>b<sub>11</sub>b<sub>10</sub>b<sub>9</sub>b<sub>8</sub>b<sub>7</sub>b<sub>6</sub>b<sub>5</sub>b<sub>4</sub>b<sub>3</sub>b<sub>2</sub>b<sub>1</sub>b<sub>0</sub> would become b7b6b5b4b3b2b1b0b15b14b13b12b11b10b9b8) and an XOR with
the current round key value. According to Feistel, it is easy to notice that the plaintext blocks entering the
encryption algorithm will consist of 32 bits (4 bytes). The program output must be the encrypted text displayed
in hexadecimal (ciphertext).




#### Special Requirements: 

Projects will need to handle input strings limited by the end of line or a maximum of 50 characters(example:
LOSS_OF_POINTS_CAUSED_BY_NOT_READING_THIS). In case the string length is not a multiple of 4,
characters from the beginning of the string should be used to fill the open spaces (Example: FGRADE, should
be treated as FGRADEFG). Encryption does not need to be tested for inverted operation, so do not try to
develop a decryption version of the algorithm (Feistel decryption uses the same algorithm with reversed keys).
