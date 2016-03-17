# wtpc2016: dia 5: Profiling


## Profiling tools

### time

### gprof: -pg flag, the profiling file is generated after running the compiled program and running the code.
    ```
    $ gcc *.c -pg -o *.e
    $ gprof *.e *.out > *.info
    $ ls -tr
    ```
### otras???

#### Algun tic toc?

#### internal_profiling.txt


### perf
    ```
    $ perf stat *.e
    $ perf record *.e
    $ perf report -i *.info
    ```



## Optimization flags:

### -O0
    Sin ninguna optimizacion
### -O1

### -O3

## **GRAFICAR?**

## Casos


### profile_me_1
#### -o0
    
    ```Violación de segmento (`core' generado)```
    Soluciones:
        Achicar el problema (Modifica el problema en si)
        Agrandar el tamaño de stack memory (ulimit -s unlimited)

    1. time
      real	0m2.078s
      user	0m1.801s
      sys	0m0.276s

    2. gproof
    Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ns/call  ns/call  name    
   74.26      1.56     1.56 25000000    62.38    62.38  first_assign
   19.64      1.97     0.41                             main
    6.71      2.11     0.14 25000000     5.63     5.63  second_assign
    
    3. perf
    tast clock: 1964ms
    
    
#### -o2
    1. time
        real	0m0.002s
        user	0m0.000s
        sys	0m0.002s
        
    2. gproof
          No time acumalated:
          El programa corre demasiado rapido.
    
    3. perf: 0.0016 seconds


### profile_me_2
