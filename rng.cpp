double generateComplexRandom() {
    // Using multiple random generators to make prediction difficult
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    double randomValue = dis(gen);
    double complexValue = sin(randomValue * M_PI) + cos(randomValue * M_PI_2);
    complexValue *= dis(gen);

    // Additional cryptographic hash function to further obscure the value
    hash<double> hash_fn;
    size_t hashedValue = hash_fn(complexValue);

    return hashedValue % 10000 / 10000.0;  // Normalize to [0, 1]
}
