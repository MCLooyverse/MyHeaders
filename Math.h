#ifndef MATHMCL_H
#define MATHMCL_H

#ifndef DEVIATION
#define DEVIATION 0.000001
#endif


#include <vector>
#include <string>

typedef unsigned int uint;
typedef unsigned long long int ullint;
typedef long long int llint;



namespace MCL {
  const double PI =     3.14159265358979323846;
  const double TAU =    6.28318530717958647692;
  const double EulerE = 2.71828182845904523536;


  const std::vector<unsigned long int> PrimeList = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387, 5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791, 5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939, 5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133, 6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221, 6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919};


  double pow(double, long long int);
  double pow(double, double);
  long long int pow(long long int, ullint);

  double NM_root(long long int Index, double Radicand, double Deviation, double Guess, double OG_Guess);
  double root(long long int Index, double Radicand, std::string Method = "NM", double Deviation = DEVIATION);


  double mod(double, double);
  ullint mod(llint, const ullint);
  ullint mod(ullint, const ullint);

  ullint powmod(llint, llint, const ullint);

  long long int floor(double);
  long long int ceil(double);
  long long int round(double);

  double frac(double);


  std::vector<ullint> fact(ullint);
  std::vector<ullint> pfact(ullint);
  std::vector<ullint> upfact(ullint);
  ullint totient(ullint);

  std::vector<ullint> SievePrimes(ullint);

  bool BFPrimeCheck(ullint);
  bool FermatPrimeCheck(ullint);


  double log(double, double);
  double ln(double);
  long long int flog(double, double); //equal to floor(log(double, double))


  long long int abs(long long int);
  double abs(double);

  short int sgn(long long int);
  short int sgn(double);


  long long int* ToFrac(double);


  double cos(double theta);
  double sin(double theta);

  ullint Factorial(ullint n);
  ullint Choose(ullint n, ullint m);
  std::vector<ullint> AllChoose(ullint n, bool = 0);

  ullint CountRecur(ullint Freq, ullint Phase, ullint Len);

  template <class T> T max(T a);
  template <class T> T min(T a);
  template <class T> T max(T a, T b...);
  template <class T> T min(T a, T b...);

  template <class T> T SHL(T, llint);


  //Definitions
  double pow(double Base, long long int Exponent)
  {
    //double, llint
    bool Inv = Exponent < 0;
    if (Inv)
      Exponent *= -1;

    double Output = 1;
    for (long long int c = 0; c < Exponent; c++)
    {
      if (Inv)
        Output /= Base;
      else
        Output *= Base;
    }

    return Output;
  }
  double pow(double Base, double Exponent)
  {
    //double, double
    long long int fExponent[] = { round(Exponent * (1 << 7)), 1 << 7 };

    return  root(fExponent[1], pow(Base, fExponent[0]));
    //delete[] fExponent;
  }
  long long int pow(long long int Base, unsigned long long int Exponent)
  {
    //llint, ullint
    long long int Output = 1;
    for (int c = 0; c < Exponent; c++)
      Output *= Base;
    return Output;
  }

  double NM_root(long long int Index, double Radicand, double Deviation, double Guess)
  {
    //std::clog << "\nFinding root(" << Index << ", " << Radicand << ")\n\n";
    if (Index == 0)
    {
      return 0;
    }

    if (Index == 1 || Radicand == 0 || Radicand == 1)
    {
      return Radicand;
    }

    bool Inv = Index < 0;
    if (Inv)
    {
      Index *= -1;
    }

    double OG_Guess = Guess;
    int Counter = 0;
    //std::cout << "Looping in root\n\n";
    while (abs(pow(Guess, Index) - Radicand) > Deviation && (Counter++ < 10000))
    {
      //f(x) = x^Index - Radicand;  L(x, Guess) = f'(Guess)(x - Guess) + f(Guess) = Index * Guess^(Index-1) * (x - Guess) + Guess^Index - Radicand
      //Find g such that L(g, Guess) = 0;  g = (Radicand - Guess^Index) / (Index * Guess^(Index - 1)) + Guess
      //std::clog << Counter << ":g = " << Guess << "; Deviation = |" << pow(Guess, Index) - Radicand << "|\n";

      if (Guess == 0)
        Guess = ++OG_Guess;
      else
      {
        //std::clog << "..g\' += " << Radicand << " / (" << Index << " * (" << Guess << ")^(" << Index-1 << ")) - " << Guess << " / " << Index << "\n";
        //std::clog << "..   += " << Radicand << " / (" << Index  << " * " << pow(Guess, Index-1) << ") - " << Guess / Index;
        //std::clog << "\n..   += " << Radicand << " / " << Index * pow(Guess, Index-1) << " - " << Guess / Index;
        //std::clog << "\n..   += " << Radicand / (Index * pow(Guess, Index-1)) - Guess / Index << "\n";
        Guess += Radicand / (Index * pow(Guess, Index-1)) - Guess / Index;
      }

      /*
      if (Counter > 1000)
        break;
      ++Counter;//*/
    }

    if (Inv)
      return 1/Guess;
    else
      return Guess;
  }
  double root(long long int Index, double Radicand, std::string Method, double Deviation)
  {
    if (Method == "NM")
    {
      return NM_root(Index, Radicand, Deviation, 1);
    }
  }


  double mod(double Num, double Den)
  {
    return Num - floor(Num / Den) * Den;
  }
  ullint mod(llint a, const ullint b)
  {
    while (a > b)
      a -= b;
    while (a & (1 << (8 * sizeof(llint) - 1)))
      a += b;
    return a;
  }
  ullint mod(ullint a, const ullint b)
  {
    while (a > b)
      a -= b;
    return a;
  }

  ullint powmod(llint Base, llint Exponent, const ullint Modulus)
  {
    while (Base < 0)
      Base += Modulus;
    bool Neg = 0;
    if (Exponent < 0)
    {
      Neg = 1;
      Exponent *= -1;
    }

    ullint Power = 1;
    for (ullint i = 0; i < Exponent; i++)
      (Power *= Base) %= Modulus;

    if (!Neg)
      return Power;

    //std::cout << "Finding inverse of " << Power << " modulo " << Modulus << "\n\n";
    ullint Mul = 0;
    while (Mul % Power != Power - 1)
    {
      Mul += Modulus;
      //std::cout << "Trying is " << Mul << "+1 a multiple of " << Power << "\n";
    }
    return (Mul + 1) / Power;
  }

  long long int floor(double x)
  {
    long long int f = (long long int)x;
    if (x - f < 0)
      --f;
    return f;
  }
  long long int ceil(double x)
  {
    long long int c = (long long int)x;
    if (x - c > 0)
      ++c;
    return c;
  }
  long long int round(double x)
  {
    long long int r = floor(x);
    if (x - r >= 0.5)
      ++r;
    return r;
  }

  double frac(double x)
  {
    return x - floor(x);
  }


  std::vector<ullint> fact(ullint x)
  {
    std::vector<ullint> Factors;
    ullint i;
    for (i = 1; i * i <= x; i++)
    {
      if (x % i == 0)
        Factors.push_back(i);
    }

    int Back = Factors.size()-1;
    if (i * i == x)
      --Back;

    for (int c = 0; c <= Back; c++)
    {
      Factors.push_back(x / Factors[Back - c]);
    }

    return Factors;
  }
  std::vector<ullint> pfact(ullint x)
  {
    std::vector<ullint> Factors;
    for (ullint p = 2; p*p <= x; p++)
    {
      while (x % p == 0)
      {
        x /= p;
        Factors.push_back(p);
      }
    }
    if (x != 1)
      Factors.push_back(x);

    return Factors;
  }
  std::vector<ullint> OLD_upfact(ullint x, bool OnePrefix)
  {
    std::vector<ullint> Factors;
    if (OnePrefix)
      Factors = { 1 };
    ullint OldX = x;
    while (x % 2 == 0)
      x /= 2;
    if (OldX != x)
    {
      Factors.push_back(2);
      OldX = x;
    }
    for (ullint p = 3; p * p <= x; p += 2)
    {
      while (x % p == 0)
        x /= p;
      if (OldX != x)
      {
        Factors.push_back(p);
        OldX = x;
      }
    }
    if (x != 1)
      Factors.push_back(x);
    return Factors;
  }
  std::vector<ullint> upfact(ullint x)
  {
    std::vector<ullint> Factors;
    if (x&1 == 0)
    {
      x >>= 1;
      Factors.push_back(2);
      while (x&1 == 0)
        x >>= 1;
    }

    for (ullint p = 3; p * p <= x; p += 2)
    {
      if (x % p == 0)
      {
        x /= p;
        Factors.push_back(p);
        while (x % p == 0)
          x /= p;
      }
    }
    if (x != 1)
      Factors.push_back(x);
    return Factors;
  }
  ullint OLD_totient(ullint n)
  {
    //Implementing phi(n) = sum over f in fact(n) of (-1)^(|upfact(f)|) * n/f
    //In words, phi of n is the sum of n on each factor of n,
    //with each term being positive if the particular factor has an even amount of prime factors,
    //or negative if it has an odd amount of prime factors.
    //Ex: phi(30) = sum over f in { 1, 2, 3, 5, 6, 10, 15, 30 } of (-1)^(|upfact(f)|) * n / f
    //= (-1)^0 * 30
    //+ (-1)^1 * 30/2 + (-1)^1 * 30/3 + (-1)^1 * 30/5
    //+ (-1)^2 * 30/6 + (-1)^2 * 30/10+ (-1)^2 * 30/15
    //+ (-1)^3 * 30/30
    //
    //= 30
    //- 15 - 10 - 6
    //+ 5  + 3  + 2
    //- 1
    //= 8

    std::vector<ullint> Primes = upfact(n); //Unique prime factors of n.  Ex: upfact(12) = { 2, 3 }
    std::vector<ullint> OfEach = AllChoose(Primes.size()); //{ Primes.size() choose x | x in [0, Primes.size()] }
    ullint Sum = 0; //Empty sum

    //Collection of j vars for selecting primes out of our bunch of primes
    //We'll need Primes.size() of them at most, plus another on the end for a nifty trick
    uint* js = new uint[Primes.size()+1];
    //Initializing them all to Primes.size()
    for (uint j = 0; j < Primes.size()+1; j++)
      js[j] = Primes.size();

    //Constructing and adding/subtracting to our Sum factors of n with `i` prime factors
    for (uint i = 0; i <= Primes.size(); i++)
    {
      //We only need `i` indicies out of js, since we need to specify `i` primes
      //Starting with {1,2,3,4...,i-1,...}
      for (uint j = 0; j < i; j++)
        js[j] = j;

      //Precomputed Primes.size() choose i.  How many ways are there to choose `i` primes out of Primes?
      //This many
      for (uint j = 0; j < OfEach[i]; j++)
      {
        uint Product = 1;  //Empty product
        //Take the product of all the primes specified by our 'js'
        for (uint k = 0; k < i; k++)
          Product *= Primes[js[k]];

        //If `i` is odd, subtract, else add.  Reminder:  `i` is the number of prime factors of each factor.
        if (i%2)
          Sum -= n / Product;
        else
          Sum += n / Product;

        //This funky business is how we make sure that we've selected every possible combination of primes
        //(Ignoring order)
        //
        //Take as an example some n which has 5 unique prime factors, and say we're in `i = 3`
        //Then picture js like this
        //js[0]: [x----]
        //js[1]: [-x---]
        //js[2]: [--x--]
        //Which represents js = {0,1,2,/*irrelevant*/}
        //It will progress each time the loop we're in now loops like this:
        //js[0]: [x----]    [x----]    [x----]    [x----]    [x----]    [x----]    [-x---]    [-x---]    [-x---]    [--x--]
        //js[1]: [-x---] -> [-x---] -> [-x---] -> [--x--] -> [--x--] -> [---x-] -> [--x--] -> [--x--] -> [---x-] -> [---x-] -> Done!
        //js[2]: [--x--]    [---x-]    [----x]    [---x-]    [----x]    [----x]    [---x-]    [----x]    [----x]    [----x]
        //
        //js follows the rule that x < y => js[x] < js[y]
        uint k = i;
        //Find the element closest to the end such that adding one to it would not break the above rule
        //This is why we had not new ...[Primes.size()], but new ...[Primes.size() + 1], it is there only so we
        //don't have a special case if k is too big, because it never can get too big.
        for ( ; js[k] + 1 >= js[k+1]; k--)
        {
          if (k == 0)
            break;
        }

        //Add one to it
        ++js[k];
        //Get everything in front of it to come back
        while (++k < i)
          js[k] = js[k-1] + 1;
      }
    }

    //Fin
    return Sum;
  }
  ullint totient(ullint n)
  {
    std::vector<ullint> ps = upfact(n);
    for (ullint p : ps)
      n -= n/p;
    return n;
  }

  std::vector<ullint> SievePrimes(ullint UpTo)
  {
    ullint* SieveList = new ullint[UpTo-2];
    ullint* End = SieveList + (UpTo - 2);
    for (ullint i = 0; i < UpTo-2; i++)
    {
      SieveList[i] = i+2;
    }

    //ullint* Prime, Write, Erase;  Occasionally, C++ has big dumb
    ullint* Prime = SieveList;
    ullint* Write = SieveList;
    ullint* Erase;
    while ((*Prime) * (*Prime) < UpTo)
    {
      Erase = Prime + (*Prime) * ((*Prime) - 1);
      while (Erase < End)
      {
        *Erase = 0;
        Erase += *Prime;
      }
      *(Write++) = *Prime;
      while (*Prime == 0)
        ++Prime;
    }
    *(Write++) = *Prime;
    while (++Prime < End)
    {
      if (*Prime)
        *(Write++) = *Prime;
    }

    std::vector<ullint> Output(SieveList, Write);
    delete[] SieveList;
    return Output;
  }
  ullint* pSievePrimes(ullint UpTo)
  {
    ullint* SieveList = new ullint[UpTo-2];
    ullint* End = SieveList + (UpTo - 2);
    for (ullint i = 0; i < UpTo-2; i++)
    {
      SieveList[i] = i+2;
    }

    //ullint* Prime, Write, Erase;  Occasionally, C++ has big dumb
    ullint* Prime = SieveList;
    ullint* Write = SieveList;
    ullint* Erase;
    while ((*Prime) * (*Prime) < UpTo)
    {
      Erase = Prime + (*Prime) * ((*Prime) - 1);
      while (Erase < End)
      {
        *Erase = 0;
        Erase += *Prime;
      }
      *(Write++) = *(Prime++);
      while (*Prime == 0)
        ++Prime;
    }
    *(Write++) = *Prime;
    while (++Prime < End)
    {
      if (*Prime)
        *(Write++) = *Prime;
    }
    *(Write++) = 0;
    return SieveList;
  }

  ullint GCF(ullint x, ullint y)
  {
    ullint Result = 1;
    while (x&1 == 0 && y&1 == 0)
    {
      Result <<= 1;
      x >>= 1;
      y >>= 1;
    }
    while (x&1 == 0)
      x >>= 1;
    while (y&1 == 0)
      y >>= 1;
    for (ullint p = 3; p*p <= x && p*p <= y; p += 2)
    {
      while (x % p == 0 && y % p == 0)
      {
        Result *= p;
        x /= p;
        y /= p;
      }
      while (x % p == 0)
        x /= p;
      while (y % p == 0)
        y /= p;
    }
    if (x != 1 && y != 1)
    {
      if (y % x == 0)
        Result *= x;
      else
        Result *= y;
    }

    return Result;
  }

  ullint LCM(ullint x, ullint y)
  {
    ullint Result = 1;
    //std::cout << "\nx=" << x << ";y=" << y << "\n";
    //std::cout << "Checking 2:\n";
    while (x % 2 == 0)
    {
      Result <<= 1;
      x >>= 1;
      if (y % 2 == 0)
        y >>= 1;
      //std::cout << "\tx=" << x << ";y=" << y << "\n";
    }
    while (y % 2 == 0)
    {
      Result <<= 1;
      y >>= 1;
      //std::cout << "\tx=" << x << ";y=" << y << "\n";
    }
    for (ullint p = 3; p*p <= x && p*p <= y; p += 2)
    {
      //std::cout << "Checking " << p << ":\n";
      while (x % p == 0)
      {
        Result *= p;
        x /= p;
        if (y % p == 0)
          y /= p;
        //std::cout << "\tx=" << x << ";y=" << y << "\n";
      }
      while (y % p == 0)
      {
        Result *= p;
        y /= p;
      //std::cout << "\tx=" << x << ";y=" << y << "\n";
      }
    }
    if (x != 1)
      Result *= x;
    if (y != 1)
      Result *= y;

    return Result;
  }

  bool BFPrimeCheck(ullint p)
  {
    if (p == 1)
      return 0;
    if (p == 2)
      return 1;
    if ((p & (ullint)1) == 0)
      return 0;
    ullint Shifter = 1;
    Shifter <<= (sizeof(ullint) * 8 - 1);
    ullint Count = sizeof(ullint) * 8 - 1;
    while ((Shifter & p) == 0)
    {
      Shifter >>= 1;
      --Count;
    }
    //std::cout << "\nflog(2, " << p << ") = " << Count << "\n";
    --Count;
    ullint Copy;
    for(int i = 3; i * i <= p; i += 2)
    {
      //std::cout << "Dividing " << p << " by " << i << " starting with bit " << Count << " in output.\n";
      Copy = p;
      Shifter = i << Count;
      while (Shifter > Copy)
      {
        Shifter >>= 1;
        --Count;
      }
      while (Copy >= i)
      {
        Copy -= Shifter;
        while (Shifter > Copy)
          Shifter >>= 1;
      }
      //std::cout << "Remainder: " << Copy << "\n\n";
      if (Copy == 0)
        return 0;
      /*
      if (p%i == 0)
        return 0;//*/
    }
    return 1;
  }
  bool FermatPrimeCheck(ullint p)
  {
    if (p < 2)
      return 0;

    for (ullint a = 2; a < p; a++)
    {
      ullint Power = 1;
      for (ullint i = 0; i < p; i++)
        (Power *= a) %= p;

      if (Power != a)
        return 0;
    }

    return 1;
  }


  double log(double Base, double Logerand)
  {
    return ln(Logerand) / ln(Base);
  }
  double ln(double Logerand)
  {
    long long int InvEpsilon = 1000000;
    return (root(InvEpsilon, Logerand) - 1) * InvEpsilon;
  }
  long long int flog(double Base, double Logerand)
  {
    long long int Exponent = 0;
    double Power = 1;

    while (Power * Base <= Logerand)
    {
      ++Exponent;
      Power *= Base;
    }

    while (Power > Logerand)
    {
      --Exponent;
      Power /= Base;
    }

    return Exponent;
  }


  long long int abs(long long int x)
  {
    if (x & (1 << (8 * sizeof(llint) - 1)))
      return ~x + 1;
    else
      return x;
  }
  double abs(double x)
  {
    if (x < 0)
      return -x;
    else
      return x;
  }

  short int sgn(long long int x)
  {
    if (x > 0)
      return 1;
    if (x < 0)
      return -1;
    return 0;
  }
  short int sgn(double x)
  {
    if (x > 0)
      return 1;
    if (x < 0)
      return -1;
    return 0;
  }


  long long int* ToFrac(double x)
  {
    long long int Den = 1;
    while (frac(x) != 0)
    {
      x *= 2;
      Den << 1;
    }

    long long int* Output = new long long int[2];
    Output[0] = x;
    Output[1] = Den;

    return Output;
  }



  double cos(double theta)
  {
    double Reduced = -pow(mod(theta + PI, TAU) - PI, (llint)2);
    double Term = 1;

    double Output = 0;

    for (unsigned int i = 0; i < 10; i++)
    {
      Output += Term;
      Term *= Reduced / (4 * i * i + 6 * i + 2);  //(2i + 1)(2i + 2) = 4i^2 + 6i + 2
    }

    return Output;
  }
  double sin(double theta)
  {
    double Reduced = -pow(mod(theta + PI, TAU) - PI, (llint)2);
    double Term = theta;

    double Output = 0;

    for (unsigned int i = 0; i < 10; i++)
    {
      Output += Term;
      Term *= Reduced / (4 * i * i + 10 * i + 6);  //(2i + 2)(2i + 3) = 4i^2 + 10i + 6
    }

    return Output;
  }


  ullint Factorial(ullint n)
  {
    ullint Output = 1;
    for (ullint i = 2; i <= n; i++)
      Output *= i;
    return Output;
  }
  ullint Choose(ullint n, ullint m)
  {
    const ullint dif = n - m;
    ullint Output = 1;
    while (n > dif)
      Output *= n--;
    Output /= Factorial(m);
    return Output;
  }
  std::vector<ullint> AllChoose(ullint n, bool ZeroPrefix)
  {
    //*
    std::vector<ullint> Output;
    if (ZeroPrefix)
      Output = {0,1};
    else
      Output = {1};
    for (ullint i = 1; i <= n; i++)
      Output.push_back((Output.back() * (n - i + 1)) / i);
    return Output;
    /*/
    std::vector<ullint> Output(n + ZeroPrefix);
    if (ZeroPrefix)
      Output[0] = 0;
    for (unsigned int i = 0; i <= n; i++)
      Output[i + ZeroPrefix] = Choose(n, i);
    return Output;//*/
  }

  ullint CountRecur(ullint Freq, ullint Phase, ullint Len)
  {
    return Len / Freq + ((Len % Freq) && ((Phase + Freq - 1) % Freq >= Freq - (Len % Freq)));
  }



  // Template function definitions
  bool elem(char c, std::string str)
  {
    for (char x : str)
    {
      if (x == c)
        return 1;
    }
    return 0;
  }
  template <class T>
  bool elem(const T& Object, const std::vector<T>& Set)
  {
    for (T x : Set)
    {
      if (x == Object)
        return 1;
    }
    return 0;
  }


  template <class T>
  T sum(std::vector<T> Set)
  {
    T Output = 0;
    for (T i : Set)
      Output += i;

    return Output;
  }


  template <class T, class U, class V>
  bool between_incl(T Between, U A, V B)
  {
    return (A <= Between && Between <= B) || (B <= Between && Between <= A);
  }

  template <class T>
  T max(T a)
  {
    return a;
  }
  template <class T>
  T min(T a)
  {
    return a;
  }
  template <class T>
  T max(T a, T b...)
  {
    T c = max(b);
    if (a > c)
      return a;
    else
      return c;
  }
  template <class T>
  T min(T a, T b...)
  {
    T c = min(b);
    if (a < c)
      return a;
    else
      return c;
  }

  template <class T> T SHL(T a, llint s)
  {
    if (s < 0)
      return a >> (-s);
    else
      return a << s;
  }
};


#endif
