def selection_sort(array):
    for i in range(len(array)):
        for j in range(len(array)):
            if array[j] > array[i]:
                array[j], array[i] = array[i], array[j]
    return array

vals = [2,1,4,2,1,3,5,7,23,5,3,56,3,1000]
print(selection_sort(vals.copy()))