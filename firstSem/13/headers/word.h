// word.h

#define LEN 64

void Clear(char W[]) {
    for (int i = 0; i < LEN; ++i) W[i] = '\0';
}

int Len(char W[]) {
    int i;
    for (i = 0; W[i] != '\0'; ++i) {}
    return i;
}

void Copy(char W1[], char W2[]) {
    Clear(W2);
    for (int i = 0; i < Len(W1); ++i) W2[i] = W1[i];
}
