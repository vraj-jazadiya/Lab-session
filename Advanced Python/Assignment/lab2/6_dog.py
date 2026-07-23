
class Dog:

    legs = 4

    @classmethod
    def walk(cls, animal_name):
        print(animal_name, "walks with", cls.legs, "legs.....")


Dog.walk("Dog")
Dog.walk("Cat")
Dog.walk("Cow")


