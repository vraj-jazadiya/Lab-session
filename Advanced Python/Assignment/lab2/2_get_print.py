
class Test:

    def get_String(self):
        self.string = input("Enter a string: ")

    def print_String(self):
        print("String in uppercase:", self.string.upper())


t = Test()

t.get_String()

t.print_String()

