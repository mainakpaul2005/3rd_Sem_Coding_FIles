#Wap to sort a dataset provided by user using different sorting techniques.
#Bubble, Merge, Quick and Heap Sort and compare their performance.
import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left_half = merge_sort(arr[:mid])
    right_half = merge_sort(arr[mid:])
    return merge(left_half, right_half)

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)


def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
    return arr

if __name__ == "__main__":
    try:
        data = list(map(int, input("Enter numbers separated by spaces: ").split()))
    except ValueError:
        print("Invalid input. Please enter only numbers separated by spaces.")
        exit()

    sorting_algorithms = {
        "Bubble Sort": bubble_sort,
        "Merge Sort": merge_sort,
        "Quick Sort": quick_sort,
        "Heap Sort": heap_sort
    }

    results = {}

    for name, sort_func in sorting_algorithms.items():
        data_copy = data.copy()
        start_time = time.perf_counter()
        sorted_data = sort_func(data_copy)
        end_time = time.perf_counter()
        results[name] = (end_time - start_time) * 1e6;  # Time in microseconds

    print("\nOriginal Data:", data)
    print("Sorted Data (using built-in sort):", sorted(data))
    print("\n--- Performance Comparison ---")
    for name, duration in results.items():
        print(f"{name}: {duration:.2f} microseconds")
    print("--------------------------")