#include <iostream>
using namespace std;


//              BASIC MATHS CONCEPTS
/*
            1. Digit Concept (very important topic)

        N = 7789, extract all the digits(i.e we need 7, 7, 8, 9 these digits separatly)
    sol- 1. by doing 7789 % 10 = 9 (we will get 9 as remainder) // our first nmbr

         2. 7789 / 10 = 778.9
            int of 778.9 = 778  // int a = 778.9; cout << a;
            778 % 10 = 8        // our second nmbr

         3. 778 / 10 = 77.8
            int of 77.8 = 77
            77 % 10 = 7         // our third nmbr

         4. 77 / 10 = 7.7
            int of 7.7 = 7
            7 % 10 = 7          // our forth nmbr

    pseudo code for above steps
    N - user input

    while(N > 10)
    {
    lastdigit = N % 10;
    print (lastdigit);
    N = N / 10;
    }
    // after this loop we will get the digits in reverse order


               2. Count Digits

            find the number of digits present in the given number 'N'
        sol- lets take the nmbr N = 7789 from last example
             we will do the same process, now the pseudo code

        Pseudo code for this example
        N - user input

        count = 0;
        while(N > 10)
        {
        lastdigit = N % 10'
        count = count + 1;
        N = N / 10;
        }
        print (count);

        Actual code (on online coding tool) -
        int count(int n) {
            int cnt = 0;
            while(n > 0)
            {
                int lastDigit = n % 10;
                cnt = cnt + 1;
                n = n / 10;
            }
            return cnt;
        }

    Time Complexity here is - O(log (N))    // <- log base 10


                3. Reverse a number

            WAP to generate the reverse of a given nmbr N.
            Note- if a nmbr has trailing Zeroes. Then its Reverse willnot include them.
                  for ex- reverse of 10400 is 401 instead of 00401
        sol- we already know from Digits Count that 
                7789 gets print as -> 9 8 7 7
             by above we can say that if we have a variable 'reversenmbr'
                reversenmbr = (reversenmbr * 10) + lastdigit;

             initially we will declare reversenmbr as '0', then
         1. by doing 7789 % 10 = 9 
            reversenmbr = (0 * 10) + 9;
            reversenmbr = 9;

         2. 7789 / 10 = 778.9
            int of 778.9 = 778
            778 % 10 = 8
            reversenmbr = (9 * 10) + 8;
            reversenmbr = 98;

         3. 778 / 10 = 77.8
            int of 77.8 = 77
            77 % 10 = 7
            reversenmbr = (98 * 10) + 7;
            reversenmbr = 987;

         4. 77 / 10 = 7.7
            int of 7.7 = 7
            7 % 10 = 7
            reversenmbr = (987 * 10) + 7;
            reversenmbr = 9877;

         Pseudo code for above steps
    N - user input

    while(N > 10)
    {
    lastdigit = N % 10;
    print (lastdigit);
    N = N / 10;
    reversenmbr = (reversenmbr * 10) + lastdigit;
    }

    Actual Code
    int main()
    {
        int n;
        cin >> n;
        int revNum = 0;
        while(n > 0)
        {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
        }
        cout << revNum;
    }



                4. Palindrome

            WAP to determine if given nmbr is palindrome or not.
        sol- as the 3.Reverse a number

    Actual Code
    int main()
    {
        int n;
        cin >> n;
        int revNum = 0;
        int dup = n;        // bcz at the end of the loop n becomes '0' and we will not be comapring '0'(n) with palindrome
        while(n > 0)
        {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
        }
        if(dup == revNum)
            cout << "true";
        else
            cout << "false";
    }



                    5. Armstrong Number

                Armstrong Nmbr - digits raised to the power count of digits
                                 exa- 177 => 1^3 + 7^3 + 7^3,  (we have to check they are equal or not)
                                      35 => 3^2 + 5^2,  (we have to check they are equal or not)
                                      1234 => 1^4 + 2^4 + 3^4 + 4^4,  (we have to check they are equal or not)
            
            sol - we are going to extract particular digits how we did in 1.Digits Count

    Actual Code
        int n;
        int dup1 = n;
        int cnt = 0;
        while(n > 0)
        {
            int lastDigit = n % 10;
            cnt = cnt + 1;
            n = n / 10;
        }
        return cnt;

    int dup2 = dup1;
    int sum = 0;

    while(dup1 > 0)
    {
        int lastD = dup1 % 10;
        sum = sum + pow(lastDigit, cnt);
        dup1 = dup1 / 10;
    }
    cout << "sum: " << sum;
    
    if(sum == dup2)
        cout << "Armstrong nmbr";
    else
        cout << "not armstrong nmbr";



                6. Print all Divisors

            WAP toprint all the divisors of a given nmbr
        sol - we can say all the divisors of any given nmbr are always less than that nmbr
              
    Actual Code
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            cout << i << " ";
    }
    Time Complexity of above code is -> O(N)
    
    if we want a leeser time complexity then there's another method 
    int n;
    cin >> n;

    vector<int> ls;         // we are using 'list' STL
    // O(sqrt(n))
    for(int i = 1; i = sqrt(n); i++)        // we can also write 'i = sqrt(n)' as 'i * i = n'
    {
        if(n % i == 0)
        {
            ls.push_back(i);
            if((n / i) != 1)
                ls.push_back(n / i);
        }
    }
    // O(nmbr of factors * log(nmbr of factors)),  n is the nmbr of factors
    sort(ls.begin(), ls.end());
    // O(nmbr of factors)
    for(auto it : ls)               
        cout << it << " ":

    // New Time Complexity is the addition of all the time complexity in this new method



                    7. Prime Nmbr


            sol- A prime nmbr has exact 2 factors '1' and 'itself'

    Pseudo code
    cnt = 0;

    for(i = 1; i <= N; i++)
    {
        if(N % i == 0)
            cnt++;
    }
    if (cnt == 2)
        print(prime)
    else
        not prime

    Time Complexity - O(N)

    the other method with O(sqrt(n))
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i * i = n; i++)
    {
        if(n % i == 0)
        {
            cnt++;
            if((n / i) != 1)
                cnt++;
        }
    }
    if(cnt == 2)
        cout << "Prime";
    else
        cout << "not prime";



                    8. GDC and HCF
                    Greatest Common Divisor and Highest Common Factor

            sol- we can say that to get GDC(LCM) of two nmbrs(N1, N2), we can
                 loop 'i' from '1' to N1/N2 and in each iteration check if the
                 nmbr divides both N1 and N2. The consecutive nmbr which divides
                 both of them will replace the GDC(initially GDC will be '1' and 
                 after getting replaced it will be largest nmbr at the end).

    Pseudo Code
    gcd = 1;

    for(int i = 1; i <= N1; i++)        // if N1 is larger than N2, then we should write this line as below
    for(int i = 1; i <= min(N1, N2); i++)
        {
        if(N1 % i == 0 && N2 % i == 0)
            gcd = i;                    // last nmbr which gets stored in gcd will be the largest bcz 'i' is increasing
        }
    Time Complexity - O(min(N1, N2))


    Another method
    for(i = min(N1, N2); i >= 1; i--)       // if N1= 20 and N2= 40, then min = 20 
        {
        if(N1 % i == 0 && N2 % i == 0)      // 20 % 20 == 0 && 40 % 20 == 0, both conditions are true
            {
            print(gcd = i);                 // then gcd will be '20', from above comments
            break;                          // and the program gets terminated
            }
        }
    Time Complexity - O(min(N1, N2))



                    Euclidean Algorithm
                        for solving GCD

            sol- this algo says(int terms of equation)_
                    
                    gcd(N1, N2) = gcd(N1 - N2, N2)      // where 'N1 > N2'
                    gcd(a, b)   = gcd(a - b, b)         // where 'a > b'

                exa- gcd(20, 15) = gcd(5, 15)       // we can apply Euclidean algo to this equation as well
                     gcd(15, 5)  = gcd(10, 5)       // again applying
                     gcd(10, 5)  = gcd(5, 5)        // again applying
                     gcd(5, 5)   = gcd(0, 1)        // the moment one of the nmbr become '0', the other nmbr will be the 'gcd'
                     gcd = 5

                 from above example we can say that like the nmbrs (52, 10), it will take 
                 alot of steps to get to the gcd.
                 by simplifying the Euclidean Algorithm, we get

                 gcd(a, b) = gcd(a % b, b)      // where a > b
                    greater % smaller  --> when we get one of them as '0', the other is 'gcd'

    Pseudo Code                 // solve 52, 10 by this code
    while(a > 0 && b > 0)
    {
        if(a > b)
            a = a % b;
        else
            b = b % a;
    }
    if(a == 0)
        print(b);
    else
        print(a);

    Time Complexity - O(log of phi(min(a, b)))      // phi - Φ
                                                    // whenever there is division happening Time Complexity will always be in terms of "log"
                                                    // in this code bcz swaping of a and b is happening, the base is  'Φ', not the other

    Actual Code
    int gcd(int a, int b)
    {
        while(a > 0 && b > 0)
        {
            if(a > b)
                a = a % b;
            else
                b = b % a;
        }
        if(a == 0)
            return b;
        else
            return a;
    }
*/

int main()
{
    cout << "Hello World!\n";
}