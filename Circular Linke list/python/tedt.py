# names_list = ["Alice", "Bob", "Charlie", "David"]
# marks_tuple = (85, 90, 78, 92)
# unique_ids_set = {101, 102, 103, 104}
# student_info_dict = {"name": "Kartik", "age": 20, "department": "IT"}

# for key, value in student_info_dict.items():
    # print(f"key :{key}, value:{value}")


# students = ["Kartik", "Aanya", "Rohan", "Neha", "Simran"]

# for i in range(len(students)):
#     print(f"{i+1}welcome {students[i]}")

def changedlist(lst):
    if(len(lst)%2!=0):
        return "list must be even"
    
    mid1=len(lst)//2-1
    mid2=len(lst)//2

    firstmid=lst[mid1]
    secondmid=lst[mid2]

    new_lst=lst[:mid1]+lst[mid1+1:mid2]+lst[mid2+1:]

    return lst[mid1]+new_lst+lst[mid2]

test_list = ["a", "b", "c", "d", "e", "f", "g", "h"]
result=changedlist(test_list)
print(result)