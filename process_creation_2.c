/*
 * Goals:
 * Parent process creates two child processes.
 * Each child processes runs "date --utc", and then exits.
 * Parent process waits for the child processes to complete and then exits.
 */