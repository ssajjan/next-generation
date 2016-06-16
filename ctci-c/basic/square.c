Square of a number without using * or ^.

1   result = x/1/x


2	/**
     * Simple multiplication using bitwise operators.
     */
    public static int multiply(int a, int b) {
        int product = 0;

        while (a > 0) {
            if ((a & 1) != 0)
                product += b;
            b = b << 1;
            a = a >> 1;
        }
        return product;
    }


3

Some concepts to allow recusrsion:

n^2 = (n-1  + 1)^2  = (n-1)^2 + 1^2 + 2*(n-1)(1) = (n-1)^2 + n + n-1




int square(int n)
{
  if(n == 1 || n == 0) return n;
  if(n < 0) return square(-n);



return square(n-1)+n+(n-1);
}


4

for (int i=0 ;i<n; i++)
  square+=n;
