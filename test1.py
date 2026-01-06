numbers = [10, 20, 30, 40, 50]

for num in numbers:
    if num > 30:
        print(f"{num}")
        
a, b = input("숫자 두 개를 입력해주세요: ").split()
print(f"입력한 숫자는 {a}와 {b}입니다.")

data = list(map(int, input("숫자들을 입력해주세요: ").split()))
for num in data:
    print(f"입력한 숫자는 {num}입니다.")
    
n = int(input("몇 개의 숫자를 입력하시겠습니까? "))
data = list(map(int, input("숫자들을 입력하세요: ").split()))
for num in data:
    print(f"입력한 숫자는 {num}입니다.")