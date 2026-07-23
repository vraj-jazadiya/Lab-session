class FYBCA:

    admission = 0

    def __init__(self):
        FYBCA.admission = FYBCA.admission + 1

    @classmethod
    def total_admission(cls):
        print("Total Admission in FYBCA:", cls.admission)


s1 = FYBCA()
s2 = FYBCA()
s3 = FYBCA()
s4 = FYBCA()
s5 = FYBCA()

FYBCA.total_admission()
