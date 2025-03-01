"add_numbers"
def add_numbers():
    "Main function"
    a=1
    b=1
    y=""
    while True:
        a=input("a:")
        b=input("b:")
        print(a+b)
        y=input("Print y if you want to finish:")
        if y=="y":
            break
add_numbers() # f_hww (\r\n)
