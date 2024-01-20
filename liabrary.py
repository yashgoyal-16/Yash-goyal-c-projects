class liabrary:
    def __init__(self) :
        self.noofbook = 0
        self.nameofbook = []
    def addbook(self,nameofbook):
       self.nameofbook.append(nameofbook)
       self.noofbook = len(self.nameofbook)
    def show(self):
        print(f"the number of books are {self.noofbook} and name of book")
        for book in self.nameofbook:
            print(book)
l1 = liabrary()
a = int(input("Enter number of books you want too add"))
for i in range(a):
   l1.addbook(input("Enter book name : "))



l1.show()