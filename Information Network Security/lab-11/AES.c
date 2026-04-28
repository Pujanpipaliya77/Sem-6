#include <stdio.h>
#include <string.h>

// ---------- SubBytes ----------
void SubBytes(unsigned char *state, int len) {
    for (int i = 0; i < len; i++)
        state[i] ^= 0x63;
}

// ---------- ShiftRows ----------
void ShiftRows(unsigned char *state, int len) {
    if (len < 2) return;

    unsigned char temp = state[0];
    for (int i = 0; i < len - 1; i++)
        state[i] = state[i + 1];
    state[len - 1] = temp;
}

// ---------- MixColumns ----------
void MixColumns(unsigned char *state, int len) {
    for (int i = 0; i < len; i++)
        state[i] ^= 0xAA;
}

// ---------- AddRoundKey ----------
void AddRoundKey(unsigned char *state, unsigned char *key, int len) {
    for (int i = 0; i < len; i++)
        state[i] ^= key[i % 16];
}

// ---------- AES Round ----------
void AES_Round(unsigned char *state, unsigned char *key, int len, int round, int totalRounds) {
    SubBytes(state, len);
    ShiftRows(state, len);

    if (round != totalRounds)
        MixColumns(state, len);

    AddRoundKey(state, key, len);
}

// ---------- MAIN ----------
int main() {
    unsigned char plaintext[100];
    unsigned char key[100] = "STATIC_AES_KEY"; // 16-byte key (128-bit)
    int rounds;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    int len = strlen(plaintext) - 1; // remove newline
    plaintext[len] = '\0';

    rounds = len;   // 🔥 rounds decided from plaintext length

    // Initial AddRoundKey
    AddRoundKey(plaintext, key, len);

    // Execute rounds
    for (int r = 1; r <= rounds; r++)
        AES_Round(plaintext, key, len, r, rounds);

    // Final Ciphertext
    printf("\nCiphertext (HEX): ");
    for (int i = 0; i < len; i++)
        printf("%02X ", plaintext[i]);
}
