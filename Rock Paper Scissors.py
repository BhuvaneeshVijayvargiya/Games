import random

play = 'y'
choices = ('r','p','s')

while play == 'y':
    computerTurn = random.choice(choices)
    userTurn = input('choose from (r/p/s): \n').lower()
    if userTurn not in choices:
        print('invalid choice')
    print(f'you chose: {userTurn} and computer chose: {computerTurn} \n')
   
    if computerTurn == 'r':
        if userTurn == 'r':
           print('It\'s a draw \n')
        if userTurn == 'p':
            print('User wins \n')
        if userTurn == 's':
            print('Computer wins')
    if computerTurn == 'p':
        if userTurn == 'p':
           print('It\'s a draw \n')
        if userTurn == 's':
            print('User wins \n')
        if userTurn == 'r':
            print('Computer wins')
    if computerTurn == 's':
        if userTurn == 's':
           print('It\'s a draw \n')
        if userTurn == 'r':
            print('User wins \n')
        if userTurn == 'p':
            print('Computer wins')
  
    play = input('Do you wanna play again(y/n): \n').lower()    