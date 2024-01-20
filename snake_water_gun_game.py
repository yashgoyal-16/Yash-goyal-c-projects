import random
while (True):

  def check(comp, user):
    if comp == user:
      return 0
    if (comp == 0 and user == 1):
      return -1
    if (comp == 2 and user == 0):
      return -1
    if (comp == 2 and user == 1):
      return -1
    if (comp == 1 and user == 2):
      return -1
    else:
      return 1

  comp = random.randint(1, 3)
  user = int(input("Enter your choice 0 for sanke 1 for water 2 for gun : "))
  score = check(comp, user)
  if score == 0:
    print("Match tie")
  elif (score == 1):
    print("you win")
  elif (score == -1):
    print("you loose")
