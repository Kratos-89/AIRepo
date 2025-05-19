% Initial state: both jugs are empty
initial_state((0,0)).

% Goal state: Jug A has 2 liters
goal_state((2,_)).

% Rules (Transitions)

% Fill Jug A
move((A,B), (4,B), 'Fill A') :- A < 4.

% Fill Jug B
move((A,B), (A,3), 'Fill B') :- B < 3.

% Empty Jug A
move((A,B), (0,B), 'Empty A') :- A > 0.

% Empty Jug B
move((A,B), (A,0), 'Empty B') :- B > 0.

% Pour A -> B
move((A,B), (A1,B1), 'Pour A to B') :-
    A > 0,
    B < 3,
    Total is A + B,
    (Total =< 3 -> A1 is 0, B1 is Total; A1 is Total - 3, B1 is 3).

% Pour B -> A
move((A,B), (A1,B1), 'Pour B to A') :-
    B > 0,
    A < 4,
    Total is A + B,
    (Total =< 4 -> A1 is Total, B1 is 0; A1 is 4, B1 is Total - 4).

% Path finding logic using DFS

solve :-
    initial_state(Start),
    goal_state(Goal),
    dfs(Start, Goal, [Start], Moves),
    print_moves(Moves).

dfs(State, State, _, []).
dfs(State, Goal, Visited, [Action|Moves]) :-
    move(State, NextState, Action),
    \+ member(NextState, Visited),
    dfs(NextState, Goal, [NextState|Visited], Moves).

% Helper to print the solution
print_moves([]).
print_moves([Move|Rest]) :-
    write(Move), nl,
    print_moves(Rest).