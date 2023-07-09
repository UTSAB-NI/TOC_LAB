#include <stdio.h>
#include <string.h>

#define MAX_STATES 10

int transition[MAX_STATES][2][MAX_STATES]; // NFA transitions
int final_states[MAX_STATES]; // NFA final states

void add_transition(int state, int input, int next_state) {
    transition[state][input][next_state] = 1;
}

void add_final_state(int state) {
    final_states[state] = 1;
}

int is_final_state(int state) {
    return final_states[state];
}

int is_accepted(char *str) {
    int len = strlen(str);
    int current_states[MAX_STATES] = {0};
    int num_current_states = 1;
    current_states[0] = 0; // start state

    for (int i = 0; i < len; i++) {
        int next_states[MAX_STATES] = {0};
        int num_next_states = 0;
        int input = str[i] - '0'; // convert char to integer input

        for (int j = 0; j < num_current_states; j++) {
            int current_state = current_states[j];
            for (int k = 0; k < MAX_STATES; k++) {
                if (transition[current_state][input][k]) {
                    next_states[k] = 1;
                    num_next_states++;
                }
            }
        }

        for (int j = 0; j < MAX_STATES; j++) {
            if (next_states[j]) {
                current_states[num_current_states] = j;
                num_current_states++;
            }
        }

        // If there are no next states, the string is not accepted
        if (num_next_states == 0) {
            return 0;
        }
    }

    // Check if any of the current states are final states
    for (int i = 0; i < num_current_states; i++) {
        if (is_final_state(current_states[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Define NFA transitions and final states
    add_transition(0, 0, 0);
    add_transition(0, 1, 0);
    add_transition(0, 1, 1);
    add_transition(1, 0, 2);
    add_transition(1, 1, 0);
    add_transition(2, 0, 2);
    add_transition(2, 1, 2);
    add_final_state(2);

    // Test the NFA with some example strings
    printf("%d\n", is_accepted("010")); // expected output: 1 (accepted)
    printf("%d\n", is_accepted("110")); // expected output: 0 (not accepted)
    printf("%d\n", is_accepted("0110")); // expected output: 1 (accepted)

    return 0;
}

