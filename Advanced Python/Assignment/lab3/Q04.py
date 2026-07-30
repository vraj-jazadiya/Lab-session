# 4.	Create a Human class contains Head class and display() methods that display name of person
# a.	Now  add one Head class in Human class that contains talk() method that display message like “talking”.
# b.	Now add one more Brain class in Human class  that contains think() method that display message like “thinking”.
# c.	Now call all methods.

class Human:
    class Head:
        def talk(self):
            print("Talking")

    class Brain:
        def think(self):
            print("Thinking")

    def display(self, name):
        print("Name of the person:", name)

# Example usage:
human = Human()
human.display("Raghav")
head = human.Head()
brain = human.Brain()
head.talk()
brain.think()