args of said program :

-number_of_philosophers

-time_to_die

-time_to_eat

-time_to_sleep

-(number_of_times_each_philosophers_must_eat)


Each philosopher is represented as a *thread*.

Each philosopher is assigned a *fork* (if 1 philosopher, 1 fork, if > 1 then each philo has a fork to the left and right).

To prevent duplication of *forks* we must use *mutex*.


Rules :

Each philosopher is either **eating**, **thinking** or **sleeping**.

Each philosopher takes **2 forks** to eat (no 2 neighboors can eat simultaneously).

Once a philosopher is done **eating**, he **sleeps**. (forks are back on the table).

Once awakened, he starts to **think**.


--------------------------------------------------------------------------------------------------------------------------

Each philosopher needs to eat (**can't die of hunger**)

Each state change of a philosopher is formatted as a timestamp (in ms).

10 ms max between the death of a philosopher and the timestamp message print.


--------------------------------------------------------------------------------------------------------------------------

Tips :

https://www.youtube.com/watch?v=FY9livorrJI&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=3
https://en.wikipedia.org/wiki/Dining_philosophers_problem
https://cdn.intra.42.fr/pdf/pdf/41344/fr.subject.pdf

--------------------------------------------------------------------------------------------------------------------------

#include <pthread.h>

add -pthread flag to GCC

eg ```gcc -pthread -Wall -Werror```

pthread_create(reference to the thread(&thread), attribute (NULL), routine function pointer (&routine), argument (NULL))

pthread_join(thread, pointer to the result of that thread(NULL)) is the function that wait for the thread to finish it's work (is basically a "wait" function like with processes)

Threads are a segment of a process, it means many threads can run in a process.

All threads share the same set of variables and addresses.

**Race conditions** will happen without mutex (pthread_mutex_init/pthread_mutex_lock/pthread_mutex_unlock/pthread_mutex_destroy). In a multithreaded context, without mutex, all threads can start and wait at a random time. Mutex protects a thread against other threads executing at the same time.
