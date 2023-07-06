# Dining Philosophers Problem
This project presents a solution to the Dining Philosophers problem using multi-threading. The Dining Philosophers problem is a classic synchronization problem in computer science that demonstrates challenges related to resource allocation and deadlock avoidance.

<div id="header" align="center">
  <img src="https://4.bp.blogspot.com/-QjBnBxGbH38/UuyeUvi4_kI/AAAAAAAAR9s/sSJHU3WvwNQ/s1600/Dining-Philosophers-Problem.jpg"/>
</div>


## Problem Description

The Dining Philosophers problem involves a group of philosophers sitting around a circular table with bowls of rice and chopsticks. Each philosopher spends their time thinking and eating, but they require two chopsticks to eat. The chopsticks are shared resources between adjacent philosophers.

The challenge lies in developing a solution that ensures the philosophers can access the chopsticks without encountering deadlocks (where multiple philosophers hold one chopstick each, preventing any of them from eating) or starvation (where a philosopher is indefinitely denied access to the chopsticks).

## Implementation

The solution to the Dining Philosophers problem is implemented using the following code snippets:

### Initializing Philosophers and Resources

The `init_philos` function initializes the philosophers' data structure:

```c
int init_philos(t_data *data) {
    // Initialize each philosopher with their respective properties
    // such as ID, number of times eaten, left and right forks, etc.
    // ...
    return true;
}
```

The `init_mutex` function initializes the mutexes required for resource synchronization:

```c
int init_mutex(t_data *data) {
    // Initialize the mutexes for forks and other shared resources
    // using the pthread_mutex_init function
    // ...
    return true;
}
```
The `parse_all` function parses the program arguments and initializes the data structure:

```c
int parse_all(t_data *data, char **av) {
    // Parse the program arguments and fill the data structure with the provided values
    // Initialize the mutexes and philosophers' data
    // ...
    return true;
}
```

### Philosopher Actions
The `philo_eats` function represents a philosopher's eating behavior:

```c
void philo_eats(t_philos *philo) {
    // Acquire the necessary forks (mutexes) for eating
    // Log that the philosopher has taken the forks
    // ...
    // Perform eating actions and track the number of times eaten
    // ...
    // Release the acquired forks (mutexes) when done eating
    // ...
}
```
The `routine` function is the main routine executed by each philosopher thread:

```c
void *routine(void *void_philo) {
    // Perform the sequence of actions for a philosopher
    // including eating, sleeping, and thinking
    // ...
    return NULL;
}
```

### Synchronization and Termination
The `dead_check` function checks for a philosopher's death due to starvation:

```c
void dead_check(t_data *data, t_philos *philo) {
    // Continuously monitor each philosopher's last meal time
    // and check if it exceeds the time_to_die threshold
    // ...
}
```
The `init_routine` function initializes the philosopher threads and checks for termination conditions:

```c
int init_routine(t_data *data) {
    // Create philosopher threads and start their routines
    // Monitor termination conditions such as all philosophers eating enough or a philosopher's death
    // ...
    return true;
}
```

### Utility Functions
Several utility functions are used to handle time, sleeping, and logging:

- `ft_atoi`: A function to convert a string to an integer.
- `timestamp`: A function to get the current timestamp in milliseconds.
- `m_time`: A function to calculate the time difference between two timestamps.
- `s_sleep`: A function to sleep for a specified amount of time.

### Usage
To compile and run the Dining Philosophers program, follow these steps:

1. Clone the repository or download the source code.
2. Compile the program using the appropriate compiler command. For example:
```bash
gcc -pthread main.c -o dining_philosophers
Run the program with the desired arguments. For example:
./dining_philosophers 5 200 100 100
```
This command runs the program with 5 philosophers, a time-to-die of 200 milliseconds, a time-to-eat of 100 milliseconds, and a time-to-sleep of 100 milliseconds.

### Conclusion
The Dining Philosophers problem is a classic synchronization challenge that tests your understanding of multi-threading and resource management. This project provides an implementation of the problem using mutexes and threads in C.

By carefully coordinating the acquisition and release of resources, the implemented solution ensures that the philosophers can eat without deadlocks or starvation.
<br/>

### Resources
https://www.youtube.com/watch?v=FY9livorrJI&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=3
https://en.wikipedia.org/wiki/Dining_philosophers_problem
https://cdn.intra.42.fr/pdf/pdf/41344/fr.subject.pdf

