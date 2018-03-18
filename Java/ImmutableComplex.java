/*
Rule 17. Minimizie Mutability

To make a class immutable:
- Don't provide methods that modify the objects state
- Ensure the class can't be extended
- Make all fields final
- Make all fields private
- Ensure exclusive access to any mutable components.
*/

public final class ImmutableComplex {
  private final double re;
  private final double im;

  public ImmutableComplex(double re, double im) {
    this.re = re;
    this.im = im;
  }

  public double realPart(){return re;}
  public double imaginaryPart(){return im;}

  public ImmutableComplex plus(ImmutableComplex c) {
    return new ImmutableComplex(re + c.re, im + c.im);
  }

  // ... rest of API (minus, times, divided)

  @Override
  public boolean equals(Object o) {
    if (o == this) return true;
    if (!(o instanceof ImmutableComplex)) return false;
    ImmutableComplex c = (ImmutableComplex) o;
    return Double.compare(c.re, re) == 0 && Double.compare(c.im, im) == 0;
  }

  @Override
  public int hashCode() {
    return 31 * Double.hashCode(re) + Double.hashCode(im);
  }

  @Override 
  public String toString() {
    return "(" + re +  " + " + im + "i)";
  }
}