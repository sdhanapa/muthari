 POSIX THREAD Basics:

 Thread is a basic unit of execution flow.
 Process has atleast one thread.(main thread)
 A thread can create another thread, called chiled thread, this new thread can create another thread and so on.
 The point where the new thread is created from main thread is called fork point.

       #include <pthread.h>
       int pthread_create(pthread_t *restrict thread,
                          const pthread_attr_t *restrict attr,
                          typeof(void *(void *)) *start_routine,
                          void *restrict arg);

       The pthread_create() function starts a new thread starts by invoking
       start_routine(); arg is passed as the sole argument of
       start_routine().

       The attr argument points to a pthread_attr_t structure whose
       contents are used at thread creation time to determine attributes
       for the new thread; such as setting their stack size, scheduling policy, detach state, and more.
       
           $ ulimit -s       # No stack limit ==> default stack size is 2 MB
           unlimited
           $ ./a.out
           Thread attributes:
                   Detach state        = PTHREAD_CREATE_JOINABLE
                   Scope               = PTHREAD_SCOPE_SYSTEM
                   Inherit scheduler   = PTHREAD_INHERIT_SCHED
                   Scheduling policy   = SCHED_OTHER
                   Scheduling priority = 0
                   Guard size          = 4096 bytes
                   Stack address       = 0x40196000
                   Stack size          = 0x201000 bytes

       On success, pthread_create() returns 0; on error, it returns an
       error number, and the contents of *thread are undefined.
------------------------
Modes of thread creation :

2 Modes:

Joinable and Detached Thread.

Joinable thread:
1) point at where the pthread_create is invoked, its called Fork point. And Child thread is created.
2) By default child thread is a Joinable thread.
3) point at where the pthread_join is invoked, its called Join point. Until the child thread join the parent thread after its exit, child thread resources are not released. Only after the joining of child thread to the parent thread, the child  thread's resouces are released.

4) Joinable thread can be converted into detached thread, while its running and vise-versa.
5) Joinable thread returns the result from child thread.
6) ** Any thread of same process can invoke pthread_join() for any joinable thread. that is, child thread can send exit/ done /termionation signal to both grandchild thread or to parent thread.

int pthread_join(pthread_t thread, void **retval);

       On success, pthread_join() returns 0; on error, it returns an
       error number.

    The pthread_join() function is used to wait for a thread to terminate 
    and clean up resources associated with it. It allows the calling thread 
    to block until the specified thread has finished executing. This is 
    essential when dealing with multiple threads, as it ensures that the 
    program doesn’t exit prematurely and that all threads complete their 
    work before the program terminates.

    retval is a pointer to a location where the exit status of the thread will be stored. 
    If you don't need the exit status, you can pass NULL here.

usecase: reducer mapper,

Here, parent thread is called reducer and all its child joinable threads are called mappers, these mappers can work on defined chunk or independent data and then joins the reducer(parent thread). example reading a larger file by deviding the files into chunk and asking child thread to read. 


Detached Threads:

1) Resouces of the detached child thread are released as soon as the child thread exits.
2) Detached thread can be converted into attached thread and vice versa.
3) Detached thread do not return any return to joining thread.


int pthread_detach(pthread_t thread);

       On success, pthread_detach() returns 0; on error, it returns an
       error number.

       The pthread_detach() function marks the thread identified by
       thread as detached.  When a detached thread terminates, its
       resources are automatically released back to the system without
       the need for another thread to join with the terminated thread.

       Attempting to detach an already detached thread results in
       unspecified behavior.


Usecase: Example:

TCP server thread interacting with TCP client thread, where no return is expected.

---------------------------
Race condition in Muti threading condition.

In mutithreading scenario, we cannot say, either main thread or new thread is going to excute first. this is based on scheduling of the os.
this situation is called "race condition".

------------------------
Thread Memory Management

1) Process has following memory segments.

P-STACK[Local varial and function arguments]
.
.
HEAP [Dynamic memory]
DATA(BSS Unitialized and Initialized data)[Global and Static]
CODE[Instruction]

2)  When the process creates the new thread, the new thread T1 has all the access to the main thread or process except STACK segement, since each thread has its own stack.
--------------------

Thread termination

1) thread returns
2) pthread exit()
3) thread cancellation

-----------------------

Thread Scheduling:

Scheduling is the process of allocating CPU to the thread according to scheduling Policy, such as FIFO, Shortest- Job-First etc..

1) Kernel(OS) schedules ONLY threads of multiple process, but not the process.
   1.1) If single thread makes any mistake such as SEGFAULT, then the own process will be terminates by the Kernel.

2) Term "Race" condition occurs, due to the fact that which thread kernel assignes to the CPU for the processing.

Note: Similarly SIGNAL is sent to the process not to the threads.

----------------

Interthread Communication:

1) Thread Communication is nothing but the exchange of data between threads.
2) Following IPC terchniques can ber used to ITC also, but its not recommented.
3) Instead, "callback function or function pointer" is preffered.Because of following reason,
       a) very fast,
       b) it not transfer of actual data, its tranfer of computation.
       c) completely run in user spcae, hence no kernel resources are explicitly created.
--------------


Mutex
1) Mutex are prefered for thread of different process sharing the resource.


POSIX data types :
pthread_mutex_t  is a opaque data type meaning, its internal implemention is hidden from the programmer. it is used to define the types of the Mutex.


        Macro	                                    Description
MUTEX TYPES defining macros:        
PTHREAD_MUTEX_NORMAL_INITIALIZER	       Statically initializes a normal mutex (alternative).
PTHREAD_MUTEX_ERRORCHECK_INITIALIZER	Statically initializes an error-checking mutex.
PTHREAD_MUTEX_RECURSIVE_INITIALIZER	Statically initializes a recursive mutex.
PTHREAD_MUTEX_INITIALIZER	              Statically initializes a normal mutex (configures mutex to default without needing to call pthread_mutex_init()).
NULL                                      Dynamic Mutex Initialization

MUTEX Robustness defining macros:
PTHREAD_MUTEX_STALLED                     Default behavior for mutex robustness.
PTHREAD_MUTEX_ROBUST                      Mutex that can recover from owner thread termination.

Process-Shared:
PTHREAD_PROCESS_PRIVATE                   Mutex is shared only within the same process (default).
PTHREAD_PROCESS_SHARED                    Mutex can be shared across multiple processes.

Mutex Protocol:
PTHREAD_PRIO_NONE                         No specific protocol (default).
PTHREAD_PRIO_INHERIT                      Priority inheritance protocol to handle priority inversion.
PTHREAD_PRIO_PROTECT                      Priority ceiling protocol to handle priority inversion.

MUTES API's:


      ┌────────────┬────────────┬────────────────┬───────────────────────┐
      │ Mutex Type │ Robustness │     Relock     │ Unlock When Not Owner │
      ├────────────┼────────────┼────────────────┼───────────────────────┤
      │ NORMAL     │ non-robust │ deadlock       │ undefined behavior    │
      ├────────────┼────────────┼────────────────┼───────────────────────┤
      │ NORMAL     │ robust     │ deadlock       │ error returned        │
      ├────────────┼────────────┼────────────────┼───────────────────────┤
      │ ERRORCHECK │ either     │ error returned │ error returned        │
      ├────────────┼────────────┼────────────────┼───────────────────────┤
      │ RECURSIVE  │ either     │ recursive      │ error returned        │
      ├────────────┼────────────┼────────────────┼───────────────────────┤
      │ DEFAULT    │ non-robust │ undefined      │ undefined behavior†   │
      │            │            │ behavior†      │                       │
      ├────────────┼────────────┼────────────────┼───────────────────────┤
      │ DEFAULT    │ robust     │ undefined      │ error returned        │
      │            │            │ behavior†      │                       │
      └────────────┴────────────┴────────────────┴───────────────────────┘

      NORMAL Mutex: Does not perform any error check.
      Robust is the ability of the mutex to handle crash or termination of the thread.

      ERRORCHECK Mutex: performs error checking, if the thread attempt to reloack mutex 
      it already owns or if the thread tries to unlock the thread it does not own it gives an ERROR.

      Recursive Mutex are used by thread, when it calls the recursive function.

These API's are used to Initialize, lock,unlock and destroy the mutex and also configure their behaviour using attributes.      

       pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

       int pthread_mutex_init(pthread_mutex_t *restrict mutex,const pthread_mutexattr_t *restrict attr);
       int pthread_mutex_destroy(pthread_mutex_t *mutex);   \

       int pthread_mutex_lock(pthread_mutex_t *mutex);    ----> Blocks and waits until the mutex is available.
       int pthread_mutex_trylock(pthread_mutex_t *mutex); ----> Non-blocking, tries to lock the mutex without waiting
       int pthread_mutex_timedlock(pthread_mutex_t *restrict mutex,const struct timespec *restrict abstime);  ----> Waits for the mutex for a specific amount of time, then either locks it or times out.

       int pthread_mutex_unlock(pthread_mutex_t *mutex);
       int pthread_mutexattr_init(pthread_mutexattr_t *attr);
       int pthread_mutexattr_destroy(pthread_mutexattr_t *attr); 
       int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type);
       int pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict attr,int *restrict type);
       int pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr,int *restrict pshared);
       int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr,int pshared);    
       int pthread_mutex_consistent(pthread_mutex_t *mutex);
