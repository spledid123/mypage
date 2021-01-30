def find(nums,target,n):
    front=0
    rear=n-1
    while front<rear:
        mid=int((front+rear)/2)
        if nums[mid]<target:front=mid+1
        else:rear=mid
    return nums[rear],rear
nums=[1,2,3,3,3,3,7,100]
print(find(nums,3,len(nums)))
#递增，若递减则改为>
