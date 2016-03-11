# wtpc2016: dia 4: Debug: Respuestas a los Segmentation Fault
Se define como violacion de acceso (violacion del segmento o access violation y segmentation fault en Inglés) al intento fallido de acceso a información o a programas a los que no se tiene autorización para ver o modificar.

## FALTA GENERAR EL CORE-FILE del bug
```
(gdb) generate-core-file
aviso: Memory read failed for corefile section, 8192 bytes at 0x7ffff7ffa000.
Saved corefile core.20268
```
```
El núcleo se generó por «/mnt/4BB44C493029E314/Doctorado2015/YTEC/Cursos Capacitacion/wtpc2016/dia4/HOdeb».
Program terminated with signal SIGSEGV, Segmentation fault.
#0  0x00000000004005c8 in mat_Tmat_mul (A=<error de lectura de variable: No se puede acceder a la memoria en la dirección 0x7ffffe826498>,
    C=<error de lectura de variable: No se puede acceder a la memoria en la dirección 0x7ffffe826490>) at source.c:36
```

## C
```
$ ./big.x
Violación de segmento (`core' generado)
```
```
$ gdb ./big.x
$ run
Program received signal SIGSEGV, Segmentation fault.
0x00000000004005c8 in mat_Tmat_mul (A=<error de lectura de variable: No se puede acceder a la memoria en la dirección 0x7ffffe826498>,
```

Ahora utilizamos ```ulimit -s unlimited```: ulimit permite modificar los soft limites (stack size) por defecto.

    1. ¿Devuelven el mismo error que antes?
        No, al cambiar el stack size desde 8192kb a unlmiited (BUSCAR STACK SIZE) el kernel?? puede asignar suficiente memoria a la subrutina.
    2. Averigüen qué hicieron al ejecutar la sentencia `ulimit -s unlimited`. Algunas pistas son: abran otra terminal distinta y fíjense si vuelve al mismo error, fíjense la diferencia entre `ulimit -a` antes y después de ejecutar `ulimit -s unlimited`, googleen, etcétera
        GOOGLE:
    3. La "solución" anterior, ¿es una solución en el sentido de debugging?
        No, ya que es una solución particular para este problema, y (supongo) que definir siempre el stack size unlimited puede llevar a problemas de uso de memoria.



## Fortran


## ulimit

```
NAME
       ulimit - get and set user limits

SYNOPSIS
       #include <ulimit.h>

       long ulimit(int cmd, long newlimit);

DESCRIPTION
       Warning: This routine is obsolete.  Use getrlimit(2), setrlimit(2), and sysconf(3) instead.  For the shell command ulimit(), see bash(1).

       The ulimit() call will get or set some limit for the calling process.  The cmd argument can have one of the following values.

       UL_GETFSIZE
              Return the limit on the size of a file, in units of 512 bytes.

       UL_SETFSIZE
              Set the limit on the size of a file.

       3      (Not implemented for Linux.)  Return the maximum possible address of the data segment.

       4      (Implemented but no symbolic constant provided.)  Return the maximum number of files that the calling process can open.

RETURN VALUE
       On success, ulimit() returns a nonnegative value.  On error, -1 is returned, and errno is set appropriately.

ERRORS
       EPERM  A unprivileged process tried to increase a limit.

CONFORMING TO
       SVr4, POSIX.1-2001.  POSIX.1-2008 marks ulimit() as obsolete.

SEE ALSO
       bash(1), getrlimit(2), setrlimit(2), sysconf(3)

COLOPHON
       This  page  is part of release 3.54 of the Linux man-pages project.  A description of the project, and information about reporting bugs, can
       be found at http://www.kernel.org/doc/man-pages/.

```

**Fuente**: http://ss64.com/bash/ulimit.html
ulimit provides control over the resources available to the shell and to processes started by it, on systems that allow such control.

The soft limit is the value that the kernel enforces for the corresponding resource. The hard limit acts as a ceiling for the soft limit.

An unprivileged process may only set its soft limit to a value in the range from 0 up to the hard limit, and (irreversibly) lower its hard limit. A privileged process can make arbitrary changes to either limit value.
