import random

numbers = {
0 : "zero",
1 : "one",
2 : "two",
3 : "three",
4 : "four",
5 : "five",
6 : "six",
7 : "seven",
8 : "eight",
9 : "nine",
}

def num_gen():
    list = []
    i = 0 
    while i<5:
        x = random.randint(0,9)
        if x in list:
            continue
        list.append(x)
        i += 1
    return list

def ply_gss():
    guess = input("enter a 5 digit number:")
    list2 = []
    for i in guess:
        i = int(i)
        list2.append(i)
    return list2

def check(gs,gn):
    list3 = []
    i = 0
    while i<5:
        if gs == gn:
            print("YOU GUESSED IT RIGHT!!")
            return "end"
        elif gs[i] == gn[i]:
            list3.append(gs[i])
        elif gs[i] in gn:
            list3.append(numbers[gs[i]])
        else:
            list3.append("X")
        i += 1
    return list3

def numbrle():
    while True:
        gn = num_gen()
        #print(gn)
        i = 0
        while i<6:
            print("number of tries" , i+1)
            gs = ply_gss()
            print(check(gs,gn))
            if check(gs,gn) == "end":
                break
            i += 1
        inp = input("q for exit, anything else to continue:")
        if inp == "q":
            print("exiting...")
            break

numbrle()