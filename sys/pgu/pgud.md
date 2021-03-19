20210313 p216-232
## optimization = speed + space
1. Optimization is the process of making your application run more effectively.
2. You can optimize for many things - speed, memory space usage, disk space usage.
3.  It is better to not optimize at all than to optimize too soon.

## When to optimize
1. Optimization is not necessary during early development for the following reasons
2. Therefore, the time to optimize is toward the end of development.
3. By focusing on the correct order, I was able to finish a project that was both correct and efficient.

## Where to optimize
There are two main categories of optimization - local optimizations and global optimizations

## Local Optimizations
1. Precomputing Calculations
2. Remembering Calculation Results
3. Locality of Reference
You bundle as many operations on data that is physically close to each other in memory.
4. Register Usage
5. Inline Functions
6. Optimized Instructions
7. Addressing Modes, using indirect address instead of base pointer addressing.
8. Data Alignment

using indirect addressing mode instead of base pointer addressing mode:
```
int *pint = int_arr;
pint++; // indirect addressing mode
int_arr[i]; // base pointer addressing mode
```

## Global Optimization
1. The more stateless parts of your program you have, the more opportunities you have to optimize.
2. Two great benefits resulting from statelessness is that
most stateless functions are parallelizable and often benefit from memoization.

## function properities to global optimization
1. Parallelization
2. Statelessness

## Ends
1. Different people like different approaches, but a good programmer takes all of them into account.
