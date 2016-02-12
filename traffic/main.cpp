#include "SolveAndExplain.h"

void solve_and_explain(int puzzle_number) {
    SolveAndExplain solve_and_explain(puzzle_number);
    solve_and_explain.go();
}

int main() {
    int puzzles[] = {-1, 1, 2, 38, 39, 40};
    for (int puzzle_number : puzzles) {
        solve_and_explain(puzzle_number);
    }
    return 0;
}