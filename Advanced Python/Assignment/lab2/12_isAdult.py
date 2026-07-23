
class Person:

    @staticmethod
    def isAdult(age):
        if age >= 18:
            print("Person is an Adult")
        else:
            print("Person is not an Adult")


Person.isAdult(25)
Person.isAdult(15)

