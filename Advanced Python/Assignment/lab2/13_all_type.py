class Example:

    static_var = 100

    def __init__(self):
        self.instance_var = 200

    def instance_method(self):
        local_var = 300

        print("\n--- Inside Instance Method ---")
        print("Local Variable:", local_var)
        print("Instance Variable:", self.instance_var)
        print("Static Variable:", Example.static_var)

    @classmethod
    def class_method(cls):
        local_var = 400

        print("\n--- Inside Class Method ---")
        print("Local Variable:", local_var)
        print("Instance Variable: Cannot access directly")
        print("Static Variable:", cls.static_var)

    @staticmethod
    def static_method():
        local_var = 500

        print("\n--- Inside Static Method ---")
        print("Local Variable:", local_var)
        print("Instance Variable: Cannot access directly")
        print("Static Variable:", Example.static_var)


e = Example()

e.instance_method()

Example.class_method()
Example.static_method()
