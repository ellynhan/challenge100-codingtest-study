import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

nums = input()
i = 0
while True:
    i += 1
    num = str(i)
    while len(num) > 0 and len(nums) > 0:
        if num[0] == nums[0]:
            nums = nums[1:]
        num = num[1:]
    if nums == '':
        print(i)
        break
  
        