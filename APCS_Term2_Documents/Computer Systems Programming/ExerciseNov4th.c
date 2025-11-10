unsigned checkMSB(unsigned x) {
    return (x >> 31) & 1;
}

unsigned checkLSB(unsigned x) {
    return x & 1;
}