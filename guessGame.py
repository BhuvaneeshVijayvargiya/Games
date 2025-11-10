import random

randomNum = random.randint(1, 100)
attempts = 1
while True:
    guessedNum = int(
        input(f"Attempt {attempts}: \n Guess a number between 1 and 100: "))
    if guessedNum < randomNum:
        print("Guess higher \n")
        attempts += 1
    elif guessedNum > randomNum:
        print('Guess lower \n')
        attempts += 1
    else:
        print(f'Your guess is correct \n \nYou took {attempts} attempts')
        print
        break
