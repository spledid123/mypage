def find(nums,target,n):
    if nums[n-1]<target:
        return n
    front=0
    rear=n-1
    while front<rear:
        mid=int((front+rear)/2)
        if nums[mid]<target:front=mid+1
        else:rear=mid
    return rear
nums=[1,2,3,3,3,3,3,7,100]
print(find(nums,101,len(nums)))
#递增，若递减则改为>

