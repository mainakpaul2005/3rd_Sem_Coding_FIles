students = {1:{},2:{},3:{}}
ch = "y"

while ch.lower() == "y":
    m = int(input("\n1.Insert & Print\n2.Modify Age\n3.Add University\n4.Remove Stream\n5.Insert 3 Students\nEnter choice: "))

    if m == 1:
        students[1] = {"name":input("Name: "),"age":int(input("Age: ")),"stream":input("Stream: ")}
    elif m == 2 and "age" in students[1]:
        students[1]["age"] = int(input("New Age: "))
    elif m == 3:
        students[1]["university"] = input("University: ")
    elif m == 4 and "stream" in students[1]:
        students[1].pop("stream")
    elif m == 5:
        for i in range(1,4):
            students[i] = {"name":input(f"Name {i}: "),"age":int(input(f"Age {i}: ")),"stream":input(f"Stream {i}: ")}
    else:
        print("Invalid Choice or No Data!")

    # print details
    for i,d in students.items():
        if d:
            print(f"\nStudent {i}: " + ", ".join(f"{k.capitalize()}: {v}" for k,v in d.items()))

    ch = input("\nDo you want to proceed? (y/n): ")
