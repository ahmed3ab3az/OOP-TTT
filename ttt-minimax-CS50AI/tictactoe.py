"""
Tic Tac Toe Player
"""
import copy
import math

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    Xcnt = sum(row.count(X) for row in board)
    Ocnt = sum(row.count(O) for row in board)

    if Xcnt <= Ocnt:
        return X
    else:
        return O



def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    PossibleMoves = set()
    for rowIndex , row in enumerate(board):
        for columnIndex, Ceil in enumerate(row):
            if Ceil == None:
                PossibleMoves.add((rowIndex, columnIndex))
    return PossibleMoves


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    player_move = player(board)
    new_board = copy.deepcopy(board)
    i, j = action
    if board[i][j] != None:
        raise Exception
    else:
        new_board[i][j] = player_move
    return new_board


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    for player in (X, O):
        # check vertical
        for row in board:
            if row == [player] * 3:
                return player

        # check horizontal
        for i in range(3):
            column = [board[x][i] for x in range(3)]
            if column == [player] * 3:
                return player

        # check diagonal
        if [board[i][i] for i in range(0, 3)] == [player] * 3:
            return player

        elif [board[i][~i] for i in range(0, 3)] == [player] * 3:
            return player
    return None



def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    if winner(board) != None:
        return True
    # moves still possible
    for row in board:
        if EMPTY in row:
            return False

    # no possible moves
    return True


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    else:
        return 0


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    def MaxValue(board):
        optimal_move = ()
        if terminal(board):
            return utility(board), optimal_move
        else:
            v = -88
            for action in actions(board):
                minval = MinValue(result(board, action))[0]
                if minval > v:
                    v = minval
                    optimal_move = action
            return v, optimal_move
    def MinValue(board):
        optimal_move = ()
        if terminal(board):
            return utility(board), optimal_move
        else:
            v = 88
            for action in actions(board):
                maxval = MaxValue(result(board, action))[0]
                if maxval < v:
                    v = maxval
                    optimal_move = action
            return v, optimal_move

    curr_player = player(board)

    if terminal(board):
        return None

    if curr_player == X:
        return MaxValue(board)[1]

    else:
        return MinValue(board)[1]
