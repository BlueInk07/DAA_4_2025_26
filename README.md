Objective

To analyze a recursive algorithm by writing its recurrence relation, finding time complexity using the Master Theorem, and validating the results through implementation.

Theory

The recurrence relation of the given recursive function was derived in the form:
T(n) = aT(n/b) + f(n)

Using the Master Theorem, the asymptotic time complexity was calculated by comparing f(n) with n^(log_b a) and identifying the applicable case of the theorem.

Implementation

The given code was modified to:

Count the number of basic operations performed

Track the maximum depth of the recursion tree

Measure execution time in milliseconds using system time

Observation

The program was executed for different input sizes n.
For each input size, the number of operations, recursion depth, and execution time were printed.

Conclusion

The experimental results follow the theoretical time complexity obtained using the Master Theorem.
As input size increases, the operation count and execution time increase accordingly, validating the analysis.

Learning Outcome

Understanding recurrence relations

Applying the Master Theorem

Measuring recursion depth and execution time in practice
