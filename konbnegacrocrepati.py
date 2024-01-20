income = 0
print("Kon banega crore pati")
print("Who is the prime minister of India")
options = ["a. rahul", "b. narendra modi", "c. sachin tendulkar", "d. narendra lodhi"]
for option in options:
  print(option)
inputl = input("\nEnter your option : ")
if inputl== "b":
  income += 10000
  print("You earned 10000 rupees")
else:
  print("You lose")
  exit()
print("Who is the national bird of India")
options1 = ["a. lion", "b. peackock", "c. piegon", "d. crow"]
for option in options1:
  print(option)
input1 = input("\nEnter your option : ")
if input1 == "b":
  income += 10000
  print("you earned 10000 rupees")
else:
  print("You lose 10000 rupees")
  income = 0
  


print("You earned ", income, "rupees")
exit()