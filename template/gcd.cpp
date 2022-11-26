template <typename T>
T gcd(T x, T y) { return (x % y) ? gcd(y, x % y) : y; }
