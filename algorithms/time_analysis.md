# Series formula
## Geometric series
a + ar + ar^2 + ar^3 + ... + ar^n = a(1-r^(n+1))/(1 - r)
## Infinite geometric series with r < 1. (Used to derive upper bound for geo series)
a + ar + ... = a/(1-r)

# Upperbound proof method
In order to prove T(n) = O(g(n)). Prove that there $\exists$ c > 0,n<sub>0</sub> > 0 s.t T(n) <= cg(n) for all n >= n<sub>0</sub>

E.g: T(n) = nlog(n) <=> there $\exists$ c > 0 ,n<sub>0</sub> > 0 s.t T(n) <= cnlog(n) for all n >= n<sub>0</sub>

## Methods for recurrence relation
### Substitution method
```
Given:
    T(1) = 1
    T(n) = 2T(n/2) + n
Prove:
    T(n) = O(nlogn)
    or there exists c > 0, n0 > 0 s.t 
        T(n) <= cnlog(n)  (1)
        for all n >= n0
```
Proof:

T(1) = 1 > clog1 = 0. Which doesn't hold for (1).
But since we're only required to prove that the condition T(n) <= cnlog(n) is true for all n >= n<sub>0</sub>, 
we can choose a different base case.

We see that T(2) = 4 and T(3) = 5. If we choose c >= 2. Both T(2) and T(3) holds for our condition.
Choosing them to be the base case for our inductive proof is sufficient because all n > 3 will resolve
to one of this two cases.

Now we prove that if (1) hold for n=n/2 then it will hold for n=n.
Assume it holds for n=n/2. It means 
```
T(n/2) <= (cn/2)log(n/2)
```
Plug into T(n), we get: 
```
T(n) <= 2(cn/2)log(n/2) + n = cnlog(n) - cn + n <= cnlog(n) for any c >= 1 because n 
is always >= 0 (It doesn't make sense for a function to have negative input size)
```