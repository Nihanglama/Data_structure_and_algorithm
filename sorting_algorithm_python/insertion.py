arr=[2,4,5,6,3,1,7,8,9,0]

def insertion(arr):
    for i in range(1,len(arr)):
        sorted=arr[i]
        j=i-1
        while(j>=0 and arr[j]>sorted):
            arr[j+1]=arr[j]
            j=j-1
        arr[j+1]=sorted

    print(arr)

insertion(arr)
            
