#ifndef TYPE_MATH_H
#define TYPE_MATH_H

#ifndef DEVIATION
#define DEVIATION 0.000001
#endif

#include <vector>
#include <string>

namespace mcl
{
  typedef bool Boolean;
  typedef unsigned long long int Natural;
  typedef long long int Integer;
  typedef double Real;
  typedef std::vector<Boolean> BooleanSet;
  typedef std::vector<Natural> NaturalSet;
  typedef std::vector<Integer> IntegerSet;
  typedef std::vector<Real> RealSet;

  struct Complex
  {
    Real R;
    Real I;

    Complex(const Complex& z) : R(z.R), I(z.I) {}
    Complex(Real a, Real b) : R(a), I(b) {}
    Complex(Real a) : R(a), I(0) {}
    Complex(Integer a) : R(a), I(0) {}
    Complex(Natural a) : R(a), I(0) {}
    Complex(Boolean a) : R(a), I(0) {}
    Complex() : R(0), I(0) {}
    Complex(int a) : R(a), I(0) {}

    Complex& operator=(Boolean x);
    Complex& operator=(Natural x);
    Complex& operator=(Integer x);
    Complex& operator=(Real x);
    Complex& operator=(Complex z);
    Complex& operator=(int x);

    operator Boolean() const;
    operator Natural() const;
    operator Integer() const;
    operator Real() const;

    Complex operator*(Boolean x) const;
    Complex operator*(Natural x) const;
    Complex operator*(Integer x) const;
    Complex operator*(Real x) const;
    Complex operator*(Complex z) const;
    friend Complex operator*(Boolean x, Complex z);
    friend Complex operator*(Natural x, Complex z);
    friend Complex operator*(Integer x, Complex z);
    friend Complex operator*(Real x, Complex z);
    Complex operator*(int x) const;

    Complex operator+(Boolean x) const;
    Complex operator+(Natural x) const;
    Complex operator+(Integer x) const;
    Complex operator+(Real x) const;
    Complex operator+(Complex z) const;
    friend Complex operator+(Boolean x, Complex z);
    friend Complex operator+(Natural x, Complex z);
    friend Complex operator+(Integer x, Complex z);
    friend Complex operator+(Real x, Complex z);

    Complex operator/(Boolean x) const;
    Complex operator/(Natural x) const;
    Complex operator/(Integer x) const;
    Complex operator/(Real x) const;
    Complex operator/(Complex z) const;
    friend Complex operator/(Boolean x, Complex z);
    friend Complex operator/(Natural x, Complex z);
    friend Complex operator/(Integer x, Complex z);
    friend Complex operator/(Real x, Complex z);
    Complex operator/(int x) const;

    Complex operator-(Boolean x) const;
    Complex operator-(Natural x) const;
    Complex operator-(Integer x) const;
    Complex operator-(Real x) const;
    Complex operator-(Complex z) const;
    friend Complex operator-(Boolean x, Complex z);
    friend Complex operator-(Natural x, Complex z);
    friend Complex operator-(Integer x, Complex z);
    friend Complex operator-(Real x, Complex z);
    Complex operator-(int x) const;

    Complex operator%(Boolean x) const;
    Complex operator%(Natural x) const;
    Complex operator%(Integer x) const;
    Complex operator%(Real x) const;
    Complex operator%(Complex z) const;
    friend Complex operator%(Boolean x, Complex z);
    friend Complex operator%(Natural x, Complex z);
    friend Complex operator%(Integer x, Complex z);
    friend Complex operator%(Real x, Complex z);


    Complex& operator*=(Boolean x);
    Complex& operator*=(Natural x);
    Complex& operator*=(Integer x);
    Complex& operator*=(Real x);
    Complex& operator*=(Complex z);

    Complex& operator+=(Boolean x);
    Complex& operator+=(Natural x);
    Complex& operator+=(Integer x);
    Complex& operator+=(Real x);
    Complex& operator+=(Complex z);

    Complex& operator/=(Boolean x);
    Complex& operator/=(Natural x);
    Complex& operator/=(Integer x);
    Complex& operator/=(Real x);
    Complex& operator/=(Complex z);

    Complex& operator-=(Boolean x);
    Complex& operator-=(Natural x);
    Complex& operator-=(Integer x);
    Complex& operator-=(Real x);
    Complex& operator-=(Complex z);

    Complex& operator%=(Boolean x);
    Complex& operator%=(Natural x);
    Complex& operator%=(Integer x);
    Complex& operator%=(Real x);
    Complex& operator%=(Complex z);


    Boolean operator==(Boolean x) const;
    Boolean operator==(Natural x) const;
    Boolean operator==(Integer x) const;
    Boolean operator==(Real x) const;
    Boolean operator==(Complex z) const;
    friend Boolean operator==(Boolean x, Complex z);
    friend Boolean operator==(Natural x, Complex z);
    friend Boolean operator==(Integer x, Complex z);
    friend Boolean operator==(Real x, Complex z);
    Boolean operator==(int x) const;

    Boolean operator!=(Boolean x) const;
    Boolean operator!=(Natural x) const;
    Boolean operator!=(Integer x) const;
    Boolean operator!=(Real x) const;
    Boolean operator!=(Complex z) const;
    friend Boolean operator!=(Boolean x, Complex z);
    friend Boolean operator!=(Natural x, Complex z);
    friend Boolean operator!=(Integer x, Complex z);
    friend Boolean operator!=(Real x, Complex z);
    Boolean operator!=(int x) const;

    Complex conj() const;

    std::string str() const;
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    //friend std::ostringstream& operator<<(std::ostringstream&, const Complex&);
  };
  //operator Complex(Boolean);
  //operator Complex(Natural);
  //operator Complex(Integer);
  //operator Complex(Real);

  //typedef Complex Complex;
  typedef std::vector<Complex> ComplexSet;



  const Real PI =     3.14159265358979323846;
  const Real TAU =    6.28318530717958647692;
  const Real EulerE = 2.71828182845904523536;


  enum MathErr {
    Undefined
  };

  /*
  Boolean pow(Boolean, Boolean);
  Boolean pow(Boolean, Natural);
  Boolean pow(Boolean, Integer);
  Boolean pow(Boolean, Real);
  Boolean pow(Boolean, Complex);
  */
  template <class T> Boolean pow(Boolean, T);

  Natural pow(Natural, Boolean);
  Natural pow(Natural, Natural);
  Real pow(Natural, Integer);
  Real pow(Natural, Real);
  Complex pow(Natural, Complex);

  Integer pow(Integer, Boolean);
  Integer pow(Integer, Natural);
  Real pow(Integer, Integer);
  Complex pow(Integer, Real);
  Complex pow(Integer, Complex);

  Real pow(Real, Boolean);
  Real pow(Real, Natural);
  Real pow(Real, Integer);
  Complex pow(Real, Real);
  Complex pow(Real, Complex);

  /*
  Complex pow(Complex, Boolean);
  Complex pow(Complex, Natural);
  Complex pow(Complex, Integer);
  Complex pow(Complex, Real);
  Complex pow(Complex, Complex);
  */
  template <class T> Complex pow(Complex, T);


  /*
  root(Boolean, Boolean);
  root(Boolean, Natural);
  root(Boolean, Integer);
  root(Boolean, Real);
  root(Boolean, Complex);
  */
  template <class T> T root(Boolean, T);

  Natural root(Natural, Boolean);
  Real root(Natural, Natural);
  Complex root(Natural, Integer);
  Complex root(Natural, Real);
  Complex root(Natural, Complex);

  Boolean root(Integer, Boolean);
  Real root(Integer, Natural);
  Complex root(Integer, Integer);
  Complex root(Integer, Real);
  Complex root(Integer, Complex);

  Boolean root(Real, Boolean);
  Real root(Real, Natural);
  Complex root(Real, Integer);
  Complex root(Real, Real);
  Complex root(Real, Complex);

  Boolean root(Complex, Boolean);
  Complex root(Complex, Natural);
  Complex root(Complex, Integer);
  Complex root(Complex, Real);
  Complex root(Complex, Complex);




  Boolean mod(Boolean, Boolean);
  Boolean mod(Boolean, Natural);
  Integer mod(Boolean, Integer);
  Real mod(Boolean, Real);
  Complex mod(Boolean, Complex);

  Boolean mod(Natural, Boolean);
  Natural mod(Natural, Natural);
  Integer mod(Natural, Integer);
  Real mod(Natural, Real);
  Complex mod(Natural, Complex);

  Boolean mod(Integer, Boolean);
  Natural mod(Integer, Natural);
  Integer mod(Integer, Integer);
  Real mod(Integer, Real);
  Complex mod(Integer, Complex);

  Real mod(Real, Boolean);
  Real mod(Real, Natural);
  Real mod(Real, Integer);
  Real mod(Real, Real);
  Complex mod(Real, Complex);
  /*
  mod(Complex, Boolean);
  mod(Complex, Natural);
  mod(Complex, Integer);
  mod(Complex, Real);
  mod(Complex, Complex);
  */
  template <class T> Complex mod(Complex, T);



  Boolean powmod(Boolean, Boolean, Boolean);
  Boolean powmod(Boolean, Boolean, Natural);
  /*
  powmod(Boolean, Boolean, Integer);
  powmod(Boolean, Boolean, Real);
  powmod(Boolean, Boolean, Complex);
  */
  Boolean powmod(Boolean, Natural, Boolean);
  Boolean powmod(Boolean, Natural, Natural);
  /*
  powmod(Boolean, Natural, Integer);
  powmod(Boolean, Natural, Real);
  powmod(Boolean, Natural, Complex);
  */
  Boolean powmod(Boolean, Integer, Boolean);
  Boolean powmod(Boolean, Integer, Natural);
  /*
  powmod(Boolean, Integer, Integer);
  powmod(Boolean, Integer, Real);
  powmod(Boolean, Integer, Complex);
  */
  /*
  powmod(Boolean, Real, Boolean);
  powmod(Boolean, Real, Natural);
  powmod(Boolean, Real, Integer);
  powmod(Boolean, Real, Real);
  powmod(Boolean, Real, Complex);

  powmod(Boolean, Complex, Boolean);
  powmod(Boolean, Complex, Natural);
  powmod(Boolean, Complex, Integer);
  powmod(Boolean, Complex, Real);
  powmod(Boolean, Complex, Complex);
  */

  Boolean powmod(Natural, Boolean, Boolean);
  Natural powmod(Natural, Boolean, Natural);
  /*
  powmod(Natural, Boolean, Integer);
  powmod(Natural, Boolean, Real);
  powmod(Natural, Boolean, Complex);
  */
  Boolean powmod(Natural, Natural, Boolean);
  Natural powmod(Natural, Natural, Natural);
  /*
  powmod(Natural, Natural, Integer);
  powmod(Natural, Natural, Real);
  powmod(Natural, Natural, Complex);
  */
  Boolean powmod(Natural, Integer, Boolean);
  Natural powmod(Natural, Integer, Natural);
  /*
  powmod(Natural, Integer, Integer);
  powmod(Natural, Integer, Real);
  powmod(Natural, Integer, Complex);
  */
  /*
  powmod(Natural, Real, Boolean);
  powmod(Natural, Real, Natural);
  powmod(Natural, Real, Integer);
  powmod(Natural, Real, Real);
  powmod(Natural, Real, Complex);

  powmod(Natural, Complex, Boolean);
  powmod(Natural, Complex, Natural);
  powmod(Natural, Complex, Integer);
  powmod(Natural, Complex, Real);
  powmod(Natural, Complex, Complex);
  */

  Boolean powmod(Integer, Boolean, Boolean);
  Natural powmod(Integer, Boolean, Natural);
  /*
  powmod(Integer, Boolean, Integer);
  powmod(Integer, Boolean, Real);
  powmod(Integer, Boolean, Complex);
  */
  Boolean powmod(Integer, Natural, Boolean);
  Natural powmod(Integer, Natural, Natural);
  /*
  powmod(Integer, Natural, Integer);
  powmod(Integer, Natural, Real);
  powmod(Integer, Natural, Complex);
  */
  Boolean powmod(Integer, Integer, Boolean);
  Natural powmod(Integer, Integer, Natural);
  /*
  powmod(Integer, Integer, Integer);
  powmod(Integer, Integer, Real);
  powmod(Integer, Integer, Complex);
  */
  /*
  powmod(Integer, Real, Boolean);
  powmod(Integer, Real, Natural);
  powmod(Integer, Real, Integer);
  powmod(Integer, Real, Real);
  powmod(Integer, Real, Complex);

  powmod(Integer, Complex, Boolean);
  powmod(Integer, Complex, Natural);
  powmod(Integer, Complex, Integer);
  powmod(Integer, Complex, Real);
  powmod(Integer, Complex, Complex);
  */
  /*
  powmod(Real, Boolean, Boolean);
  powmod(Real, Boolean, Natural);
  powmod(Real, Boolean, Integer);
  powmod(Real, Boolean, Real);
  powmod(Real, Boolean, Complex);

  powmod(Real, Natural, Boolean);
  powmod(Real, Natural, Natural);
  powmod(Real, Natural, Integer);
  powmod(Real, Natural, Real);
  powmod(Real, Natural, Complex);

  powmod(Real, Integer, Boolean);
  powmod(Real, Integer, Natural);
  powmod(Real, Integer, Integer);
  powmod(Real, Integer, Real);
  powmod(Real, Integer, Complex);

  powmod(Real, Real, Boolean);
  powmod(Real, Real, Natural);
  powmod(Real, Real, Integer);
  powmod(Real, Real, Real);
  powmod(Real, Real, Complex);

  powmod(Real, Complex, Boolean);
  powmod(Real, Complex, Natural);
  powmod(Real, Complex, Integer);
  powmod(Real, Complex, Real);
  powmod(Real, Complex, Complex);

  /*
  powmod(Complex, Boolean, Boolean);
  powmod(Complex, Boolean, Natural);
  powmod(Complex, Boolean, Integer);
  powmod(Complex, Boolean, Real);
  powmod(Complex, Boolean, Complex);

  powmod(Complex, Natural, Boolean);
  powmod(Complex, Natural, Natural);
  powmod(Complex, Natural, Integer);
  powmod(Complex, Natural, Real);
  powmod(Complex, Natural, Complex);

  powmod(Complex, Integer, Boolean);
  powmod(Complex, Integer, Natural);
  powmod(Complex, Integer, Integer);
  powmod(Complex, Integer, Real);
  powmod(Complex, Integer, Complex);

  powmod(Complex, Real, Boolean);
  powmod(Complex, Real, Natural);
  powmod(Complex, Real, Integer);
  powmod(Complex, Real, Real);
  powmod(Complex, Real, Complex);

  powmod(Complex, Complex, Boolean);
  powmod(Complex, Complex, Natural);
  powmod(Complex, Complex, Integer);
  powmod(Complex, Complex, Real);
  powmod(Complex, Complex, Complex);

  template <class T, class U> Complex powmod(Complex, T, U);*/


  Boolean floor(Boolean);
  Natural floor(Natural);
  Integer floor(Integer);
  Integer floor(Real);
  Complex floor(Complex);

  Boolean ceil(Boolean);
  Natural ceil(Natural);
  Integer ceil(Integer);
  Integer ceil(Real);
  Complex ceil(Complex);

  Boolean round(Boolean);
  Natural round(Natural);
  Integer round(Integer);
  Integer round(Real);
  Complex round(Complex);

  template <class T> T frac(T);



  NaturalSet fact(Natural);
  NaturalSet pfact(Natural);
  NaturalSet upfact(Natural);
  Natural totient(Natural);

  NaturalSet SievePrimes(Natural);

  Boolean IsPrime_Check(Natural);
  Boolean IsPrime_Fermat(Natural);


  /*Always undefined
  log(Boolean, Boolean);
  log(Boolean, Natural);
  log(Boolean, Integer);
  log(Boolean, Real);
  log(Boolean, Complex);
  */
  //template <class T, class U> Complex log(T, U);
  //*
  //Boolean log(Natural, Boolean);
  Real log(Natural, Natural);
  Complex log(Natural, Integer);
  Complex log(Natural, Real);
  Complex log(Natural, Complex);

  //Boolean log(Integer, Boolean);
  Complex log(Integer, Natural);
  Complex log(Integer, Integer);
  Complex log(Integer, Real);
  Complex log(Integer, Complex);

  //Boolean log(Real, Boolean);
  Complex log(Real, Natural);
  Complex log(Real, Integer);
  Complex log(Real, Real);
  Complex log(Real, Complex);

  //Boolean log(Complex, Boolean);
  Complex log(Complex, Natural);
  Complex log(Complex, Integer);
  Complex log(Complex, Real);
  Complex log(Complex, Complex);
  //*/

  template <class T> Boolean log(T, Boolean);

  Boolean ln(Boolean);
  Real ln(Natural);
  Complex ln(Integer);
  Complex ln(Real);
  Complex ln(Complex);


  Natural flog(Natural, Natural);


  Boolean abs(Boolean);
  Natural abs(Natural);
  Natural abs(Integer);
  Real abs(Real);
  Real abs(Complex);

  Boolean sqabs(Boolean);
  Natural sqabs(Natural);
  Natural sqabs(Integer);
  Real sqabs(Real);
  Real sqabs(Complex);

  Boolean sgn(Boolean);
  Boolean sgn(Natural);
  Integer sgn(Integer);
  Integer sgn(Real);
  Complex sgn(Complex);

  Real arg(Integer);
  Real arg(Real);
  Real arg(Complex);

  Real Re(Complex);
  Real Im(Complex);



  Real cos(Real);
  Complex cos(Complex);

  Real sin(Real);
  Complex sin(Complex);

  Real tan(Real);
  Complex tan(Complex);

  Complex arccos(Real);
  Complex arccos(Complex);

  Complex arcsin(Real);
  Complex arcsin(Complex);

  Real arctan(Real);
  Complex arctan(Complex);

  Complex cis(Real);
  Complex cis(Complex);



  Boolean Factorial(Boolean);
  Natural Factorial(Natural);
  Natural Factorial(Integer);
  /* No.  Absolutely not.
  Real Factorial(Real);
  Complex Factorial(Complex);
  */



  Natural GCD(Natural a, Natural b);



  Natural Choose(Natural, Natural);


  Natural CountRecur(Natural Period, Natural Phase, Natural Len);



  template <class T> std::vector<std::vector<T>> Permute(const std::vector<T>& S);



  template <class T> T max(T a);
  template <class T> T min(T a);
  template <class T> T max(T a, T b...);
  template <class T> T min(T a, T b...);



  template <class T> std::vector<T> Intersect(std::vector<T> A, std::vector<T> B);

  template <class T> Boolean elem(T a, std::vector<T> A);

  //====Defintions====


  template <class T> Boolean pow(Boolean a, T b)//Slightly wrong
  {
    return a;
  }

  Natural pow(Natural a, Boolean b)
  {
    if (a == 0 && b == 0)
      throw(Undefined);

    if (b == 0)
      return 1;
    return a;
  }
  Natural pow(Natural a, Natural b)
  {
    /*
    Natural o = 1;
    for (Natural i = 0; i < b; i++)
      o *= a;
    return o;
    */
    Natural o = 1;
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        o *= a;
      a *= a;
    }
    return o;
  }
  Real pow(Natural a, Integer b)
  {
    Boolean s = b < 0;
    if (s)
      b = -b;

    Real o = 1;
    /*
    for (Natural i = 0; i < b; i++)
      o *= a;
    */

    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        o *= a;
      a *= a;
    }

    if (s)
      return 1/o;
    return o;
  }
  Real pow(Natural a, Real b)
  {
    Integer n = b;
    Natural d = 1;
    while (n != b)
    {
      n = (b *= 2);
      d <<= 1;
    }

    return pow(root(d, a), n);
  }//*
  Complex pow(Natural a, Complex b)
  {
    if (a == 0)
    {
      if (sgn(b) != 1.0)
        throw(Undefined);
      return 0.0;
    }
    return pow(a, b.R) * cis(b.I * ln(a));
  }//*/

  Integer pow(Integer a, Boolean b)
  {
    if (b)
      return a;
    if (a == 0)
      throw(Undefined);
    return 1;
  }
  Integer pow(Integer a, Natural b)
  {
    Integer o = 1;
    /*
    for (Natural i = 0; i < b; i++)
      o *= a;
    */
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        o *= a;
      a *= a;
    }
    return o;
  }
  Real pow(Integer a, Integer b)
  {
    Boolean s = b < 0;
    if (s)
      b = -b;

    Real o = 1;
    /*
    for (Natural i = 0; i < b; i++)
      o *= a;
    */
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        o *= a;
      a *= a;
    }
    if (s)
      return 1/o;
    return o;
  }
  Complex pow(Integer a, Real b)
  {
    Integer n = b;
    Natural d = 1;
    while (n != b)
    {
      n = (b *= 2);
      d <<= 1;
    }

    return pow(root(d, a), n);
  }
  //*
  Complex pow(Integer a, Complex b)
  {
    if (a == 0)
    {
      if (sgn(b) != 1.0)
        throw(Undefined);
      return 0.0;
    }
    return pow(a, b.R) * cis(b.I * ln(a));
  }//*/

  Real pow(Real a, Boolean b)
  {
    if (b)
      return a;
    if (a == 0)
      throw(Undefined);
    return 1;
  }
  Real pow(Real a, Natural b)
  {
    /*
    Real o = 1;
    for (Natural i = 0; i < b; i++)
      o *= a;
    return o;
    */
    //Maybe
    Real o = 1;
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        o *= a;
      a *= a;
    }
    return o;
  }
  Real pow(Real a, Integer b)
  {
    Boolean s = b < 0;
    if (s)
      b = -b;

    Real o = 1;
    /*
    for (Natural i = 0; i < b; i++)
      o *= a;
    */
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        o *= a;
      a *= a;
    }
    if (s)
      return 1/o;
    return o;
  }
  Complex pow(Real a, Real b)
  {
    Integer n = b;
    Natural d = 1;
    while (n != b)
    {
      n = (b *= 2);
      d <<= 1;
    }

    return pow(root(d, a), n);
  }
  Complex pow(Real a, Complex b)
  {
    if (a == 0)
    {
      if (sgn(b) != 1.0)
        throw(Undefined);
      return 0.0;
    }
    return pow(a, b.R) * cis(b.I * ln(a));
  }

  template <class T> Complex pow(Complex a, T b)
  {
    if (a == 0.0)
    {
      if (sgn(b) != 1.0)
        throw(Undefined);
      return 0.0;
    }
    return pow(abs(a), b) * cis(arg(a) * b);
  }



  template <class T> T root(Boolean a, T b)
  {
    if (a == 0)
      throw(Undefined);
    return b;
  }

  Natural root(Natural a, Boolean b)
  {
    if (a == 0)
      throw(Undefined);
    return b;
  }
  Real root(Natural a, Natural b)
  {
    if (a == 0)
      throw(Undefined);
    if (a == 1)
      return (Real)b;
    if (b == 0)
      return 0.0;
    if (b == 1)
      return 1.0;

    //Using Newton's method on f(x) = x^a - b
    Real g = 1;
    Real p = 1;
    while (abs(p - b) > DEVIATION)
    {
      //Tangent line to f(x) at (g, f(g)):  f'(g)(x - g) + f(g) = ag^a / g * (x - g) + g^a - b
      //= (a(x - g) / g + 1)g^a - b
      //= (ax / g - a + 1)g^a - b
      //let g' be the zero of the tangent line => (ag' / g - a + 1)g^a - b = 0
      //=> g' = g/a * (b / g^a + a - 1) = b / (ag^(a-1)) + g - g/a

      g += g / a * (b / p - 1);
      p = pow(g, a);
    }

    return g;
  }
  Complex root(Natural a, Integer b)
  {
    if (a == 0)
      throw(Undefined);
    if (a == 1)
      return (Real)b;
    if (b == 0)
      return 0.0;
    if (b == 1)
      return 1.0;

    if (b < 0)
      return root(a, (Natural)(-b)) * cis(PI / a);

    Real g = 1;
    Real p = 1;
    while (abs(p - b) > DEVIATION)
    {
      g += g / a * (b / p - 1);
      p = pow(g, a);
    }

    return Complex(g);
  }
  Complex root(Natural a, Real b)
  {
    if (a == 0)
      throw(Undefined);
    if (a == 1)
      return (Real)b;
    if (b == 0)
      return 0.0;
    if (b == 1)
      return 1.0;

    if (b < 0)
      return root(a, (Natural)(-b)) * cis(PI / a);

    Real g = 1;
    Real p = 1;
    while (abs(p - b) > DEVIATION)
    {
      g += g / a * (b / p - 1);
      p = pow(g, a);
    }

    return Complex(g);
  }
  Complex root(Natural a, Complex b)
  {
    return root(a, abs(b)) * cis(arg(b) / a);
  }

  Boolean root(Integer a, Boolean b)
  {
    if (a == 0 || (b == 0 && a < 0))
      throw(Undefined);
    return b;
  }
  Real root(Integer a, Natural b)
  {
    if (a == 0 || (b == 0 && a < 0))
      throw(Undefined);
    if (a == 1)
      return (Real)b;
    if (b == 0)
      return 0.0;
    if (b == 1)
      return 1.0;


    Boolean s = a < 0;
    if (s)
      a = -a;

    Real g = 1;
    Real p = 1;
    while (abs(p - b) > DEVIATION)
    {
      g += g / a * (b / p - 1);
      p = pow(g, a);
    }

    if (s)
      return 1 / g;
    return g;
  }
  Complex root(Integer a, Integer b)
  {
    if (a == 0 || (b == 0 && a < 0))
      throw(Undefined);
    if (a == 1)
      return (Real)b;
    if (b == 0)
      return 0.0;
    if (b == 1)
      return 1.0;

    if (b < 0)
      return root(a, (Natural)(-b)) * cis(PI / a);

    Boolean s = a < 0;
    if (s)
      a = -a;

    Real g = 1;
    Real p = 1;
    while (abs(p - b) > DEVIATION)
    {
      g += g / a * (b / p - 1);
      p = pow(g, a);
    }

    if (s)
      return Complex(1 / g);
    return Complex(g);
  }
  Complex root(Integer a, Real b)
  {
    if (a == 0 || (b == 0 && a < 0))
      throw(Undefined);
    if (a == 1)
      return (Real)b;
    if (b == 0)
      return 0.0;
    if (b == 1)
      return 1.0;

    if (b < 0)
      return root(a, -b) * cis(PI / a);

    Boolean s = a < 0;
    if (s)
      a = -a;

    Real g = 1;
    Real p = 1;
    while (abs(p - b) > DEVIATION)
    {
      g += g / a * (b / p - 1);
      p = pow(g, a);
    }

    if (s)
      return 1 / g;
    return g;
  }
  Complex root(Integer a, Complex b)
  {
    return root(a, abs(b)) * cis(arg(b) / a);
  }

  Boolean root(Real a, Boolean b)
  {
    if (a == 0 || (b == 0 && a < 0))
      throw(Undefined);
    return b;
  }
  Real root(Real a, Natural b)
  {
    Integer n = a;
    Natural d = 1;
    while (n != a)
    {
      n = (a *= 2);
      d <<= 1;
    }

    return pow(root(n, b), d);
  }
  Complex root(Real a, Integer b)
  {
    Integer n = a;
    Natural d = 1;
    while (n != a)
    {
      n = (a *= 2);
      d <<= 1;
    }

    return pow(root(n, b), d);
  }
  Complex root(Real a, Real b)
  {
    Integer n = a;
    Natural d = 1;
    while (n != a)
    {
      n = (a *= 2);
      d <<= 1;
    }

    return pow(root(n, b), d);
  }
  Complex root(Real a, Complex b)
  {
    return root(a, abs(b)) * cis(abs(b) / a);
  }

  Boolean root(Complex a, Boolean b)
  {
    if (a == 0.0 || (b == 0 && sgn(a) != 1.0))
      throw(Undefined);
    return b;
  }
  Complex root(Complex a, Natural b)
  {
    if (a == 0.0)
      throw(Undefined);
    return pow(b, a.conj() / sqabs(a));
  }
  Complex root(Complex a, Integer b)
  {
    if (a == 0.0)
      throw(Undefined);
    return pow(b, a.conj() / sqabs(a));
  }
  Complex root(Complex a, Real b)
  {
    if (a == 0.0)
      throw(Undefined);
    return pow(b, a.conj() / sqabs(a));
  }
  Complex root(Complex a, Complex b)
  {
    if (a == 0.0)
      throw(Undefined);
    return pow(b, a.conj() / sqabs(a));
  }



  Boolean mod(Boolean a, Boolean b)
  {
    if (b)
      return 1;
    throw(Undefined);
  }
  Boolean mod(Boolean a, Natural b)
  {
    switch (b)
    {
      case 0:
        throw(Undefined);
      case 1:
        return 0;
      default:
        return a;
    }
  }
  Integer mod(Boolean a, Integer b)
  {
    switch (b)
    {
      case 0:
        throw(Undefined);
      case 1:
      case -1:
        return 0;
      default:
        if (b > 0)
          return a;
        if (a)
          return b + 1;
        return 0;
    }
  }
  Real mod(Boolean a, Real b)
  {
    if (b == 0)
      throw(Undefined);
    if (a == 0)
      return 0;

    if (b > 1)
      return 1;
    if (b == 1)
      return 0;
    if (0 < b && b < 1)
      return 1 - b;
    return b + 1;
  }
  Complex mod(Boolean a, Complex b)
  {
    return a - b * floor(a / b);
  }

  Boolean mod(Natural a, Boolean b)
  {
    if (b)
      return 0;
    throw(Undefined);
  }
  Natural mod(Natural a, Natural b)
  {
    if (b == 0)
      throw(Undefined);
    return a % b;
  }
  Integer mod(Natural a, Integer b)
  {
    if (b == 0)
      throw(Undefined);
    if (b > 0)
      return a % b;
    return (a % (-b)) + b;
  }
  Real mod(Natural a, Real b)
  {
    if (b == 0)
      throw(Undefined);

    return (Real)a - b * floor(a / b);
  }
  Complex mod(Natural a, Complex b)
  {
    if (b == 0.0)
      throw(Undefined);

    return a - b * floor(a / b);
  }

  Boolean mod(Integer a, Boolean b)
  {
    if (b)
      return 0;
    throw(Undefined);
  }
  Natural mod(Integer a, Natural b)
  {
    if (b == 0)
      throw(Undefined);

    if (a < 0)
      return b - ((-a) % b);
    return a % b;
  }
  Integer mod(Integer a, Integer b)
  {
    if (b == 0)
      throw(Undefined);

    if (a < 0 && b < 0)
      return -((-a) % (-b));
    if (a < 0)
      return b - ((-a) % b);
    if (b < 0)
      return (a % (-b)) + b;
    return a % b;
  }
  Real mod(Integer a, Real b)
  {
    if (b == 0)
      throw(Undefined);

    return (Real)a - b * floor(a / b);
  }
  Complex mod(Integer a, Complex b)
  {
    if (b == 0.0)
      throw(Undefined);

    return a - b * floor(a / b);
  }

  Real mod(Real a, Boolean b)
  {
    if (b)
      return a - floor(a);
    throw(Undefined);
  }
  Real mod(Real a, Natural b)
  {
    if (b == 0)
      throw(Undefined);

    return a - b * floor(a / b);
  }
  Real mod(Real a, Integer b)
  {
    if (b == 0)
      throw(Undefined);

    return a - b * floor(a / b);
  }
  Real mod(Real a, Real b)
  {
    if (b == 0)
      throw(Undefined);

    return a - b * floor(a / b);
  }
  Complex mod(Real a, Complex b)
  {
    if (b == 0.0)
      throw(Undefined);

    return a - b * floor(a / b);
  }

  template <class T> Complex mod(Complex a, T b)
  {
    if (b == 0.0)
      throw(Undefined);

    return a - b * floor(a / b);
  }



  Boolean powmod(Boolean a, Boolean b, Boolean c)
  {
    if ((!a && !b) || !c)
      throw(Undefined);
    return 0;
  }
  Boolean powmod(Boolean a, Boolean b, Natural c)
  {
    if ((!a && !b) || c == 0)
      throw(Undefined);

    if (c == 1)
      return 0;
    return a;
  }
  Boolean powmod(Boolean a, Natural b, Boolean c)
  {
    if ((!a && b == 0) || !c)
      throw(Undefined);
    return 0;
  }
  Boolean powmod(Boolean a, Natural b, Natural c)
  {
    if ((!a && b == 0) || c == 0)
      throw(Undefined);
    if (c == 1)
      return 0;
    return a;
  }
  Boolean powmod(Boolean a, Integer b, Boolean c)
  {
    if ((!a && b <= 0) || !c)
      throw(Undefined);
    return 0;
  }
  Boolean powmod(Boolean a, Integer b, Natural c)
  {
    if ((!a && b <= 0) || c == 0)
      throw(Undefined);
    if (c == 1)
      return 0;
    return a;
  }

  Boolean powmod(Natural a, Boolean b, Boolean c)
  {
    if ((a == 0 && !b) || !c)
      throw(Undefined);
    return 0;
  }
  Natural powmod(Natural a, Boolean b, Natural c)
  {
    if ((a == 0 && !b) || c == 0)
      throw(Undefined);
    if (b)
      return a % c;
    return c > 1;
  }
  Boolean powmod(Natural a, Natural b, Boolean c)
  {
    if ((a == 0 && b == 0) || !c)
      throw(Undefined);
    return 0;
  }
  Natural powmod(Natural a, Natural b, Natural c)
  {
    if ((a == 0 && b == 0) || c == 0)
      throw(Undefined);

    a %= c;

    Natural o = 1;
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        (o *= a) %= c;
      (a *= a) %= c;
    }
    return o;
  }
  Boolean powmod(Natural a, Integer b, Boolean c)
  {
    if ((a == 0 && b <= 0) || !c)
      throw(Undefined);
    return 0;
  }
  Natural powmod(Natural a, Integer b, Natural c)
  {
    if ((a == 0 && b <= 0) || c == 0)
      throw(Undefined);

    a %= c;

    Boolean s = b < 0;
    if (s)
      b = -b;

    Natural o = 1;
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        (o *= a) %= c;
      (a *= a) %= c;
    }

    if (s)
    {
      Natural r = 1;
      while (r % o != 0)
        r += c;
      return r / o;
    }

    return o;
  }

  Boolean powmod(Integer a, Boolean b, Boolean c)
  {
    if ((a == 0 && !b) || !c)
      throw(Undefined);
    return 0;
  }
  Natural powmod(Integer a, Boolean b, Natural c)
  {
    if ((a == 0 && !b) || c == 0)
      throw(Undefined);

    if (!b)
      return c != 1;
    return mod(a, c);
  }
  Boolean powmod(Integer a, Natural b, Boolean c)
  {
    if ((a == 0 && !b) || !c)
      throw(Undefined);
    return 0;
  }
  Natural powmod(Integer a, Natural b, Natural c)
  {
    if ((a == 0 && b <= 0) || c == 0)
      throw(Undefined);

    a = mod(a, c);

    Natural o = 1;
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        (o *= a) %= c;
      (a *= a) %= c;
    }

    return o;
  }
  Boolean powmod(Integer a, Integer b, Boolean c)
  {
    if ((a == 0 && !b) || !c)
      throw(Undefined);
    return 0;
  }
  Natural powmod(Integer a, Integer b, Natural c)
  {
    if ((a == 0 && b <= 0) || c == 0)
      throw(Undefined);

    a = mod(a, c);

    Boolean s = b < 0;
    if (s)
      b = -b;

    Natural o = 1;
    for (Natural i = 1; i <= b && i != 0; i <<= 1)
    {
      if (i & b)
        (o *= a) %= c;
      (a *= a) %= c;
    }

    if (s)
    {
      Natural r = 1;
      while (r % o != 0)
        r += c;
      return r / o;
    }

    return o;
  }



  Boolean floor(Boolean a)
  {
    return a;
  }
  Natural floor(Natural a)
  {
    return a;
  }
  Integer floor(Integer a)
  {
    return a;
  }
  Integer floor(Real a)
  {
    if (a < 0)
      return (Integer)(a - 1);
    return (Integer)a;
  }
  Complex floor(Complex a)
  {
    return Complex(floor(a.R), floor(a.I));
  }

  Boolean ceil(Boolean a)
  {
    return a;
  }
  Natural ceil(Natural a)
  {
    return a;
  }
  Integer ceil(Integer a)
  {
    return a;
  }
  Integer ceil(Real a)
  {
    Integer b = floor(a);
    if (b != a)
      ++b;
    return b;
  }
  Complex ceil(Complex a)
  {
    return Complex(ceil(a.R), floor(a.I));
  }

  Boolean round(Boolean a)
  {
    return a;
  }
  Natural round(Natural a)
  {
    return a;
  }
  Integer round(Integer a)
  {
    return a;
  }
  Integer round(Real a)
  {
    //if |x - floor(x)| < |x - ceil(x)|: return floor(x), return ceil(x) <=> if 2x < ceil(x) + floor(x): ...
    //Technically incorrect, but handeled alright: assume frac(x) != 0, then if 2x < 2floor(x) + 1, or if x < floor(x) + 0.5

    Integer b = floor(a);
    if (a < b + 0.5)
      return b;
    return b + (a != b);
  }
  Complex round(Complex a)
  {
    return Complex(round(a.R), round(a.I));
  }

  template <class T> T frac(T a)
  {
    return a - floor(a);
  }



  NaturalSet fact(Natural a)
  {
    NaturalSet Factors;
    Natural i = 1;
    for ( ; i*i <= a; i++)
    {
      if (a % i == 0)
        Factors.push_back(i);
    }

    Natural Back = Factors.size();
    if (i*i == a)
      --Back;

    for (Natural c = 1; c <= Back; c++)
      Factors.push_back(a / Factors[Back - c]);

    return Factors;
  }
  NaturalSet pfact(Natural a)
  {
    NaturalSet Factors;
    while (a & 1 == 0)
    {
      Factors.push_back(2);
      a >>= 1;
    }

    for (Natural p = 3; p*p <= a; p += 2)
    {
      while (a % p == 0)
      {
        Factors.push_back(p);
        a /= p;
      }
    }
    if (a != 1)
      Factors.push_back(a);

    return Factors;
  }
  NaturalSet upfact(Natural a)
  {
    NaturalSet Factors;
    if (a & 1 == 0)
    {
      Factors.push_back(2);
      a >>= 1;
      while (a & 1 == 0)
        a >>= 1;
    }

    for (Natural p = 3; p*p <= a; p += 2)
    {
      if (a % p == 0)
      {
        Factors.push_back(p);
        a /= p;
        while (a % p == 0)
          a /= p;
      }
    }
    if (a != 1)
      Factors.push_back(a);

    return Factors;
  }
  Natural totient(Natural a)
  {
    NaturalSet ps = upfact(a);
    for (Natural p : ps)
      a -= a / p;
    return a;
  }



  NaturalSet SievePrimes(Natural a)
  {
    NaturalSet SieveList(a - 2);
    for (Natural i = 2; i < a; i++)
      SieveList[i - 2] = i;

    Natural ip = 0, iw = 0, ie = 2;
    while (SieveList[ip] * SieveList[ip] < a)
    {
      while (ie < a - 2)
      {
        SieveList[ie] = 0;
        ie += SieveList[ip];
      }
      SieveList[iw++] = SieveList[ip++];
      while (SieveList[ip] == 0)
        ++ip;
      ie = ip + SieveList[ip] * (SieveList[ip] - 1);
    }

    SieveList[iw++] = SieveList[ip];
    while (++ip < a - 2)
    {
      if (SieveList[ip])
        SieveList[iw++] = SieveList[ip];
    }

    SieveList.resize(iw);
    return SieveList;
  }



  Boolean IsPrime_Check(Natural a)
  {
    if (a == 1)
      return 0;
    if (a == 2)
      return 1;
    if ((a & 1) == 0)
      return 0;

    Natural Shifter = 1;
    Natural Count = sizeof(Natural) * 8 - 1;
    Shifter <<= Count;

    while ((Shifter & a) == 0)
    {
      Shifter >>= 1;
      --Count;
    }

    --Count;
    for (Natural i = 3, c = a; i * i <= a; i += 2, c = a)
    {
      Shifter = i << Count;
      while (Shifter > c)
      {
        Shifter >>= 1;
        --Count;
      }
      while (c >= i)
      {
        c -= Shifter;
        while (Shifter > c)
          Shifter >>= 1;
      }

      if (c == 0)
        return 0;
    }
    return 1;
  }
  Boolean IsPrime_Fermat(Natural a)
  {
    if (a < 2)
      return 0;

    for (Natural n = 2; n < a; n++)
    {
      if (powmod(n, a-1, a) != 1)
        return 0;
    }

    return 1;
  }

  /*
  template <class T> Boolean log(T a, Boolean b)
  {
    if (a == 0 || a == 1 || !b)
      throw(Undefined);
    return 0;
  }
  Real log(Natural a, Natural b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Natural a, Integer b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Natural a, Real b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Natural a, Complex b)
  {
    return ln(b) / ln(a);
  }

  Complex log(Integer a, Natural b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Integer a, Integer b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Integer a, Real b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Integer a, Complex b)
  {
    return ln(b) / ln(a);
  }

  Complex log(Real a, Natural b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Real a, Integer b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Real a, Real b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Real a, Complex b)
  {
    return ln(b) / ln(a);
  }

  Complex log(Complex a, Natural b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Complex a, Integer b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Complex a, Real b)
  {
    return ln(b) / ln(a);
  }
  Complex log(Complex a, Complex b)
  {
    return ln(b) / ln(a);
  }
  */


  Boolean ln(Boolean a)
  {
    if (!a)
      throw(Undefined);
    return 0;
  }
  Real ln(Natural a)
  {
    const Natural M = 1000000;  //Big.
    return M * (root(M, a) - 1);
  }
  Complex ln(Integer a)
  {
    const Natural M = 1000000;  //Big.
    return M * (root(M, a) - 1);
  }
  Complex ln(Real a)
  {
    const Natural M = 1000000;  //Big.
    return M * (root(M, a) - 1);
  }
  Complex ln(Complex a)
  {
    const Natural M = 1000000;  //Big.
    return M * (root(M, a) - 1);
  }



  Natural flog(Natural a, Natural b)
  {
    if (b == 0)
      throw(Undefined);

    Natural Power = 1;
    Natural Expon = 0;

    while (Power < b)
    {
      Power *= a;
      ++Expon;
    }

    return Expon;
  }



  Boolean abs(Boolean a)
  {
    return a;
  }
  Natural abs(Natural a)
  {
    return a;
  }
  Natural abs(Integer a)
  {
    if (a < 0)
      return -a;
    return a;
  }
  Real abs(Real a)
  {
    if (a < 0)
      return -a;
    return a;
  }
  Real abs(Complex a)
  {
    return root(2ull, a.R * a.R + a.I * a.I);
  }

  Boolean sqabs(Boolean a)
  {
    return a;
  }
  Natural sqabs(Natural a)
  {
    return a * a;
  }
  Natural sqabs(Integer a)
  {
    return a * a;
  }
  Real sqabs(Real a)
  {
    return a * a;
  }
  Real sqabs(Complex a)
  {
    return a.R * a.R + a.I * a.I;
  }

  Boolean sgn(Boolean a)
  {
    return a;
  }
  Boolean sgn(Natural a)
  {
    return (Boolean)a;
  }
  Integer sgn(Integer a)
  {
    if (a == 0)
      return 0;
    if (a < 0)
      return -1;
    return 1;
  }
  Integer sgn(Real a)
  {
    if (a == 0)
      return 0;
    if (a < 0)
      return -1;
    return 1;
  }
  Complex sgn(Complex a)
  {
    if (a == 0)
      return 0;
    return a / abs(a);
  }

  Real arg(Integer a)
  {
    if (a < 0)
      return PI;
    return 0;
  }
  Real arg(Real a)
  {
    if (a < 0)
      return PI;
    return 0;
  }
  Real arg(Complex a)
  {
    if (a.R == 0)
      return sgn(a.I) * PI/2;
    if (a.R < 0)
      return arctan(a.I / a.R) - sgn(a.I) * PI;
    return arctan(a.I / a.R);
  }

  Real Re(Complex a)
  {
    return a.R;
  }
  Real Im(Complex a)
  {
    return a.I;
  }



  Real cos(Real a)
  {
    //1 - x^2 / 2 + x^4 / 24 - ...
    //1 + (1)(-x^2 / 2) + (-x^2 / 2)(-x^2 / 12) + (x^4 / 24)(-x^2 / 30) ...

    a = mod(a + PI, TAU) - PI;
    Real s = -a * a / 2;
    Real Sum = 1;
    Real Term = 1;
    for (Natural k = 1; k < 20/*Arbitrary*/; k++)
    {
      Term *= s / (k * ((k << 1) - 1));
      Sum += Term;
    }
    return Sum;
  }
  Complex cos(Complex a)
  {
    //cos(x) = (e^(ix) + e^(-ix)) / 2
    //cos(a + bi) = (e^(ia - b) + e^(-ia + b)) / 2
    Complex c = cis(a.R); //=e^(ia)
    Real eb = pow(EulerE, a.I);

    return (c / eb + c.conj() * eb) / 2;
  }

  Real sin(Real a)
  {
    //x - x^3 / 6 + x^5 / 120 - ...
    //x + (x)(-x^2 / 6) + (-x^3 / 6)(-x^2 / 20) ...

    a = mod(a + PI, TAU) - PI;
    Real s = -a * a / 2;
    Real Sum = a;
    Real Term = a;
    for (Natural k = 1; k < 20; k++)
    {
      Term *= s / (k * ((k << 1) + 1));
      Sum += Term;
    }
    return Sum;
  }
  Complex sin(Complex a)
  {
    Complex c = cis(a.R);
    Real eb = pow(EulerE, a.I);

    return Complex(0, -0.5) * (c / eb - c.conj() * eb);
  }

  Real tan(Real a)
  {
    return sin(a) / cos(a);
  }
  Complex tan(Complex a)
  {
    return sin(a) / cos(a);
  }

  Complex arccos(Real);
  Complex arccos(Complex);

  Complex arcsin(Real);
  Complex arcsin(Complex);

  Real arctan(Real a)
  {
    if (abs(a) > 1)
      return sgn(a) * PI/2 - arctan(1/a);
    return 0.97239411 * a - 0.19194795 * a * a * a;
  }
  Complex arctan(Complex);

  Complex cis(Real a)
  {
    return Complex(cos(a), sin(a));
  }
  Complex cis(Complex a)
  {
    return cos(a) + Complex(0,1) * sin(a);
  }



  Boolean Factorial(Boolean a)
  {
    return 1;
  }
  Natural Factorial(Natural a)
  {
    Natural Prod = 1;
    for (Natural k = 2; k <= a; k++)
      Prod *= k;
    return Prod;
  }
  Natural Factorial(Integer a)
  {
    if (a < 0)
      throw(Undefined);

    Natural Prod = 1;
    for (Natural k = 2; k <= a; k++)
      Prod *= k;
    return Prod;
  }



  Natural Choose(Natural a, Natural b)
  {
    const Natural Dif = a - b;
    Natural Prod = 1;
    while (a > Dif)
      Prod *= a--;
    Prod /= Factorial(b);
    return Prod;
  }


  Natural old_GCD(Natural a, Natural b)
  {
    Natural Result = 1;
    while (a&1 == 0 && b&1 == 0)
    {
      Result <<= 1;
      a >>= 1;
      b >>= 1;
    }
    while (a&1 == 0)
      a >>= 1;
    while (b&1 == 0)
      b >>= 1;
    for (Natural p = 3; p*p <= a && p*p <= b; p += 2)
    {
      while (a % p == 0 && b % p == 0)
      {
        Result *= p;
        a /= p;
        b /= p;
      }
      while (a % p == 0)
        a /= p;
      while (b % p == 0)
        b /= p;
    }
    if (a != 1 && b != 1)
    {
      if (b % a == 0)
        Result *= a;
      else
        Result *= b;
    }

    return Result;
  }


  Natural GCD(Natural a, Natural b)
  {
    if (a == 0)
      return b;
    if (b == 0)
      return b;

    
    while (a != b)
    {
      if (a < b)
        b -= a;
      else
        a -= b;
    }
    return a;
  }


  Natural CountRecur(Natural Period, Natural Phase, Natural Len)
  {
    return Len / Period + ((Len % Period) && ((Phase + Period - 1) % Period >= Period - (Len % Period)));
  }


  template <class T> std::vector<std::vector<T>> Permute(const std::vector<T>& S)
  {
    if (S.size() < 2)
      return { S };

    std::vector<std::vector<T>> Output;
    for (int i = 0; i < S.size(); i++)
    {
      std::vector<T> tmp = S;
      for (int j = i; j < S.size() - 1; j++)
        tmp[j] = S[j+1];
      tmp.resize(S.size() - 1);
      auto SubPerms = Permute(tmp);
      for (auto p : SubPerms)
      {
        Output.push_back({S[i]});
        for (auto e : p)
          Output.back().push_back(e);
      }
    }

    return Output;
  }



  template <class T> T max(T a)
  {
    return a;
  }
  template <class T> T min(T a)
  {
    return a;
  }
  template <class T> T max(T a, T b...)
  {
    T c = max(b);
    if (a > c)
      return a;
    return c;
  }
  template <class T> T min(T a, T b...)
  {
    T c = min(b);
    if (a < c)
      return a;
    return c;
  }


  template <class T> std::vector<T> Intersect(std::vector<T> A, std::vector<T> B)
  {
    std::vector<T> Output = {};
    for (T a : A)
    for (T b : B)
    {
      if (a == b)
      {
        Output.push_back(a);
        break;
      }
    }
    return Output;
  }

  template <class T> Boolean elem(T a, std::vector<T> A)
  {
    for (T x : A)
    {
      if (x == a)
        return 1;
    }
    return 0;
  }



  //===Complex Definitions===
  Complex& Complex::operator=(Boolean x)
  {
    R = x;
    I = 0;
    return *this;
  }
  Complex& Complex::operator=(Natural x)
  {
    R = x;
    I = 0;
    return *this;
  }
  Complex& Complex::operator=(Integer x)
  {
    R = x;
    I = 0;
    return *this;
  }
  Complex& Complex::operator=(Real x)
  {
    R = x;
    I = 0;
    return *this;
  }
  Complex& Complex::operator=(Complex z)
  {
    R = z.R;
    I = z.I;
    return *this;
  }
  Complex& Complex::operator=(int x)
  {
    R = x;
    I = 0;
    return *this;
  }

  Complex::operator Boolean() const
  {
    return *this != 0;
  }
  Complex::operator Natural() const
  {
    return abs(floor(R));
  }
  Complex::operator Integer() const
  {
    return floor(R);
  }
  Complex::operator Real() const
  {
    return R;
  }/*
  operator Complex(Boolean x)
  {
    return Complex(x);
  }
  operator Complex(Natural x)
  {
    return Complex(x);
  }
  operator Complex(Integer x)
  {
    return Complex(x);
  }
  operator Complex(Real x)
  {
    return Complex(x);
  }*/

  Complex Complex::operator*(Boolean x) const
  {
    if (x)
      return *this;
    return Complex(0);
  }
  Complex Complex::operator*(Natural x) const
  {
    return Complex(R * x, I * x);
  }
  Complex Complex::operator*(Integer x) const
  {
    return Complex(R * x, I * x);
  }
  Complex Complex::operator*(Real x) const
  {
    return Complex(R * x, I * x);
  }
  Complex Complex::operator*(Complex z) const
  {
    return Complex(R * z.R - I * z.I, R * z.I + I * z.R);
  }
  Complex operator*(Boolean x, Complex z)
  {
    if (x)
      return z;
    return 0;
  }
  Complex operator*(Natural x, Complex z)
  {
    return z * x;
  }
  Complex operator*(Integer x, Complex z)
  {
    return z * x;
  }
  Complex operator*(Real x, Complex z)
  {
    return z * x;
  }
  Complex Complex::operator*(int x) const
  {
    return Complex(R * x, I * x);
  }

  Complex Complex::operator+(Boolean x) const
  {
    return Complex(R + x, I);
  }
  Complex Complex::operator+(Natural x) const
  {
    return Complex(R + x, I);
  }
  Complex Complex::operator+(Integer x) const
  {
    return Complex(R + x, I);
  }
  Complex Complex::operator+(Real x) const
  {
    return Complex(R + x, I);
  }
  Complex Complex::operator+(Complex z) const
  {
    return Complex(R + z.R, I + z.I);
  }
  Complex operator+(Boolean x, Complex z)
  {
    return z + x;
  }
  Complex operator+(Natural x, Complex z)
  {
    return z + x;
  }
  Complex operator+(Integer x, Complex z)
  {
    return z + x;
  }
  Complex operator+(Real x, Complex z)
  {
    return z + x;
  }

  Complex Complex::operator/(Boolean x) const
  {
    if (x)
      return *this;
    throw(Undefined);
  }
  Complex Complex::operator/(Natural x) const
  {
    if (x == 0)
      throw(Undefined);
    return Complex(R / x, I / x);
  }
  Complex Complex::operator/(Integer x) const
  {
    if (x == 0)
      throw(Undefined);
    return Complex(R / x, I / x);
  }
  Complex Complex::operator/(Real x) const
  {
    if (x == 0)
      throw(Undefined);
    return Complex(R / x, I / x);
  }
  Complex Complex::operator/(Complex z) const
  {
    if (z == 0)
      throw(Undefined);
    return *this * z.conj() / sqabs(z);
  }
  Complex operator/(Boolean x, Complex z)
  {
    if (z == 0)
      throw(Undefined);
    if (x)
      return z.conj() / sqabs(z);
    return 0;
  }
  Complex operator/(Natural x, Complex z)
  {
    if (z == 0)
      throw(Undefined);
    return z.conj() * x / sqabs(z);
  }
  Complex operator/(Integer x, Complex z)
  {
    if (z == 0)
      throw(Undefined);
    return z.conj() * x / sqabs(z);
  }
  Complex operator/(Real x, Complex z)
  {
    if (z == 0)
      throw(Undefined);
    return z.conj() * x / sqabs(z);
  }
  Complex Complex::operator/(int x) const
  {
    if (x == 0)
      throw(Undefined);
    return Complex(R / x, I / x);
  }

  Complex Complex::operator-(Boolean x) const
  {
    return Complex(R - x, I);
  }
  Complex Complex::operator-(Natural x) const
  {
    return Complex(R - x, I);
  }
  Complex Complex::operator-(Integer x) const
  {
    return Complex(R - x, I);
  }
  Complex Complex::operator-(Real x) const
  {
    return Complex(R - x, I);
  }
  Complex Complex::operator-(Complex z) const
  {
    return Complex(R - z.R, I - z.I);
  }
  Complex operator-(Boolean x, Complex z)
  {
    return Complex((Real)x - z.R, -z.I);
  }
  Complex operator-(Natural x, Complex z)
  {
    return Complex((Real)x - z.R, -z.I);
  }
  Complex operator-(Integer x, Complex z)
  {
    return Complex((Real)x - z.R, -z.I);
  }
  Complex operator-(Real x, Complex z)
  {
    return Complex((Real)x - z.R, -z.I);
  }
  Complex Complex::operator-(int x) const
  {
    return Complex(R - x, I);
  }

  Complex Complex::operator%(Boolean x) const
  {
    if (x)
      return Complex(frac(R), frac(I));
    throw(Undefined);
  }
  Complex Complex::operator%(Natural x) const
  {
    return mod(*this, x);
  }
  Complex Complex::operator%(Integer x) const
  {
    return mod(*this, x);
  }
  Complex Complex::operator%(Real x) const
  {
    return mod(*this, x);
  }
  Complex Complex::operator%(Complex z) const
  {
    return mod(*this, z);
  }
  Complex operator%(Boolean x, Complex z)
  {
    return mod(x, z);
  }
  Complex operator%(Natural x, Complex z)
  {
    return mod(x, z);
  }
  Complex operator%(Integer x, Complex z)
  {
    return mod(x, z);
  }
  Complex operator%(Real x, Complex z)
  {
    return mod(x, z);
  }


  Complex& Complex::operator*=(Boolean x)
  {
    if (!x)
      *this = 0;
    return *this;
  }
  Complex& Complex::operator*=(Natural x)
  {
    *this = *this * x;
    return *this;
  }
  Complex& Complex::operator*=(Integer x)
  {
    *this = *this * x;
    return *this;
  }
  Complex& Complex::operator*=(Real x)
  {
    *this = *this * x;
    return *this;
  }
  Complex& Complex::operator*=(Complex z)
  {
    *this = *this * z;
    return *this;
  }

  Complex& Complex::operator+=(Boolean x)
  {
    *this = *this + x;
    return *this;
  }
  Complex& Complex::operator+=(Natural x)
  {
    *this = *this + x;
    return *this;
  }
  Complex& Complex::operator+=(Integer x)
  {
    *this = *this + x;
    return *this;
  }
  Complex& Complex::operator+=(Real x)
  {
    *this = *this + x;
    return *this;
  }
  Complex& Complex::operator+=(Complex z)
  {
    *this = *this + z;
    return *this;
  }

  Complex& Complex::operator/=(Boolean x)
  {
    *this = *this / x;
    return *this;
  }
  Complex& Complex::operator/=(Natural x)
  {
    *this = *this / x;
    return *this;
  }
  Complex& Complex::operator/=(Integer x)
  {
    *this = *this / x;
    return *this;
  }
  Complex& Complex::operator/=(Real x)
  {
    *this = *this / x;
    return *this;
  }
  Complex& Complex::operator/=(Complex z)
  {
    *this = *this / z;
    return *this;
  }

  Complex& Complex::operator-=(Boolean x)
  {
    *this = *this - x;
    return *this;
  }
  Complex& Complex::operator-=(Natural x)
  {
    *this = *this - x;
    return *this;
  }
  Complex& Complex::operator-=(Integer x)
  {
    *this = *this - x;
    return *this;
  }
  Complex& Complex::operator-=(Real x)
  {
    *this = *this - x;
    return *this;
  }
  Complex& Complex::operator-=(Complex z)
  {
    *this = *this - z;
    return *this;
  }

  Complex& Complex::operator%=(Boolean x)
  {
    *this = *this % x;
    return *this;
  }
  Complex& Complex::operator%=(Natural x)
  {
    *this = *this % x;
    return *this;
  }
  Complex& Complex::operator%=(Integer x)
  {
    *this = *this % x;
    return *this;
  }
  Complex& Complex::operator%=(Real x)
  {
    *this = *this % x;
    return *this;
  }
  Complex& Complex::operator%=(Complex z)
  {
    *this = *this % z;
    return *this;
  }


  Boolean Complex::operator==(Boolean x) const
  {
    return (R == x) && (I == 0);
  }
  Boolean Complex::operator==(Natural x) const
  {
    return (R == x) && (I == 0);
  }
  Boolean Complex::operator==(Integer x) const
  {
    return (R == x) && (I == 0);
  }
  Boolean Complex::operator==(Real x) const
  {
    return (R == x) && (I == 0);
  }
  Boolean Complex::operator==(Complex z) const
  {
    return (R == z.R) && (I == z.I);
  }
  Boolean operator==(Boolean x, Complex z)
  {
    return (x == z.R) && (0 == z.I);
  }
  Boolean operator==(Natural x, Complex z)
  {
    return (x == z.R) && (0 == z.I);
  }
  Boolean operator==(Integer x, Complex z)
  {
    return (x == z.R) && (0 == z.I);
  }
  Boolean operator==(Real x, Complex z)
  {
    return (x == z.R) && (0 == z.I);
  }
  Boolean Complex::operator==(int x) const
  {
    return (I == 0) && (R == x);
  }

  Boolean Complex::operator!=(Boolean x) const
  {
    return (I != 0) || (R != x);
  }
  Boolean Complex::operator!=(Natural x) const
  {
    return (I != 0) || (R != x);
  }
  Boolean Complex::operator!=(Integer x) const
  {
    return (I != 0) || (R != x);
  }
  Boolean Complex::operator!=(Real x) const
  {
    return (I != 0) || (R != x);
  }
  Boolean Complex::operator!=(Complex z) const
  {
    return (I != z.I) || (R != z.R);
  }
  Boolean operator!=(Boolean x, Complex z)
  {
    return (0 != z.I) || (x != z.R);
  }
  Boolean operator!=(Natural x, Complex z)
  {
    return (0 != z.I) || (x != z.R);
  }
  Boolean operator!=(Integer x, Complex z)
  {
    return (0 != z.I) || (x != z.R);
  }
  Boolean operator!=(Real x, Complex z)
  {
    return (0 != z.I) || (x != z.R);
  }
  Boolean Complex::operator!=(int x) const
  {
    return (I != 0) || (R != x);
  }

  Complex Complex::conj() const
  {
    return Complex(R, -I);
  }

  std::string Complex::str() const
  {
    std::string Output = "";
    Real cR = R, cI = I;
    if (cR < 0)
    {
      Output += "-";
      cR *= -1;
    }

    Real PV = 10;
    while (PV <= cR)
      PV *= 10;

    while (PV > 1)
    {
      PV /= 10;
      Output += '0' + floor(cR / PV);
      cR = mod(cR, PV);
    }

    if (cR != 0)
      Output += '.';

    for (Natural i = 0; cR != 0 && i < 6; i++)
    {
      PV /= 10;
      Output += '0' + floor(cR / PV);
      cR = mod(cR, PV);
    }



    if (cI < 0)
    {
      Output += " - ";
      cI *= -1;
    }
    else
      Output += " + ";

    PV = 10;
    while (PV <= cI)
      PV *= 10;

    while (PV > 1)
    {
      PV /= 10;
      Output += '0' + floor(cI / PV);
      cI = mod(cI, PV);
    }

    if (cI != 0)
      Output += '.';

    for (Natural i = 0; cI != 0 && i < 6; i++)
    {
      PV /= 10;
      Output += '0' + floor(cI / PV);
      cI = mod(cI, PV);
    }

    Output += 'i';
    return Output;
  }

  std::ostream& operator<<(std::ostream& s, const Complex& z)
  {
    if (z.R && z.I > 0)
      s << z.R << " + " << z.I << "i";
    else if (z.R && z.I < 0)
      s << z.R << " - " << (-z.I) << "i";
    else if (z.R)
      s << z.R;
    else if (z.I == 0)
      s << "0";
    else
      s << z.I << "i";
    return s;
  }
  /*std::ostringstream& operator<<(std::ostringstream& s, const Complex& z)
  {
    if (z.R && z.I > 0)
      s << z.R << " + " << z.I << "i";
    else if (z.R && z.I < 0)
      s << z.R << " - " << (-z.I) << "i";
    else if (z.R)
      s << z.R;
    else if (z.I == 0)
      s << "0";
    else
      s << z.I << "i";
    return s;
  }*/
}


#endif
