import random

def read_string(prompt):
  return input(prompt)

def read_integer(prompt):
  line = read_string(prompt)
  while not line.isdigit():
    print("Please enter a whole number")
    line = read_string(prompt)
  return int(line)

correctNumber = random.randrange(1,100)

print("I am thinking of a number between 1 and 100.")
print("Which number is it?")

guess = read_integer("Enter your number here: ")
while guess != correctNumber:
  if guess < correctNumber:
    guess = read_integer("Go a bit higher than that: ")
  elif guess > correctNumber:
    guess = read_integer("Go a bit lower than that: ")
print("Congratulations! You are correct")
