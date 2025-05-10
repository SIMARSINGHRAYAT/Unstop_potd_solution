import sys

def main():
    n = int(sys.stdin.readline())
    tasks = list(map(int, sys.stdin.readline().split()))
    W = int(sys.stdin.readline())
    
    # Check if the number of workers exceeds the number of tasks
    if W > n:
        print(-1)
        return
    
    left = max(tasks)
    right = sum(tasks)
    answer = 0
    
    def is_possible(mid):
        parts = 1
        current_sum = 0
        for task in tasks:
            if current_sum + task > mid:
                parts += 1
                current_sum = 0
            current_sum += task
        return parts <= W
    
    while left <= right:
        mid = (left + right) // 2
        if is_possible(mid):
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    
    print(answer)

if __name__ == "__main__":
    main()